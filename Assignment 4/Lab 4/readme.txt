Lab 4
CS2303
Sean Arackal
CX04

using the evidence from:
Breakpoint 2, sum (n=5) at dtest.c:21
21	    total += i;
(gdb) print &i
$1 = (int *) 0x7fffffffdf98
(gdb) print &total
$2 = (int *) 0x7fffffffdf9c
(gdb) next

Question 1:
Address of i is less than address of total. Stacks go from higher to lower numbered addresses. This means total is closer to the top of the stack.

Question 2:
Address of i: 0x7fffffffdf98
Address of total: 0x7fffffffdf9c

Question 3:
As total is declared after i, it is a newer variable. From the addresses in question 2, we can see that the memory address for total is higher which means
that the stack grows down in memory.



Somplete Console run:

(gdb) run 5
Starting program: /home/sarackal/cs2303_labs/cs2303_lab04/dtest 5
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
Starting program dtest.

Breakpoint 2, sum (n=5) at dtest.c:21
21	    total += i;
(gdb) print &i
$1 = (int *) 0x7fffffffdf98
(gdb) print &total
$2 = (int *) 0x7fffffffdf9c
(gdb) next
20	  for (i = 0; i <= n; i++) {
(gdb) next

Breakpoint 2, sum (n=5) at dtest.c:21
21	    total += i;
(gdb) print &i
$3 = (int *) 0x7fffffffdf98
(gdb) print &total
$4 = (int *) 0x7fffffffdf9c
(gdb) next
20	  for (i = 0; i <= n; i++) {
(gdb) next

Breakpoint 2, sum (n=5) at dtest.c:21
21	    total += i;
(gdb) print &i
$5 = (int *) 0x7fffffffdf98
(gdb) print &total
$6 = (int *) 0x7fffffffdf9c
(gdb)
