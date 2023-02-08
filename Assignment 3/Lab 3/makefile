ctest: ctest.o mystring.o
	gcc ctest.o mystring.o -o ctest

ctest.o: ctest.c mystring.h
	gcc -c ctest.c

mystring.o: mystring.c mystring.h
	gcc -c mystring.c
	
docs: 
	doxygen
	cp -p -r /home/sarackal/cs2303_labs/cs2303_lab03/html/* /home/sarackal/public_html/cs2303_lab03

clean: 
	rm -f mystring.o ctest.o ctest

