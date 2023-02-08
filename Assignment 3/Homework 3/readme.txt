README


make
to complie the code

make clean
to remove previous compliations and objects

make docs
to genereate documentation for the code

Programs:
ctest
use ./ctest to run the program


sample output:
sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw3$ make
gcc -c ctest.c
gcc -c mystring.c
gcc -c structure.c
gcc ctest.o mystring.o structure.o -o ctest
sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw3$ ./ctest
Arrays:   a1: 0x7ffc6ac3afd0, a2: 0x7ffc6ac3b052, a3: 0x7ffc6ac3afb0
Pointers: p1: 0x55ad9eac400c, p2: (nil)

C-string values:
a1: Hi
a2: Hello
a3: Hello, also

After concatenating a2 to the end of a1
a1: HiHello

Concatenating a2 to a1, with copy_limit = 13
a1: HiHelloHello

Concatenating a3 to a1, with copy_limit = 8
a1: HiHelloHelloHello, a

Before dup, array a2 = 0x7ffc6ac3b052, contents = Hello
After dup, pointer p2 =  0x55ad9fff86b0, contents = Hello
Printing persons
Name is Sean Arackal
Birth year is 2004
Salary is 100000
Name is Brian Jin
Birth year is 2004
Salary is 200000
Name is VKUUXFITHO
Birth year is 1793
Salary is 125774

Printing random person array
Name is JNYXQSDPAG
Birth year is 1642
Salary is 160836
Name is EKDCZFNVPH
Birth year is 1863
Salary is 104857
Name is MZHUNUKXHJ
Birth year is 1939
Salary is 183806

Printing random person array copy
Name is JNYXQSDPAG
Birth year is 1642
Salary is 160836
Name is EKDCZFNVPH
Birth year is 1863
Salary is 104857
Name is MZHUNUKXHJ
Birth year is 1939
Salary is 183806
sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw3$ make clean
rm -f *.o
rm -f ctest mystring structure
sarackal@CS2303-VirtualBox:~/cs2303_hws/cs2303_hw3$

Functions:
char* mystrdup(const char* source); //dupes string
char* mystrndup(const char* source, size_t n); //dupes string until n
size_t mystrlen(const char* source); //returns length of string
char* mystrcpy(char* cpy, const char* source); //makes copy of string
char* mystrncpy(char* cpy, const char* source, size_t n); //make copy of string upto n chars
char* mystrcat(char* target, const char* source); //concatenates two strings
char* mystrncat(char* target, const char* source, size_t n); //concatenates two strings upto n chars
Person* make_person(char* name, int birth_year, int salary); //creates struct of Person type
void printPerson(Person *p); //prints person
char genRandomChar(); //generates a random character
char* genRandomString(size_t size); //generates a random string
int genRandomInt(int min, int max); // generates a random integers
Person* genRandomPerson(); //generates a random Person
Person** genRandomPersonArray(size_t n); //generates a random array of Persons
void printPersonArray(Person** personArray, size_t n); //prints an array of Persons
Person** copyPersonArray(Person** source, size_t n);//copies and array of persons
void freePersonArray(Person** personArray, size_t n);//frees an array of persons from the memory

see documentaion for more details on the functions
