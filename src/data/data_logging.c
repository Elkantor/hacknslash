

void* data_logging_file = 0L;

#if !defined data_logging
    const
#endif
    struct data_logging {
        void* file;
        const char* file_name;
    } 
#if defined data_logging
    ;
#else
    data_logging = {
        .file       = &data_logging_file, 
        .file_name  = "log.html",
    };
#endif