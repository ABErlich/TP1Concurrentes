#include "maestroPizzero_com.h"

#include <sys/stat.h>
#include <unistd.h>
#include <iostream>


MaestroPizzeroCom::MaestroPizzeroCom() : fd(-1), nombre("./tmp/pizzero_fifo") {
	mkfifo (nombre.c_str(), 0666);
}

void MaestroPizzeroCom::esperarPedido() {
    fd = open(nombre.c_str(), O_WRONLY);
    close(fd);
}

void MaestroPizzeroCom::pedirPizza() {
    fd = open(nombre.c_str(), O_RDONLY);
    close(fd);
}


MaestroPizzeroCom::~MaestroPizzeroCom() {
	unlink(nombre.c_str());
}
