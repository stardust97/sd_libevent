#ifndef _SD_LIBEVENT_ACCEPTOR_H_
#define _SD_LIBEVENT_ACCEPTOR_H_


#include <functional>

#include "base/EventLoop.h"
#include "base/Socket.h"
#include "base/Channel.h"
#include "base/InetAddress.h"


namespace stardust{
namespace libevent{

class Acceptor {
  using NewConnectionCallback = std::function<void(Socket*)>;
public:
  Acceptor(EventLoop* loop);
  ~Acceptor();

  void SetAcceptCallback(NewConnectionCallback const& cb);
private:
  void on_accept_new_connection();
  EventLoop* loop_;
  Socket* socket_; // 接收新连接的socket
  Channel* accept_channel_;
  NewConnectionCallback callback_; // 发生新连接时的函数
};



} // namespace libevent
} // namespace stardust


#endif // _SD_LIBEVENT_ACCEPTOR_H_