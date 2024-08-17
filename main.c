#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "runtime.h"

int main(int argc,char *argv[])
{
    for(int i=1;i<argc;i++)
        printf("%s\n",argv[i]);
    if(argc==1)
        printf("Program code loaded. Please use argument commands to continue using the program.\n");
    else
    {
        if(str_equal("-help",argv[1]))
            help_menu_run(argc,argv);
    }
    return 0;
}
