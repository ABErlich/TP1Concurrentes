#include "canasta.h"
#include <stdio.h>
#include <iostream>
#include "lockFile.h"

Canasta::Canasta(): MemoriaCompartida("/bin/ls", 'A'), lock("./tmp/canasta_temp.txt") {


}

Canasta::Canasta (const std::string& archivo, const char letra): MemoriaCompartida(archivo, letra), lock("./tmp/canasta_temp.txt") {
}

int Canasta::mirar() {
    lock.tomarLock();
    int panes = leer();
    lock.liberarLock();
    return panes;
}

int Canasta::vaciar() {
    lock.tomarLock();
    escribir(0);
    lock.liberarLock();
    return 0;
}

int Canasta::agregarPan() {

    lock.tomarLock();
    int panes = leer();
    panes ++;
    escribir(panes);
    lock.liberarLock();
    return panes;
}

int Canasta::sacarPan() {
    lock.tomarLock();
    int panes = leer();  

    panes--;
    if(panes >= 0){    
        escribir(panes);
    }
    
    lock.liberarLock();
    panes ++;
    return panes;
}

Canasta::~Canasta() {

}
