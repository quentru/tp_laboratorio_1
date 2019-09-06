#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
int main()
{
    int menu;
    int resultadoSuma, resultadoResta, resultadoMultiplicacion, x=0 , y=0 , resultadoFactorialUno, resultadoFactorialDos;
    float resultadoDivision;
    int bandera=0;
    int auxiliar=1, auxiliarDos=1;
    while(menu!=5)
    {
        printf("el Primer numero es %d \n",x);
        printf("el segundo numero es %d \n",y);
        printf("1_para ingresar el primer numero \n 2_para ingresar el segundo numero \n 3_Calcular todas las operaciones \n 4_Para mostrar todas las operaciones \n 5_Para salir \n que desea hacer??\n");
        scanf("%d", &menu);
        switch(menu)
        {
        case 1:
        bandera++;
        printf("Ingrese un numero\n");
        scanf("%d",&x);
        if(x!=0)
            {
                auxiliar=0;
                system("cls");
            }
            else
            {
            auxiliarDos=1;
            system("cls");
        }
        break;
        case 2:
        bandera++;
        printf("Ingrese un numero\n");
        scanf("%d",&y);
        if(y!=0)
            {
                auxiliarDos=0;
                system("cls");
            }
            else
            {
                auxiliarDos=1;
                system("cls");
        }
        break;
        case 3:
            bandera=1;
            resultadoFactorialUno = factorialDeA(x);
            resultadoFactorialDos = factorialDeA(y);
            resultadoSuma = suma(x,y);
            resultadoResta = resta(x,y);
            resultadoMultiplicacion = multiplicacion(x,y);
            resultadoDivision = division(x,y);
            system("cls");
        break;
        case 4:
            if(bandera==0)
                {
                    printf("No hay resultados que mostrar, por favor ingrese ambos numeros");
                }else{
        printf("El resultado de la suma es %d , y el de la resta %d , \nel de la multiplicacion es %d ", resultadoSuma , resultadoResta, resultadoMultiplicacion);
        printf(", el factorial del primer numero es %d ,\n el resultado del otro factorial es %d\n",resultadoFactorialUno ,resultadoFactorialDos);
        bandera=0;
           if(auxiliar==1 || auxiliarDos==1)
            {
                printf("no se puede dividir por 0\n");
            }else{
        printf(" y el resultado de la division es %.2f\n", resultadoDivision);
        system("pause");
        system("cls");
        }
        }
        break;
        case 5:
        exit(0);
        }
    }
    return 0;
}
