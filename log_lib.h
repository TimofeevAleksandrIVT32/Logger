#ifndef LOG_LIB_H
#define LOG_LIB_H

#include <stdarg.h>

#define log_debug(message, ...) log_message(0, __FILE__, __LINE__, message,  ##__VA_ARGS__)
#define log_info(message, ...) log_message(1, __FILE__, __LINE__, message, ##__VA_ARGS__)
#define log_warning(message, ...) log_message(2, __FILE__, __LINE__, message, ##__VA_ARGS__)
#define log_error(message, ...) log_message(3, __FILE__, __LINE__, message, ##__VA_ARGS__)

// для использования при аварийных ситуациях (например malloc, вернувший NULL)
#define log_emerg_sit(message, ...) log_message(4, __FILE__, __LINE__, message, ##__VA_ARGS__)

void log_init(char *filename);
void log_message(int level, const char *file, int line, const char* message, ...);
void log_close();

#endif  /* LOG_LIB_H */
