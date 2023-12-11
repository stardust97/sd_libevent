#ifndef _SD_LIBEVENT_EVENTLOOP_H_
#define _SD_LIBEVENT_EVENTLOOP_H_

#include "base/Epoll.h"
#include "base/ThreadPool.h"

namespace stardust{
namespace libevent{

class EventLoop {
public:
  EventLoop();
  ~EventLoop();
  void Loop();
  void UpdateChannel(Channel* channel);
  void DisableChannel(Channel* channel);
  
private:
  Epoll *ep_;
  bool quit_;


};


} // namespace libevent
} // namespace stardust



#endif // _SD_LIBEVENT_EVENTLOOP_H_