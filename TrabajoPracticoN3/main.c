#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char continuar='s';
    int flagArchivoCargado=0;
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    while(continuar=='s'){
    printf("Que desea hacer??\n");
    printf("1_Cargar datos desde el archivo data.csv\n");
    printf("2_Cargar datos desde el archivo data.bin\n");
    printf("3_Listar empleados\n");
    printf("4_Dar de alta a un empleado\n");
    printf("5_Modificar empleado\n");
    printf("6_Dar de baja a un empleado\n");
    printf("7_Ordenar alfabeticamente a los empleados\n");
    printf("8_Guardar datos desde un archivo de texto\n");
    printf("9_Guardar datos en binario\n");
    printf("10_Salir\n");
    getInt(&option, "Ingrese una opcion\n", "Solo hay 10 opciones\n", 1, 10);
        switch(option)
        {
            case 1:
                if(flagArchivoCargado!=0)
                    {
                        printf("Error, ya se cargo una vez el archivo\n");
                        system("pause");
                        system("cls");
                    }
                    else if(controller_loadFromText("data.csv", listaEmpleados))
                        {
                            flagArchivoCargado=1;
                            printf("se leyo correctamente\n");
                            system("pause");
                            system("cls");
                        }
                    break;
            case 2:
                if(flagArchivoCargado!=0)
                    {
                        printf("Error, ya se cargo una vez el archivo\n");
                        system("pause");
                        system("cls");
                    }
                    else if(controller_loadFromBinary("data.bin", listaEmpleados))
                        {
                            flagArchivoCargado=1;
                            printf("se leyo correctamente\n");
                            system("pause");
                            system("cls");
                        }
                    break;
            case 3:
                if(controller_ListEmployee(listaEmpleados))
                    {
                        printf("se listo correctamente\n");
                        system("pause");
                        system("cls");
                    }
                    break;
            case 4:
                if(controller_addEmployee(listaEmpleados))
                    {
                        printf("Se dio de alta correctamente\n");
                        system("pause");
                        system("cls");
                    }
                    break;
            case 5:
                if(controller_editEmployee(listaEmpleados))
                    {
                        printf("Se modifico correctamente\n");
                        system("pause");
                        system("cls");
                    }
                    break;
            case 6:
                if(controller_removeEmployee(listaEmpleados))
                    {
                        printf("Se dio de baja correctamente\n");
                        system("pause");
                        system("cls");
                    }
                break;
            case 7:
                if(controller_sortEmployee(listaEmpleados))
                    {
                        printf("Se ordeno alfabeticamente la lista\n");
                        system("pause");
                        system("cls");
                    }
                break;
            case 8:
                if(controller_saveAsText("data.csv",listaEmpleados))
                   {
                        printf("Se guardo correctamente en el archivo de texto\n");
                        system("pause");
                        system("cls");
                   }
                   break;
            case 9:
                if(controller_saveAsBinary("data.bin",listaEmpleados))
                   {
                        printf("Se guardo correctamente en el archivo binario\n");
                        system("pause");
                        system("cls");
                   }
                   break;
            case 10:
                continuar='n';
                break;
        }
        }
    return 0;
}
