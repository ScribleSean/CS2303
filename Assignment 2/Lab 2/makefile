all: at

at: at.o print_arrays.o
	gcc --std=c11 at.o print_arrays.o -o at

at.o: at.c print_arrays.h
	gcc --std=c11 -c at.c

print_arrays.o: print_arrays.c print_arrays.h
	gcc --std=c11 -c print_arrays.c
	
docs:
	doxygen
	cp -p -r /home/sarackal/cs2303_labs/cs2303_lab02/html/* /home/sarackal/public_html/cs2303_lab02
	
clean:
	rm -f *.o
	rm -f at print_arrays
