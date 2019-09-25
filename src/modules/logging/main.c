#include "logging.c"

int main(int argc, char** argv){
    // clear the logging file (by default called log.html, to modify, change the char* value of the logging_data_file_name variable)
    logging_flush();
    logging_open();
    
    logging_write("<div style='color: red;'>%s %ld</div>", "this is a new stuff", 5165454);
    const char* html_content = "<em>this is a test in italic mode</em>";
    logging_write("%s", html_content);

    logging_close();
    return 0;
}