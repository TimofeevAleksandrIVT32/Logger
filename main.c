#include <stdio.h>
#include "test.h"
#include "log_lib.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid number of arguments\n");
        return 1;
    }
    log_init(argv[1]);
    log_debug("debug message!!!");
    test_f();
    log_close();
    return 0;
}
