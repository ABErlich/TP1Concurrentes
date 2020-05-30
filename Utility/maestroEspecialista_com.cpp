#include "maestroEspecialista_com.h"

#include <sys/stat.h>
#include <unistd.h>
#include <iostream>


MaestroEspecialistaCom::MaestroEspecialistaCom() : 
    fd(-1),
    nombreIda("./tmp/especialista_fifo_ida"),
    nombreVuelta("./tmp/especialista_fifo_vuelta"),
    lockPedido("./tmp/especialista_fifo_tmp.txt"),
    lockEntrega("./tmp/especialista_fifo_tmp2.txt") {
	mkfifo (nombreIda.c_str(), 0666);
    mkfifo (nombreVuelta.c_str(), 0666);
}



std::string MaestroEspecialistaCom::esperarPedido() {
    char numero[100] = "";

    fd = open(nombreIda.c_str(), O_RDONLY);
        
    read(fd, numero, sizeof(numero));
    close(fd);

    return std::string(numero);
}

void MaestroEspecialistaCom::entregarMasa() {
    char entrega[100] = "masa";

    fd = open(nombreVuelta.c_str(), O_WRONLY);
    write(fd, entrega, sizeof(entrega));
    close(fd);
    
}

void MaestroEspecialistaCom::pedirMasa() {
    lockPedido.tomarLock();
    fd = open(nombreIda.c_str(), O_WRONLY);
    close(fd);
    lockPedido.liberarLock();
}

void MaestroEspecialistaCom::pedirMasa(std::string numero) {

    lockPedido.tomarLock();
    fd = open(nombreIda.c_str(), O_WRONLY);
    write(fd, numero.c_str(), sizeof(numero));
    close(fd);
    lockPedido.liberarLock();
    
}

std::string MaestroEspecialistaCom::esperarMasa() {
    char respuesta[100] = "";

    lockEntrega.tomarLock();
    fd = open(nombreVuelta.c_str(), O_RDONLY);
        
    read(fd, respuesta, sizeof(respuesta));
    close(fd);
    
    lockEntrega.liberarLock();
    return std::string(respuesta);
}

MaestroEspecialistaCom::~MaestroEspecialistaCom() {
    unlink(nombreIda.c_str());
	unlink(nombreVuelta.c_str());
}
