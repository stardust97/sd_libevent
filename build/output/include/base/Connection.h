#ifndef _SD_LIBEVENT_CONNECTION_H_
#define _SD_LIBEVENT_CONNECTION_H_

#include <functional>
#include <memory>

#include "base/Channel.h"
#include "base/EventLoop.h"
#include "base/Buffer.h"
#include "base/Socket.h"

namespace stardust{
namespace libevent{

class Connection {
  using NewMsgCallback = std::function<void(Connection*)>;
  using DisConnectCallback = std::function<void(Channel*)>;

public:
  enum class ConnState {
    CONNECTED, CLOSED
  };
  
  Connection(EventLoop* loop, Socket* socket);
  ~Connection();
  
  void SetNewMsgCallback(NewMsgCallback cb);
  void SetDisconnectCallback(DisConnectCallback cb);
  void Read();
  void Write();
  void SetWriteBuf(const char* buf);
  void SetWriteBuf(std::string const& contex);
  /// @brief 获取当前连接的状态
  ConnState GetState() {return state_;};
  /// @brief  关闭当前连接 
  void Close();

private:
  void blocked_read();
  void no_blocked_read();
  void blocked_write();
  void no_blocked_write();

  constexpr static int32_t KMaxBufSize = 1024;
  EventLoop* loop_;
  std::unique_ptr<Channel> ch_; // 客户端连接的Channel
  std::unique_ptr<Socket> socket_; // 客户端连接的Scoket
  std::unique_ptr<Buffer> read_buf_;
  std::unique_ptr<Buffer> write_buf_;
  ConnState state_;
  NewMsgCallback new_msg_callback_;
  DisConnectCallback dis_conn_callback_;
};




} // namespace libevent
} // namespace stardust


#endif // _SD_LIBEVENT_CONNECTION_H_