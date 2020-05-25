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
#include "../Utility/sigintHandler.h"
#include "../Utility/signalHandler.h"

#define TIEMPO_HORNEADO_PREPIZZA 1
#define TIEMPO_COCCION_PIZZA 1

using namespace std;

//// EL MAESTRO PIZZERO VA A ESTAR COMPUESTO POR DOS PROCESOS
//// 1) EL PRIMER PROCESO SE VA A ENCARGAR DE CADA X TIEMPO, PEDIRLE MASA A EL MAESTRO ESPECIALISTA Y PREPARAR LA PREPIZZA
//// 2) EL SEGUNDO PROCESO SE VA A ENCARGAR DE ESCUCHAR LOS PEDIDOS DEL RECEPCIONISTA, Y AL RECIBIR UNO, COCINAR LA PIZZA

int main () {
    Logger logger;
    SigintHandler sigint_handler;
    SignalHandler::getInstance()->registrarHandler(SIGINT, &sigint_handler);
    
    while (sigint_handler.getGracefulQuit() == 0) {
        MaestroEspecialistaCom comunicacionEspecialista;
        MaestroPizzeroCom comunicacionRecepcionista;
        
        std::string numero = comunicacionRecepcionista.esperarPedido(); // ACA BLOQUEA HASTA QUE LE LLEGA UN PEDIDO DE PIZZA
        comunicacionEspecialista.pedirMasa(numero); // LE PIDE LA MASA AL ESPECIALISTA

        sleep(TIEMPO_HORNEADO_PREPIZZA + TIEMPO_COCCION_PIZZA);
        logger.log(obtenerFechaYHora() + " - Maestro Pizzero: Pedido numero: " + numero + " entregando pizza...\n");
    }

    logger.log(" - Maestro pizzero: Retirandome\n");
    SignalHandler::destruir();
    return 0;
}

