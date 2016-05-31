all: foverloading

foverloading: overload.o hub.o 
	g++ overload.o hub.o -std=c++11 -o foverloading

overload.o: overload.cpp
	g++ -c -std=c++11 overload.cpp

hub.o: hub.cpp
	g++ -c -std=c++11 hub.cpp

clean:
	rm *o foverloading
