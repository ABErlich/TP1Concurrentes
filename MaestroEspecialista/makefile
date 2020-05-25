maestroEspecialista: maestroEspecialista.o maestroEspecialista_com.o
	g++ maestroEspecialista.o maestroEspecialista_com.o -o maestroEspecialista

maestroEspecialista.o: maestroEspecialista.cpp
	g++ -c maestroEspecialista.cpp

maestroEspecialista_com.o:
	g++ -c ../Utility/maestroEspecialista_com.cpp

clean:
	rm *.o maestroEspecialista