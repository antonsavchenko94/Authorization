#include "tracer.h"


Tracer::Tracer(vmime::shared_ptr<std::ostringstream> stream, vmime::shared_ptr<vmime::net::service> serv, const int connectionId)
  : m_stream(stream), m_service(serv), m_connectionId(connectionId)
{
}

void Tracer::traceSend(const vmime::string &line)
{
  *m_stream << "[" << m_service->getProtocolName() << ":" << m_connectionId
            << "] C: " << line << std::endl;
}

void Tracer::traceReceive(const vmime::string &line)
{
  *m_stream << "[" << m_service->getProtocolName() << ":" << m_connectionId
            << "] S: " << line << std::endl;
}


TracerFactory::TracerFactory(vmime::shared_ptr<std::ostringstream> stream)
  : m_stream(stream)
{
}

vmime::shared_ptr<vmime::net::tracer> TracerFactory::create(vmime::shared_ptr<vmime::net::service> serv, const int connectionId)
{
  return vmime::make_shared <Tracer>(m_stream, serv, connectionId);
}
