all:  sorttest sorttest2

sorttest: sorttest.o sort.o timesort.o
	gcc -g sorttest.o sort.o timesort.o -o sorttest

sorttest.o: sorttest.c sort.h
	gcc -g -c --std=gnu89 sorttest.c

sorttest2: sorttest2.o sort.o timesort.o
	gcc -g sorttest2.o sort.o timesort.o -o sorttest2

sorttest2.o: sorttest2.c sort.h
	gcc -g -c --std=gnu89 sorttest2.c

sort.o: sort.c sort.h
	gcc -g -c --std=gnu89 sort.c

timesort.o: timesort.c sort.h
	gcc -g -c --std=gnu89 timesort.c

clean:
	rm -f  *.o sorttest sorttest2

docs:
	doxygen
	cp -rp /home/sarackal/cs2303_hws/cs2303_hw4/html/* /home/sarackal/public_html/cs2303_hw4
