#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <ctime>
#include <sstream>
#include <string.h>
#include "maestroPizzero.h"
#include "../Utility/utility.h"
#include "../Utility/fifoEscritura.h"
#include "../Utility/fifoLectura.h"
#include "../Utility/memoriaCompartida.h"

#define TIEMPO_HORNEADO_PREPIZZA 10
#define TIEMPO_COCCION_PIZZA 5
#define CANT_INICIAL_PREPIZZAS 5
#define MASA "masa del maestro pizzero"

using namespace std;

//// EL MAESTRO PIZZERO VA A ESTAR COMPUESTO POR DOS PROCESOS
//// 1) EL PRIMER PROCESO SE VA A ENCARGAR DE CADA X TIEMPO, PEDIRLE MASA A EL MAESTRO ESPECIALISTA Y PREPARAR LA PREPIZZA
//// 2) EL SEGUNDO PROCESO SE VA A ENCARGAR DE ESCUCHAR LOS PEDIDOS DEL RECEPCIONISTA, Y AL RECIBIR UNO, COCINAR LA PIZZA

int main () {

    string archivo = "/bin/ls";
    
    pid_t pid = fork();
    if (pid < 0) {
        cout << "Error fork: " << string(strerror(errno)) << endl;
        return errno;
    }
    

    if (pid == 0) {
        // Proceso hijo
        MemoriaCompartida<int> cantPrepizzas (archivo, 'B');
        cantPrepizzas.escribir(CANT_INICIAL_PREPIZZAS);

        esperarPedidoDePizza(cantPrepizzas);
    } else {
        // Proceso padre
        MemoriaCompartida<int> cantPrepizzas (archivo, 'B');
        
        while (true) {
            pedirMasaYPrepararPrepizza();
            sleep(TIEMPO_HORNEADO_PREPIZZA);
            guardarPrepizza(cantPrepizzas);
        }
    }

    wait(NULL);

    return 0;

}

void esperarPedidoDePizza(MemoriaCompartida<int> &cantPrepizzas) {
    
    static const int BUFFSIZE = 100;
    static const std::string ARCHIVO_FIFO_LECTURA = "../Fifos/Pizzero_Recepcionista";
    static const std::string ARCHIVO_FIFO_ESCRITURA = "../Fifos/Recepcionista_Pizzero";
    char buffer[BUFFSIZE];

    while (true) {
        try {
            FifoLectura pedido (ARCHIVO_FIFO_LECTURA);
            pedido.leer(buffer, BUFFSIZE);
            cout << obtenerFechaYHora() << " - Maestro pizzero: Recibi un pedido de pizza" << endl;
            sleep(TIEMPO_COCCION_PIZZA);
            FifoEscritura respuesta (ARCHIVO_FIFO_LECTURA);

        } catch(std::string error) {
            cout << error << endl;
        }
    }
}


void pedirMasaYPrepararPrepizza() {
    static const int BUFFSIZE = 100;
    static const std::string ARCHIVO_FIFO_ESCRITURA = "../fifo_especialista_panadero";

    FifoEscritura pedido (ARCHIVO_FIFO_ESCRITURA);
    pedido.escribir(MASA, sizeof(MASA));
    
}

void guardarPrepizza(MemoriaCompartida<int> &cantPrepizzasMem) {
    int cantPrepizzas = cantPrepizzasMem.leer();
    cantPrepizzas++;
    cantPrepizzasMem.escribir(cantPrepizzas);
    cout << obtenerFechaYHora() << " - Maestro Pizzero: Termine una prepizza, hay: " << cantPrepizzas << endl;
}