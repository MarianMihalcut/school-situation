#include <stdio.h>
#include "data.h"
#include <stdlib.h>

info *allocation()
{
    info *student=0;
    student=(info *) malloc(100*sizeof(info));
    for(int i=0;i<100;i++)
        student[i].name=(char *) malloc(20*sizeof(char));
    return student;
}

void deallocation(info *student)
{
    for(int i=0;i<100;i++)
        free(student[i].name);
    free(student);
}

void copy_char(int offset,int index,char *dest,char *source)
{
    int i,j;
    for(i=offset,j=0;i<index;i++,j++)
        dest[j]=source[i];
    dest[j]='\0';
}

void bring_data(info *student)
{
    int cnt=0;
    FILE *f;
    char *str=0;
    str=(char *) malloc(50*sizeof(char));
    f=fopen("data.csv","r");
    char name[50];
    int year,mat1,mat2,mat3,mat4,mat5;
    while(year)
    {
        printf("Code success!");
        /*int offset=0;
        char *str1=0;
        str1=(char *) malloc(50*sizeof(char));
        while(str[offset]!='\0')
        {
            int index=offset+1;
            while(str[index]!=',' && str[index]!='\0')
                index++;
            copy_char(offset,index,str1,str);
            if(str[index]=='\0')
                offset=index;
            else
                offset=index+1;
            fprintf(stdout,"%s\n",str1);
        }*/
    }
    //needs work on extracting data from csv 
}