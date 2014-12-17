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

    Start task	  6541113525308
    End task	  6541738584072
    Start task	  6542113524775
    End task	  6542738578872
    Start task	  6543113524782
    End task	  6543738578982
    Start task	  6544113524705
    End task	  6544738579071
    Start task	  6545113524778
    End task	  6545738579456
    Start task	  6546113524813
    End task	  6546738579889
    Start task	  6547113524793
    End task	  6547738579471
    Start task	  6548113524782
    End task	  6548738579032
    Start task	  6549113524772
    End task	  6549738578804
    Start task	  6550113524711
    End task	  6550738578794

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

    value: 12535317
    Start task 0	  892 ns
    End task 0	  40009856 ns
    Task length 0	  12502039 ns
    Start task 1	  40016660 ns
    End task 1	  120018308 ns
    Task length 1	  24998992 ns
    Start task 2	  120021900 ns
    End task 2	  240039860 ns
    Task length 2	  37503328 ns
    Start task 0	  240042712 ns
    End task 0	  280059144 ns
    Task length 0	  12504374 ns
    Start task 1	  280061888 ns
    End task 1	  360077464 ns
    Task length 1	  25003344 ns
    Start task 0	  360081044 ns
    End task 0	  400082136 ns
    Task length 0	  12499580 ns
    Start task 2	  400084528 ns
    End task 2	  520100248 ns
    Task length 2	  37502628 ns
    Start task 0	  520103840 ns
    End task 0	  560104912 ns
    Task length 0	  12499574 ns
    Start task 1	  560107188 ns
    End task 1	  640108312 ns
    Task length 1	  24998828 ns
    Start task 0	  641847680 ns
    End task 0	  681851464 ns
    Task length 0	  12500421 ns
    Start task 2	  681854224 ns
    End task 2	  801870968 ns
    Task length 2	  37502948 ns
    Start task 1	  801873376 ns
    End task 1	  881901972 ns
    Task length 1	  25007412 ns
    Start task 0	  881904420 ns
    End task 0	  921905492 ns
    Task length 0	  12499574 ns
    Start task 0	  962771352 ns
    End task 0	  1002777732 ns
    Task length 0	  12501232 ns
    Start task 1	  1002782772 ns
    End task 1	  1082784052 ns
    Task length 1	  24998877 ns
    Start task 2	  1082787224 ns
    End task 2	  1202804432 ns
    Task length 2	  37503093 ns
    Start task 0	  1202806852 ns
    End task 0	  1242823264 ns
    Task length 0	  12504367 ns
    Start task 1	  1242825660 ns
    End task 1	  1322841276 ns
    Task length 1	  25003356 ns
    Start task 0	  1322844916 ns
    End task 0	  1362845996 ns
    Task length 0	  12499576 ns
    Start task 2	  1362848308 ns
    End task 2	  1482863800 ns
    Task length 2	  37502556 ns
    Start task 0	  1482867328 ns
    End task 0	  1522868408 ns
    Task length 0	  12499576 ns
    Start task 1	  1522870716 ns
    End task 1	  1602871844 ns
    Task length 1	  24998830 ns
    Start task 2	  1604623184 ns
    End task 2	  1724642648 ns
    Task length 2	  37503798 ns
    Start task 1	  1724646912 ns
    End task 1	  1804648024 ns
    Task length 1	  24998825 ns
    Start task 1	  1925542324 ns
    End task 1	  2005547332 ns
    Task length 1	  25000042 ns
    Start task 2	  2005552440 ns
    End task 2	  2125553960 ns
    Task length 2	  37498190 ns
    Start task 1	  2166235020 ns
    End task 1	  2246238876 ns
    Task length 1	  24999682 ns
    Start task 2	  2246465920 ns
    End task 2	  2366469368 ns
    Task length 2	  37498792 ns
    Start task 2	  2567389632 ns
    End task 2	  2687394684 ns
    Task length 2	  37499294 ns
    Start task 2	  2888313588 ns
    End task 2	  3008317968 ns
    Task length 2	  37499084 ns


### EDF set 1

    value: 12535317
    Start task 0	  892 ns
    End task 0	  40009856 ns
    Task length 0	  12502039 ns
    Start task 1	  40016660 ns
    End task 1	  120018308 ns
    Task length 1	  24998992 ns
    Start task 2	  120021900 ns
    End task 2	  240039860 ns
    Task length 2	  37503328 ns
    Start task 0	  240042712 ns
    End task 0	  280059144 ns
    Task length 0	  12504374 ns
    Start task 1	  280061888 ns
    End task 1	  360077464 ns
    Task length 1	  25003344 ns
    Start task 0	  360081044 ns
    End task 0	  400082136 ns
    Task length 0	  12499580 ns
    Start task 2	  400084528 ns
    End task 2	  520100248 ns
    Task length 2	  37502628 ns
    Start task 0	  520103840 ns
    End task 0	  560104912 ns
    Task length 0	  12499574 ns
    Start task 1	  560107188 ns
    End task 1	  640108312 ns
    Task length 1	  24998828 ns
    Start task 0	  641847680 ns
    End task 0	  681851464 ns
    Task length 0	  12500421 ns
    Start task 2	  681854224 ns
    End task 2	  801870968 ns
    Task length 2	  37502948 ns
    Start task 1	  801873376 ns
    End task 1	  881901972 ns
    Task length 1	  25007412 ns
    Start task 0	  881904420 ns
    End task 0	  921905492 ns
    Task length 0	  12499574 ns
    Start task 0	  962771352 ns
    End task 0	  1002777732 ns
    Task length 0	  12501232 ns
    Start task 1	  1002782772 ns
    End task 1	  1082784052 ns
    Task length 1	  24998877 ns
    Start task 2	  1082787224 ns
    End task 2	  1202804432 ns
    Task length 2	  37503093 ns
    Start task 0	  1202806852 ns
    End task 0	  1242823264 ns
    Task length 0	  12504367 ns
    Start task 1	  1242825660 ns
    End task 1	  1322841276 ns
    Task length 1	  25003356 ns
    Start task 0	  1322844916 ns
    End task 0	  1362845996 ns
    Task length 0	  12499576 ns
    Start task 2	  1362848308 ns
    End task 2	  1482863800 ns
    Task length 2	  37502556 ns
    Start task 0	  1482867328 ns
    End task 0	  1522868408 ns
    Task length 0	  12499576 ns
    Start task 1	  1522870716 ns
    End task 1	  1602871844 ns
    Task length 1	  24998830 ns
    Start task 2	  1604623184 ns
    End task 2	  1724642648 ns
    Task length 2	  37503798 ns
    Start task 1	  1724646912 ns
    End task 1	  1804648024 ns
    Task length 1	  24998825 ns
    Start task 1	  1925542324 ns
    End task 1	  2005547332 ns
    Task length 1	  25000042 ns
    Start task 2	  2005552440 ns
    End task 2	  2125553960 ns
    Task length 2	  37498190 ns
    Start task 1	  2166235020 ns
    End task 1	  2246238876 ns
    Task length 1	  24999682 ns
    Start task 2	  2246465920 ns
    End task 2	  2366469368 ns
    Task length 2	  37498792 ns
    Start task 2	  2567389632 ns
    End task 2	  2687394684 ns
    Task length 2	  37499294 ns
    Start task 2	  2888313588 ns
    End task 2	  3008317968 ns
    Task length 2	  37499084 ns

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
