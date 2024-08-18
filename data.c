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

}

void collect_data(info *student)
{
    
}