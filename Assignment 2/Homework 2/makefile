all: at at2 at3

at: at.o print_arrays.o
	gcc --std=c11 at.o print_arrays.o -o at

at.o: at.c print_arrays.h
	gcc --std=c11 -c at.c
	
at2: at2.o print_arrays.o array_sort.o 
	gcc --std=c11 at2.o print_arrays.o array_sort.o -o at2
	
at2.o: at2.c print_arrays.h array_sort.h
	gcc --std=c11 -c at2.c

print_arrays.o: print_arrays.c print_arrays.h
	gcc --std=c11 -c print_arrays.c
	
array_sort.o: array_sort.c array_sort.h
	gcc --std=c11 -c array_sort.c
	
at3: at3.o print_arrays.o array_sort.o 
	gcc --std=c11 at3.o print_arrays.o array_sort.o -o at3
	
at3.o: at3.c print_arrays.h array_sort.h
	gcc --std=c11 -c at3.c
	
docs:
	doxygen
	cp -p -r /home/sarackal/cs2303_hws/cs2303_hw2/html/* /home/sarackal/public_html/cs2303_hw2
	
clean:
	rm -f *.o
	rm -f at print_arrays at2 array_sort at3
