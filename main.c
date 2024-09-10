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
        else if(str_equal(argv[1],"-add_data"))
        {
            student=add_data(student);
            mount_data(student);
        }
        else if(str_equal(argv[1],"-list"))
        {
            if(argc==2)
                list_all(student);
            else if(argc==3 && str_equal(argv[2],"--field"))
                printf("Please run the command again and provide a name for search.");
            else if(argc==4 && str_equal(argv[2],"--field"))
                list_field(student,argv[3]);
            mount_data(student);
        }
        else if(str_equal(argv[1],"-del"))
        {
            if(argc==2)
                student=delete_all(student);
            else if(argc==3 && str_equal(argv[2],"--field"))
                printf("Please run the command again and provide a name for deletion.");
            else if(argc==4 && str_equal(argv[2],"--field"))
                student=delete_field(student,argv[3]);
            mount_data(student);
        }
        else if(str_equal(argv[1],"-calc"))
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
        else if(str_equal(argv[1],"-count"))
        {
            if(argc==2)
                fprintf(stdout,"Please add a flag and eventually a name/subject!\n");
            else if(argc==3 && !str_equal(argv[2],"-bck"))
            {   
                if(str_equal(argv[2],"-stud_num"))
                    fprintf(stdout,"%d\n",count_students_number(student));
                else if(str_equal(argv[2],"-stud_pass"))
                    fprintf(stdout,"%d\n",count_students_passed(student));
                else if(str_equal(argv[2],"-stud_fail"))
                    fprintf(stdout,"%d\n",count_students_failed(student));
            }
            else if((argc==3 || argc==4) && str_equal(argv[2],"-bck"))
                fprintf(stdout,"Please do not forget to insert a flag and/or a name/subject.");
            else if(argc==5 && str_equal(argv[2],"-bck"))
            {
                if(str_equal(argv[3],"--student"))
                    fprintf(stdout,"%d\n",count_backlog_students(student,argv[4]));
                if(str_equal(argv[3],"--object"))
                    fprintf(stdout,"%d\n",count_backlog_objects(student,argv[4]));
            }
        }
        else
            fprintf(stdout,"Please check the help menu for the correct commands.");
    }
    return 0;
}
