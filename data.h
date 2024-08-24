#ifndef DATA_H_
#define DATA_H_

typedef struct _info
{
    char name[20];
    int study_year;
    int programming;
    int num_methods;
    int spec_math;
    int data_stuctures;
    int discrete_math;
}info;

void copy_char(int offset,int index,char *dest,char *source);
int bring_data(info student[]);
void mount_data(info student[],int nr);




#endif