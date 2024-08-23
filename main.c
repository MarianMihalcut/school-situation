#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "runtime.h"
#include "data.h"

int main(int argc,char *argv[])
{
    if(argc==1)
        printf("Program code loaded. Please use argument commands to continue using the program.\n");
    else
    {
        if(str_equal(argv[1],"-help"))
            help_menu_run(argc,argv);
        if(str_equal(argv[1],"-add_data"))
        {
            info *student;
            student=allocation();
            int nr;
            nr=bring_data(student);
            for(int i=0;i<nr;i++)
            {
                fprintf(stdout,"%s\n",student[i].name);
                fprintf(stdout,"%d %d %d %d %d %d %d",student[i].study_year,student[i].programming,student[i].num_methods,student[i].spec_math,student[i].data_stuctures,student[i].discrete_math);
                fprintf(stdout,"\n\n");
            }
            deallocation(student);
        }
    }
    //need to work on data stored in student pointer
    return 0;
}
