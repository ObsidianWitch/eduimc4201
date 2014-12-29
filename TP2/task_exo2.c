#include <linux/module.h>
MODULE_LICENSE("GPL");
#include <asm/io.h>
#include <asm/rtai.h>
#include <rtai_sched.h>
#include <rtai_sem.h>

#define STACK_SIZE  2000
#define PERIOD		50000000
#define TICK_PERIOD 1000000    //  1 ms
#define TEN_MS      10000000   // 10 ms
#define N_TASK      2
#define N_LOOP      10
#define VALUE		1000000

static RT_TASK tasks[N_TASK];
static RTIME first_release;
static SEM semaphore;

/*void run_for_1_time_unit() {
	int i;
	for(i = 0; i <  VALUE; i++) {
		nop();
	}
}*/

void task_body(long int arg) {
    RTIME reference = rt_get_time();
	int counter_period = 5 * TEN_MS;
	int counter = 0;

	while(1) {
		counter++;
		rt_sem_signal(&semaphore);

		rt_printk("[Task]: Counter: %d\tExecution time :%llu ns\tPeriod: %d ns\n", counter,
        	count2nano(rt_get_time()-reference), counter_period);

        reference = rt_get_time();

		rt_task_set_resume_end_times(-nano2count(counter_period),-nano2count(counter_period));
		counter_period += TEN_MS;
	}
}

void wd_body(long int arg) {
	RTIME begin, end;

    // First wait
	rt_sem_wait(&semaphore);
    begin = rt_get_time();

    while (1) {
    	RTIME diff, endwd;

    	rt_sem_wait_timed(&semaphore, nano2count(15*TEN_MS));
    	end = rt_get_time();
    	diff = end-begin;
    	rt_printk("wd: diff: %llu\n", count2nano(diff));

    	if (count2nano(diff) > 15*TEN_MS) {
    		rt_printk("Counter timeout\n");
    	}

    	// TODO? run_for_1_time_unit();
    	endwd = rt_get_time();

    	if (count2nano(endwd - begin) > 10*TEN_MS) {
    		rt_printk("Watchdog timeout\n");
    	}

    	begin = endwd;
    }
}

static int my_init(void) {
    int ierr1, ierr2;
	rt_typed_sem_init(&semaphore, 0, BIN_SEM);

    rt_set_oneshot_mode();
    ierr2 = rt_task_init(&tasks[1], wd_body, 1, STACK_SIZE, 1, 0, 0);
    ierr1 = rt_task_init(&tasks[0], task_body, 2, STACK_SIZE, 1, 0, 0);


    printk("[task 1] init return code %d by program %s\n", ierr1, __FILE__);
    printk("[task 2] init return code %d by program %s\n", ierr2, __FILE__);

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

/*
[task 1] init return code 0 by program /home/rtai/Desktop/rtai_tp/tp2/watchdog/task.c
[task 2] init return code 0 by program /home/rtai/Desktop/rtai_tp/tp2/watchdog/task.c
[Task]: Counter: 1	Execution time :147 ns	Period: 50000000 ns
[Task]: Counter: 2	Execution time :49997183 ns	Period: 60000000 ns
wd: diff: 49998946
[Task]: Counter: 3	Execution time :59997786 ns	Period: 70000000 ns
wd: diff: 59998061
[Task]: Counter: 4	Execution time :69998864 ns	Period: 80000000 ns
wd: diff: 69999577
[Task]: Counter: 5	Execution time :79998953 ns	Period: 90000000 ns
wd: diff: 79999941
[Task]: Counter: 6	Execution time :89998639 ns	Period: 100000000 ns
wd: diff: 89999356
[Task]: Counter: 7	Execution time :99999132 ns	Period: 110000000 ns
wd: diff: 100000570
Watchdog timeout
[Task]: Counter: 8	Execution time :109998417 ns	Period: 120000000 ns
wd: diff: 109999359
Watchdog timeout
[Task]: Counter: 9	Execution time :119998559 ns	Period: 130000000 ns
wd: diff: 119999647
Watchdog timeout
[Task]: Counter: 10	Execution time :129998451 ns	Period: 140000000 ns
wd: diff: 129999074
Watchdog timeout
[Task]: Counter: 11	Execution time :139999057 ns	Period: 150000000 ns
wd: diff: 140000192
Watchdog timeout
[Task]: Counter: 12	Execution time :149998524 ns	Period: 160000000 ns
wd: diff: 149999337
Watchdog timeout
wd: diff: 150000349
Counter timeout
Watchdog timeout
[Task]: Counter: 13	Execution time :159998994 ns	Period: 170000000 ns
wd: diff: 9998306
wd: diff: 150000212
Counter timeout
Watchdog timeout
[Task]: Counter: 14	Execution time :169998731 ns	Period: 180000000 ns
wd: diff: 19998148
wd: diff: 150000224
Counter timeout
Watchdog timeout
[Task]: Counter: 15	Execution time :179998791 ns	Period: 190000000 ns
wd: diff: 29998040
wd: diff: 150000219
Counter timeout
Watchdog timeout
[Task]: Counter: 16	Execution time :189998869 ns	Period: 200000000 ns
wd: diff: 39998659
wd: diff: 150000211
Counter timeout
Watchdog timeout
[Task]: Counter: 17	Execution time :199998356 ns	Period: 210000000 ns
wd: diff: 49997644
wd: diff: 150000169
Counter timeout
Watchdog timeout
[Task]: Counter: 18	Execution time :209998866 ns	Period: 220000000 ns
wd: diff: 59998593
wd: diff: 150000226
Counter timeout
Watchdog timeout
[Task]: Counter: 19	Execution time :219998811 ns	Period: 230000000 ns
wd: diff: 69998661
wd: diff: 150000237
Counter timeout
Watchdog timeout
[Task]: Counter: 20	Execution time :229998396 ns	Period: 240000000 ns
wd: diff: 79997889
wd: diff: 150000172
Counter timeout
Watchdog timeout
[Task]: Counter: 21	Execution time :239998536 ns	Period: 250000000 ns
wd: diff: 89998141
wd: diff: 150000209
Counter timeout
Watchdog timeout
[Task]: Counter: 22	Execution time :249999119 ns	Period: 260000000 ns
wd: diff: 99998598
wd: diff: 150000201
Counter timeout
Watchdog timeout
[Task]: Counter: 23	Execution time :259998696 ns	Period: 270000000 ns
wd: diff: 109998624
Watchdog timeout
wd: diff: 150000416
Counter timeout
Watchdog timeout
[Task]: Counter: 24	Execution time :269998634 ns	Period: 280000000 ns
wd: diff: 119997996
Watchdog timeout
wd: diff: 150000381
Counter timeout
Watchdog timeout
*/
