#include <stdio.h>
#include <string.h>
#include "runtime.h"
#include "print_func.h"
#include "data.h"
#include <stdlib.h>

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

info *add_data(info *student)
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
    student=insert_elem(student,name,year,mat1,mat2,mat3,mat4,mat5);
    return student;
}
 
void list_field(info *student,char name[])
{
    info *student1=student;
    while(student1!=NULL && strcmp(student1->name,name)!=0)
        student1=student1->next;
    if(student1==NULL)
        fprintf(stdout,"The name cannot be found in the database.\n");
    else
    {
        fprintf(stdout,"Study year: %d\n",student1->study_year);
        fprintf(stdout,"Programming grade: %d\n",student1->programming);
        fprintf(stdout,"Numerical methods grade: %d\n",student1->num_methods);
        fprintf(stdout,"Special math grade: %d\n",student1->spec_math);
        fprintf(stdout,"Data structures grade: %d\n",student1->data_stuctures);
        fprintf(stdout,"Discrete math: %d\n",student1->discrete_math);
    }
}

void list_all(info *student)
{
    while(student!=NULL)
    {
        fprintf(stdout,"Name: %s\n",student->name);
        fprintf(stdout,"Study year: %d\n",student->study_year);
        fprintf(stdout,"Programming grade: %d\n",student->programming);
        fprintf(stdout,"Numerical methods grade: %d\n",student->num_methods);
        fprintf(stdout,"Special math grade: %d\n",student->spec_math);
        fprintf(stdout,"Data structures grade: %d\n",student->data_stuctures);
        fprintf(stdout,"Discrete math: %d\n",student->discrete_math);
        fprintf(stdout,"\n");
        student=student->next;
    }
}

info *delete_field(info *student,char name[])
{
    if(strcmp(student->name,name)==0)
        student=delete_front(student);
    else
    {
        info *student1=student;
        while(student1->next!=NULL && strcmp(student1->next->name,name)!=0)
            student1=student1->next;
        if(student1->next==NULL && strcmp(student1->next->name,name)==0)
            student1=delete_tail(student1);
        else if(strcmp(student1->next->name,name)==0)
            student1=delete_between(student1);
    }
    return student;
}

info *delete_all(info *student)
{
    while(student!=NULL)
    {
        info *student1=student;
        student=student->next;
        memset(student1,0,sizeof(info));
        free(student1);
    }
    return student;
}

float calc_average_student(info *student,char name[])
{
    info *student1=student;
    while(student1!=NULL && strcmp(student1->name,name)!=0)
        student1=student1->next;
    float sum=0;
    if(student1==NULL)
    {
        fprintf(stdout,"The student has not been found.\n");
        return -1;
    }
    else if(student_failed(student1))
    {
        fprintf(stdout,"This student did not passed.\n");
        return -1;
    }
    else
    {
        sum+=student1->programming+student1->num_methods+student1->spec_math;
        sum+=student1->data_stuctures+student1->discrete_math;
        return sum/5;
    }
    
}

float calc_average_general(info *student)
{
    info *student1=student;
    float sum=0;
    int cnt=0;
    while(student1!=NULL)
    {
        if(!student_failed(student1))
        {
            sum+=calc_average_student(student1,student1->name);
            cnt++;
        }
        student1=student1->next;
    }
    return sum/cnt;
}

float calc_average_subject(info *student,char subject[])
{
    info *student1=student;
    float sum=0;
    int cnt=0;
    int sub=decode_subject(subject);
    if(sub==-1)
        return -1;
    while(student1!=NULL)
    {
        if(!student_failed(student1))
        {
            switch(sub)
            {
                case 1:
                    sum+=student1->programming;
                    break;
                case 2:
                    sum+=student1->num_methods;
                    break;
                case 3:
                    sum+=student1->spec_math;
                    break;
                case 4:
                    sum+=student1->data_stuctures;
                    break;
                case 5:
                    sum+=student1->discrete_math;
                    break;
            }
            cnt++;
        }
        student1=student1->next;
    }
    return sum/cnt;
}

int count_students_number(info *student)
{
    info *student1=student;
    int cnt=0;
    while(student1!=NULL)
    {
        cnt++;
        student1=student1->next;
    }
    return cnt;
}

int count_students_passed(info *student)
{
    info *student1=student;
    int cnt=0;
    while(student1!=NULL)
    {
        if(!student_failed(student1))
            cnt++;
        student1=student1->next;
    }
    return cnt;
}

int count_students_failed(info *student)
{
    info *student1=student;
    int cnt=0;
    while(student1!=NULL)
    {
        if(student_failed(student1))
            cnt++;
        student1=student1->next;
    }
    return cnt;
}

int count_backlog_students(info *student, char name[])
{
    info *student1=student;
    while(student1!=NULL && strcmp(student->name,name)==0)
        student1=student1->next;
    if(student1==NULL)
    {
        fprintf(stdout,"The student has not been found in database.\n");
        return -1;
    }
    else
    {
        int cnt=0;
        if(student1->programming<5)
            cnt++;
        if(student1->num_methods<5)
            cnt++;
        if(student1->spec_math<5)
            cnt++;
        if(student1->data_stuctures<5)
            cnt++;
        if(student1->discrete_math<5)
            cnt++;
        return cnt;
    }
}

int count_backlog_objects(info *student,char subject[])
{
    info *student1=student;
    int code=decode_subject(subject);
    if(code==-1)
        return -1;
    else
    {
        int cnt=0;
        while(student1!=NULL)
        {
            switch(code)
            {
                case 1:
                    if(student1->programming<5)
                        cnt++;
                    break;
                case 2:
                    if(student1->num_methods<5)
                        cnt++;
                    break;
                case 3:
                    if(student1->spec_math<5)
                        cnt++;
                    break;
                case 4:
                    if(student1->data_stuctures<5)
                        cnt++;
                    break;
                case 5:
                    if(student1->discrete_math<5)
                        cnt++;
                    break;
            }
            student1=student1->next;
        }
        return cnt;
    }
}