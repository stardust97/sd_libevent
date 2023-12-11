#ifndef _SD_LIBEVENT_EPOLL_H_
#define _SD_LIBEVENT_EPOLL_H_

#include <cstdint>
#include <memory>
#include <vector>

#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

// #include "base/Channel.h" //BUG 头文件不应该互相包含！


namespace stardust{
namespace libevent{

class Channel; //利用前置声明代替循环包含的头文件

class Epoll {
public:
  Epoll();
  ~Epoll();

  void AddToEpoll(Channel* channel, uint32_t events);

  void RemoveFromEpoll(Channel* channel);

  void ModifyEpollEvent(Channel* channel, uint32_t eventes);

  void Wait( std::vector<Channel*>& active_events);

  void UpdateChannel(Channel* channel);
  int32_t polled_nums_;
private:
  void fill_active_channels( std::vector<Channel*>& active_events, int32_t nums);
  
  static constexpr int32_t kInitEventListSize = 16;

  int32_t epoll_fd_;

  std::vector<epoll_event> events_; //发生事件的epoll_event

};



} // namespace libevent
} // namespace stardust

#endif //_SD_LIBEVENT_EPOLL_H_
