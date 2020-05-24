#ifndef MAESTRO_PANADERO_H
#define MAESTRO_PANADERO_H

#include "../Utility/memoriaCompartida.h"
#include "../Utility/lockFile.h"

void pedirMasaYHornear();
void guardarPanEnCanasto(MemoriaCompartida<int> &canasta);

#endif