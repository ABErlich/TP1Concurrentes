#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "../Utility/utility.h"
#include "../Utility/memoriaCompartida.h"
#include "../Utility/canasta.h"


#define PIZZA "pizza"
#define PAN "pan"
#define FIN "fin"
#define TIEMPO_DE_RECUPERACION 4

using namespace std;

//// EL RECEPCIONISTA LO QUE HACE ES RECIBIR PEDIDOS
//// EN CASO DE QUE EL PEDIDO SEA UN PAN, SE VA A FIJAR AL CANASTO SI HAY PAN, EN CASO DE NO HABER DEVUELVE QUE NO HAY
//// EN CASO DE QUE EL PEDIDO SEA UNA PIZZA, DELEGA EL PEDIDO AL MAESTRO PIZZERO

void hacerPedido(string pedido, int numeroPedido);
string leerPedido();

int main () {

    string pedido;
    cout << obtenerFechaYHora() << " - Recepcionista: Hola soy su recepcionista" << endl;
    
    cin >> pedido;
    while (pedido.compare(FIN) != 0){

        int numeroPedido = rand() % 10000; // genero un numero random para el pedido
        cout << obtenerFechaYHora() << " - Recepcionista: Pedido numero: " << numeroPedido << " en preparacion" << endl;
        //sleep(TIEMPO_DE_RECUPERACION); // Simulo un tiempo que tarda el recepcionista en hacer el pedido 
        hacerPedido(pedido, numeroPedido);
        
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
void hacerPedido(string pedido, int numeroPedido) {
    
    if (pedido.compare(PAN) == 0) {
        Canasta canasta;

        // En el caso del pan, tengo que ir a la canasta y ver si hay algun pan
        int panes = canasta.sacarPan();

        if (panes > 0) {
            cout << obtenerFechaYHora() << " - Recepcionista: Pedido numero: " << numeroPedido << " aqui tienes tu pan..." << endl;
            cout << "Cantidad de panes que quedan: " << canasta.mirar() << endl;
        } else {
            cout << "Disculpe, no hay mas pan" << endl;
        }
        
    } else if (pedido.compare(PIZZA) == 0) {
        cout << "Preparando pizza" << endl;
        // En el caso de la pizza tengo que hacer el pedido a un maestro pizzero y esperar que la cocine

    } else {
        cout << "El pedido " << pedido << " no forma parte del menu." << endl;
    }

}