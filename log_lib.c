#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <execinfo.h>
#include "log_lib.h"

// объявляем макросы здесь, чтобы они не были доступны пользователям библиотеки
#define BUF_SIZE 100
#define LEVEL_MAX_SIZE 10

// объявляем функции и переменную как static, чтобы они не были доступны пользователям библиотеки
static void select_level(char *l, int level);
static void get_time();
static void get_call_stack(int level);
static FILE *log_file;

// функция инициализации
void log_init(char *file_name) {
    log_file = fopen(file_name, "a");
    if (!log_file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
}

// функция записи в log файл
void log_message(int level, const char *file, int line, const char* message, ...) {
    char l[LEVEL_MAX_SIZE];
    select_level(l, level);
    get_time();

    fprintf(log_file, " %s:%d: %s: ", file, line, l);
    va_list args;
    va_start(args, message);
    vfprintf(log_file, message, args);
    va_end(args);
    fprintf(log_file, "\n");

    get_call_stack(level);
}

// функция закрытия log файла
void log_close() {
    fprintf(log_file, "\n");
    fclose(log_file);
}

// функция выбора уровня важности сообщения
static void select_level(char *l, int level) {
    switch (level) {
        case 0:
            strcpy(l,"debug");
            break;
        case 1:
            strcpy(l,"info");
            break;
        case 2:
            strcpy(l,"warning");
            break;
        case 3:
            strcpy(l,"error");
            break;
        case 4:
            strcpy(l,"emerg sit");
            break;
    }
}

// функция получения текущих даты и времени
static void get_time() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char date_time[256];
    strftime(date_time, sizeof(date_time), "%Y-%m-%d %H:%M:%S", &tm);
    fprintf(log_file, "[%s]", date_time);
}

// функция получения стека вызовов
static void get_call_stack(int level) {
    if (level == 3) {
        void* buffer[BUF_SIZE];
        int nptrs = backtrace(buffer, BUF_SIZE);
        char** strings = backtrace_symbols(buffer, nptrs);
        if (!strings) {
            perror("Backtrace_symbols function failed");
            fclose(log_file);
            exit(EXIT_FAILURE);
        }
        fprintf(log_file, "Stack trace:\n");
        for (int i = 0; i < nptrs; i++) {
            fprintf(log_file, "%s\n", strings[i]);
        }
        free(strings);
    }
}
