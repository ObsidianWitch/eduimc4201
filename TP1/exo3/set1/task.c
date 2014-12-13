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
#define N_TASK      3

static int C[N_TASK] = {1, 2, 3};
static int Period[N_TASK] = {4, 6, 8};
static int Priority[N_TASK] = {1, 2, 3};
static RT_TASK[N_TASK] tasks;

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
    int i;

    rt_set_oneshot_mode();

    for (i = 0 ; i < N_TASKS ; i++) {
        int ierr = rt_task_init(tasks[i], task_body, i, STACK_SIZE, Priority[i], 0, 0);

        printk("[task %d] init return code %d by program %s\n", i, ierr, __FILE__);

        if (!ierr) {
            return ierr;
        }
    }

    start_rt_timer(nano2count(TICK_PERIOD));

    for (i = 0 ; i < N_TASKS ; i++) {
        rt_task_make_periodic(tasks[i], rt_get_time(), nano2count(Period[i] * PERIOD));
    }

    return 0;
}

void my_exit(void) {
    stop_rt_timer();

    for (i = 0 ; i < N_TASKS ; i++) {
        rt_task_delete(tasks[i]);
    }
}

module_init(my_init);
module_exit(my_exit);
