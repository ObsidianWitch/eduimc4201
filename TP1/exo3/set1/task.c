/*
RTAI module skeleton
*/
#include <linux/module.h>
MODULE_LICENSE("GPL");
#include <asm/io.h>

#include <asm/rtai.h>
#include <rtai_sched.h>

#define STACK_SIZE  2000
#define PERIOD      100000000  //  0.1 s
#define TICK_PERIOD 1000000    //  1 ms
#define VALUE       200000000
#define N_LOOP      10

static int C[3] = {1, 2, 3}; // low value -> high priority
static int Period[3] = {4, 6, 8};
static int Priority[3] = {1, 2, 3}; // 4, 6, 8
static RT_TASK task1, task2, task3;

void task_body(int arg) {
    static int loop = N_LOOP;

    while (loop-) {
        int i;

        rt_printk("Start task %d\t  %llu ns\n", arg, rt_get_time_ns());
        for(i = 0; i < C[arg] * VALUE; i++) {
            nop();
        }
        rt_printk("End task %d\t  %llu ns\n", arg, rt_get_time_ns());

        rt_task_wait_period();
    }
}

static int my_init(void) {
    int i, ierr1, ierr2, ierr3;

    rt_set_oneshot_mode();

    ierr1 = rt_task_init(&task1, task_body, 0, STACK_SIZE, Priority[0], 0, 0);
    ierr2 = rt_task_init(&task2, task_body, 1, STACK_SIZE, Priority[1], 0, 0);
    ierr3 = rt_task_init(&task3, task_body, 2, STACK_SIZE, Priority[2], 0, 0);
    printk("[task %d] init return code %d by program %s\n", 1, ierr1, __FILE__);
    printk("[task %d] init return code %d by program %s\n", 2, ierr2, __FILE__);
    printk("[task %d] init return code %d by program %s\n", 3, ierr3, __FILE__);

    if (!ierr1 && !ierr2 && !ierr3) {
        start_rt_timer( nano2count(TICK_PERIOD));

        rt_task_make_periodic(&task1, rt_get_time(), nano2count(Period[0] * PERIOD));
        rt_task_make_periodic(&task2, rt_get_time(), nano2count(Period[1] * PERIOD));
        rt_task_make_periodic(&task3, rt_get_time(), nano2count(Period[2] * PERIOD));
    }
    
    return ierr1 && ierr2 && ierr3;
}

void my_exit(void) {
    stop_rt_timer();
    rt_task_delete(&task1);
    rt_task_delete(&task2);
    rt_task_delete(&task3);
}

module_init(my_init);
module_exit(my_exit);
