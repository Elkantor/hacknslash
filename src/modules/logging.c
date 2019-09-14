#include <stdio.h>
#include <stdarg.h>

#if defined _WIN32 && defined module_logging_build_dll
    #define LOGGING __declspec(dllexport) // We are building logging as a win32 shared library (.dll)
#elif defined _WIN32 && defined module_logging
    #define LOGGING __declspec(dllimport) // we are using logging as a win32 shared library (.dll)
#else
    #define LOGGING // We are building or using logging as a static library (or a shared one on linux)
#endif

void logging_flush(const char* in_file_name){
    /*
        flush the content from the log file by opening it in
        writing mode, which erased the previous content, and
        closing it as soon as it's opened
    */
    fclose(fopen(in_file_name, "w"));
}

void logging_close(FILE** out_log_file){
    fclose(*out_log_file);
}

int logging_open(FILE** out_log_file, const char* in_file_name){
    *out_log_file = fopen(in_file_name, "a");
    if(*out_log_file == NULL){
        printf("Can't open the logging file\n");
        return -1;
    }
    return 1;
}

int logging_write(FILE** out_log_file, const char* in_color, const char* in_text, ...){
    if(*out_log_file == NULL){
        printf("Can't write in the logging file\n");
        return -1;
    }

    /*
        vlist variable is used here. To know how it works, you can
        check these links for more info:
        - https://stackoverflow.com/questions/15830641/pass-many-arguments-to-a-c-function
        - https://jameshfisher.com/2016/11/23/c-varargs
    */
    va_list args;
    va_start(args, in_text);
    va_end(args);
    fprintf(*out_log_file, "<font color=\"%s\">", in_color);
    vfprintf(*out_log_file, in_text, args);
    fprintf(*out_log_file, "</font></br>\n");
    return 1;
}

#if !defined module_logging
    const 
#endif
    struct LOGGING logging {
        void (*const flush)(const char* in_file_name);
        void (*const close)(FILE** out_log_file);
        int (*const open)(FILE** out_log_file, const char* in_file_name);
        int (*const write)(FILE** out_log_file, const char* in_color, const char* in_text, ...);
    }
#if defined module_logging
    ;
#else
    logging = {
        .flush              = logging_flush,
        .close              = logging_close,
        .open               = logging_open,
        .write              = logging_write,
    };
#endif