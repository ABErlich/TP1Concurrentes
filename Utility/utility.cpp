#include "utility.h"
#include <sstream>
#include <stdlib.h>

std::string obtenerFechaYHora() {
    
    time_t now = time(0);

    tm *ltm = localtime(&now);

    std::ostringstream os;
    os << ltm->tm_mday << '/' << ltm->tm_mon << '/' << 1900 + ltm->tm_year << ' ';
    os << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec;

    std::string s = os.str();
    return s;
}

