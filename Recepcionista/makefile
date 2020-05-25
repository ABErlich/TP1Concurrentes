recepcionista: recepcionista.o lockFile.o canasta.o
	g++ recepcionista.o lockFile.o canasta.o -o recepcionista

recepcionista.o: recepcionista.cpp
	g++ -c recepcionista.cpp

canasta.o: lockFile.o
	g++ -c ../Utility/canasta.cpp

lockFile.o: 
	g++ -c ../Utility/lockFile.cpp

clean:
	rm *.o recepcionista