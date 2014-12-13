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
