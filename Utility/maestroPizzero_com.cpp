#include "maestroPizzero_com.h"

#include <sys/stat.h>
#include <unistd.h>
#include <iostream>


MaestroPizzeroCom::MaestroPizzeroCom() : fd(-1), nombre("./tmp/pizzero_fifo") {
	mkfifo (nombre.c_str(), 0666);
}

std::string MaestroPizzeroCom::esperarPedido() {
    char numero[100];

    fd = open(nombre.c_str(), O_RDONLY);
    read(fd, numero, sizeof(numero));
    close(fd);

    return std::string(numero);
}

void MaestroPizzeroCom::pedirPizza(std::string numeroPedido) {

    fd = open(nombre.c_str(), O_WRONLY);
    write(fd, numeroPedido.c_str(), sizeof(numeroPedido));
    close(fd);
    
}

MaestroPizzeroCom::~MaestroPizzeroCom() {
	unlink(nombre.c_str());
}
