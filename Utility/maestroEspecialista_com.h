#ifndef MAESTROESPECIALISTACOM_H_
#define MAESTROESPECIALISTACOM_H_

#include <string>
#include <fcntl.h>
#include <sys/stat.h>
#include "lockFile.h"

class MaestroEspecialistaCom {

protected:
	int fd;
	LockFile lock;
	std::string nombre;

public:
	MaestroEspecialistaCom();
	virtual ~MaestroEspecialistaCom();

    void pedirMasa();
	void pedirMasa(std::string numero);
    std::string entregarMasa();


};



#endif /* MAESTROESPECIALISTACOM_H_ */