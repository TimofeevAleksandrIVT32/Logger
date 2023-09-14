#include "log_lib.h"
#include "test.h"

void test_f() {
    log_info("info message!!!");
    test_fun();
}

void test_fun() {
    log_warning("warning message!!!");
    test_funct();
}

void test_funct() {
    log_error("error message!!!");
    test_function();
}

void test_function() {
    log_emerg_sit("emergency situation message!!!");
}
