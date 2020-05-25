maestroPanadero: maestroPanadero.o canasta.o lockFile.o logger.o maestroEspecialista_com.o signalHandler.o
	g++ maestroPanadero.o canasta.o lockFile.o logger.o maestroEspecialista_com.o signalHandler.o -o maestroPanadero

maestroPanadero.o: maestroPanadero.cpp
	g++ -c maestroPanadero.cpp

canasta.o: lockFile.o
	g++ -c ../Utility/canasta.cpp

lockFile.o:
	g++ -c ../Utility/lockFile.cpp

logger.o:
	g++ -c ../Utility/logger.cpp

maestroEspecialista_com.o:
	g++ -c ../Utility/maestroEspecialista_com.cpp

signalHandler.o:
	g++ -c ../Utility/signalHandler.cpp

clean:
	rm *.o maestroPanadero