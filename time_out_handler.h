#include <QtCore/QCoreApplication>

#include <iostream>
#include <sstream>
#include <clocale>
#include <vector>
#include <locale>
#include <map>

#include "vmime/vmime.hpp"
#include "vmime/platforms/posix/posixHandler.hpp"

class timeoutHandler : public vmime::net::timeoutHandler {
public:

    bool isTimeOut();

    void resetTimeOut();

    bool handleTimeOut();
};

class timeoutHandlerFactory : public vmime::net::timeoutHandlerFactory {
public:
    vmime::shared_ptr <vmime::net::timeoutHandler> create();
};

