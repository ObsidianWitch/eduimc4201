#include <linux/module.h>
MODULE_LICENSE("GPL");
#include <asm/io.h>
#include <asm/rtai.h>
#include <rtai_sched.h>
#include <rtai_sem.h>

#define STACK_SIZE  2000
#define PERIOD		50000000   // 50 ms
#define TICK_PERIOD 1000000    //  1 ms
#define TEN_MS      10000000   // 10 ms
#define N_TASK      2
#define VALUE		1000000
#define HIGH_PRIO   0
#define LOW_PRIO    1

static RT_TASK tasks[N_TASK];
static RTIME first_release;
static SEM semaphore;
static int is_counting = 1;

void task_body(long int arg) {
    RTIME reference = rt_get_time();
	int counter_period = PERIOD;
	int counter = 0;

	while(counter_period <= 20 * TEN_MS) {
		counter++;
		rt_sem_signal(&semaphore);

		rt_printk("[Counter %d]: Execution time :%llu ns\tPeriod: %d ns\n", counter,
        	count2nano(rt_get_time()-reference), counter_period);

        reference = rt_get_time();

		rt_task_set_resume_end_times(-nano2count(counter_period),-nano2count(counter_period));
		counter_period += TEN_MS;
	}
	
	is_counting = 0;
}

void wd_body(long int arg) {
	rt_sem_wait(&semaphore);
	
    while (is_counting) {
    	RTIME begin, diff;
    	int sig;
		
		begin = rt_get_time();
    	sig = rt_sem_wait_timed(&semaphore, nano2count(15*TEN_MS));
    	diff = rt_get_time() - begin;
    	
		if (count2nano(diff) >= 10*TEN_MS) {
    		rt_printk("[WD] Watchdog timeout\n");
    	}

    	if (sig != 0) {
    		rt_printk("[WD] Counter timeout\n");
    	}
    }
}

static int my_init(void) {
    int ierr1, ierr2;
	rt_typed_sem_init(&semaphore, 0, BIN_SEM);

    rt_set_oneshot_mode();
    ierr2 = rt_task_init_cpuid(&tasks[1], wd_body, HIGH_PRIO, STACK_SIZE, 1, 0, 0, 0);
    ierr1 = rt_task_init_cpuid(&tasks[0], task_body, LOW_PRIO, STACK_SIZE, 1, 0, 0, 0);

    printk("[Counter] init return code %d by program %s\n", ierr1, __FILE__);
    printk("[WD] init return code %d by program %s\n", ierr2, __FILE__);

    if (ierr1 == -1 || ierr2 == -1) {
        return -1;
	}

    start_rt_timer(nano2count(TICK_PERIOD));

	first_release = rt_get_time();
    rt_task_make_periodic(&tasks[0], first_release, nano2count(PERIOD));
    rt_task_resume(&tasks[1]);

    return 0;
}

void my_exit(void) {
	int i;
    stop_rt_timer();

    for (i = 0 ; i < N_TASK ; i++) {
        rt_task_delete(&tasks[i]);
    }

    rt_sem_delete(&semaphore);
}

module_init(my_init);
module_exit(my_exit);
