#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <stdexcept>
#include <sys/wait.h>
#include "./Utility/logger.h"
#include "./Utility/canasta.h"
#include "./Utility/sigintHandler.h"
#include "./Utility/signalHandler.h"

using namespace std;

struct params_t {
    int cantRecepcionistas;
    int cantPizzeros;
    int cantPanaderos;
};

params_t parsearParametros(int argc, char **argv);
void crearProcesos(int cant, string execPath);

int main (int argc, char **argv) {
    params_t params;
    Logger logger;

    try {
        params = parsearParametros(argc, argv);
    } catch (const exception&) { 
        cout << "Parametros invalidos" << endl;
        throw;
    }

    Canasta canasta;
    canasta.vaciar();

    // Creo los procesos en funcion de los parametros
    cout << "Creando al maestro especialista." << endl;
    crearProcesos(1, "./MaestroEspecialista/maestroEspecialista");

    // recepcionistas
    cout << "Creando " << params.cantRecepcionistas << " recepcionistas." << endl;
    crearProcesos(params.cantRecepcionistas, "./Recepcionista/recepcionista");

    
    cout << "Creando " << params.cantPizzeros << " pizzeros." << endl;
    crearProcesos(params.cantPizzeros, "./MaestroPizzero/maestroPizzero");
    
    cout << "Creando " << params.cantPanaderos << " panaderos." << endl;
    crearProcesos(params.cantPanaderos, "./MaestroPanadero/maestroPanadero");

    wait(NULL);

    return 0;
}

params_t parsearParametros(int argc, char **argv) {
    params_t params;

    int recepcionistas = stoi(argv[1]);
    int pizzeros = stoi(argv[2]);
    int panaderos = stoi(argv[3]);

    params.cantPanaderos = panaderos;
    params.cantPizzeros = pizzeros;
    params.cantRecepcionistas = recepcionistas;
    return params;

}
void crearProcesos(int cant, string execPath) {

    char * const argv[] = {NULL};
    char * const envp[] = {NULL};
    // Creo los procesos
    for (int i = 0; i < cant; i++) {
        pid_t id = fork();
        if(id == 0) {
            // lanzo el codigo del proceso
            execve(execPath.c_str(), argv, envp);
        } else if (id < 0) {
            throw "Error al crear proceso";
        }
    }

    
}