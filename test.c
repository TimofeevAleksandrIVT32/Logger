#include "log_lib.h"
#include "test.h"

void test_f(char *str) {
    log_info("%s info message!!!",str);
    test_fun(str);
}

void test_fun(char *str) {
    log_warning("%s warning message!!!", str);
    test_funct(str);
}

void test_funct(char *str) {
    log_error("%s error message!!!", str);
    test_function(str);
}

void test_function(char *str) {
    log_emerg_sit("%s emergency situation message!!!", str);
}
