
all: fed2cs2303 zipcode

fed2cs2303: fed2cs2303.o zipfed.o
	g++ -g fed2cs2303.o zipfed.o -o fed2cs2303

fed2cs2303.o: fed2cs2303.c zipfed.hpp
	g++ -g -c fed2cs2303.c

zipfed.o: zipfed.cpp zipfed.hpp
	g++ -g -c zipfed.cpp

zipfilter.o: zipfed.hpp
	g++ -g -c zipfilter.c

zipcode: zipcode.o zipfed.o
	g++ -g zipcode.o zipfed.o -lreadline -o zipcode

zipcode.o: zipcode.c zipfed.hpp
	g++ -g -c zipcode.c

docs:
	doxygen
	cp -p /home/sarackal/cs2303_hws/cs2303_hw6/html/* /home/sarackal/public_html/cs2303_hw6

clean:
	rm -r *.o fed2cs2303 zipcode
