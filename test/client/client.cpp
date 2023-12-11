
#include <thread>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>

#include "base/Connection.h"
#include "base/Socket.h"
#include "base/InetAddress.h"
#include "util/Logger.h"

using stardust::libevent::Logger;
using stardust::libevent::EventLoop;
using stardust::libevent::Connection;
using stardust::libevent::InetAddress;
using stardust::libevent::Socket;

int main(){
  Logger logger = Logger::GetInstance();
  logger.Init("conf/log4cxx.properties");
  LOG4CXX_INFO(Logger::GetLogger(), "server start ");
  InetAddress *addr= new InetAddress("127.0.0.1", 8888);
  Socket* socket = new Socket();
  socket -> Connect(addr);
  Connection* conn = new Connection(nullptr, socket);
  try {
    for(int32_t i = 0; i < 200; ++i) {
      std::string msg = "hello "+ std::to_string(i);
      conn ->SetWriteBuf( msg );
      conn ->Write();
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      // conn->Read();
    }
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}