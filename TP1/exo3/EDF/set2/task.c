#include <linux/module.h>
MODULE_LICENSE("GPL");
#include <asm/io.h>

#include <asm/rtai.h>
#include <rtai_sched.h>

#define STACK_SIZE  2000
#define TICK_PERIOD 1000000    //  1 ms
#define VALUE       20000000
#define N_LOOP      10
#define N_TASK      3
#define ONE_SEC     1000000000

static int C[N_TASK] = {2, 2, 5};
static int Period[N_TASK] = {7, 11, 13};
static int Priority[N_TASK] = {1, 2, 3};
static RT_TASK tasks[N_TASK];
static RTIME first_release;

RTIME calibrate() {
	int k;
    RTIME a, b, value;

    a = rt_get_time();
    for(k = 0; k < VALUE; k++){
    	nop();
    }
    b = rt_get_time();

    value = b-a;
    printk("value: %llu\n", value);

    return value;
}

void run_for_1_time_unit() {
    int i;
    for(i = 0; i <  VALUE; i++) {
        nop();
    }
}

void task_body(int arg) {
     int loop = N_LOOP;

	rt_task_set_resume_end_times(-0, -Period[arg]*time_unit);

    while (loop--) {
        int i;
		RTIME begin, end;
		begin = rt_get_time();
        rt_printk("Start task %d\t  %llu ns\n", arg, count2nano(begin-first_release));
        for(i = 0; i < C[arg] ; i++) {
            run_for_1_time_unit();
        }
        end = rt_get_time();
        rt_printk("End task %d\t  %llu ns\n", arg, count2nano(end-first_release));
        rt_printk("Task length %d\t  %llu ns\n", arg, count2nano(end-begin));

		rt_task_set_resume_end_times(-Period[arg]*time_unit, -Period[arg]*time_unit);
    }
}

static int my_init(void) {
    int i;
    RTIME time_unit;

    rt_set_oneshot_mode();

    for (i = 0 ; i < N_TASK ; i++) {
        int ierr = rt_task_init(&tasks[i], task_body, i, STACK_SIZE, Priority[i], 0, 0);

        printk("[task %d] init return code %d by program %s\n", i, ierr, __FILE__);

        if (ierr == -1) {
            return ierr;
        }
    }

    start_rt_timer(nano2count(TICK_PERIOD));

    time_unit = calibrate();

	first_release = rt_get_time() + nano2count(2 * ONE_SEC);
    for (i = 0 ; i < N_TASK ; i++) {
        rt_task_make_periodic(&tasks[i], first_release, Period[i] * time_unit);
    }

    return 0;
}

void my_exit(void) {
	int i;
    stop_rt_timer();

    for (i = 0 ; i < N_TASK ; i++) {
        rt_task_delete(&tasks[i]);
    }
}

module_init(my_init);
module_exit(my_exit);
