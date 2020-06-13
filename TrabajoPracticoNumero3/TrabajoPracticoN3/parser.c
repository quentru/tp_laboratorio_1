#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
parser


 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* nuevoEmpleado;
    int cantidadDeLectura, valorDeRetorno=0;
    char buffer[4][20];
    while(!feof(pFile))
        {
            cantidadDeLectura = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]);
            if(cantidadDeLectura<4)
                {
                    printf("error");
                }
                nuevoEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                ll_add(pArrayListEmployee, nuevoEmpleado);
                valorDeRetorno=1;
            //printf("%s %s %s %s\n",  buffer[0],buffer[1],buffer[2],buffer[3]);
        }
    fclose(pFile);
    return valorDeRetorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* nuevoEmpleado;
    int cantidadDeLectura, valorDeRetorno=0;
    while(!feof(pFile))
        {
            nuevoEmpleado=employee_new();
            if(nuevoEmpleado!=NULL)
                {
                    cantidadDeLectura = fread(nuevoEmpleado,sizeof(Employee),1,pFile);
                    if(cantidadDeLectura==1)
                    {
                        ll_add(pArrayListEmployee, nuevoEmpleado);
                        valorDeRetorno=1;
                    }

                }else
                {
                    valorDeRetorno=0;
                }
        }
    fclose(pFile);
    return valorDeRetorno;
}
