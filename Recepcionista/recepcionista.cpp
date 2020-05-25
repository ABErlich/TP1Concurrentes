#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "../Utility/utility.h"
#include "../Utility/memoriaCompartida.h"
#include "../Utility/canasta.h"
#include "../Utility/logger.h"
#include "../Utility/maestroPizzero_com.h"
#include "../Utility/sigintHandler.h"
#include "../Utility/signalHandler.h"

#define PIZZA "pizza"
#define PAN "pan"
#define FIN "fin"
#define TIEMPO_DE_BUSCAR_PAN 4
#define TIEMPO_DE_PEDIR_PIZZA 3

using namespace std;

//// EL RECEPCIONISTA LO QUE HACE ES RECIBIR PEDIDOS
//// EN CASO DE QUE EL PEDIDO SEA UN PAN, SE VA A FIJAR AL CANASTO SI HAY PAN, EN CASO DE NO HABER DEVUELVE QUE NO HAY
//// EN CASO DE QUE EL PEDIDO SEA UNA PIZZA, DELEGA EL PEDIDO AL MAESTRO PIZZERO
void hacerPedido(string pedido, int numeroPedido, Logger &logger);

int main () {
    
    string pedido;
    Logger logger;
    SigintHandler sigint_handler;
    SignalHandler::getInstance()->registrarHandler(SIGINT, &sigint_handler);

    logger.log(obtenerFechaYHora() + " - Recepcionista: Hola soy su recepcionista\n");

    
    while (sigint_handler.getGracefulQuit() == 0){
        cin >> pedido;

        // genero un numero pseudo random para el pedido
        srand(time(0));
        int numeroPedido = rand() % 10000; 
        
        hacerPedido(pedido, numeroPedido, logger);
        
    }

    logger.log(" - Recepcionista: Retirandome\n");
    SignalHandler::destruir();
    return 0;
}


void hacerPedido(string pedido, int numeroPedido, Logger &logger) {
    
    if (pedido.compare(PAN) == 0) {
        
        // En el caso del pan, tengo que ir a la canasta y ver si hay algun pan
        logger.log(obtenerFechaYHora() + " - Recepcionista: Pedido numero: " + to_string(numeroPedido) + " yendo a buscar pan.\n");
        Canasta canasta;

        sleep(TIEMPO_DE_BUSCAR_PAN);
        
        int panes = canasta.sacarPan();

        if (panes > 0) {
            logger.log(obtenerFechaYHora() + " - Recepcionista: Pedido numero: " + to_string(numeroPedido) + " aqui tienes tu pan. Quedan: " + to_string(canasta.mirar()) +"\n");
        } else {
            logger.log(obtenerFechaYHora() + "- Recepcionista: Pedido numero: " + to_string(numeroPedido) + " Disculpe, no hay mas pan\n");
        }
        
    } else if (pedido.compare(PIZZA) == 0) {

        // En el caso de la pizza tengo que hacer el pedido a un maestro pizzero y esperar que la cocine        
        MaestroPizzeroCom comunicacionPizzero;
        logger.log(obtenerFechaYHora() + " - Recepcionista: Pedido numero: " + to_string(numeroPedido) + " pizza en preparacion\n");
        comunicacionPizzero.pedirPizza(to_string(numeroPedido));

        sleep(TIEMPO_DE_PEDIR_PIZZA);
        
    } else {
        cout << " - Recepcionista: Pedido numero: " << numeroPedido << ", el pedido " << pedido << " no forma parte del menu." << endl;
    }

}