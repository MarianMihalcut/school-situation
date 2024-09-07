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

//calculations
float calc_average_student(info *student,char name[]);
float calc_average_general(info *student);
float calc_average_subject(info *student,char subject[]);

//count
int count_students_number(info *student);
int count_students_passed(info *student);
int count_students_failed(info *student);
int count_backlog_students(info *student,char name[]);
int count_backlog_objects(info *student,char subject[]);

#endif