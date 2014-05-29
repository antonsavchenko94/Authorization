#include "time_out_handler.h"


bool timeoutHandler::isTimeOut(){
  // This is a cancellation point: return true if you want to cancel
  // the current operation. If you return true, handleTimeOut() will
  // be called just after this, and before actually cancelling the
  // operation
  return false;
}

void timeoutHandler::resetTimeOut(){
  // Called at the beginning of an operation (eg. connecting,
  // a read() or a write() on a socket...)
}

bool timeoutHandler::handleTimeOut() {  return true;  }


vmime::shared_ptr<vmime::net::timeoutHandler> timeoutHandlerFactory::create()
{
  return vmime::make_shared <timeoutHandler>();
}
