maestroEspecialista: maestroEspecialista.o maestroEspecialista_com.o logger.o lockFile.o
	g++ maestroEspecialista.o maestroEspecialista_com.o logger.o lockFile.o -o maestroEspecialista

maestroEspecialista.o: maestroEspecialista.cpp
	g++ -c maestroEspecialista.cpp

maestroEspecialista_com.o:
	g++ -c ../Utility/maestroEspecialista_com.cpp

lockFile.o: 
	g++ -c ../Utility/lockFile.cpp

logger.o:
	g++ -c ../Utility/logger.cpp

clean:
	rm *.o maestroEspecialista