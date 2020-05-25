#ifndef FIFO_H_
#define FIFO_H_

#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

class Fifo {
public:
	Fifo(const std::string nombre);
	virtual ~Fifo();
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

void Fifo::eliminar() const {
	if(unlink(nombre.c_str()) < 0){
		std::string mensaje = std::string("Error en unlink: ") + std::string(strerror(errno));
		std::cout << mensaje << std::endl;
		throw mensaje;
	}
}


#endif /* FIFO_H_ */