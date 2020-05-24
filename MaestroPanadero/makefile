maestroPanadero: maestroPanadero.o lockFile.o
	g++ maestroPanadero.o lockFile.o -o maestroPanadero

maestroPanadero.o: maestroPanadero.cpp
	g++ -c maestroPanadero.cpp

lockFile.o: 
	g++ -c ../Utility/lockFile.cpp

clean:
	rm *.o maestroPanadero