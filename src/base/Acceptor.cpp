#include "base/Acceptor.h"
#include "base/Socket.h"
#include "util/Logger.h"

namespace stardust{
namespace libevent{


Acceptor::Acceptor(EventLoop *loop):loop_(loop), socket_(nullptr),
    accept_channel_(nullptr) {
  socket_ = new Socket();
  InetAddress address ("127.0.0.1", 8888); //TODO 支持自定义IP与端口
  socket_ -> Bind(address);
  socket_ -> Listen();
  accept_channel_ = new Channel(loop_, socket_->GetFd());
  accept_channel_ -> SetReadCallback(std::bind(&Acceptor::on_accept_new_connection, this));
  accept_channel_ -> EnableReading(); //阻塞 LT模式
  LOG4CXX_INFO(Logger::GetLogger(), "start to accept");
}

Acceptor::~Acceptor() {
  delete socket_;
  delete accept_channel_;
  LOG4CXX_INFO(Logger::GetLogger(), "Acceptor determinated");
}

void Acceptor::SetAcceptCallback(NewConnectionCallback const& cb) {
  LOG4CXX_DEBUG(Logger::GetLogger(), "accept channel " << accept_channel_->GetFd() 
      << " register new connection callback");
  callback_ = cb;
}

void Acceptor::on_accept_new_connection() {
  InetAddress cli_addr;
  int32_t client_fd = socket_->Accept(&cli_addr);
  auto& client_addr = cli_addr.GetAddr();
  LOG4CXX_INFO(Logger::GetLogger(), " client fd: " << client_fd << " ip: " \
      << inet_ntoa(client_addr.sin_addr) << " port: " << ntohs(client_addr.sin_port));
  // Connection* conn = new Connection(sub_reactor_[random], client_fd);
  Socket *client_socket= new Socket(client_fd);
  callback_(client_socket);
}


} // namespace libevent
} // namespace stardust


