#include <linux/module.h>
MODULE_LICENSE("GPL");
#include <asm/io.h>

#include <asm/rtai.h>
#include <rtai_sched.h>

#define ID          1
#define PRIORITY    1
#define STACK_SIZE  2000
#define PERIOD      1000000000 //  1 s
#define TICK_PERIOD 1000000    //  1 ms
#define N_LOOP      10

static RT_TASK my_task;

void my_code(long int arg) {
    RTIME t_first_release = rt_get_time_ns();
    static int loop = N_LOOP ;

    while (loop--) {
        RTIME t = rt_get_time_ns();

        rt_printk("Hello world  %llu\n", t - t_first_release);
        rt_task_wait_period();
    }
}

static int my_init(void) {
    int ierr;

    rt_set_oneshot_mode();

    ierr = rt_task_init(&my_task, my_code, ID, STACK_SIZE, PRIORITY, 0, 0);
    printk("[task %d] init return code %d by program %s\n", ID, ierr, __FILE__);

    if (!ierr) {
        start_rt_timer(nano2count(TICK_PERIOD));
        rt_task_make_periodic(&my_task, rt_get_time(), nano2count(PERIOD));
    }
    
    return ierr;
}

void my_exit(void) {
    stop_rt_timer();
    rt_task_delete(&my_task);
}


module_init(my_init);
module_exit(my_exit);
