#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

/*typedef struct Employee list, *pEmployee;
pEmployee = &list;*/




#endif // EMPLOYEE_H_INCLUDED
