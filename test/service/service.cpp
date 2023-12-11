
#include <filesystem>
#include <iostream>

#include "base/EventLoop.h"
#include "base/Server.h"
#include "base/Connection.h"
#include "util/Logger.h"

using stardust::libevent::Logger;
using stardust::libevent::EventLoop;
using stardust::libevent::Server;
using stardust::libevent::Connection;

int main() {
  Logger logger = Logger::GetInstance();
  logger.Init("conf/log4cxx.properties");
  LOG4CXX_INFO(Logger::GetLogger(), "server start ");
  EventLoop* loop = new EventLoop();
  Server* server = new Server(loop);
  server ->SetConnectionCallback(
    [](Connection* conn) {
      conn -> Read();
      if(conn -> GetState() == Connection::ConnState::CLOSED) {
        printf("Connection closed\n");
        conn -> Close();
        return;
      }
      LOG4CXX_DEBUG(Logger::GetLogger(), " read once ");
      // conn -> Write(); // TODO
    }
  );
  loop -> Loop();
  delete server;
  delete loop;
  return 0;
}
