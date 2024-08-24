#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "runtime.h"
#include "data.h"

int main(int argc,char *argv[])
{
    //if(argc==1)
        printf("Program code loaded. Please use argument commands to continue using the program.\n");
    //else
    //{
        info student[100];
        int nr;
        nr=bring_data(student);
        //if(str_equal(argv[1],"-help"))
            //help_menu_run(argc,argv);
        //if(str_equal(argv[1],"-add_data"))
            add_data(student,nr);
        mount_data(student,nr);
    //}
    
    return 0;
}
