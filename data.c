#include <stdio.h>
#include "data.h"

info *allocation()
{
    info *student=0;
    student=malloc(100*sizeof(info));
    for(int i=0;i<100;i++)
    {
        student[i].name=malloc(20*sizeof(info));
        student[i].study_year=malloc(sizeof(int));
        student[i].math=malloc(sizeof(int));
        student[i].grammar=malloc(sizeof(int));
        student[i].physics=malloc(sizeof(int));
        student[i].chemestry=malloc(sizeof(int));
        student[i].info_tech=malloc(sizeof(int));
    }
    return student;
}

void deallocation(info *student)
{
    for(int i=0;i<100;i++)
    {
        free(student[i].name);
        free(student[i].study_year);
        free(student[i].math);
        free(student[i].grammar);
        free(student[i].physics);
        free(student[i].chemestry);
        free(student[i].info_tech);
    }
    free(student);
}

int bring_data(info *student)
{
    FILE *f=0;
    f=fopen('data.txt','w');
    while(!EOF)
    {
        
    }
}