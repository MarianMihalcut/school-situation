#ifndef DATA_H_
#define DATA_H_

typedef struct _info
{
    char *name;
    int study_year;
    int math;
    int grammar;
    int physics;
    int chemestry;
    int info_tech;
}info;

info *allocation();
void deallocation(info *student);
void collect_data(info *student);




#endif