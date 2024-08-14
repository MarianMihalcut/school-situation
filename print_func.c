#include <stdio.h>
#include <print_func.h>

//listing commands
void help_add_data()
{
    printf("Command: ./main -add_data\n");
    printf("When command is executed, a prompt collecting and adding data will appear.");
    printf("\n Will print the name, the study year and grades for specific subjects(avalaible in this program)\n");
}

void list_field()
{
    printf("Command: ./main -list --field <name>\n");
    printf("Lists the grades for a student given from command.\n");
    printf("Prints an error if the student was not found.\n");
}

void list_table()
{
    printf("Command: ./main -list \n");
    printf("Lists the whole table memorized in table.txt.\n");
}

void delete_field()
{
    printf("Command: ./main -del --field <name>\n");
    printf("Deletes a specific field with a given name. The command is irreversible.\n");
}

void delete_all()
{
    printf("Command: ./main -del\n");
    printf("Deletes the whole table.txt file. Deletion is irreversible.\n");
}

//for calculations
void calc_average_student()
{
    printf("Command: ./main -calc --student <name>\n");
    printf("Calculates the average from the grades of a specified student.\n");
    printf("Pass criteria is to have at least 5 at all objects.\n");
}

void calc_average_general()
{
    printf("Command: ./main -calc --general\n");
    printf("Calculates firstly the average of each students.\n");
    printf("Then adds the results and divide them by total number of students.\n");
    printf("This command is statistical.\n");
}

void calc_average_subject()
{
    printf("Command: ./main -calc --subject <subject_name>\n");
    printf("Calculates the average of all grades for a subject.\n");
    printf("This command is statistical.\n");
}

void count_students_number()
{
    printf("Command: ./main -count -stud_num\n");
    printf("Counts all of the students available in the database.\n");
}

void count_students_passed()
{
    printf("Command: ./main -count -stud_pass\n");
    printf("Counts all of students that passed the semester.\n");
    printf("Pass condition: have at least 5 on all grades.\n");
}

