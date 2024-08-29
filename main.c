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
            student=add_data(student);
        if(str_equal(argv[1],"-list"))
        {
            if(argc==2)
                list_all(student);
            else if(argc==3 && str_equal(argv[2],"--field"))
                printf("Please run the command again and provide a name for search.");
            else if(argc==4 && str_equal(argv[2],"--field"))
                list_field(student,argv[3]);
        }
        if(str_equal(argv[1],"-del"))
        {
            if(argc==2)
                student=delete_all(student);
            else if(argc==3 && str_equal(argv[2],"--field"))
                printf("Please run the command again and provide a name for deletion.");
            else if(argc==4 && str_equal(argv[2],"--field"))
                student=delete_field(student,argv[3]);
        }
        mount_data(student);
    }
    return 0;
}
