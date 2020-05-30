#include "maestroPizzero_com.h"

#include <sys/stat.h>
#include <unistd.h>
#include <iostream>


MaestroPizzeroCom::MaestroPizzeroCom() : fd(-1), nombre("./tmp/pizzero_fifo"), lockRecepcionista("./tmp/pizzero_fifo_tmp.txt"), lockPizzero("./tmp/pizzero_fifo_tmp2.txt") {
	mkfifo (nombre.c_str(), 0666);
}

std::string MaestroPizzeroCom::esperarPedido() {
    char numero[100] = "\0";

    lockPizzero.tomarLock();
    if((fd = open(nombre.c_str(), O_RDONLY)) < 0){
        numero[0] = '\0';
        return std::string(numero);
    };

    if(read(fd, numero, sizeof(numero)) < 0){
        numero[0] = '\0';
    }
    close(fd);
    lockPizzero.liberarLock();

    return std::string(numero);
}

void MaestroPizzeroCom::pedirPizza(std::string numeroPedido) {

    lockRecepcionista.tomarLock();
    if((fd = open(nombre.c_str(), O_WRONLY)) < 0){
        return;
    };

    write(fd, numeroPedido.c_str(), sizeof(numeroPedido));
    close(fd);
    lockRecepcionista.liberarLock();
    
    
}

MaestroPizzeroCom::~MaestroPizzeroCom() {
	unlink(nombre.c_str());
}
