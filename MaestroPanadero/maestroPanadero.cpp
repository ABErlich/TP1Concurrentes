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
#include "../Utility/memoriaCompartida.h"


#define TIEMPO_HORNEADO_PAN 5
#define CANT_INICIAL_PANES 5
#define MASA "masa"

//// EL MAESTRO PANADERO VA A ESTAR COMPUESTO POR UN UNICO PROCESO
//// CADA X TIEMPO (Puedo suponer "tiempo de horneado") LE VA A PEDIR AL MAESTRO ESPECIALISTA UNA MASA
//// LUEGO LA VA A HORNEAR Y CUANDO TERMINA LA VA A PONER EN LA CANASTA (Memoria compartida)

using namespace std;

int main () {
    string archivo = "/bin/ls";
    
    MemoriaCompartida<int> canasta (archivo, 'A');
    canasta.escribir(CANT_INICIAL_PANES);

    while (true) {
        pedirMasaYHornear();
        sleep(TIEMPO_HORNEADO_PAN);
        guardarPanEnCanasto(canasta);
    }
    
    return 0;
}

void pedirMasaYHornear() {

    static const int BUFFSIZE = 100;
    static const std::string ARCHIVO_FIFO_LECTURA = "../Fifos/Especialista_Panadero";
    static const std::string ARCHIVO_FIFO_ESCRITURA = "../Fifos/Panadero_Especialista";

    FifoEscritura pedido (ARCHIVO_FIFO_ESCRITURA);
    pedido.escribir(MASA, sizeof(MASA));
   
}

void guardarPanEnCanasto(MemoriaCompartida<int> &canasta) {

    int cantPanes = canasta.leer();
    cantPanes++;
    canasta.escribir(cantPanes);

    cout << obtenerFechaYHora() << " - Maestro panadero: Agregue un pan al canasto, cantidad: " << cantPanes << endl;

}