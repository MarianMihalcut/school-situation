#include <stdio.h>
#include <string.h>
#include "runtime.h"
#include "print_func.h"
#include "data.h"

int str_equal(char *str1,const char *str2)
{
    int i=0;
    int len1=strlen(str1);
    int len2=strlen(str2);
    int min_len=len1<len2?len1:len2;
    for(int i=0;i<min_len;i++)
    {
        if(str1[i]!=str2[i])
            return 0;
    }
    return 1;
}

void help_menu_run(int argc,char *argv[])
{
    if(argc==2)
        help_menu();
    else if(argc==3)
    {
        char *str=argv[2];
        if(str_equal(str,"add_data"))
            help_add_data();
        else if(str_equal(str,"list_field"))
            help_list_field();
        else if(str_equal(str,"list_table"))
            help_list_table();
        else if(str_equal(str,"delete_field"))
            help_delete_field();
        else if(str_equal(str,"delete_all"))
            help_delete_all();
        else if(str_equal(str,"calc_stud_avg"))
            help_calc_average_student();
        else if(str_equal(str,"calc_gen_avg"))
            help_calc_average_general();
        else if(str_equal(str,"calc_sub_avg"))
            help_calc_average_subject();
        else if(str_equal(str,"cnt_stud"))
            help_count_students_number();
        else if(str_equal(str,"cnt_stud_pass"))
            help_count_students_passed();
        else if(str_equal(str,"cnt_stud_failed"))
            help_count_students_failed();
        else if(str_equal(str,"cnt_bck_stud"))
            help_count_backlog_students();
        else if(str_equal(str,"cnt_bck_obj"))
            help_count_backlog_objects();
        else
            printf("Error:Incorrect arguments introduced. Please see help for commands\n");
    }
    else
        printf("Too many arguments given! A max of 2 is allowed for help.");
}

void add_data(info *student)
{
    char name[20];
    int year,mat1,mat2,mat3,mat4,mat5;
    fprintf(stdout,"Please enter the name of student:\n");
    fscanf(stdin,"%s",name);
    fprintf(stdout,"Please give the study year:\n");
    fscanf(stdin,"%d",&year);
    fprintf(stdout,"Please give the grades for the following objects:\n");
    fprintf(stdout,"Programming:\n");
    fscanf(stdin,"%d",&mat1);
    fprintf(stdout,"Numerical methods:\n");
    fscanf(stdin,"%d",&mat2);
    fprintf(stdout,"Special math:\n");
    fscanf(stdin,"%d",&mat3);
    fprintf(stdout,"Data structures:\n");
    fscanf(stdin,"%d",&mat4);
    fprintf(stdout,"Discrete math:\n");
    fscanf(stdin,"%d",&mat5);
    insert_elem(student,name,year,mat1,mat2,mat3,mat4,mat5);
}
 