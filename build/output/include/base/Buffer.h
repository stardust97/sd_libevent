#ifndef _SD_LIBEVENT_BUFFER_H_
#define _SD_LIBEVENT_BUFFER_H_


#include <string>

namespace stardust{
namespace libevent{

class Buffer{
public:
  Buffer();
  ~Buffer();

  ssize_t GetSize();
  void Append(const char* str, ssize_t len);
  void Clear();
  char const* GetStr();
private:
  std::string buf_; // 缓冲区容器

};



} // namespace libevent
} // namespace stardust


#endif //_SD_LIBEVENT_BUFFER_H_