#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
    int value=-1;
    for(int i=0;i<len; i++)
        {
            list[i].isEmpty=1;
        }
        value=0;
        return value;
}
/** \brief  show the options the user have
*
* \return int Return the option choosen
*
*/
int menu()
{
    int option;
    printf("Que desea hacer??\n");
    printf("1_Dar de alta a un Empleado\n");
    printf("2_Modificar un Empleado\n");
    printf("3_Dar de baja un Empleado\n");
    printf("4_Listar Empleados\n");
    printf("5_Salir\n");
    scanf("%d", &option);
    return option;
}
/** \brief find an array lenght free and return it.
*
* \param list Employee
*
* \param len int
*
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findFree(Employee * list, int len)
{
    int index=-1;
    for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
                {
                    index=i;
                    return index;
                }
        }
        return index;
}
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee
*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int addEmployee(Employee* list, int id, char name[], char lastName[], float salary, int sector, int len)
{
    int reply=0;
    int index;
    index=findFree(list, len);
    if(index!=-1)
        {
            list[index].id=id;
            strcpy(list[index].name, name);
            strcpy(list[index].lastName, lastName);
            list[index].salary = salary;
            list[index].sector = sector;
            list[index].isEmpty=0;
        }else
        {
            printf("No hay espacio en el sistema");
            reply=-1;
        }
        return reply;
}
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee
*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len, int id)
{
    int index=-1;
    for(int i=0; i<len; i++)
        {
            if(list[i].id==id)
                {
                    index=i;
                    return index;
                }
        }
        return index;
}
/** \brief modify an Employe array and let you choose what field do you want change
*
* \param list Employee
*
* \param len int
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int modifyEmployee(Employee* list, int len)
{
    char option;
    int id, index, optionToModify, reply = 0;
    printf("Ingrese el ID de la persona a modificar\n");
    scanf("%d", &id);
    index = findEmployeeById(list, len, id);
    printEmployee(list[index]);
    printf("Desea modificar Este usuario??\n");
    fflush(stdin);
    scanf("%c", &option);
    if(option == 's')
        {
            printf("Que desea modificar??\n");
            printf("1-Nombre\n");
            printf("2_Apellido\n");
            printf("3_Salario\n");
            printf("4_Sector\n");
            scanf("%d", &optionToModify);
            switch(optionToModify)
            {
                case 1:
                    printf("Reingrese su nombre\n");
                    fflush(stdin);
                    gets(list[index].name);
                break;
                case 2:
                    printf("Reingrese su apellido\n");
                    fflush(stdin);
                    gets(list[index].lastName);
                break;
                case 3:
                    printf("Reingrese su salario\n");
                    scanf("%f", &list[index].salary);
                break;
                case 4:
                    printf("Reingrese su sector");
                    scanf("%d", &list[index].sector);
                break;
                default:
                    printf("Solo se permiten 4 opciones");
                    break;
            }
        }else
        {
            reply=-1;
        }
    return reply;
}

/** \brief print the content of an employee array
*
* \param list Employee
*
*/
void printEmployee(Employee list)
{
    printf("ID\t Nombre\t Apellido\t salario\t sector\n");
    printf("%d\t %s\t %s\t %f\t %d\n", list.id, list.name, list.lastName, list.salary, list.sector);
}
/** \brief print the content of employees array
*
* \param list Employee
*
* \param length int
*
*/
void printEmployees(Employee* list, int len)
{
    int flag=0;
    for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
                {
                    flag=1;
                    printEmployee(list[i]);
                }
        }
        if(flag==0)
            {
                printf("No hay empleados para mostrar\n");
            }
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee
*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
    char option;
    int index=0;
    int reply=-1;
    index = findEmployeeById(list, len, id);
    printEmployee(list[index]);
    printf("Desea darle de baja a este usuario??\n");
    fflush(stdin);
    scanf("%c", &option);
    if(option=='s')
        {
            if(index!=-1)
                {
                     list[index].isEmpty=1;
                     reply=0;
                }else
                {
                    printf("No existe un propietario con ese id\n");
                }
        }else
        {
            return reply;
        }
        return reply;
}
/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
*
* \param list Employee
*
* \param len int
* \param order int  [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
    int reply=-1;
    Employee auxiliary;
    if(order==0)
        {
            for(int i=0; i<len-1; i++)
                {
                    for(int j=i+1; j<len; j++)
                    {
                        if(strcmp(list[i].lastName, list[j].lastName)<0)
                            {
                                auxiliary=list[i];
                                list[i]=list[j];
                                list[j]=auxiliary;
                                reply=0;
                            }
                            if(strcmp(list[i].lastName, list[j].lastName)==0)
                                {
                                    if(list[i].sector<list[j].sector)
                                        {
                                            auxiliary=list[i];
                                            list[i]=list[j];
                                            list[j]=auxiliary;
                                            reply=0;
                                        }
                                }
                    }
            }
            }else
            {
                for(int i=0; i<len-1; i++)
                    {
                        for(int j=i+1; j<len; j++)
                        {
                            if(strcmp(list[i].lastName, list[j].lastName)>0)
                                {
                                    auxiliary=list[i];
                                    list[i]=list[j];
                                    list[j]=auxiliary;
                                    reply=0;
                                }
                                if(strcmp(list[i].lastName, list[j].lastName)==0)
                                    {
                                        if(list[i].sector>list[j].sector)
                                            {
                                                auxiliary=list[i];
                                                list[i]=list[j];
                                                list[j]=auxiliary;
                                                reply=0;
                                            }
                                    }
                        }
                    }
            }
return reply;
}
