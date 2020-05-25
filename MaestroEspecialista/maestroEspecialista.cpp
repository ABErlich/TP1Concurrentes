#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <ctime>
#include <sstream>
#include "../Utility/utility.h"
#include "maestroEspecialista.h"
#include <string.h>
#include "../Utility/maestroEspecialista_com.h"
#include "../Utility/logger.h"
#include "../Utility/sigintHandler.h"
#include "../Utility/signalHandler.h"

#define FIN "fin"
#define MASA "masa"
#define MASA_MADRE_TIEMPO_ALIMENTACION 16


using namespace std;

//// EL MAESTRO ESPECIALISTA VA A ESTAR COMPUESTO POR DOS PROCESOS
//// 1) EL PRIMER PROCESO SE VA A ENCARGAR DE ALIMENTAR LA MASA MADRE CADA CIERTO TIEMPO
//// 2) EL SEGUNDO PROCESO SE VA A ENCARGAR DE ESCUCHAR LOS PEDIDOS DE LOS OTROS MAESTROS Y ENTREGARLES UN POCO DE MASA
///     SE VAN A ESTAR RECIBIENDO LOS ARCHIVOS EN UN FIFO

int main () {
    Logger logger;
    SigintHandler sigint_handler;
    SignalHandler::getInstance()->registrarHandler(SIGINT, &sigint_handler);

    pid_t pid = fork();
    if (pid < 0) {
        cout << "Error fork: " << string(strerror(errno)) << endl;
        return errno;
    }

    if (pid == 0) {
        // Proceso hijo
        //MaestroEspecialistaCom comunicacion;
        while (sigint_handler.getGracefulQuit() == 0) {
            MaestroEspecialistaCom comunicacion;
            std::string numero = comunicacion.entregarMasa();
            sleep(5);
            logger.log(obtenerFechaYHora() + " - Maestro especialista: Entrego masa para pedido " + numero + '\n');
        }
        
        return 0;
    } else {
        while (sigint_handler.getGracefulQuit() == 0) {
            sleep(MASA_MADRE_TIEMPO_ALIMENTACION);
            logger.log(obtenerFechaYHora() + " - Maestro especialista: Alimento la masa madre\n");
        }
    }

    wait(NULL);
    logger.log(" - Maestro especialista: Retirandome\n");
    SignalHandler::destruir();
    return 0;
}