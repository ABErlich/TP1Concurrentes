#ifndef CANASTA_H_
#define CANASTA_H_

#include <unistd.h>
#include <fcntl.h>
#include <string>
#include "memoriaCompartida.h"
#include "lockFile.h"

class Canasta: protected MemoriaCompartida<int> {

private:
    LockFile lock;

public:
    Canasta();
	Canasta(const std::string& archivo, const char letra);
	~Canasta();

    int mirar();
    int vaciar();
    int agregarPan();
    int sacarPan();
};


#endif /* CANASTA_H_ */
