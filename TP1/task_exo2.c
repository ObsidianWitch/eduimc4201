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
static RTIME first_release;

void my_code(long int arg) {
    static int loop = N_LOOP ;

    while (loop--) {
		RTIME begin, end;
        int i;
		
		begin = rt_get_time();
        rt_printk("Start task\t %llu ns\n", count2nano(begin - first_release));
        for(i = 0; i < PERIOD; i++) {
            nop();
        }
        end = rt_get_time();
        rt_printk("End task\t\t %llu ns\n", count2nano(end - first_release));
        rt_printk("Execution time\t %llu ns\n\n", count2nano(end - begin));

        rt_task_wait_period();
    }
}

static int my_init(void) {
    int ierr;

    rt_set_oneshot_mode();

    ierr = rt_task_init_cpuid(&my_task, my_code, ID, STACK_SIZE, PRIORITY, 0, 0, 0);
    printk("[task %d] init return code %d by program %s\n", ID, ierr, __FILE__);

    if (!ierr) {
		first_release = rt_get_time();
        start_rt_timer(nano2count(TICK_PERIOD));
        rt_task_make_periodic(&my_task, first_release, nano2count(PERIOD));
    }

    return ierr;
}

void my_exit(void) {
    stop_rt_timer();
    rt_task_delete(&my_task);
}


module_init(my_init);
module_exit(my_exit);
