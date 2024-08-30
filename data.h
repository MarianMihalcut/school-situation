#ifndef DATA_H_
#define DATA_H_

//data is saved if it's given as argument and returned

typedef struct _info
{
    char name[20];
    int study_year;
    int programming;
    int num_methods;
    int spec_math;
    int data_stuctures;
    int discrete_math;
    struct _info *next;
}info;

info *allocate_elem();
info *insert_elem(info *student,char name[],int year,int mat1,int mat2,int mat3,int mat4,int mat5);
info *delete_between(info *student); //pointer before that which is deleted
info *delete_front(info *student);
info *delete_tail(info *student); //pointer before the last

void copy_char(int offset,int index,char *dest,char *source);
info *bring_data(info *student);
void mount_data(info *student);

#endif