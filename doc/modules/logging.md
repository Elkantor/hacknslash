# logging
----
The logging module handles the writting process in a log file in the html format (that allows you to write log with different colors, table... everything you could do with html. The logging file is viewable like any other html file, in a web browser.

**[Available inside src/modules/logging.c](https://github.com/Elkantor/hacknslash/blob/master/src/modules/logging.c)**

Associated data which can be used by this module are inside the **[src/data/data_logging.c file](https://github.com/Elkantor/hacknslash/blob/master/src/data/data_logging.c)**

---

### functions
- <em>[void flush(const char* in_file_name)](#h6-void-flush(const-char*-in_file_name-)</em>
- <em>[int logging_open(FILE** out_log_file, const char* in_file_name)](#h6-int-logging_open-file-em-out_log_file-const-char-em-in_file_name-)</em>

---
</br>

###### void flush(const char* in_file_name)

_Clean the content of the logging file_

<u>Example</u>:
```c
    logging.flush("log.html");
```
or by including the associated data_logging.c file:
```c
    logging.flush(data_logging.file_name);
```
***
</br>

###### int logging_open(FILE** out_log_file, const char* in_file_name)

_Open the logging file at the in_file_name name (you can give it the path + the name too)_

<u>Example</u>:
```c
    FILE* my_file;
    logging.open(&my_file, "log.html");
```
or by including the associated data_logging.c file:
```c
    logging.open(data_logging.file, data_logging.file_name);
```
***
</br>