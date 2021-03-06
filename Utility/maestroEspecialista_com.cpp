#include "maestroEspecialista_com.h"

#include <sys/stat.h>
#include <unistd.h>
#include <iostream>


MaestroEspecialistaCom::MaestroEspecialistaCom() : fd(-1), nombre("./tmp/especialista_fifo"), lock("./tmp/especialista_fifo_tmp.txt") {
	mkfifo (nombre.c_str(), 0666);
}

std::string MaestroEspecialistaCom::entregarMasa() {
    char numero[100] = "";

    if((fd = open(nombre.c_str(), O_RDONLY)) < 0){
        
    };

    read(fd, numero, sizeof(numero));
    close(fd);

    return std::string(numero);
}

void MaestroEspecialistaCom::pedirMasa() {
    lock.tomarLock();
    if((fd = open(nombre.c_str(), O_WRONLY)) < 0) {
        
    };
    close(fd);
    lock.liberarLock();
}

void MaestroEspecialistaCom::pedirMasa(std::string numero) {

    lock.tomarLock();
    if((fd = open(nombre.c_str(), O_WRONLY)) < 0) {
        
    };
    write(fd, numero.c_str(), sizeof(numero));
    close(fd);
    lock.liberarLock();
    
}



MaestroEspecialistaCom::~MaestroEspecialistaCom() {
	unlink(nombre.c_str());
}
