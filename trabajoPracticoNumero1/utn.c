#include <stdio.h>
#include <stdlib.h>


/**
*\brief calcular el factorial del numero recibido y devolvera el resultado
*\param recibe un numero
*\return devuelve el resultado del numero factorizado
*
*
*/
int factorialDeA(int a)
{

            int factorial;
                if(a==0)
                {
                    factorial=1;
                }
                else{
                factorial=a;
                for(int i=1;i<a;i++)
                {
                    factorial = factorial * i;
                }
            }
            return factorial;

}
/**
*\brief ejecuta una suma y devuelve un producto
*\param recibe dos numeros enteros
*\return devuelve el resultado de la suma
*
*
*/
int suma(int a , int b)
{
    int producto;
    producto = a + b;
    return producto;
}
/**
*\brief ejecuta una resta y devuelve una diferencia
*\param recibe dos numeros enteros
*\return devuelve el resultado de la resta
*
*
*/
int resta(int a , int b)
{
    int diferencia;
    diferencia = a - b;
    return diferencia;
}
/**
*\brief ejecuta una multiplicacion y devuelve un producto
*\param recibe dos numeros enteros
*\return devuelve el resultado de la multiplicacion
*
*
*/
int multiplicacion(int a , int b)
{
    int multiplicacion;
    multiplicacion = a * b;
    return multiplicacion;
}
/**
*\brief ejecuta una division y devuelve un cociente
*\param recibe dos numeros enteros
*\return devuelve el resultado de la division
*
*
*/
float division(int a , int b)
{
    float division;
    division = (float)a/b;
    return division;
}
