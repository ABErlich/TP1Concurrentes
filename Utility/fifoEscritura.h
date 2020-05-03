#ifndef FIFOESCRITURA_H_
#define FIFOESCRITURA_H_

#include "fifo.h"

class FifoEscritura : public Fifo {
public:
	FifoEscritura(const std::string nombre);
	~FifoEscritura();

	//void abrir();
	ssize_t escribir(const void* buffer, const ssize_t buffsize) const;
};

/////////////////////////////////////////
/////////////////////////////////////////

FifoEscritura::FifoEscritura(const std::string nombre) : Fifo(nombre) {
	fd = open (nombre.c_str(), O_WRONLY);
}

FifoEscritura::~FifoEscritura() {
	close ( fd );
	fd = -1;
}

// void FifoEscritura::abrir() {
// 	fd = open (nombre.c_str(), O_WRONLY);
// }

ssize_t FifoEscritura::escribir(const void* buffer, const ssize_t buffsize) const {
	return write (fd, buffer, buffsize);
}


#endif /* FIFOESCRITURA_H_ */