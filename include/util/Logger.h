#ifndef _SD_LIBEVENT_LOGGER_H_
#define _SD_LIBEVENT_LOGGER_H_

#include <log4cxx/logger.h>

namespace stardust{
namespace libevent{
class Logger {
public:
  Logger();
  ~Logger();
  void Init(std::string conf_file);
  static Logger& GetInstance();

 static log4cxx::LoggerPtr GetLogger() { return logger_ptr_;}

private:
 static log4cxx::LoggerPtr logger_ptr_;
};

} // namespace libevent
} // namespace stardust



#endif // _SD_LIBEVENT_LOGGER_H_






