#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "runtime.h"

int main(int argc,char *argv[])
{
    if(argc==1)
        printf("Program code loaded. Please use argument commands to continue using the program.\n");
    else
    {
        if(str_equal(argv[1],"-help"))
            help_menu_run(argc,argv);
    }
    return 0;
}
