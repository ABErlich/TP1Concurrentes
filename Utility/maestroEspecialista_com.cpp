#include "maestroEspecialista_com.h"

#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <string.h>

MaestroEspecialistaCom::MaestroEspecialistaCom() : fd(-1), nombre("./tmp/especialista_fifo") {
	mkfifo (nombre.c_str(), 0666);
}

std::string MaestroEspecialistaCom::entregarMasa() {
    char numero[100] = "";
    fd = open(nombre.c_str(), O_RDONLY);
    read(fd, numero, sizeof(numero));

    if(strlen(numero) > 0){
        return std::string(numero);
    } else {
        return "sin numero";
    }

    close(fd);
}

void MaestroEspecialistaCom::pedirMasa() {
    fd = open(nombre.c_str(), O_WRONLY);
    close(fd);
}

void MaestroEspecialistaCom::pedirMasa(std::string numero) {
    fd = open(nombre.c_str(), O_WRONLY);
    write(fd, numero.c_str(), sizeof(numero));
    close(fd);
}



MaestroEspecialistaCom::~MaestroEspecialistaCom() {
	unlink(nombre.c_str());
}
