recepcionista: recepcionista.o lockFile.o canasta.o logger.o maestroPizzero_com.o signalHandler.o
	g++ recepcionista.o lockFile.o canasta.o logger.o maestroPizzero_com.o signalHandler.o -o recepcionista

recepcionista.o: recepcionista.cpp
	g++ -c recepcionista.cpp

canasta.o: lockFile.o
	g++ -c ../Utility/canasta.cpp

lockFile.o: 
	g++ -c ../Utility/lockFile.cpp

logger.o:
	g++ -c ../Utility/logger.cpp

maestroPizzero_com.o:
	g++ -c ../Utility/maestroPizzero_com.cpp

signalHandler.o:
	g++ -c ../Utility/signalHandler.cpp

clean:
	rm *.o recepcionista