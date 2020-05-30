#ifndef MAESTROPIZZEROCOM_H_
#define MAESTROPIZZEROCOM_H_

#include <string>
#include <fcntl.h>
#include <sys/stat.h>
#include "lockFile.h"

class MaestroPizzeroCom {
public:
	MaestroPizzeroCom();
	virtual ~MaestroPizzeroCom();

    void pedirPizza(std::string numeroPedido);
    std::string esperarPedido();

protected:
	int fd;
	std::string nombre;
	LockFile lockRecepcionista;
	LockFile lockPizzero;
};



#endif /* MAESTROPIZZEROCOM_H_ */