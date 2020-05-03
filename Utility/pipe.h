#ifndef PIPE_H_
#define PIPE_H_

#include <unistd.h>
#include <fcntl.h>

class Pipe {

private:
	int descriptores[2];
	bool lectura;
	bool escritura;

public:
	static const int LECTURA = 0;
	static const int ESCRITURA = 1;

	Pipe();
	~Pipe();

	void setearModo (const int modo);

	ssize_t escribir (const void* dato, const int datoSize);
	ssize_t leer (void* buffer, const int buffSize);

	int getFdLectura () const;
	int getFdEscritura () const;

	void cerrar ();
};

#endif /* PIPE_H_ */

Pipe::Pipe() : lectura(true), escritura(true) {
	pipe ( this->descriptores );
	/*fcntl ( this->descriptors[0],F_SETFL,O_NONBLOCK );
	fcntl ( this->descriptors[1],F_SETFL,O_NONBLOCK );*/
}

Pipe::~Pipe() {
}

void Pipe :: setearModo (const int modo) {
	if (modo == LECTURA) {
		close (this->descriptores[1]);
		this->escritura = false;

	} else if ( modo == ESCRITURA ) {
		close ( this->descriptores[0] );
		this->lectura = false;
	}
}

ssize_t Pipe :: escribir ( const void* dato,int datoSize ) {
	if ( this->lectura == true ) {
		close ( this->descriptores[0] );
		this->lectura = false;
	}

	return write ( this->descriptores[1],dato,datoSize );
}

ssize_t Pipe :: leer ( void* buffer,const int buffSize ) {
	if ( this->escritura == true ) {
		close ( this->descriptores[1] );
		this->escritura = false;
	}

	return read ( this->descriptores[0],buffer,buffSize );
}

int Pipe :: getFdLectura () const {
	if ( this->lectura == true )
		return this->descriptores[0];
	else
		return -1;
}

int Pipe :: getFdEscritura () const {
	if ( this->escritura == true )
		return this->descriptores[1];
	else
		return -1;
}

void Pipe :: cerrar () {
	if ( this->lectura == true ) {
		close ( this->descriptores[0] );
		this->lectura = false;
	}

	if ( this->escritura == true ) {
		close ( this->descriptores[1] );
		this->escritura = false;
	}
}
