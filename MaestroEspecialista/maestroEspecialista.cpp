#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <ctime>
#include <sstream>
#include "../Utility/utility.h"
#include "maestroEspecialista.h"
#include "../Utility/fifoEscritura.h"
#include "../Utility/fifoLectura.h"

#define FIN "fin"
#define MASA "masa"
#define MASA_MADRE_TIEMPO_ALIMENTACION 15


using namespace std;

//// EL MAESTRO ESPECIALISTA VA A ESTAR COMPUESTO POR DOS PROCESOS
//// 1) EL PRIMER PROCESO SE VA A ENCARGAR DE ALIMENTAR LA MASA MADRE CADA CIERTO TIEMPO
//// 2) EL SEGUNDO PROCESO SE VA A ENCARGAR DE ESCUCHAR LOS PEDIDOS DE LOS OTROS MAESTROS Y ENTREGARLES UN POCO DE MASA
///     SE VAN A ESTAR RECIBIENDO LOS ARCHIVOS EN UN FIFO

int main () {
  
    pid_t pid = fork();
    if (pid < 0) {
        cout << "Error fork: " << string(strerror(errno)) << endl;
        return errno;
    }

    if (pid == 0) {
        // Proceso hijo
        esperarPedidosDeMasa();
        return 0;
    } else {
        // Proceso padre
        alimentarMasaMadre();
    }

    wait(NULL);

    return 0;
}

void alimentarMasaMadre() {

    while (true) {
        sleep(MASA_MADRE_TIEMPO_ALIMENTACION);
        cout << obtenerFechaYHora() << " - Maestro especialista: Alimento la masa madre" << endl;
    }
    
    return;
}

void esperarPedidosDeMasa() {

    static const int BUFFSIZE = 100;
    //static const std::string ARCHIVO_FIFO_ESCRITURA = "../Fifos/Especialista_Panadero";
    static const std::string ARCHIVO_FIFO_LECTURA = "../Fifos/Panadero_Especialista";
    char buffer[BUFFSIZE];

    while (true) {
        try {
            FifoLectura pedido (ARCHIVO_FIFO_LECTURA);
            pedido.leer(buffer, BUFFSIZE);
            cout << obtenerFechaYHora() << " - Maestro especialista: Recibi un pedido de masa..." << endl;
        } catch(std::string error) {
            cout << error << endl;
        }
    }

}
