all: stacktest stacktest_dbg

stacktest: stacktest.o stack.o
	gcc -g stacktest.o stack.o -o stacktest

stacktest_dbg: stacktest_dbg.o stack.o
	gcc -g stacktest_dbg.o stack.o -o stacktest_dbg

stacktest.o: stacktest.c stack.h
	gcc -g -c stacktest.c

stacktest_dbg.o: stacktest.c stack.h
	gcc -g -c stacktest.c -o stacktest_dbg.o -DDEBUG_TEST

stack.o: stack.c stack.h
	gcc -g -c stack.c

docs:
	doxygen
	cp -p /home/sarackal/cs2303_labs/cs2303_lab05/html/* /home/sarackal/public_html/cs2303_lab05

clean:
	rm -f *.o stacktest stacktest_dbg
