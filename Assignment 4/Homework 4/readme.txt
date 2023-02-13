commands in cmd line:
make : to compile the program
make clean : to delete the executable to object files created using the make command
make docs : to generate doxygen documentation for the file


programs:
sorttest : functions to sort and print arrays taking all inputs from cmd line
sorttest2: functions to create, sort and print arrays taking only 2 inputs from cmd line

check doxygen documentation for more details

commands after the "make" compilation:

./sorttest string_of_numbers_separated_by_a_space
example : ./sorttest 4 1 5 2 3

./sorttest2 num_of_ints_to_randomly_gen_and_sort either_sort_descending_or_alt_sort_descending

examples : ./sorttest2 10000 sort_descending
           ./sorttest2 10000 alt_sort_descending


sample tests:

sorttest:

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw4$ ./sorttest
Must enter at least 2 numbers on the command line! Exiting.

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw4$ ./sorttest 1
Must enter at least 2 numbers on the command line! Exiting.

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw4$ ./sorttest 1 2 3
Unsorted array:
1
2
3
Sorted array (descending order):
3
2
1
Timestamp before sorting: Seconds: 1676249026, Microseconds: 977622
Timestamp after sorting: Seconds: 1676249026, Microseconds: 977622
Time spent sorting: Seconds: 0, Microseconds: 0



sorttest2:

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw4$ ./sorttest2
Must enter exactly two arguments on the command line!

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw4$ ./sorttest2 1 1
Enter only "sort_descending" or "alt_sort_descending" after the first argument on the command line!

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw4$ ./sorttest2 10 alt_sort_descending
Unsorted array:
1069196319
1625680943
1591099537
1190698047
307827677
1023991866
1868287561
1648752496
2009286391
1637214996
Sorted array (descending order):
2009286391
1868287561
1648752496
1637214996
1625680943
1591099537
1190698047
1069196319
1023991866
307827677
Timestamp before sorting: Seconds: 1676249202, Microseconds: 556363
Timestamp after sorting: Seconds: 1676249202, Microseconds: 556364
Time spent sorting: Seconds: 0, Microseconds: 1

last three lines from other tests:
./sorttest2 10000 sort_descending

Timestamp before sorting: Seconds: 1676249269, Microseconds: 59526
Timestamp after sorting: Seconds: 1676249269, Microseconds: 183685
Time spent sorting: Seconds: 0, Microseconds: 124159

./sorttest2 10000 alt_sort_descending
Timestamp before sorting: Seconds: 1676249339, Microseconds: 285303
Timestamp after sorting: Seconds: 1676249339, Microseconds: 378098
Time spent sorting: Seconds: 0, Microseconds: 92795

Question:
Is using incrementing pointers actually faster than using array indexing? If so, approximately how much faster?

Answer:
alt_sort_descending is about 1.33 times faster than sort_descending due to the use of pointers.
