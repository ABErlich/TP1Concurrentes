#ifndef LOGGER_H_
#define LOGGER_H_

#include <unistd.h>
#include <fcntl.h>
#include <string>
#include "lockFile.h"
#include <fstream>

class Logger {

private:
    LockFile lock;
    std::ofstream logfile;

public:
    Logger();
	~Logger();

    void log(std::string mensaje);
};


#endif /* LOGGER_H_ */
