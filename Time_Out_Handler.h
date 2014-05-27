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

    bool isTimeOut(){
        // This is a cancellation point: return true if you want to cancel
        // the current operation. If you return true, handleTimeOut() will
        // be called just after this, and before actually cancelling the
        // operation
        return false;
    }

    void resetTimeOut(){
        // Called at the beginning of an operation (eg. connecting,
        // a read() or a write() on a socket...)
    }

    bool handleTimeOut() {  return true;  }
};


class timeoutHandlerFactory : public vmime::net::timeoutHandlerFactory {
public:
    vmime::shared_ptr <vmime::net::timeoutHandler> create()
    {
        return vmime::make_shared <timeoutHandler>();
    }
};

