#include <stdio.h>
#include <stdarg.h>

/************************************* [DATA] *************************************************/
void* logging_data_file             = 0L;
const char* logging_data_file_name  = "log.html";


/************************************* [PROCEDURES] *******************************************/
static inline void logging_flush(const char* in_file_name){
    fclose(fopen(in_file_name, "w"));
}

static inline void logging_close(){
    fclose(logging_data_file);
}

static inline int logging_open(const char* in_file_name){
    logging_data_file = fopen(in_file_name, "a");
    if(logging_data_file == NULL){
        printf("Can't open the logging file\n");
        return -1;
    }
    return 1;
}

int logging_write(const char* in_text, ...){
    if(logging_data_file == NULL){
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
    vfprintf(logging_data_file, in_text, args);
    fprintf(logging_data_file, "</br>");
    return 1;
}