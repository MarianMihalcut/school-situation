#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "runtime.h"
#include "data.h"

int main(int argc,char *argv[])
{
    //if(argc==1)
        //printf("Program code loaded. Please use argument commands to continue using the program.\n");
    //else
    //{
        info *student=0;
        student=bring_data(student);
        //if(str_equal(argv[1],"-help"))
            //help_menu_run(argc,argv);
        //if(str_equal(argv[1],"-add_data"))
            //add_data(student);
            char name[20];
        fscanf(stdin,"%s",name);
        student=insert_elem(student,name,3,10,10,4,9,10);
        mount_data(student);
    //}
    return 0;
}
