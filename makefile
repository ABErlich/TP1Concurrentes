panaderia: panaderia.o canasta.o lockFile.o
	g++ panaderia.o canasta.o lockFile.o -o panaderia

panaderia.o: panaderia.cpp
	g++ -c panaderia.cpp

canasta.o: lockFile.o
	g++ -c ./Utility/canasta.cpp

lockFile.o:
	g++ -c ./Utility/lockFile.cpp

clean:
	rm *.o panaderia