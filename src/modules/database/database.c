#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include "modules/logging/logging.c"

/************************************* [DATA] *************************************************/
const char* database_path = "./data.db";
sqlite3* database_ptr;
sqlite3_stmt* database_statement;

/************************************* [PROCEDURES] *******************************************/
void database_load(void){
    int result = sqlite3_open(database_path, &database_ptr);
    if(result){
        logging_open();
        logging_write("Can't open database: %s", sqlite3_errmsg(database_ptr));
        logging_close(logging_data_file);  
    }else{
        logging_open();
        logging_write("Database opened successfully");
        logging_close(logging_data_file);  
    }
}

void database_unload(void){
    logging_open();
    logging_write("Database closed successfully");
    logging_close(logging_data_file); 
    sqlite3_close(database_ptr);
}

void database_cmd_end(void){
    sqlite3_finalize(database_statement);
}

#endif // DATABASE_H