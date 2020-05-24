#ifndef MAESTRO_PIZZERO_H
#define MAESTRO_PIZZERO_H

#include "../Utility/memoriaCompartida.h"


void pedirMasaYPrepararPrepizza();
void esperarPedidoDePizza(MemoriaCompartida<int> &cantPrepizzas);
void guardarPrepizza(MemoriaCompartida<int> &cantPrepizzas);

#endif