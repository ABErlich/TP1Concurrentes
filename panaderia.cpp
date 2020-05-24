#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdexcept>

using namespace std;

struct params_t {
    int cantRecepcionistas;
    int cantPizzeros;
    int cantPanaderos;
};

params_t parseParameters(int argc, char **argv);

int main (int argc, char **argv) {
    params_t params;
    try {
        params = parseParameters(argc, argv);
    } catch (const exception&) { 
        cout << "Parametros invalidos" << endl;
        throw;
    }
    cout << params.cantRecepcionistas << endl;


}

params_t parseParameters(int argc, char **argv) {
    params_t params;

    int recepcionistas = stoi(argv[1]);
    int pizzeros = stoi(argv[2]);
    int panaderos = stoi(argv[3]);

    params.cantPanaderos = panaderos;
    params.cantPizzeros = pizzeros;
    params.cantRecepcionistas = recepcionistas;
    return params;

}
