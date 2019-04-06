#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
int main()
{
    int menu;
    int resultadoSuma, resultadoResta, resultadoMultiplicacion, x = 0, y = 0, resultadoFactorialUno, resultadoFactorialDos;
    float resultadoDivision;
    int bandera=0;
    int auxiliar=0;
    while(menu!=5)
    {
        printf("1_para ingresar el primer numero \n 2_para ingresar el segundo numero \n 3_Calcular todas las operaciones \n 4_Para mostrar todas las operaciones \n 5_Para salir \n que desea hacer??\n");
        scanf("%d", &menu);
        switch(menu)
        {
        case 1:
        bandera++;
        printf("Ingrese un numero\n");
        scanf("%d",&x);
        if(x==0)
            {
                auxiliar=1;
            }
            else
            {
            printf("el Primer numero es %d \n",x);
        }
        break;
        case 2:
        bandera++;
        printf("Ingrese un numero\n");
        scanf("%d",&y);
        if(y==0)
            {
                auxiliar=1;
            }
            else
            {
        printf("el segundo numero es %d \n",y);
        }
        break;
        case 3:
        bandera++;
        resultadoFactorialUno = factorialDeA(x);
        resultadoFactorialDos = factorialDeA(y);
        resultadoSuma = suma(x,y);
        resultadoResta = resta(x,y);
        resultadoMultiplicacion = multiplicacion(x,y);
        resultadoDivision = division(x,y);
        break;
        case 4:
            if(!(bandera==3))
                {
                    printf("No hay resultados que mostrar, por favor ingrese ambos numeros");
                }else{
        printf("El resultado de la suma es %d , y el de la resta %d , \nel de la multiplicacion es %d ", resultadoSuma , resultadoResta, resultadoMultiplicacion);
        printf(", el factorial del primer numero es %d \ny el resultado del otro factorial es %d\n",resultadoFactorialUno ,resultadoFactorialDos);
           if(auxiliar==1)
            {
                printf("no se puede dividir por 0\n");
            }else{
        printf("y el de la division es %.2f", resultadoDivision);
        }
        }
        case 5:
        exit(0);
        }
    }
    return 0;
}
