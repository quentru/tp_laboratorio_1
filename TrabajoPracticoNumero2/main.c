#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#define TAM 1000

int main()
{
    char name[51];
    char lastName[51];
    int id=0;
    int sector, order;
    float salary;
    char exit='n';
    int reply;
    Employee list[TAM];
    reply = initEmployees(list, TAM);
    if(reply==0)
    {
        while(exit=='n')
            {
                switch(menu())
                {
                    case 1:
                        id =  id + 1;
                        printf("Ingrese su nombre\n");
                        fflush(stdin);
                        gets(name);
                        printf("ingrese su apellido\n");
                        fflush(stdin);
                        gets(lastName);
                        printf("Ingrese su salario\n");
                        scanf("%f", &salary);
                        printf("Ingrese su sector\n");
                        scanf("%d", &sector);
                        reply = addEmployee(list, id, name, lastName, salary, sector, TAM);
                        if(reply==0)
                            {
                                printf("Se dio de alta correctamente\n");
                                system("pause");
                                system("cls");
                            }
                        break;
                    case 2:
                        reply = modifyEmployee(list, TAM);
                        if(reply==0)
                            {
                                printf("Se modifico al empleado\n");
                                system("pause");
                                system("cls");
                                break;
                            }
                            break;
                    case 3:
                        printf("Ingrese el ID de la persona a dar de baja\n");
                        scanf("%d", &id);
                        reply=removeEmployee(list, TAM, id);
                        if(reply==0)
                            {
                                printf("Se dio de baja al empleado\n");
                                system("pause");
                                system("cls");
                                break;
                            }
                            break;
                    case 4:
                        printEmployees(list, TAM);
                        system("pause");
                        system("cls");
                        break;
                    case 5:
                        printf("como desea ordenar el array??\n");
                        printf("0_Decendente\n");
                        printf("1_ascendente\n");
                        scanf("%d", &order);
                        reply = sortEmployees(list, TAM, order);
                        if(reply==0)
                            {
                                printf("Se ordenaron los empleados segun su criterio\n");
                                system("pause");
                                system("cls");
                                break;
                            }
                            break;
                    case 6:
                        exit='s';
                        break;
                }
            }
        //printf("Iniciado");

    }else
    {
        printf("Hubo un erroral iniciar");
        return 0;
    }
return 0;
}
