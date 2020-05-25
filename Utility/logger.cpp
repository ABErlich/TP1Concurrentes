#include "logger.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "lockFile.h"
#include <fstream>

Logger::Logger(): lock("log.txt") {
    
}

void Logger::log(std::string mensaje) {

    lock.tomarLock();
    logfile.open("log.txt", std::ios::out | std::ios::app);
    logfile << mensaje;
    logfile.close();
    lock.liberarLock();
}

Logger::~Logger() {
    
}
