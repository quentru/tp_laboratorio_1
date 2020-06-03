#include "inc/input.h"
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int menu();
int initEmployees(Employee* list, int len);
int findFree(Employee* list, int len);
int addEmployee(Employee* list, int id, char name[], char lastName[], float salary, int sector, int len);
int findEmployeeById(Employee* list, int len, int id);
int modifyEmployee(Employee* list, int len);
void printEmployee(Employee list);
void printEmployees(Employee* list, int len);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
