#include <iostream>
#include <string.h>
#include <stdlib.h>

#define PIZZA "pizza"
#define PAN "pan"
#define FIN "fin"

using namespace std;

void hacerPedido(string pedido);

int main () {
    
    string pedido = "";

    cout << "Hola soy un recepcionista" << endl;


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


    if (pedido.compare(PAN) == 0){
        cout << "Preparando pan" << endl;
        // En el caso del pan, tengo que ir a la canasta y ver si hay algun pan para


    } else if (pedido.compare(PIZZA) == 0){
        cout << "Preparando pizza" << endl;
        // En el caso de la pizza tengo que hacer el pedido a un maestro pizzero y esperar que la cocine



        
    } else{
        cout << "El pedido " << pedido << " no forma parte del menu." << endl;
    }

}