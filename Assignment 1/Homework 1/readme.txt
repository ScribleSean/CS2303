Homework 1
Sean Arackal (sarackal@wpi.edu)


num.c

/* Very simple program to demo reading a number from the command line.
 * Created by Sean Arackal, sarackal
 * 
 * Usage:
 *   ./num some_number
 * Example:
 *   ./num 2303
 * 
 */


Possible Outputs/ Test data:


sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./num 
Must enter a number on the command line!

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./num 1 1 
The number you entered was: 1

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./num 100
The number you entered was: 100

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./num -100
The number you entered was: -100


grades.c

/* Very simple program to calculate the gpa from a list of inputted numbers.
 * Created by Sean Arackal, sarackal
 * 
 * Usage:
 *   ./grades a_list_of_numbers
 * Example:
 *   ./grades 1 4 3
 *  value of MAX_INPUTS set to 20
 */
 
 
Possible Outputs/ Test data:


sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./grades
Enter one or more grades on the command line!

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./grades 1
Grades entered: 1
Grade: 1
The lowest grade was: 1
The highest grade was: 1
Cumulative GPA from the given grades is: 1.000000
sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./grades 1 1 1 1 1
Grades entered: 5
Grade: 1
Grade: 1
Grade: 1
Grade: 1
Grade: 1
The lowest grade was: 1
The highest grade was: 1
Cumulative GPA from the given grades is: 1.000000

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./grades 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
Too many inputs. Removing extra inputs.
Grades entered: 20
Grade: 1
Grade: 2
Grade: 3
Grade: 4
Grade: 5
Grade: 6
Grade: 7
Grade: 8
Grade: 9
Grade: 10
Grade: 11
Grade: 12
Grade: 13
Grade: 14
Grade: 15
Grade: 16
Grade: 17
Grade: 18
Grade: 19
Grade: 20
The lowest grade was: 1
The highest grade was: 20
Cumulative GPA from the given grades is: 10.500000


leap.c

/* Simple program to check if inputted number is a leap year or not
 * Created by Sean Arackal, sarackal
 * 
 * Usage:
 *   ./leap a_number
 * Example:
 *   ./leapS 2303
 * 
 */


Possible Outputs/ Test data:


sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./leap
Must enter a number on the command line!

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./leap 1
Cannot check check the year 1 as we can only check for years after 1752

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./leap 1751
Cannot check check the year 1751 as we can only check for years after 1752

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./leap 1752
The year 1752 is a leap year!

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./leap 1900
The year 1900 is not a leap year 

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./leap 200
Cannot check check the year 200 as we can only check for years after 1752

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./leap 2000
The year 2000 is a leap year!

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./leap 2004
The year 2004 is a leap year!

sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw1$ ./leap 2005
The year 2005 is not a leap year 

