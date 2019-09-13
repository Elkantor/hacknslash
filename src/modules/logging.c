#if defined _WIN32 && defined module_logging_build_dll
    #define LOG __declspec(dllexport) // We are building log as a win32 shared library (.dll)
    #include <stdio.h>
#elif defined _WIN32 && defined module_logging
    #define LOG __declspec(dllimport) // we are using log as a win32 shared library (.dll)
#else
    #define LOG // We are building or using log as a static library (or a shared one on linux)
#endif

int log_open(FILE* out_log_file, const char* in_file_name){
    out_log_file = fopen(in_file_name, "a+"); // open file and append to it's content
    if(out_log_file == NULL){
        printf("can't open the log file\n");
        return -1;
    }
    fprintf(out_log_file, "[LOG]\n");
    return 0;
}

#if !defined module_logging
    const 
#endif
    struct LOG logging {
        int (*const open)(FILE* out_log_file, const char* in_file_name);
    }
#if defined module_logging
    ;
#else
    logging = {
        .open = log_open,
    };
#endif