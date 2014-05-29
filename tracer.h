#include <QtCore/QCoreApplication>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <locale>
#include <clocale>

#include "vmime/vmime.hpp"
#include "vmime/platforms/posix/posixHandler.hpp"
/** Tracer used to demonstrate logging communication between client and server.
  */

class Tracer : public vmime::net::tracer
{
public:
    Tracer(vmime::shared_ptr <std::ostringstream> stream,
             vmime::shared_ptr <vmime::net::service> serv, const int connectionId);
    void traceSend(const vmime::string& line);
    void traceReceive(const vmime::string& line);

private:
    vmime::shared_ptr <std::ostringstream> m_stream;
    vmime::shared_ptr <vmime::net::service> m_service;
    const int m_connectionId;
};

class TracerFactory : public vmime::net::tracerFactory
{
public:
    TracerFactory(vmime::shared_ptr <std::ostringstream> stream);
    vmime::shared_ptr <vmime::net::tracer> create
        (vmime::shared_ptr <vmime::net::service> serv, const int connectionId);
private:
    vmime::shared_ptr <std::ostringstream> m_stream;
};

