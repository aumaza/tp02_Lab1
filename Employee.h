#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

typedef struct
{
    int file;
    char name[51];
    char lastName[51];
    char sex;
    float salary;
    int idSection;
    int isEmpty;

}Employee;

typedef struct
{
    int id;
    char description[25];

}Section;

int initEmployees(Employee* pEmployee, int len);
int showOneEmployee(Employee* pEmployee);
void initEmployee(Employee* pEmployee, int tam);
int searchFree(Employee* pEmployee, int tam);
int searchEmployee(Employee* pEmployee, int tam, int file);
void addEmployee(Employee* pEmployee, int tam);
void hardcoreSection(Section* pSection);
void showSection(Section* pSection);
//void showEmployee(Employee* pEmployee);
void showEmployees(Employee* pEmployee, int tam);
void showEmployeeByReference(Employee* oneEmployee);
void eraseEmployee(Employee* pEmployee, int tam);
void editEmployeeSalary(Employee* pEmployee, int tam);
void editEmployeeLastName(Employee* pEmployee, int tam);
void editEmployeeName(Employee* pEmployee, int tam);
void hardcoreEmployee(Employee* pEmployee);
void editEmployeeSection(Employee* pEmployee, int tam);
int editMain();
void showEmployeeBySection(Employee* pEmployee, int tam, Section* pSection, int tamSection);
int selectSection(Section* pSection, int tam);
void loadDescription(Section* pSection, int tam, int idSection, char* string);
void sortEmployeesBySectionByName(Employee* pEmployee,int tam, Section* pSection, int tamSection);
void sortEmployeeByNameOrder(Employee* pEmployee, int cant);
void loadDescriptionSection(Section* pSection, int tam, int idSection, char* string);
void showGreatestSalary(Employee* pEmployee, int tam, Section* pSection, int tamSection);
void sortBySalary(Employee* pEmployee, int tam);


/*typedef struct Employee list, *pEmployee;
pEmployee = &list;*/


#endif // EMPLOYEE_H_INCLUDED
