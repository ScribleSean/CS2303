all: stacktest stacktest_dbg stacktest2 stacktest2_dbg

stacktest: stacktest.o stack.o
	gcc -g stacktest.o stack.o -lreadline -o stacktest

stacktest_dbg: stacktest_dbg.o stack.o
	gcc -g stacktest_dbg.o stack.o -lreadline -o stacktest_dbg

stacktest.o: stacktest.c stack.h
	gcc -g -c stacktest.c

stacktest_dbg.o: stacktest.c stack.h
	gcc -g -c stacktest.c -o stacktest_dbg.o -DDEBUG_TEST

stacktest2: stacktest2.o stack.o
	gcc -g stacktest2.o stack.o -lreadline -o stacktest2

stacktest2_dbg: stacktest2_dbg.o stack.o
	gcc -g stacktest2_dbg.o stack.o -lreadline -o stacktest2_dbg

stacktest2.o: stacktest2.c stack.h
	gcc -g -c stacktest2.c

stacktest2_dbg.o: stacktest2.c stack.h
	gcc -g -c stacktest2.c -o stacktest2_dbg.o -DDEBUG_TEST

stack.o: stack.c stack.h
	gcc -g -c stack.c

docs:
	doxygen
	cp -p /home/sarackal/cs2303_hws/cs2303_hw5/html/* /home/sarackal/public_html/cs2303_hw5

clean:
	rm -f *.o stacktest stacktest_dbg stacktest2 stacktest2_dbg
