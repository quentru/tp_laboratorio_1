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
    printf("1_Dar de alta a un Empleado\n");
    printf("2_Modificar un Empleado\n");
    printf("3_Dar de baja un Empleado\n");
    printf("4_Listar Empleados\n");
    printf("5_Ordenar empleados\n");
    printf("6_Salir\n");
    getInt(&option, "Que desea hacer\n", "Solo hay 6 opciones\n",1,6);
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
    getInt(&id,"Ingrese el ID de la persona a modificar\n", "lo minimo es 1 y lo maximo es 1000\n", 1, 1000);
    index = findEmployeeById(list, len, id);
    if(list[index].isEmpty==0 && index!=-1)
        {
            printEmployee(list[index]);
            getGenre(&option,"Desea modificar Este usuario??\n", "solo se puede ingresar s o n\n", 's', 'n');
            if(option == 's')
                {
                    printf("1-Nombre\n");
                    printf("2_Apellido\n");
                    printf("3_Salario\n");
                    printf("4_Sector\n");
                    getInt(&optionToModify,"Que desea modificar??\n", "Solo hay 4 opciones\n", 1,4);
                    switch(optionToModify)
                    {
                        case 1:
                            getName(list[index].name,"Reingrese su nombre\n", "Su nombre no puede contener mas de 50 caracteres\n", 1, 50);
                        break;
                        case 2:
                            getName(list[index].lastName,"Reingrese su apellido\n", "Su apellido no puede contener mas de 50 caracteres\n", 1, 50);
                        break;
                        case 3:
                            getFloat(&list[index].salary, "Reingrese su salario\n", "Su sueldo debe ser mayor a 18000 y menor a 1 millon\n", 1800.0, 1000000.0);
                        break;
                        case 4:
                            getInt(&list[index].sector, "Reingrese su sector\n", "Solo hay 4 sectores \n", 1, 4);
                        break;
                        default:
                            printf("Solo se permiten 4 opciones");
                            break;
                    }
                }else
                {
                    reply=-1;
                }
        }else
        {
            printf("No existe un empleado con ese ID \n");
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
    if(list[index].isEmpty==0)
    {
        printEmployee(list[index]);
        getGenre(&option,"Desea dar de baja a este usuario??\n", "solo se puede ingresar s o n\n", 's', 'n');
        if(option=='s')
            {
                        list[index].isEmpty=1;
                        reply=0;
            }else
            {
                printf("No se dio de baja\n");
            }
    }else
    {
        printf("No existe un propietario con ese ID\n");
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
