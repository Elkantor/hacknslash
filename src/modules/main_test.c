#include "logging.c"
#include "data_logging.c"

int main(int argc, char** argv){
    logging.flush(data_logging.file_name);
    logging.open(data_logging.file, data_logging.file_name);
    logging.write(data_logging.file, "red", "%s%d", "problem", 2);
    logging.write(data_logging.file, "blue", "%s : %d", "Main character id", 46);
    logging.close(data_logging.file);
    return 0;
}