#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <ctime>
#include <sstream>
#include <string>
#include "../Utility/utility.h"
#include "maestroPanadero.h"
#include "../Utility/logger.h"
#include "../Utility/canasta.h"
#include "../Utility/maestroEspecialista_com.h"
#include "../Utility/sigintHandler.h"
#include "../Utility/signalHandler.h"

#define TIEMPO_HORNEADO_PAN 11
#define MASA "masa"

//// EL MAESTRO PANADERO VA A ESTAR COMPUESTO POR UN UNICO PROCESO
//// CADA X TIEMPO (Puedo suponer "tiempo de horneado") LE VA A PEDIR AL MAESTRO ESPECIALISTA UNA MASA
//// LUEGO LA VA A HORNEAR Y CUANDO TERMINA LA VA A PONER EN LA CANASTA (Memoria compartida)

int main () {
    SigintHandler sigint_handler;
    SignalHandler::getInstance()->registrarHandler(SIGINT, &sigint_handler);
    Canasta canasta;
    Logger logger;
    MaestroEspecialistaCom comunicacion;
    
    while (sigint_handler.getGracefulQuit() == 0) {
        comunicacion.pedirMasa(); // LE PIDE MASA AL ESPECIALISTA
        sleep(TIEMPO_HORNEADO_PAN);

        int cantPanes = canasta.agregarPan(); // AGREGA EL PAN RECIEN HORNEADO AL CANASTO
        logger.log(obtenerFechaYHora() + " - Maestro panadero: Agregue un pan al canasto, cantidad: " + std::to_string(cantPanes) + '\n');
    }
    
    logger.log(" - Maestro panadero: Retirandome\n");
    SignalHandler::destruir();
    return 0;
}

