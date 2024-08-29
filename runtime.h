#ifndef RUNTIME_H_
#define RUNTIME_H_

#include "data.h"

int str_equal(char *str1,const char *str2);
void help_menu_run(int argc,char *argv[]);

//working with data
info *add_data(info *student);
void list_field(info *student,char name[]);
void list_all(info *student);
info *delete_field(info *student,char name[]);
info *delete_all(info *student);

#endif