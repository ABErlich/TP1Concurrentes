maestroPanadero: maestroPanadero.o canasta.o lockFile.o
	g++ maestroPanadero.o canasta.o lockFile.o -o maestroPanadero

maestroPanadero.o: maestroPanadero.cpp
	g++ -c maestroPanadero.cpp

canasta.o: lockFile.o
	g++ -c ../Utility/canasta.cpp

lockFile.o:
	g++ -c ../Utility/lockFile.cpp

clean:
	rm *.o maestroPanadero