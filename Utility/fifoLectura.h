#ifndef FIFOLECTURA_H_
#define FIFOLECTURA_H_

#include "fifo.h"

class FifoLectura : public Fifo {
public:
	FifoLectura(const std::string nombre);
	~FifoLectura();

	//void abrir();
	ssize_t leer(void* buffer,const ssize_t buffsize) const;
};

///////////////////////////////////
///////////////////////////////////

FifoLectura::FifoLectura(const std::string nombre) : Fifo(nombre) {
	fd = open ( nombre.c_str(),O_RDONLY );
}

FifoLectura::~FifoLectura() {
	close ( fd );
	fd = -1;
}

// void FifoLectura::abrir() {
// 	fd = open ( nombre.c_str(),O_RDONLY );
// }

ssize_t FifoLectura::leer(void* buffer,const ssize_t buffsize) const {
	return read (fd, buffer, buffsize);
}


#endif /* FIFOLECTURA_H_ */