panaderia: panaderia.o canasta.o lockFile.o logger.o signalHandler.o
	g++ panaderia.o canasta.o lockFile.o logger.o signalHandler.o -o panaderia

panaderia.o: panaderia.cpp
	g++ -c panaderia.cpp

canasta.o: lockFile.o
	g++ -c ./Utility/canasta.cpp

lockFile.o:
	g++ -c ./Utility/lockFile.cpp
	
logger.o:
	g++ -c ./Utility/logger.cpp

signalHandler.o:
	g++ -c ./Utility/signalHandler.cpp

clean:
	rm *.o panaderia