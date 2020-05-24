panaderia: panaderia.o
	g++ panaderia.o -o panaderia

panaderia.o: panaderia.cpp
	g++ -c panaderia.cpp

clean:
	rm *.o panaderia