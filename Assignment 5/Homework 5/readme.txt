Sean Arackal
CS2303 HW 5


Commands:

make: compile the program
make clean: remove objects and files created from old compilation
make docs: generate documentation for the code

./stacktest: takes strings as an input, pushes them into a stack and then pops the items
Usage: ./stacktest max_elements

./stacktest2: prints strings from the stack in reverse
Usage: ./stacktest2 max_elements

./stacktest_dbg
./stacktest2_dbg
(both commands are same as their respective functions with debugging)

Check doxygen output for more details on the functions used in the programs


Example Runs:

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw5$ ./stacktest
Enter exactly one argument on the command line!

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw5$ ./stacktest -1
-1 was entered but max elements must be greater than or equal to 0!

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw5$ ./stacktest 3 < input.txt
third line
This is the second line
This is a line

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw5$ ./stacktest 5 < input.txt
Fifth and final line
fourth
third line
This is the second line
This is a line

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw5$ ./stacktest2 5 < input.txt
enil lanif dna htfiF
htruof
enil driht
enil dnoces eht si sihT
enil a si sihT

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw5$ ./stacktest2 10 < input.txt
enil lanif dna htfiF
htruof
enil driht
enil dnoces eht si sihT
enil a si sihT
