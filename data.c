#include <stdio.h>
#include "data.h"
#include <stdlib.h>
#include <string.h>


void copy_char(int offset,int index,char *dest,char *source)
{
    int i,j;
    for(i=offset,j=0;i<index;i++,j++)
        dest[j]=source[i];
    dest[j]='\0';
}

int bring_data(info student[])
{
    int cnt=0;
    FILE *f;
    f=fopen("data.csv","r");
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
                strcpy(student[cnt].name,str1);
            else
            {
                int number=atoi(str1);
                switch(cnt_order)
                {
                    case 2:
                        student[cnt].study_year=number;
                        break;
                    case 3:
                        student[cnt].programming=number;
                        break;
                    case 4:
                        student[cnt].num_methods=number;
                        break;
                    case 5:
                        student[cnt].spec_math=number;
                        break;
                    case 6:
                        student[cnt].data_stuctures=number;
                        break;
                    case 7:
                        student[cnt].discrete_math=number;
                        break;
                }
            }
            cnt_order++;
        }
        cnt++;
    }
    fclose(f);
    return cnt;
}

void mount_data(info student[],int nr)
{
    FILE *f=0;
    f=fopen("data.csv","w");
    for(int i=0;i<nr;i++)
    {
        fprintf(f,"%s,",student[i].name);
        fprintf(f,"%d,%d,%d,%d,%d,%d\n",student[i].study_year,student[i].programming,student[i].num_methods,student[i].spec_math,student[i].data_stuctures,student[i].discrete_math);
    }
    fclose(f);
}