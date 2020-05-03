#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <ctime>
#include <sstream>
#include "../Utility/utility.h"
#include "maestroPanadero.h"
#include "../Utility/fifoEscritura.h"
#include "../Utility/fifoLectura.h"


#define TIEMPO_HORNEADO_PAN 5
#define MASA "masa"

//// EL MAESTRO PANADERO VA A ESTAR COMPUESTO POR UN UNICO PROCESO
//// CADA X TIEMPO (Puedo suponer "tiempo de horneado") LE VA A PEDIR AL MAESTRO ESPECIALISTA UNA MASA
//// LUEGO LA VA A HORNEAR Y CUANDO TERMINA LA VA A PONER EN LA CANASTA (Memoria compartida)

using namespace std;

int main () {

    while (true) {
        pedirMasaYHornear();
        sleep(TIEMPO_HORNEADO_PAN);
    }
    

    return 0;
}

void pedirMasaYHornear() {

    static const int BUFFSIZE = 100;
    static const std::string ARCHIVO_FIFO_LECTURA = "../Fifos/Especialista_Panadero";
    static const std::string ARCHIVO_FIFO_ESCRITURA = "../Fifos/Panadero_Especialista";
    char pedido[] = MASA;

    cout << obtenerFechaYHora() << " A punto de realizar un pedido de masa" << endl;
    FifoEscritura escritura (ARCHIVO_FIFO_ESCRITURA);
    escritura.escribir(pedido, sizeof(pedido));

    //  
}