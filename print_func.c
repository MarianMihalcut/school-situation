#include <stdio.h>
#include "print_func.h"

//needs a help before each command
//listing commands
void help_add_data()
{
    printf("Command: ./main -add_data\n");
    printf("When command is executed, a prompt collecting and adding data will appear.");
    printf("\n Will print the name, the study year and grades for specific subjects(avalaible in this program)\n");
}

void help_list_field()
{
    printf("Command: ./main -list --field <name>\n");
    printf("Lists the grades for a student given from command.\n");
    printf("Prints an error if the student was not found.\n");
}

void help_list_table()
{
    printf("Command: ./main -list \n");
    printf("Lists the whole table memorized in table.txt.\n");
}

void help_delete_field()
{
    printf("Command: ./main -del --field <name>\n");
    printf("Deletes a specific field with a given name. The command is irreversible.\n");
}

void help_delete_all()
{
    printf("Command: ./main -del\n");
    printf("Deletes the whole table.txt file. Deletion is irreversible.\n");
}

//for calculations
void help_calc_average_student()
{
    printf("Command: ./main -calc --student <name>\n");
    printf("Calculates the average from the grades of a specified student.\n");
    printf("Pass criteria is to have at least 5 at all objects.\n");
}

void help_calc_average_general()
{
    printf("Command: ./main -calc --general\n");
    printf("Calculates firstly the average of each students.\n");
    printf("Then adds the results and divide them by total number of students.\n");
    printf("This command is statistical.\n");
}

void help_calc_average_subject()
{
    printf("Command: ./main -calc --subject <subject_name>\n");
    printf("Calculates the average of all grades for a subject.\n");
    printf("This command is statistical.\n");
}

void help_count_students_number()
{
    printf("Command: ./main -count -stud_num\n");
    printf("Counts all of the students available in the database.\n");
}

void help_count_students_passed()
{
    printf("Command: ./main -count -stud_pass\n");
    printf("Counts all of students that passed the semester.\n");
    printf("Pass condition: have at least 5 on all grades.\n");
}

void help_count_students_failed()
{
    printf("Command: ./main -count -stud_fail\n");
    printf("Counts all of student that didn't make it.\n");
    printf("Info: counts all students having at least 1 object with a grade below 5.\n");
}

void help_count_backlog_students()
{
    printf("Command: ./main -count -bck --student <name>\n");
    printf("Counts all of the subjects that a student didn't passed.\n");
}

void help_count_backlog_objects()
{
    printf("Command: ./main -count -bck --object <name>\n");
    printf("Counts all of the students that didn't passed a specific subject.\n");
}

//listing all commands
void help_menu()
{
    printf("For each command,./main -help <command_name>\n");
    printf("Command names for help menu:\n");
    printf("For adding data: add_data\n");
    printf("To list a student with his grades: list_field\n");
    printf("To list the whole table: list_table\n");
    printf("To delete a student with his grades: delete_field\n");
    printf("To delete the whole table:delete_all\n");
    printf("Calculating a student's average: calc_stud_avg\n");
    printf("Calculating general average: calc_gen_avg\n");
    printf("Calculating a subject average: calc_sub_avg\n");
    printf("Counting all students: cnt_stud\n");
    printf("Counting all students that passed the semester: cnt_stud_pass\n");
    printf("Counting all students that failed: cnt_stud_fail\n");
    printf("Counting all of failed objects of a student: cnt_bck_stud\n");
    printf("Counting all failed students at an object: cnt_bck_obj\n");
}

