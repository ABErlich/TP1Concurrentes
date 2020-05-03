#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "../Utility/utility.h"
#include "../Utility/memoriaCompartida.h"

#define PIZZA "pizza"
#define PAN "pan"
#define FIN "fin"


using namespace std;

//// EL RECEPCIONISTA LO QUE HACE ES SIMPLEMENTE RECIBIR UN PEDIDO
//// RECIBE POR STDIN EL PEDIDO Y LO DEVUELVE LA RESPUESTA POR STDOUT
//// EN CASO DE QUE EL PEDIDO SEA UN PAN, SE VA A FIJAR AL CANASTO SI HAY PAN, EN CASO DE NO HABER DEVUELVE QUE NO HAY
//// EN CASO DE QUE EL PEDIDO SEA UNA PIZZA, DELEGA EL PEDIDO AL MAESTRO PIZZERO

void hacerPedido(string pedido);

int main () {
    
    
    string pedido;

    cout << "Esperando pedido..." << endl;
    cin >> pedido;
    while (pedido.compare(FIN) != 0){
        
        hacerPedido(pedido);
       
        cout << "Esperando pedido..." << endl;
        cin >> pedido;
    }

    return 0;
}

void hacerPedido(string pedido) {
    string archivo = "/bin/ls";
    MemoriaCompartida<int> canasta (archivo, 'A');

    if (pedido.compare(PAN) == 0) {
        // En el caso del pan, tengo que ir a la canasta y ver si hay algun pan para
        int panes = canasta.leer();
        
        if (panes > 0) {
            cout << obtenerFechaYHora() << " - Recepcionista: Aqui tienes tu pan..." << endl;
            panes--;
            canasta.escribir(panes);
            cout << "Cantidad de panes que quedan: " << canasta.leer() << endl;
        } else {
            cout << "Disculpe, no hay mas pan"<< endl;
        }
        
        


    } else if (pedido.compare(PIZZA) == 0) {
        cout << "Preparando pizza" << endl;
        // En el caso de la pizza tengo que hacer el pedido a un maestro pizzero y esperar que la cocine

    } else {
        cout << "El pedido " << pedido << " no forma parte del menu." << endl;
    }

}