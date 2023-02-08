ctest: ctest.o mystring.o structure.o
	gcc ctest.o mystring.o structure.o -o ctest

ctest.o: ctest.c mystring.h
	gcc -c ctest.c

mystring.o: mystring.c mystring.h
	gcc -c mystring.c

structure.o: structure.c structure.h
	gcc -c structure.c

docs:
	doxygen
	cp -p -r /home/sarackal/cs2303_hws/cs2303_hw3/html/* /home/sarackal/public_html/cs2303_hw3

clean:
	rm -f *.o
	rm -f ctest mystring structure
