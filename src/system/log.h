#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <sstream>

// Helper define for logging, disabled in release mode
#ifndef NDEBUG
# define glog(sev, msg) \
    do { std::stringstream s; \
         s << msg; \
         game::Log::getGlobal().log(sev, s); \
    } while (0)
#else
# define glog(severity, msg);
#endif

namespace game {

/**
 * @brief Log objects can log to a given std::ostream.
 * By default, they will log to stdout.
 */
class Log
{
public:
  /**
   * @brief The Priority enum defines the possible priorities for a log message.
   */
  enum Priority {
    ERROR,
    WARNING,
    INFO,
    DBG,
    TRACE
  };

  static std::string priorityToStr(Priority sev);

  /**
   * @brief getGlobal Retrieve the static global logger object.
   * @return A reference to the statically created global logger object.
   */
  static Log& getGlobal();

  /**
   * @brief log Print a log message with the given priority.
   */
  void log(Priority, const std::string&);

  void log(Priority sev, std::stringstream &msg);

  /**
   * @brief setLevel Set the maximum log level for the given logger.
   * Log messages below this level will be ignored.
   * @param maxLevel Maximum priority level for this logger.
   */
  void setLevel(Priority maxLevel);

  std::ostream &get(Priority sev);

  Log();
  Log(std::ostream &mOutput);

  // It doesn't make sense to copy loggers
  Log(Log const&) = delete;
  void operator=(Log const&) = delete;

private:
  std::ostream& mOutput;
  Priority mLevel;
};

/**
 * @brief Print an error message on the global log.
 */
void error(std::string msg);

}

#endif // LOG_H
