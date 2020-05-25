#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <ctime>
#include <sstream>
#include <string>
#include "../Utility/utility.h"
#include "maestroPanadero.h"
#include "../Utility/fifoEscritura.h"
#include "../Utility/fifoLectura.h"
#include "../Utility/logger.h"
#include "../Utility/canasta.h"


#define TIEMPO_HORNEADO_PAN 5
#define MASA "masa"

//// EL MAESTRO PANADERO VA A ESTAR COMPUESTO POR UN UNICO PROCESO
//// CADA X TIEMPO (Puedo suponer "tiempo de horneado") LE VA A PEDIR AL MAESTRO ESPECIALISTA UNA MASA
//// LUEGO LA VA A HORNEAR Y CUANDO TERMINA LA VA A PONER EN LA CANASTA (Memoria compartida)


int main () {
    Canasta canasta;
    Logger logger;

    while (true) {
       
        pedirMasaYHornear();
        sleep(TIEMPO_HORNEADO_PAN);
        int cantPanes = canasta.agregarPan();
        logger.log(obtenerFechaYHora() + " - Maestro panadero: Agregue un pan al canasto, cantidad: " + std::to_string(cantPanes) + '\n');

    }
    
    return 0;
}

void pedirMasaYHornear() {

    static const int BUFFSIZE = 100;
    static const std::string ARCHIVO_FIFO_ESCRITURA = "./fifo_especialista_maestro";

    FifoEscritura pedido (ARCHIVO_FIFO_ESCRITURA);
    pedido.escribir(MASA, sizeof(MASA));
    
}
