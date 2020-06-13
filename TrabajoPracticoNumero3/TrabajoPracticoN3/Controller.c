#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int valorDeRetorno=0;
    FILE* NuevoArchivo;
    NuevoArchivo=fopen(path, "r");
    if(NuevoArchivo!=NULL && pArrayListEmployee!=NULL)
    {
        if(parser_EmployeeFromText(NuevoArchivo, pArrayListEmployee))
            {
                valorDeRetorno=1;
            }
    }
    return valorDeRetorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int valorDeRetorno=0;
    FILE* NuevoArchivo;
    NuevoArchivo=fopen(path, "rb");
    if(NuevoArchivo!=NULL && pArrayListEmployee!=NULL)
    {
        if(parser_EmployeeFromBinary(NuevoArchivo, pArrayListEmployee))
            {
                valorDeRetorno=1;
            }
    }
    return valorDeRetorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int auxHorasTrabajadas, auxSueldo, auxId, valorDeRetorno=0;
    int len = ll_len(pArrayListEmployee);
    char auxNombre[50];
    Employee* auxiliar = employee_new();
    Employee* nuevoEmpleado;
    nuevoEmpleado = employee_new();
    for(int i=0;i<len; i++)
        {
            if(i == len-1)
                {
                    auxiliar = ll_get(pArrayListEmployee, i);
                }
        }
        auxId = auxiliar->id + 1;
        if(employee_setId(nuevoEmpleado, auxId))
        {
            printf("ingrese su nombre\n");
            fflush(stdin);
            scanf("%s", auxNombre);
            if(employee_setNombre(nuevoEmpleado, auxNombre))
            {
                printf("Ingrese sus horas trabajadas\n");
                scanf("%d", &auxHorasTrabajadas);
                if(employee_setHorasTrabajadas(nuevoEmpleado, auxHorasTrabajadas))
                {
                    printf("Ingrese su sueldo\n");
                    scanf("%d", &auxSueldo);
                    if(employee_setSueldo(nuevoEmpleado, auxSueldo))
                    {
                        ll_add(pArrayListEmployee, nuevoEmpleado);
                        valorDeRetorno=1;
                    }
                }
            }
        }
    return valorDeRetorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char eleccion;
    char auxNombre[50];
    Employee* auxiliar = employee_new();
    int len = ll_len(pArrayListEmployee);
    int id, opcion, auxHorasTrabajadas, flag=0,auxSueldo,valorDeRetorno=0;
    printf("Ingrese el ID de la persona a modificar\n");
    scanf("%d", &id);
    for(int i=0; i<len;i++)
        {
            auxiliar = ll_get(pArrayListEmployee, i);
            if(auxiliar->id == id)
            {
            printf("Desea modificar este usuario?? 's' o 'n'\n");
            printf("%d  %s  %d  %d\n", auxiliar->id, auxiliar->nombre, auxiliar->horasTrabajadas, auxiliar->sueldo);
            fflush(stdin);
            scanf("%c", &eleccion);
            if(eleccion=='s')
                {
                        flag=1;
                        valorDeRetorno=1;
                        printf("Que desea modificar\n");
                        printf("1_Nombre\n");
                        printf("2_Horas Trabajadas\n");
                        printf("3_Sueldo\n");
                        scanf("%d",&opcion);
                        switch(opcion)
                        {
                        case 1:
                            printf("Ingrese su nuevo nombre\n");
                            fflush(stdin);
                            scanf("%s", auxNombre);
                            employee_setNombre(auxiliar, auxNombre);
                            break;
                        case 2:
                            printf("Ingrese su nueva cantidad de horas trabajadas\n");
                            scanf("%d", &auxHorasTrabajadas);
                            employee_setHorasTrabajadas(auxiliar, auxHorasTrabajadas);
                            break;
                        case 3:
                            printf("Reingrese su nuevo sueldo\n");
                            scanf("%d", &auxSueldo);
                            employee_setSueldo(auxiliar, auxSueldo);
                            break;
                        }
                    }else if(eleccion=='n')
                    {
                        flag=1;
                        printf("Modificacion cancelada\n");
                        system("pause");
                        system("cls");
                        break;

                    }else
                    {
                        flag=1;
                        printf("No existe esa opcion\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                }
        }
        if(!flag)
            {
                printf("No existe un empleado con ese ID\n");
                system("pause");
                system("cls");
                valorDeRetorno=0;
            }
        return valorDeRetorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    char eleccion;
    Employee* auxiliar = employee_new();
    int len = ll_len(pArrayListEmployee);
    int id, flag=0,valorDeRetorno=0;
    printf("Ingrese el ID de la persona a dar de baja\n");
    scanf("%d", &id);
    for(int i=0; i<len;i++)
        {
            auxiliar = ll_get(pArrayListEmployee, i);
            if(auxiliar->id == id)
            {
            printf("Desea dar de baja este usuario?? 's' o 'n'\n");
            printf("%d  %s  %d  %d\n", auxiliar->id, auxiliar->nombre, auxiliar->horasTrabajadas, auxiliar->sueldo);
            fflush(stdin);
            scanf("%c", &eleccion);
            if(eleccion=='s')
                {
                        flag=1;
                        ll_remove(pArrayListEmployee,i);
                    }else if(eleccion=='n')
                    {
                        flag=1;
                        printf("Baja cancelada\n");
                        system("pause");
                        system("cls");
                        break;

                    }else
                    {
                        flag=1;
                        printf("No existe esa opcion\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                }
        }
        if(!flag)
            {
                printf("No existe un empleado con ese ID\n");
                system("pause");
                system("cls");
                valorDeRetorno=0;
            }
        return valorDeRetorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    char auxNombre[50];
    int valorDeRetorno=0;
    int auxId;
    int auxSueldo;
    int auxHorasTrabajadas;
    int len=ll_len(pArrayListEmployee);
    Employee* aux = employee_new();
    if(aux!=NULL)
        {
            //printf("ID   Nombre   Horas Trabajadas    Sueldo\n");
            for(int i=0; i<len; i++)
                {
                    aux = ll_get(pArrayListEmployee, i);
                    employee_getId(aux, &auxId);
                    employee_getNombre(aux, auxNombre);
                    employee_getHorasTrabajadas(aux, &auxHorasTrabajadas);
                    employee_getSueldo(aux, &auxSueldo);
                    printf("%d  %s  %d  %d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
                    valorDeRetorno=1;
                }

        }
    return valorDeRetorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleadoA=employee_new();
    Employee* empleadoB=employee_new();
    Employee* empleadoAuxiliar=employee_new();
    int valorDeRetorno=0,len = ll_len(pArrayListEmployee);
    if(pArrayListEmployee!=NULL && empleadoA!=NULL && empleadoB!=NULL && empleadoAuxiliar!=NULL)
        {
            valorDeRetorno=1;
            for(int i=0;i<len-1;i++)
                {
                    for(int j=i+1;j<len;j++)
                        {
                            empleadoA = ll_get(pArrayListEmployee,i);
                            empleadoB = ll_get(pArrayListEmployee,j);
                            if(strcmp(empleadoA->nombre, empleadoB->nombre)>0)
                                {
                                    *empleadoAuxiliar = *empleadoA;
                                    *empleadoA = *empleadoB;
                                    *empleadoB=*empleadoAuxiliar;
                                }
                        }
                }

        }
    return valorDeRetorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int valorDeRetorno=0;
    int len = ll_len(pArrayListEmployee);
    FILE* nuevoArchivo;
    nuevoArchivo=fopen(path, "w");
    Employee* nuevoEmpleado;
    if(nuevoArchivo!=NULL && pArrayListEmployee!=NULL)
        {
            for(int i=0;i<len;i++)
                {
                    nuevoEmpleado = ll_get(pArrayListEmployee, i);
                    fprintf(nuevoArchivo,"%d ,%s ,%d, %d \n",nuevoEmpleado->id,nuevoEmpleado->nombre,nuevoEmpleado->horasTrabajadas,nuevoEmpleado->sueldo);
                }
                fclose(nuevoArchivo);
                valorDeRetorno=1;
        }else
        {
            printf("hola");
            valorDeRetorno=0;
        }
    return valorDeRetorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int valorDeRetorno=0;
    int len = ll_len(pArrayListEmployee);
    FILE* nuevoArchivo;
    Employee* nuevoEmpleado;
    nuevoArchivo=fopen(path,"wb");
    if(nuevoArchivo!=NULL && pArrayListEmployee!=NULL)
        {
            for(int i=0;i<len;i++)
                {
                    nuevoEmpleado = ll_get(pArrayListEmployee,i);
                    fwrite(nuevoEmpleado,sizeof(Employee),1,nuevoArchivo);
                }
                fclose(nuevoArchivo);
                valorDeRetorno=1;
        }else
        {
            valorDeRetorno=0;
        }
    return valorDeRetorno;
}
