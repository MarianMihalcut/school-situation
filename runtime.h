#ifndef RUNTIME_H_
#define RUNTIME_H_

#include "data.h"

int str_equal(char *str1,const char *str2);
void help_menu_run(int argc,char *argv[]);

//working with data
void add_data(info student[],int nr);

#endif