#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <errno.h>
#include <sys/wait.h>
#include <ctime>
#define FIN "fin"
#define MASA "masa"

using namespace std;

//// EL MAESTRO PIZZERO VA A ESTAR COMPUESTO POR DOS PROCESOS
//// 1) EL PRIMER PROCESO SE VA A ENCARGAR DE ALIMENTAR LA MASA MADRE CADA CIERTO TIEMPO
//// 2) EL SEGUNDO PROCESO SE VA A ENCARGAR DE ESCUCHAR LOS PEDIDOS DE LOS OTROS MAESTROS Y ENTREGARLES UN POCO DE MASA

void alimentarMasaMadre();
string getCurrentDateTime();
void esperarPedidosDeMasa();

int main () {
  
    pid_t pid = fork();
    if (pid < 0) {
        cout << "Error fork: " << errno << endl;
        return errno;
    }

    if (pid == 0) {
        // Proceso hijo
        esperarPedidosDeMasa();
        return 0;
    } else {
        // Proceso padre
        alimentarMasaMadre();
    }

    wait(NULL);

    return 0;
}

void alimentarMasaMadre() {

    while (true) {
        sleep(2);
        
        cout  << getCurrentDateTime() << " - Alimente la masa madre" << endl;
    }
    
    return;
}

void esperarPedidosDeMasa() {

    string pedido;
    cin >> pedido;
    while (pedido.compare(FIN) != 0) {

        if (pedido.compare(MASA) == 0) {
            cout << getCurrentDateTime() << " Recibí un pedido de masa" << endl;
        }
        
        cin >> pedido;
    }

}

string getCurrentDateTime() {
    time_t now = time(0);

    tm *ltm = localtime(&now);

    ostringstream os;
    os << ltm->tm_mday << '/' << ltm->tm_mon << '/' << 1900 + ltm->tm_year << ' ';
    os << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec;

    string s = os.str();
    return s;
}