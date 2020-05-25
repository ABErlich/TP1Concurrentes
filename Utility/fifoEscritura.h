#ifndef FIFOESCRITURA_H_
#define FIFOESCRITURA_H_

#include "fifo.h"
#include <stdio.h>

class FifoEscritura : public Fifo {

public:
	FifoEscritura(const std::string nombre);
	~FifoEscritura();

	ssize_t escribir(const void* buffer, const ssize_t buffsize) const;
};

/////////////////////////////////////////
/////////////////////////////////////////

FifoEscritura::FifoEscritura(const std::string nombre) : Fifo(nombre) {	
	if ((fd = open (nombre.c_str(), O_WRONLY|O_CREAT)) < 0) {
		std::string mensaje = std::string("Error en open: ") + std::string(strerror(errno));
		throw mensaje;
	}
}

FifoEscritura::~FifoEscritura() {
	close(fd);
	fd = -1;
	remove(nombre.c_str());
}

ssize_t FifoEscritura::escribir(const void* buffer, const ssize_t buffsize) const {
	ssize_t escrito;

	if((escrito = write(fd, buffer, buffsize)) < 0) {
		std::string mensaje = std::string("Error en write: ") + std::string(strerror(errno));
		throw mensaje;
	}

	return escrito;
}


#endif /* FIFOESCRITURA_H_ */