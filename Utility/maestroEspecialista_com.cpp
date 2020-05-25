#include "maestroEspecialista_com.h"

#include <sys/stat.h>
#include <unistd.h>
#include <iostream>


MaestroEspecialistaCom::MaestroEspecialistaCom() : fd(-1), nombre("./tmp/especialista_fifo") {
	mkfifo (nombre.c_str(), 0666);
}

void MaestroEspecialistaCom::entregarMasa() {
    fd = open(nombre.c_str(), O_WRONLY);
    //std::cout << obtenerFechaYHora() << " Se entrego masa" << std::endl;
    close(fd);
}

void MaestroEspecialistaCom::pedirMasa() {
    fd = open(nombre.c_str(), O_RDONLY);
    //std::cout << obtenerFechaYHora() << " Se pidio masa" << std::endl;
    close(fd);
}


MaestroEspecialistaCom::~MaestroEspecialistaCom() {
	unlink(nombre.c_str());
}
