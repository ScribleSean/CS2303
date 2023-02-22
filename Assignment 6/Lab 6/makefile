
all: fed2cs2303

fed2cs2303: fed2cs2303.o zipfed.o
	g++ -g fed2cs2303.o zipfed.o -o fed2cs2303

fed2cs2303.o: fed2cs2303.c zipfed.hpp
	g++ -g -c fed2cs2303.c

zipfed.o: zipfed.cpp zipfed.hpp
	g++ -g -c zipfed.cpp

zipfilter.o: zipfed.hpp
	g++ -g -c zipfilter.c
	
docs:
	doxygen
	cp -p /home/sarackal/cs2303_labs/cs2303_lab06/html/* /home/sarackal/public_html/cs2303_lab06
	
clean:
	rm -r *.o fed2cs2303
