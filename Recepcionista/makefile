recepcionista: recepcionista.o lockFile.o canasta.o logger.o
	g++ recepcionista.o lockFile.o canasta.o logger.o -o recepcionista

recepcionista.o: recepcionista.cpp
	g++ -c recepcionista.cpp

canasta.o: lockFile.o
	g++ -c ../Utility/canasta.cpp

lockFile.o: 
	g++ -c ../Utility/lockFile.cpp

logger.o:
	g++ -c ../Utility/logger.cpp


clean:
	rm *.o recepcionista