maestroPizzero: maestroPizzero.o maestroEspecialista_com.o maestroPizzero_com.o logger.o lockFile.o signalHandler.o
	g++ maestroPizzero.o maestroPizzero_com.o maestroEspecialista_com.o logger.o lockFile.o signalHandler.o -o maestroPizzero 

maestroPizzero.o: maestroPizzero.cpp
	g++ -c maestroPizzero.cpp

maestroEspecialista_com.o:
	g++ -c ../Utility/maestroEspecialista_com.cpp

lockFile.o:
	g++ -c ../Utility/lockFile.cpp

logger.o:
	g++ -c ../Utility/logger.cpp

maestroPizzero_com.o:
	g++ -c ../Utility/maestroPizzero_com.cpp

signalHandler.o:
	g++ -c ../Utility/signalHandler.cpp

clean:
	rm *.o maestroPizzero