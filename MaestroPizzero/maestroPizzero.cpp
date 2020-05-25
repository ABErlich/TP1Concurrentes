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
#include "../Utility/maestroPizzero_com.h"
#include "../Utility/maestroEspecialista_com.h"
#include "../Utility/memoriaCompartida.h"
#include "../Utility/logger.h"

#define TIEMPO_HORNEADO_PREPIZZA 7
#define TIEMPO_COCCION_PIZZA 4

using namespace std;

//// EL MAESTRO PIZZERO VA A ESTAR COMPUESTO POR DOS PROCESOS
//// 1) EL PRIMER PROCESO SE VA A ENCARGAR DE CADA X TIEMPO, PEDIRLE MASA A EL MAESTRO ESPECIALISTA Y PREPARAR LA PREPIZZA
//// 2) EL SEGUNDO PROCESO SE VA A ENCARGAR DE ESCUCHAR LOS PEDIDOS DEL RECEPCIONISTA, Y AL RECIBIR UNO, COCINAR LA PIZZA

int main () {
    MaestroPizzeroCom comunicacionRecepcionista;
    MaestroEspecialistaCom comunicacionEspecialista;
    Logger logger;

    while (true) {
        comunicacionRecepcionista.esperarPedido();
        comunicacionEspecialista.pedirMasa();
        sleep(TIEMPO_HORNEADO_PREPIZZA + TIEMPO_COCCION_PIZZA);
        logger.log(obtenerFechaYHora() + " - Maestro Pizzero: entregando pizza...\n");
    }    

    return 0;
}

// void esperarPedidoDePizza(MemoriaCompartida<int> &cantPrepizzas) {
    
//     static const int BUFFSIZE = 100;
//     static const std::string ARCHIVO_FIFO_LECTURA = "../fifo_pizzero_recepcionista";
//     static const std::string ARCHIVO_FIFO_ESCRITURA = "../fifo_recepcionista_pizzero";
//     char buffer[BUFFSIZE];

//     while (true) {
//         try {
//             FifoLectura pedido (ARCHIVO_FIFO_LECTURA);
//             pedido.leer(buffer, BUFFSIZE);
//             cout << obtenerFechaYHora() << " - Maestro pizzero: Recibi un pedido de pizza" << endl;
//             sleep(TIEMPO_COCCION_PIZZA);
//             FifoEscritura respuesta (ARCHIVO_FIFO_LECTURA);

//         } catch(std::string error) {
//             cout << error << endl;
//         }
//     }
// }


// void pedirMasaYPrepararPrepizza() {
//     static const int BUFFSIZE = 100;
//     static const std::string ARCHIVO_FIFO_ESCRITURA = "../fifo_especialista_maestro";

//     FifoEscritura pedido (ARCHIVO_FIFO_ESCRITURA);
//     pedido.escribir(MASA, sizeof(MASA));
    
// }

// void guardarPrepizza(MemoriaCompartida<int> &cantPrepizzasMem) {
//     int cantPrepizzas = cantPrepizzasMem.leer();
//     cantPrepizzas++;
//     cantPrepizzasMem.escribir(cantPrepizzas);
//     cout << obtenerFechaYHora() << " - Maestro Pizzero: Termine una prepizza, hay: " << cantPrepizzas << endl;
// }