TP1
====

Ex1
---

Execution trace

    Hello world  28
    Hello world  999999523
    Hello world  1999999601
    Hello world  2999999531
    Hello world  3999999531
    Hello world  4999999526
    Hello world  5999999528
    Hello world  6999999523
    Hello world  7999999678
    Hello world  8999999531

Ex2
---

Execution trace

	[task 1] init return code 0 by program /home/obside/Documents/real_time_tps/TP1/task_exo2.c
	Start task		4273395 ns
	End task		406803696 ns
	Execution time	402530302 ns

	Start task		1000121951 ns
	End task		1437751081 ns
	Execution time	437629129 ns

	Start task		2000145192 ns
	End task		2445468240 ns
	Execution time	445323049 ns

	Start task		3000060099 ns
	End task		3427724019 ns
	Execution time	427663921 ns

	Start task		4001848864 ns
	End task		4429964555 ns
	Execution time	428115691 ns

	Start task		5000058153 ns
	End task		5447639623 ns
	Execution time	447581470 ns

	Start task		6000163491 ns
	End task		6434371414 ns
	Execution time	434207923 ns

	Start task		7000116167 ns
	End task		7434612401 ns
	Execution time	434496233 ns

	Start task		8000106867 ns
	End task		8398967443 ns
	Execution time	398860576 ns

	Start task		9000045953 ns
	End task		9428073434 ns
	Execution time	428027482 ns

Ex3
---

U =< n*(2^{1/n} - 1) is a sufficient condition for the schedulability of
fixed-priority algorithms iff for all i, D_i = T_i.  
For n = 3 tasks, n*(2^{1/n} - 1) = 0.7798.

U =< 1 is a necessary and sufficient condition for the schedulability of the EDF
algorithm iff for all i, D_i = T_i.

* set 1 : U = 1/4 + 2/6 + 3/8 = 0.95
* set 2 : U = 2/7 + 2/11 + 5/13 = 0.85

-> These sets are not schedulable with RM.  
-> These sets are schedulable with EDF.

### RM - Set1

Execution trace

    Start task 0	  759 ns
    End task 0	  12501474 ns
    Task length 0	  12500714 ns
    Start task 1	  12503517 ns
    End task 1	  37502458 ns
    Task length 1	  24998942 ns
    Start task 2	  37503485 ns
    Start task 0	  50158835 ns
    End task 0	  62662460 ns
    Task length 0	  12503625 ns
    Start task 1	  75238236 ns
    End task 1	  100237847 ns
    Task length 1	  24999610 ns
    Start task 0	  100317636 ns
    End task 0	  112817246 ns
    Task length 0	  12499610 ns
    End task 2	  125027074 ns
    Task length 2	  87523590 ns
    Start task 2	  125027770 ns
    Start task 0	  150476437 ns
    End task 0	  162975995 ns
    Task length 0	  12499559 ns
    Start task 1	  162977124 ns
    End task 1	  187975948 ns
    Task length 1	  24998825 ns
    End task 2	  200032539 ns
    Task length 2	  75004769 ns
    Start task 0	  200635307 ns
    End task 0	  213135760 ns
    Task length 0	  12500454 ns
    Start task 2	  213137094 ns
    Start task 1	  225714630 ns
    End task 1	  250713426 ns
    Task length 1	  24998797 ns
    Start task 0	  250794033 ns
    End task 0	  263293609 ns
    Task length 0	  12499576 ns
    End task 2	  288148361 ns

### RM - Set2

    Start task 0	  847 ns
    End task 0	  25001304 ns
    Task length 0	  25000458 ns
    Start task 1	  25003181 ns
    End task 1	  50002115 ns
    Task length 1	  24998935 ns
    Start task 2	  50003165 ns
    Start task 0	  87943696 ns
    End task 0	  112943117 ns
    Task length 0	  24999420 ns
    End task 2	  137507069 ns
    Task length 2	  87503906 ns
    Start task 1	  138197334 ns
    End task 1	  163197098 ns
    Task length 1	  24999765 ns
    Start task 2	  163324025 ns
    Start task 0	  175887354 ns
    End task 0	  200886195 ns
    Task length 0	  24998842 ns
    End task 2	  250827616 ns
    Task length 2	  87503591 ns
    Start task 0	  263831108 ns
    End task 0	  288830802 ns
    Task length 0	  24999695 ns
    Start task 1	  288832314 ns
    End task 1	  313831213 ns
    Task length 1	  24998900 ns
    Start task 2	  326648002 ns
    Start task 0	  351774670 ns
    End task 0	  376773728 ns
    Task length 0	  24999058 ns
    End task 2	  414152606 ns
    Task length 2	  87504603 ns
    Start task 1	  414591681 ns
    End task 1	  439591427 ns
    Task length 1	  24999746 ns
    Start task 0	  439718388 ns
    End task 0	  464717746 ns
    Task length 0	  24999357 ns
    Start task 2	  489971932 ns
    Start task 0	  527661982 ns
    End task 0	  552660928 ns
    Task length 0	  24998945 ns
    Start task 1	  552788734 ns
    End task 1	  577787627 ns
    Task length 1	  24998892 ns
    End task 2	  602481868 ns
    Task length 2	  112509936 ns
    Start task 0	  615605735 ns
    End task 0	  640605464 ns
    Task length 0	  24999731 ns
    Start task 2	  653295817 ns
    Start task 1	  690985909 ns
    Start task 0	  703549292 ns
    End task 0	  728548105 ns
    Task length 0	  24998815 ns
    End task 1	  740991300 ns
    Task length 1	  50005392 ns
    End task 2	  765805644 ns
    Task length 2	  112509828 ns
    Start task 0	  791493046 ns
    End task 0	  816492739 ns
    Task length 0	  24999693 ns
    Start task 2	  816619748 ns
    Start task 1	  829183085 ns
    End task 1	  854181935 ns
    Task length 1	  24998850 ns
    End task 2	  904130444 ns
    Task length 2	  87510697 ns
    Start task 1	  967380477 ns
    End task 1	  992379989 ns
    Task length 1	  24999513 ns
    Start task 2	  992381255 ns
    End task 2	  1054877825 ns
    Task length 2	  62496570 ns
    Start task 1	  1105577483 ns
    End task 1	  1130576753 ns
    Task length 1	  24999270 ns
    Start task 2	  1143267613 ns
    End task 2	  1205764549 ns
    Task length 2	  62496937 ns
    Start task 1	  1243774717 ns
    End task 1	  1268774457 ns
    Task length 1	  24999740 ns
    Start task 2	  1306591581 ns
    End task 2	  1369088637 ns
    Task length 2	  62497055 ns
    Start task 2	  1469915474 ns
    End task 2	  1532415390 ns
    Task length 2	  62499916 ns

### EDF set 1

	[task 0] init return code 0 by program /home/obside/Documents/real_time_tps/TP1/task_exo3_edf.c
	[task 1] init return code 0 by program /home/obside/Documents/real_time_tps/TP1/task_exo3_edf.c
	[task 2] init return code 0 by program /home/obside/Documents/real_time_tps/TP1/task_exo3_edf.c
	value: 35972419

	Start task 0	152218 ns
	End task 0		9467506 ns
	Task length 0	9315288 ns

	Start task 1	9502157 ns
	End task 1		26562099 ns
	Task length 1	17059943 ns

	Start task 2	26578097 ns
	End task 2		50462105 ns
	Task length 2	23884008 ns

	Start task 0	55727408 ns
	End task 0		63412955 ns
	Task length 0	7685547 ns

	Start task 1	83513360 ns
	End task 1		98996596 ns
	Task length 1	15483237 ns

	Start task 0	111348324 ns
	End task 0		119334851 ns
	Task length 0	7986527 ns

	Start task 2	119350307 ns
	End task 2		142581090 ns
	Task length 2	23230784 ns

	Start task 0	167020391 ns
	End task 0		175435833 ns
	Task length 0	8415443 ns

	Start task 1	175450210 ns
	End task 1		192542907 ns
	Task length 1	17092698 ns

	Start task 0	222638382 ns
	End task 0		236306253 ns
	Task length 0	13667872 ns


### EDF set 2

	[task 0] init return code 0 by program /home/obside/Documents/real_time_tps/TP1/task_exo3_edf.c
	[task 1] init return code 0 by program /home/obside/Documents/real_time_tps/TP1/task_exo3_edf.c
	[task 2] init return code 0 by program /home/obside/Documents/real_time_tps/TP1/task_exo3_edf.c
	value: 24986892

	Start task 0	  24387 ns
	End task 0	  17163264 ns
	Task length 0	  17138876 ns

	Start task 1	  17218292 ns
	End task 1	  33560218 ns
	Task length 1	  16341927 ns

	Start task 2	  33604061 ns
	End task 2	  78473155 ns
	Task length 2	  44869094 ns

	Start task 0	  78487536 ns
	End task 0	  94033300 ns
	Task length 0	  15545765 ns

	Start task 1	  106399457 ns
	End task 1	  121940246 ns
	Task length 1	  15540790 ns

	Start task 2	  125650798 ns
		Start task 0	  135303126 ns
		End task 0	  156063969 ns
		Task length 0	  20760843 ns
	End task 2	  196911449 ns
	Task length 2	  71260651 ns

TP2
===

exo1
---

Execution Trace

    [task 1] init return code 0 by program /home/rtai/Desktop/rtai_tp/tp2/task.c
    [task 2] init return code 0 by program /home/rtai/Desktop/rtai_tp/tp2/task.c
    T1
    T2 starts after T1
    T1 after T2
    T2 ends

    T1
    T2 starts after T1
    T1 after T2
    T2 ends

    T1
    T2 starts after T1
    T1 after T2
    T2 ends
    
exo2
---

Execution Trace

	[Counter] init return code 0 by program /media/home/obside/Documents/ESIEE/E4/IMC-4201_Real_Time_Systems/TPs/2014/TP2/task_exo2.c
	[WD] init return code 0 by program /media/home/obside/Documents/ESIEE/E4/IMC-4201_Real_Time_Systems/TPs/2014/TP2/task_exo2.c
	[Counter 1]: Execution time :537 ns	Period: 50000000 ns
	[Counter 2]: Execution time :49997769 ns	Period: 60000000 ns
	[Counter 3]: Execution time :59993311 ns	Period: 70000000 ns
	[Counter 4]: Execution time :69993624 ns	Period: 80000000 ns
	[Counter 5]: Execution time :79996640 ns	Period: 90000000 ns
	[Counter 6]: Execution time :89997109 ns	Period: 100000000 ns
	[Counter 7]: Execution time :99997198 ns	Period: 110000000 ns
	[Counter 8]: Execution time :109997454 ns	Period: 120000000 ns
	[WD] Watchdog timeout

	[Counter 9]: Execution time :119997309 ns	Period: 130000000 ns
	[WD] Watchdog timeout
	
	[Counter 10]: Execution time :129996931 ns	Period: 140000000 ns
	[WD] Watchdog timeout
	
	[Counter 11]: Execution time :139995853 ns	Period: 150000000 ns
	[WD] Watchdog timeout
	
	[Counter 12]: Execution time :149997078 ns	Period: 160000000 ns
	[WD] Watchdog timeout
	
	[WD] Watchdog timeout
	[WD] Counter timeout
	[Counter 13]: Execution time :159995490 ns	Period: 170000000 ns
	
	[WD] Watchdog timeout
	[WD] Counter timeout
	[Counter 14]: Execution time :169998011 ns	Period: 180000000 ns
	
	[WD] Watchdog timeout
	[WD] Counter timeout
	[Counter 15]: Execution time :179995787 ns	Period: 190000000 ns
	
	[WD] Watchdog timeout
	[WD] Counter timeout
	[Counter 16]: Execution time :189996388 ns	Period: 200000000 ns
	
	[WD] Watchdog timeout
	[WD] Counter timeout

exo3
---

Execution Trace

	> cat /dev/rtf0
	[Counter] init return code 0 by program /home/obside/Documents/real_time_tps/TP2/task_exo3.c
	[WD] init return code 0 by program /home/obside/Documents/real_time_tps/TP2/task_exo3.c
	[Counter 1]: Execution time :6924 ns	Period: 50000000 ns
	[Counter 2]: Execution time :50332745 ns	Period: 60000000 ns
	[Counter 3]: Execution time :59745000 ns	Period: 70000000 ns
	[Counter 4]: Execution time :70034127 ns	Period: 80000000 ns
	[Counter 5]: Execution time :80116079 ns	Period: 90000000 ns
	[Counter 6]: Execution time :89944172 ns	Period: 100000000 ns
	[Counter 7]: Execution time :100050455 ns	Period: 110000000 ns
	[WD] Watchdog timeout
	[Counter 8]: Execution time :110019078 ns	Period: 120000000 ns
	[WD] Watchdog timeout
	[Counter 9]: Execution time :120006451 ns	Period: 130000000 ns
	[WD] Watchdog timeout
	[Counter 10]: Execution time :129798212 ns	Period: 140000000 ns
	[WD] Watchdog timeout
	[Counter 11]: Execution time :140095525 ns	Period: 150000000 ns
	[WD] Watchdog timeout
	[Counter 12]: Execution time :149971340 ns	Period: 160000000 ns
	[WD] Watchdog timeout
	[WD] Watchdog timeout
	[WD] Counter timeout
	[Counter 13]: Execution time :160041252 ns	Period: 170000000 ns
	[WD] Watchdog timeout
	[WD] Counter timeout
	[Counter 14]: Execution time :170057848 ns	Period: 180000000 ns
	[WD] Watchdog timeout
	[WD] Counter timeout
	[Counter 15]: Execution time :179956790 ns	Period: 190000000 ns
	[WD] Watchdog timeout
	[WD] Counter timeout
	[Counter 16]: Execution time :189892657 ns	Period: 200000000 ns
	[WD] Watchdog timeout
	[WD] Counter timeout

