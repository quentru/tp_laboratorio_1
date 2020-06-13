#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"

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
            getName(auxNombre,"Ingrese su Nombre\n", "Solo puede tener 50 caracteres\n", 1, 60);
            if(employee_setNombre(nuevoEmpleado, auxNombre))
            {
                getInt(&auxHorasTrabajadas, "Ingrese su horas trabajadas\n", "Debe ser mayor a 1 y menos que 10000\n",1,10000);
                if(employee_setHorasTrabajadas(nuevoEmpleado, auxHorasTrabajadas))
                {
                    getInt(&auxSueldo, "Ingrese su sueldo\n", "Su sueldo debe ser mayor que 1 y menor que 1000000\n", 1, 1000000);
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
    getInt(&id, "Ingrese el ID de la persona a modificar\n", "Debe ser mayor a 1 y menor 5000\n", 1, 5000);
    for(int i=0; i<len;i++)
        {
            auxiliar = ll_get(pArrayListEmployee, i);
            if(auxiliar->id == id)
            {
            printf("Desea modificar este usuario?? 's' o 'n'\n");
            printf("%d  %s  %d  %d\n", auxiliar->id, auxiliar->nombre, auxiliar->horasTrabajadas, auxiliar->sueldo);
            fflush(stdin);
            getGenre(&eleccion, "Desea modificar este usuario ´s´ o ´n´??\n", "Solo se puede ingresar ´s´ o ´n´", 's','n');
            if(eleccion=='s')
                {
                        flag=1;
                        valorDeRetorno=1;
                        printf("Que desea modificar\n");
                        printf("1_Nombre\n");
                        printf("2_Horas Trabajadas\n");
                        printf("3_Sueldo\n");
                        getInt(&opcion, "Ingrese una opcion\n", "Solo hay 3 opciones\n", 1, 3);

                        switch(opcion)
                        {
                        case 1:
                            getName(auxNombre,"Reingrese su Nombre\n", "Solo puede tener 50 caracteres\n", 1, 60);
                            employee_setNombre(auxiliar, auxNombre);
                            break;
                        case 2:
                            getInt(&auxHorasTrabajadas, "Ingrese su horas trabajadas\n", "Debe ser mayor a 1 y menos que 10000\n",1,10000);
                            employee_setHorasTrabajadas(auxiliar, auxHorasTrabajadas);
                            break;
                        case 3:
                            getInt(&auxSueldo, "Ingrese su sueldo\n", "Su sueldo debe ser mayor que 1 y menor que 1000000\n", 1, 1000000);
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
    int id, index, flag=0, valorDeRetorno=0;
    getInt(&id, "Ingrese el ID de la persona a dar de baja\n", "Debe ser mayor a 1 y menor 5000\n", 1, 5000);
    for(int i=0; i<len;i++)
        {
            auxiliar = ll_get(pArrayListEmployee, i);
            if(auxiliar->id == id)
            {
            flag=1;
            printf("%d  %s  %d  %d\n", auxiliar->id, auxiliar->nombre, auxiliar->horasTrabajadas, auxiliar->sueldo);
            getGenre(&eleccion, "Desea dar de baja a este usuario ´s´ o ´n´??\n", "Solo se puede ingresar ´s´ o ´n´", 's','n');
                switch(eleccion)
                {
                case 's':
                    index=i;
                    valorDeRetorno=1;
                    break;
                case 'n':
                    printf("Baja cancelada\n");
                    system("pause");
                    system("cls");
                    break;
                }
            }
        }
        ll_remove(pArrayListEmployee, index);
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
