#ifndef _SD_LIBEVENT_CHANNEL_H_
#define _SD_LIBEVENT_CHANNEL_H_

#include <memory>
#include <functional>
#include <sys/epoll.h>
#include "base/EventLoop.h"

namespace stardust{
namespace libevent{

class Channel {
  constexpr static int32_t KNoneEvent = 0;
  constexpr static int32_t KReadEvent = EPOLLIN | EPOLLPRI;
  constexpr static int32_t KETReadEvent = EPOLLIN | EPOLLPRI | EPOLLET;
  constexpr static int32_t KWriteEvent = EPOLLOUT;
  constexpr static int32_t KCloseEvent = EPOLLRDHUP; // TODO 只考虑了一种情况
  constexpr static int32_t KErrorEvent = 0; // TODO 


public:
  using ReadEventCallback = std::function<void()>;
  using EventCallback = std::function<void()>;

  Channel() = delete;
  Channel(EventLoop* ep, int32_t fd);
  ~Channel();

  const int32_t& GetFd() {return fd_;};
  void SetRevents(uint32_t events);
  uint32_t GetActiveEvents() {return revents_;}; // 获取当前Channel发生的事件
  uint32_t GetEvents() {return events_;}; // 获取当前Channel关心的事件
  bool GetIsPolled() {return is_polled_;}; 
  bool GetIsBlocked() {return is_blocked_;};
  void HandleEvents(); //处理当前Channel发生的事件

  void EnableReading();
  void EnableETReading();
  void DisableReading();
  void EnableWriting();
  void DisableWriting();
  void DisableAll();

  void SetReadCallback(ReadEventCallback const& cb);
  void SetWriteCallback(EventCallback const& cb);
  void SetCloseCallback(EventCallback const& cb);
  void SetErrorCallback(EventCallback const& cb);
  
private:
  void set_fd_noblocked();
  void update_channel_events();
  int32_t fd_; //Channel所管理的fd
  bool is_blocked_; // 文件描述符的读写是否是阻塞的
  EventLoop* loop_; // Channel被哪个EventLoop所管理
  bool is_polled_; // 指示是否已经被加入到epoll中监听
  uint32_t events_; // 本Channel所关心的事件
  uint32_t revents_; // epoll返回的实际发生的事件

  ReadEventCallback read_callback_;
  EventCallback write_callback_;
  EventCallback close_callback_;
  EventCallback error_callback_;

};


} // namespace libevent
} // namespace stardust

#endif //_SD_LIBEVENT_CHANNEL_H_
