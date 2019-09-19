#include "logging.c"
#include "data_logging.c"

int main(int argc, char** argv){
    // clear the logging file (by default called log.html as the data_logging.file_name variable)
    logging.flush(data_logging.file_name);
    logging.open(data_logging.file, data_logging.file_name);
    
    logging.write(data_logging.file, "red", "%s %ld", "this is a new stuff", 5165454);
    const char* html_content = "<em>this is a test in italic mode</em>";
    logging.write(data_logging.file, "black", "%s", html_content);
    
    logging.close(data_logging.file);
    return 0;
}