#ifndef LOG_LIB_H
#define LOG_LIB_H

#include <stdarg.h>

#define LOG_MES_DEBUG 0
#define LOG_MES_INFO 1
#define LOG_MES_WARNING 2
#define LOG_MES_ERROR 3
#define LOG_MES_EMERG_SIT 4

#define log_debug(...) log_message(LOG_MES_DEBUG, __FILE__, __LINE__, ##__VA_ARGS__)
#define log_info(...) log_message(LOG_MES_INFO, __FILE__, __LINE__, ##__VA_ARGS__)
#define log_warning(...) log_message(LOG_MES_WARNING, __FILE__, __LINE__, ##__VA_ARGS__)
#define log_error(...) log_message(LOG_MES_ERROR, __FILE__, __LINE__, ##__VA_ARGS__)

// для использования при аварийных ситуациях (например malloc, вернувший NULL)
#define log_emerg_sit(...) log_message(LOG_MES_EMERG_SIT, __FILE__, __LINE__, ##__VA_ARGS__)

void log_init();
void log_message(int level, const char *file, int line, const char* message, ...);
void log_close();

#endif  /* LOG_LIB_H */
