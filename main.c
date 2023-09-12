#include "test.h"
#include "log_lib.h"

int main() {
    char file_name[STR_SIZE] = "file.log";
    char str[STR_SIZE] = "This is the";
    log_init(file_name);
    log_debug("%s debug message!!!", str);
    test_f(str);
    log_close();
    return 0;
}
