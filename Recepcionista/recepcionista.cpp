#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "../Utility/utility.h"
#include "../Utility/memoriaCompartida.h"
#include "../Utility/canasta.h"
#include "../Utility/logger.h"

#define PIZZA "pizza"
#define PAN "pan"
#define FIN "fin"
#define TIEMPO_DE_RECUPERACION 4

using namespace std;

//// EL RECEPCIONISTA LO QUE HACE ES RECIBIR PEDIDOS
//// EN CASO DE QUE EL PEDIDO SEA UN PAN, SE VA A FIJAR AL CANASTO SI HAY PAN, EN CASO DE NO HABER DEVUELVE QUE NO HAY
//// EN CASO DE QUE EL PEDIDO SEA UNA PIZZA, DELEGA EL PEDIDO AL MAESTRO PIZZERO

void hacerPedido(string pedido, int numeroPedido, Logger &logger);
string leerPedido();

int main () {

    string pedido;
    Logger logger;

    logger.log(obtenerFechaYHora() + " - Recepcionista: Hola soy su recepcionista\n");
    
    cin >> pedido;
    while (pedido.compare(FIN) != 0){

        int numeroPedido = rand() % 10000; // genero un numero random para el pedido
        
        hacerPedido(pedido, numeroPedido, logger);
        sleep(TIEMPO_DE_RECUPERACION); // Simulo un tiempo que tarda el recepcionista en terminar el pedido

        cin >> pedido;
    }

    return 0;
}


string leerPedido() {
    string pedido;
    ifstream archivo("./input.txt");
    
    if (archivo.is_open()) {
        while (getline(archivo,pedido)) {
            cout << pedido << '\n';
        }
        archivo.close();
    }
   
}
void hacerPedido(string pedido, int numeroPedido, Logger &logger) {
    
    if (pedido.compare(PAN) == 0) {
        logger.log(obtenerFechaYHora() + " - Recepcionista: Pedido numero: " + to_string(numeroPedido) + " en preparacion\n");
        Canasta canasta;

        // En el caso del pan, tengo que ir a la canasta y ver si hay algun pan
        int panes = canasta.sacarPan();

        if (panes > 0) {
            logger.log(obtenerFechaYHora() + " - Recepcionista: Pedido numero: " + to_string(numeroPedido) + " aqui tienes tu pan...\n");
            logger.log(obtenerFechaYHora() + " - Recepcionista: Cantidad de panes que quedan: " + to_string(canasta.mirar()) + '\n');
        } else {
            logger.log(obtenerFechaYHora() + "- Recepcionista: Pedido numero: " + to_string(numeroPedido) + " Disculpe, no hay mas pan\n");
        }
        
    } else if (pedido.compare(PIZZA) == 0) {
        logger.log(obtenerFechaYHora() + " - Recepcionista: Pedido numero: " + to_string(numeroPedido) + " en preparacion\n");
        // En el caso de la pizza tengo que hacer el pedido a un maestro pizzero y esperar que la cocine

    } else {
        cout << " - Recepcionista: Pedido numero: " << numeroPedido << ", el pedido " << pedido << " no forma parte del menu." << endl;
    }

}