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

using namespace std;

//// EL MAESTRO PIZZERO VA A ESTAR COMPUESTO POR DOS PROCESOS
//// 1) EL PRIMER PROCESO SE VA A ENCARGAR DE CADA X TIEMPO, PEDIRLE MASA A EL MAESTRO ESPECIALISTA Y PREPARAR LA PREPIZZA
//// 2) EL SEGUNDO PROCESO SE VA A ENCARGAR DE ESCUCHAR LOS PEDIDOS DEL RECEPCIONISTA, Y AL RECIBIR UNO, COCINAR LA PIZZA

unsigned int tiempoVariable();

int main () {
    Logger logger;
    SigintHandler sigint_handler;
    SignalHandler::getInstance()->registrarHandler(SIGINT, &sigint_handler);
    MaestroPizzeroCom comunicacionRecepcionista;
    MaestroEspecialistaCom comunicacionEspecialista;
    
    while (sigint_handler.getGracefulQuit() == 0) {
 
        std::string numero = comunicacionRecepcionista.esperarPedido(); // ACA BLOQUEA HASTA QUE LE LLEGA UN PEDIDO DE PIZZA
        
        if(numero.length() > 0){
            comunicacionEspecialista.pedirMasa(numero); // LE PIDE LA MASA AL ESPECIALISTA

            //TIEMPO VARIABLE QUE TARDA EN COCINARSE LA PIZZA
            sleep(tiempoVariable());
            logger.log(obtenerFechaYHora() + " - Maestro Pizzero: Pedido numero: " + numero + " entregando pizza al repartidor...\n");
        }
        
    }

    logger.log(obtenerFechaYHora() + " - Maestro pizzero: Retirandome\n");
    SignalHandler::destruir();
    return 0;
}

unsigned int tiempoVariable () {
	srand(time(0));
	unsigned int resultado = (unsigned int)(rand() % 20 + 1);
	return resultado;
}