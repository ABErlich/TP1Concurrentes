#ifndef UTILITY
#define UTILITY

#include <stdlib.h>
#include <sstream>

std::string obtenerFechaYHora();

std::string obtenerFechaYHora() {
    
    time_t now = time(0);

    tm *ltm = localtime(&now);

    std::ostringstream os;
    os << ltm->tm_mday << '/' << ltm->tm_mon << '/' << 1900 + ltm->tm_year << ' ';
    os << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec;

    std::string s = os.str();
    return s;
}



#endif