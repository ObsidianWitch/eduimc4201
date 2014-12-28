#include <linux/module.h>
MODULE_LICENSE("GPL");
#include <asm/io.h>
#include <asm/rtai.h>
#include <rtai_sched.h>
#include <rtai_sem.h>

#define STACK_SIZE  2000
#define PERIOD		10000000
#define TICK_PERIOD 1000000    //  1 ms
#define N_LOOP      10
#define N_TASK      2

static RT_TASK tasks[N_TASK];
static RTIME first_release;
static SEM semaphore1;
static SEM semaphore2;

void task_body1(int arg) {
     int loop = N_LOOP;

    while (loop--) {
        rt_printk("T1\n");
		rt_sem_signal(&semaphore2);
		rt_sem_wait(&semaphore1);
        rt_printk("T1 after T2\n");
		rt_sem_signal(&semaphore2);

        rt_task_wait_period();
    }
}

void task_body2(int arg) {
     int loop = N_LOOP;

    while (loop--) {
    	rt_sem_wait(&semaphore2);
        rt_printk("T2 starts after T1\n");
		rt_sem_signal(&semaphore1);
		rt_sem_wait(&semaphore2);
        rt_printk("T2 ends\n\n");

        rt_task_wait_period();
    }
}

static int my_init(void) {
    int i, ierr1, ierr2;
	rt_typed_sem_init(&semaphore1, 0, BIN_SEM);
	rt_typed_sem_init(&semaphore2, 0, BIN_SEM);

    rt_set_oneshot_mode();
    ierr1 = rt_task_init(&tasks[0], task_body1, 0, STACK_SIZE, 1, 0, 0);
    ierr2 = rt_task_init(&tasks[1], task_body2, 0, STACK_SIZE, 0, 0, 0);

    printk("[task 1] init return code %d by program %s\n", ierr1, __FILE__);
    printk("[task 2] init return code %d by program %s\n", ierr2, __FILE__);

    if (ierr1 == -1 || ierr2 == -1) {
        return -1;
	}

    start_rt_timer(nano2count(TICK_PERIOD));

	first_release = rt_get_time();
    for (i = 0 ; i < N_TASK ; i++) {
        rt_task_make_periodic(&tasks[i], first_release, PERIOD);
    }

    return 0;
}

void my_exit(void) {
	int i;
    stop_rt_timer();

    for (i = 0 ; i < N_TASK ; i++) {
        rt_task_delete(&tasks[i]);
    }

    rt_sem_delete(&semaphore1);
    rt_sem_delete(&semaphore2);
}

module_init(my_init);
module_exit(my_exit);
