#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mes;
    printf("Ingrese el mes\n");
    scanf("%d", &mes);
    switch(mes)
    {
        case 12:
        case 1:
        case 2:
            printf("Es Verano\n");
            break;
        case 3:
        case 4:
        case 5:
            printf("Es Otonio\n");
            break;
        case 6:
        case 7:
        case 8:
            printf("Es Invierno\n");
            break;
        case 9:
        case 10:
        case 11:
            printf("Es Primavera\n");
        break;
        default:
            printf("Fuera de rango\n");
            break;
    }
    return 0;
}
