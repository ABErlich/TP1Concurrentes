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
#include "../Utility/lockFile.h"


#define TIEMPO_HORNEADO_PAN 5
#define CANT_INICIAL_PANES 5
#define MASA "masa"

//// EL MAESTRO PANADERO VA A ESTAR COMPUESTO POR UN UNICO PROCESO
//// CADA X TIEMPO (Puedo suponer "tiempo de horneado") LE VA A PEDIR AL MAESTRO ESPECIALISTA UNA MASA
//// LUEGO LA VA A HORNEAR Y CUANDO TERMINA LA VA A PONER EN LA CANASTA (Memoria compartida)

//using namespace std;

int main () {
    std::string archivo = "/bin/ls";
    LockFile lock("canasta.txt");
    
    MemoriaCompartida<int> canasta (archivo, 'A');
    canasta.escribir(CANT_INICIAL_PANES);

    int i = 0;
    while (i < 2) {
       
        pedirMasaYHornear();
        sleep(TIEMPO_HORNEADO_PAN);

        lock.tomarLock();
        guardarPanEnCanasto(canasta);
        lock.liberarLock();
        i++;
    }
    
    return 0;
}

void pedirMasaYHornear() {

    static const int BUFFSIZE = 100;
    static const std::string ARCHIVO_FIFO_ESCRITURA = "./Fifos/Maestro_Especialista";

    FifoEscritura pedido (ARCHIVO_FIFO_ESCRITURA);
    pedido.escribir(MASA, sizeof(MASA));
   
}

void guardarPanEnCanasto(MemoriaCompartida<int> &canasta) {
    
    int cantPanes = canasta.leer();
    cantPanes++;
    canasta.escribir(cantPanes);

    std::cout << obtenerFechaYHora() << " - Maestro panadero: Agregue un pan al canasto, cantidad: " << cantPanes << std::endl;
    
}