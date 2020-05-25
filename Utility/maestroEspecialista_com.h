#ifndef MAESTROESPECIALISTACOM_H_
#define MAESTROESPECIALISTACOM_H_

#include <string>
#include <fcntl.h>
#include <sys/stat.h>

class MaestroEspecialistaCom {
public:
	MaestroEspecialistaCom();
	virtual ~MaestroEspecialistaCom();

    void pedirMasa();
	void pedirMasa(std::string numero);
    std::string entregarMasa();

protected:
	int fd;
	std::string nombre;
};



#endif /* MAESTROESPECIALISTACOM_H_ */