#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "runtime.h"
#include "data.h"

// Please do not touch data.csv!!!

int main(int argc,char *argv[])
{
    if(argc==1)
        printf("Program code loaded. Please use argument commands to continue using the program.\n");
    else
    {
        info *student=0;
        student=bring_data(student);
        if(str_equal(argv[1],"-help"))
            help_menu_run(argc,argv);
        if(str_equal(argv[1],"-add_data"))
        {
            student=add_data(student);
            mount_data(student);
        }
        if(str_equal(argv[1],"-list"))
        {
            if(argc==2)
                list_all(student);
            else if(argc==3 && str_equal(argv[2],"--field"))
                printf("Please run the command again and provide a name for search.");
            else if(argc==4 && str_equal(argv[2],"--field"))
                list_field(student,argv[3]);
            mount_data(student);
        }
        if(str_equal(argv[1],"-del"))
        {
            if(argc==2)
                student=delete_all(student);
            else if(argc==3 && str_equal(argv[2],"--field"))
                printf("Please run the command again and provide a name for deletion.");
            else if(argc==4 && str_equal(argv[2],"--field"))
                student=delete_field(student,argv[3]);
            mount_data(student);
        }
        if(str_equal(argv[1],"-calc"))
        {
            if(argc==2)
                fprintf(stdout,"Please provide a flag: --general,--student or --subject");
            else if(argc==3)
            {
                if(str_equal(argv[2],"--general"))
                    fprintf(stdout,"The general average is: %.2f\n",calc_average_general(student));
                else
                    fprintf(stdout,"Please provide a name or subject!\n");
            }
            else if(argc==4)
            {
                if(str_equal(argv[2],"--student"))
                {
                    float result=calc_average_student(student,argv[3]);
                    if(result!=-1)
                        fprintf(stdout,"The average is: %.2f\n",result);
                }
                if(str_equal(argv[2],"--subject"))
                {
                    float result=calc_average_subject(student,argv[3]);
                    if(result!=-1)
                        fprintf(stdout,"The average of subject is: %.2f\n",result);
                }
            }
        }
        
    }
    return 0;
}
