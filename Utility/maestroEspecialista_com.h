#ifndef MAESTROESPECIALISTACOM_H_
#define MAESTROESPECIALISTACOM_H_

#include <string>
#include <fcntl.h>
#include <sys/stat.h>
#include "lockFile.h"

class MaestroEspecialistaCom {

protected:
	int fd;
	LockFile lockPedido;
	LockFile lockEntrega;
	std::string nombreIda;
	std::string nombreVuelta;

public:
	MaestroEspecialistaCom();
	virtual ~MaestroEspecialistaCom();

	std::string esperarPedido();
    void pedirMasa();
	void pedirMasa(std::string numero);
    void entregarMasa();
	std::string esperarMasa();

};



#endif /* MAESTROESPECIALISTACOM_H_ */