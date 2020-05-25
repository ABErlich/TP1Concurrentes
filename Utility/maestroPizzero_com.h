#ifndef MAESTROPIZZEROCOM_H_
#define MAESTROPIZZEROCOM_H_

#include <string>
#include <fcntl.h>
#include <sys/stat.h>

class MaestroPizzeroCom {
public:
	MaestroPizzeroCom();
	virtual ~MaestroPizzeroCom();

    void pedirPizza();
    void esperarPedido();

protected:
	int fd;
	std::string nombre;
};



#endif /* MAESTROPIZZEROCOM_H_ */