#ifndef FIFOLECTURA_H_
#define FIFOLECTURA_H_

#include "fifo.h"
#include <stdio.h>

class FifoLectura : public Fifo {
public:
	FifoLectura(const std::string nombre);
	~FifoLectura();

	ssize_t leer(void* buffer,const ssize_t buffsize) const;
};

///////////////////////////////////
///////////////////////////////////

FifoLectura::FifoLectura(const std::string nombre) : Fifo(nombre) {
	
	if ((fd = open(nombre.c_str(), O_RDONLY|O_CREAT)) < 0) {
		std::string mensaje = std::string("Error en open: ") + std::string(strerror(errno));
		throw mensaje;
	}
}

FifoLectura::~FifoLectura() {
	close(fd);
	fd = -1;
	remove(nombre.c_str());
}

ssize_t FifoLectura::leer(void* buffer,const ssize_t buffsize) const {
	ssize_t leido;

	if ((leido = read(fd, buffer, buffsize)) < 0) {
		std::string mensaje = std::string("Error en read: ") + std::string(strerror(errno));
		throw mensaje;
	}

	return leido;
}


#endif /* FIFOLECTURA_H_ */