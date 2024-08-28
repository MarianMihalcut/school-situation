#include <stdio.h>
#include "data.h"
#include <stdlib.h>
#include <string.h>

info *allocate_elem()
{
    info *p=(info *) malloc(sizeof(info));
    p->next=NULL;
    return p;
}

info *insert_elem(info *student,char name[],int year,int mat1,int mat2,int mat3,int mat4,int mat5)
{
    if(student==NULL)
    {
        student=allocate_elem();
        strcpy(student->name,name);
        student->study_year=year;
        student->programming=mat1;
        student->num_methods=mat2;
        student->spec_math=mat3;
        student->data_stuctures=mat4;
        student->discrete_math=mat5;
    }
    else
    {
        info *student1=NULL;
        student1=allocate_elem();
        strcpy(student1->name,name);
        student1->study_year=year;
        student1->programming=mat1;
        student1->num_methods=mat2;
        student1->spec_math=mat3;
        student1->data_stuctures=mat4;
        student1->discrete_math=mat5;
        student1->next=student;
        student=student1;
    }
    return student;
}

void copy_char(int offset,int index,char *dest,char *source)
{
    int i,j;
    for(i=offset,j=0;i<index;i++,j++)
        dest[j]=source[i];
    dest[j]='\0';
}

info *bring_data(info *student)
{
    int cnt=0;
    FILE *f=0;
    f=fopen("data.csv","r");
    if(0==f)
        fprintf(stdout,"Failed to open file");
    char name[50];
    int year,mat1,mat2,mat3,mat4,mat5;
    while(!feof(f))
    {
        char *str=0;
        str=(char *) malloc(50*sizeof(char));
        fscanf(f,"%s",str);
        //fprintf(stdout,"\n%s",str);
        int offset=0;
        char *str1=0;
        str1=(char *) malloc(50*sizeof(char));
        int cnt_order=1;
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
            //fprintf(stdout,"%s\n",str1);
            if(cnt_order==1)
                strcpy(name,str1);
            else
            {
                int number=atoi(str1);
                switch(cnt_order)
                {
                    case 2:
                        year=number;
                        break;
                    case 3:
                        mat1=number;
                        break;
                    case 4:
                        mat2=number;
                        break;
                    case 5:
                        mat3=number;
                        break;
                    case 6:
                        mat4=number;
                        break;
                    case 7:
                        mat5=number;
                        break;
                }
            }
            cnt_order++;
        }
        cnt++;
        student=insert_elem(student,name,year,mat1,mat2,mat3,mat4,mat5);
    }
    fclose(f);
    return student;
}

void mount_data(info *student)
{
    FILE *f=0;
    f=fopen("data.csv","w");
    while(student!=NULL)
    {
        fprintf(f,"%s,",student->name);
        if(student->next==NULL)
            fprintf(f,"%d,%d,%d,%d,%d,%d",student->study_year,student->programming,student->num_methods,student->spec_math,student->data_stuctures,student->discrete_math);
        else
            fprintf(f,"%d,%d,%d,%d,%d,%d\n",student->study_year,student->programming,student->num_methods,student->spec_math,student->data_stuctures,student->discrete_math);
        student=student->next;
    }
    fclose(f);
}