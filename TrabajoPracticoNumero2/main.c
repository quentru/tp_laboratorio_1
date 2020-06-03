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
    int sector, order, flag=0;
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
                        getName(name,"Ingrese su nombre\n", "Su nombre no puede contener mas de 50 caracteres\n", 1, 50);
                        getName(lastName,"Ingrese su apellido\n", "Su apellido no puede contener mas de 50 caracteres\n", 1, 50);
                        getFloat(&salary, "Ingrese su salario\n", "Su sueldo debe ser mayor a 18000 y menor a 1 millon\n", 1800.0, 1000000.0);
                        getInt(&sector, "Ingrese su sector\n", "Solo hay 4 sectores \n", 1, 4);
                        reply = addEmployee(list, id, name, lastName, salary, sector, TAM);
                        flag=1;
                        if(reply==0)
                            {
                                printf("Se dio de alta correctamente\n");
                                system("pause");
                                system("cls");
                            }
                        break;
                    case 2:
                        if(flag==1)
                        {
                            reply = modifyEmployee(list, TAM);
                            if(reply==0)
                                {
                                    printf("Se modifico al empleado\n");
                                    system("pause");
                                    system("cls");
                                    break;
                                }
                        }else
                        {
                            printf("No se ingreso ningun usuario\n");
                            system("pause");
                            system("cls");
                        }
                        break;
                    case 3:
                        if(flag==1)
                        {
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
                        }else
                        {
                            printf("No se ingreso ningun usuario\n");
                            system("pause");
                            system("cls");
                        }
                            break;
                    case 4:
                        if(flag==1)
                        {
                            printEmployees(list, TAM);
                            system("pause");
                            system("cls");
                        }else
                        {
                            printf("No se ingreso ningun usuario\n");
                            system("pause");
                            system("cls");
                        }
                        break;
                    case 5:
                        if(flag==1)
                        {
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
                        }else
                        {
                            printf("No se ingreso ningun usuario\n");
                            system("pause");
                            system("cls");
                        }
                            break;
                    case 6:
                        exit='s';
                        break;
                }
            }

    }else
    {
        printf("Hubo un error al iniciar\n");
        return 0;
    }
return 0;
}
