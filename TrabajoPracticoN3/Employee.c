#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Employee.h"


/** \brief genera un puntero a una estructura "Employee" y setea todos sus campos a 0
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*)malloc(sizeof(Employee));
    if(nuevoEmpleado != NULL)
        {
            nuevoEmpleado->id=0;
            strcpy(nuevoEmpleado->nombre, "");
            nuevoEmpleado->horasTrabajadas = 0;
            nuevoEmpleado->sueldo = 0;
        }
        return nuevoEmpleado;
}


/** \brief inserta datos recibidos en los campos de la nueva estructura generada
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoEmpleado = employee_new();
    if(employee_setId(nuevoEmpleado, atoi(idStr)) && employee_setNombre(nuevoEmpleado, nombreStr) && employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr)) && employee_setSueldo(nuevoEmpleado, atoi(sueldoStr)))
        {
            return nuevoEmpleado;
        }else
        {
            printf("Ocurrio un error\n");
            nuevoEmpleado=NULL;
        }
        return nuevoEmpleado;
}


/** \brief copia el ID en el campo ID de la estructura
 *
 * \param id int
 * \param this Employee*
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{
    int retorno = 1;
    if(this==NULL)
    {
        retorno = 0;
    }else
    {
        this->id = id;
    }
    return retorno;
}


/** \brief copia el Nombre en el campo Nombre de la estructura
 *
 * \param nombre char*
 * \param this Employee*
 * \return int
 *
 */
int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = 1;
    if(this==NULL)
    {
        retorno = 0;
    }else
    {
        strcpy(this->nombre, nombre);
    }
    return retorno;
}


/** \brief copia el HorasTrabajadas en el campo HorasTrabajadas de la estructura
 *
 * \param horasTrabajadas int
 * \param this Employee*
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = 1;
    if(this==NULL)
    {
        retorno = 0;
    }else
    {
        this->horasTrabajadas = horasTrabajadas;
    }
    return retorno;
}


/** \brief copia el Sueldo en el campo Sueldo de la estructura
 *
 * \param sueldo int
 * \param this Employee*
 * \return int
 *
 */
int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = 1;
    if(this==NULL)
    {
        retorno = 0;
    }else
    {
        this->sueldo = sueldo;
    }
    return retorno;
}


/** \brief copia campo ID de la estructura en el ID
 *
 * \param id int*
 * \param this Employee*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{
    int retorno = 1;
    if(this==NULL)
    {
        retorno = 0;
    }else
    {
        *id = this->id;
    }
    return retorno;
}


/** \brief copia campo Nombre de la estructura en el Nombre
 *
 * \param nombre char*
 * \param this Employee*
 * \return int
 *
 */
int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = 1;
    if(this==NULL)
    {
        retorno = 0;
    }else
    {
        strcpy(nombre, this->nombre);
    }
    return retorno;
}


/** \brief copia campo horasTrabajadas de la estructura en el horasTrabajadas
 *
 * \param horasTrabajadas int*
 * \param this Employee*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = 1;
    if(this==NULL)
    {
        retorno = 0;
    }else
    {
        *horasTrabajadas = this->horasTrabajadas;
    }
    return retorno;
}


/** \brief copia campo Sueldo de la estructura en el Sueldo
 *
 * \param sueldo int*
 * \param this Employee*
 * \return int
 *
 */
int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = 1;
    if(this==NULL)
    {
        retorno = 0;
    }else
    {
        *sueldo = this->sueldo;
    }
    return retorno;
}

