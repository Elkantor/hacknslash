#include "logging.c"

int main(int argc, char** argv){
    // clear the logging file (by default called log.html as the logging_data_file_name variable)
    logging_flush(logging_data_file_name);
    logging_open(logging_data_file, logging_data_file_name);
    
    logging_write(logging_data_file, "%s %ld", "this is a new stuff", 5165454);
    const char* html_content = "<em>this is a test in italic mode</em>";
    logging_write(logging_data_file, "%s", html_content);
    
    logging_close(logging_data_file);
    return 0;
}