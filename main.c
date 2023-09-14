#include "test.h"
#include "log_lib.h"

int main() {
    log_init();
    log_debug("debug message!!!");
    test_f();
    log_close();
    return 0;
}
