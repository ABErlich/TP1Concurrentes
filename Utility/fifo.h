#ifndef FIFO_H_
#define FIFO_H_

#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

class Fifo {
public:
	Fifo(const std::string nombre);
	virtual ~Fifo();
	//virtual void abrir() = 0;
	//void cerrar();
	void eliminar() const;

protected:
	std::string nombre;
	int fd;
};




Fifo::Fifo(const std::string nombre) : nombre(nombre), fd(-1) {
	mknod (static_cast<const char*>(nombre.c_str()), S_IFIFO|0666, 0);
}

Fifo::~Fifo() {
	
}

// void Fifo::cerrar() {
// 	close ( fd );
// 	fd = -1;
// }

void Fifo::eliminar() const {
	unlink ( nombre.c_str() );
}


#endif /* FIFO_H_ */