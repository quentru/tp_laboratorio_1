#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

///utilizacion de arrays matriciales

void chargeString(char aArray[][50], int cantidad)
{
    char nombresHardcode[][50]={"Alfredo","Rogelio","Julieta","pablo"};
    for (int i=0; i<cantidad; i++)
        {
            strcpy(aArray[i],nombresHardcode[i]);
        }
}


int obtainMax(int aArray[], int cantidad)
{
    int mayor;
    for(int i=0; i<cantidad; i++)
        {
          if(aArray[i]>mayor || i==0)
            {
                mayor=aArray[i];
            }
        }
        return mayor;
}

int getIdMax(int arrayNumeros[], int cantidad)
{
    int indice=0;
    int mayor;
    mayor = obtainMax(arrayNumeros, cantidad);
    for(int i=0;i<cantidad;i++)
    {
        if(arrayNumeros[i] == mayor)
            {
                indice=i;
            }
    }
    return indice;
}
void showMax(int arrayNumeros[],char arrayPalabras[][50], int cantidad)
{
    int indice;
    indice=getIdMax(arrayNumeros,cantidad);
    printf("la nota mayor es %d  y el nombre %s", arrayNumeros[indice], arrayPalabras[indice]);
}
///carga, inicializacion y obtncion de arrays

void hardcode(int aArray[], int cantidad)
{
    int numerosParaHardcode[]={4,10,8,2};
    for (int i=0; i<cantidad; i++)
        {
            aArray[i] = numerosParaHardcode[i];
        }
}


void secuentialChargeArray(int aArray[], int cantidad, char mensaje[])
{
    int numero;
    for(int i=0; i<cantidad;i++)
        {
            printf(mensaje);
            scanf("%d", &numero);
            aArray[i]=numero;
        }
}


void initArray(int aArray[], int cantidad)
{
    for(int i=0; i<cantidad; i++)
       {
            aArray[i]=0;
       }
}
///Operaciones con arrays

void showArray(int aArray[], int cantidad)
{
    for(int i=0; i<cantidad; i++)
        {
            printf("%d\n",aArray[i]);
        }
}

int obtainMin(int aArray[], int cantidad)
{
    int minimo;
    for(int i=0; i<cantidad; i++)
        {
          if(aArray[i]<minimo || i==0)
            {
               minimo=aArray[i];
            }
        }
        return minimo;
}

void arraySortMinorToMajor(int aArray[], int cantidad)
{
    int aux;
    for(int i=0; i<cantidad-1;i++)
        {
            for(int j=i+1; j<cantidad;j++)
                {
                    if(aArray[i]>aArray[j])
                        {
                            aux=aArray[i];
                            aArray[i]=aArray[j];
                            aArray[j]=aux;
                        }
                }
        }
}

float getAverage(int aArray[], int cantidad)
{
    float promedio;
    int suma;
    for(int i=0; i<cantidad; i++)
        {
            suma = suma+aArray[i];
        }
    promedio = (float)suma/cantidad;
    printf("El promedio es %f", promedio);
    return promedio;
}

///Validacion y obtencion de datos

/**
* \brief Solicita una cadena de caracteres al usuario y valida que sean solo numeros
* \param number el puntero al entero que recibira el valor del numero validado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \return Si obtuvo el numero [1] si no [0]
*
*/
int validateInt(int* number, char message[], char eMessage[])
{
    int value=0;
    char numero[200];
    printf(message);
    fflush(stdin);
    gets(numero);
    for(int i=0; i<strlen(numero);i++)
        {
            if(numero[i]<48 || numero[i]>57)
                {
                    value=1;
                }
        }
        while(value==1)
            {
                value=0;
                printf(eMessage);
                fflush(stdin);
                gets(numero);
                for(int i=0; i<strlen(numero);i++)
                {
                    if(numero[i]<48 || numero[i]>57)
                    {
                        value=1;
                    }
                }
            }
        *number=atoi(numero);
        return value;
}


/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int value = -1, retorno;
    retorno = validateInt(input, message, "Solo se pueden ingresar numeros\n");
    while(retorno!=0 || *input<lowLimit || *input>hiLimit)
        {
            printf(eMessage);
            retorno = validateInt(input, message,"Solo se pueden ingresar numeros\n");
        }
    value=0;
    return value;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit){
    int value=-1;
    printf("%s\n", message);
    scanf("%f", input);
    while(*input<lowLimit || *input>hiLimit)
        {
            printf("%s", eMessage);
            scanf("%f", input);
        }
        value = 0;
    return value;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit){
    int value=-1;
    char character;
    printf("%s", message);
    fflush(stdin);
    scanf("%c", &character);
    character = tolower(character);
    while(character < lowLimit || character > hiLimit)
        {
            printf("%s",eMessage);
            fflush(stdin);
            scanf("%c", &character);
            *input = character;
        }
    value=0;
    return value;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit){
    int value=-1;
    printf("%s\n", message);
    fflush(stdin);
    gets(input);
    while(strlen(input)<lowLimit || strlen(input)>hiLimit)
        {
            printf("%s", eMessage);
            fflush(stdin);
            gets(input);
        }
        value=0;
    return value;
}

/**
* \brief Solicita un caracter al usuario que indicaria el sexo del mismo y lo valida
* \param input Se carga el caracter deseado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param genre es uno de los generos
* \param otherGenre es el otro genero
* \return Si obtuvo eel caracter [0] si no [-1]
*
*/
int getGenre(char* input, char message[], char eMessage[], char genre, char otherGenre){
    char character;
    int value = -1;
    printf("%s", message);
    fflush(stdin);
    scanf("%c", &character);
    while(character != genre &&  character!= otherGenre)
        {
            printf("%s", eMessage);
            scanf("%c", &character);
        }
        *input = character;
        value = 0;
        return value;
}

/**
* \brief funcion que valida si se ingreso un caracter
* \param recibira el caracter a validar
* \return si es un caracter [0] si es una letra [1]
*
*/
int isChar(char* input)
{
    int value = -1;
    char caracter;
    caracter = *input;
    if(caracter>57 && caracter<127)
    {
        value=1;
    }
    return value;
}



/**
* \brief evalua si el caracter recibido es una letra
* \param caracter a evaluar
* \return [-1] si no es letra, [1]si es
*
*/
int isLetter(char* input)
{
    int value=-1;
    char caracter;
    caracter = *input;
    if((caracter>64 && caracter<91) || (caracter>96 && caracter<123))
    {
        value=1;
    }
    return value;
}


/**
* \brief evalua si el caracter recibido es numero
* \param caracter a evaluar
* \return [-1] si no es numerico, [1]si es
*
*/
int isNumeric(char* input)
{
    char character;
    character = *input;
    printf("%c", character);
    int value=-1;
    if(character>48 && character<57)
        {
            value=1;
        }
            return value;
}





////Eureca

/**
* \brief Evalua si la cadena pasada por parametro es alfanumerica
* \param message es la cadena a ser evaluada
* \return vale [0] si es alfanumerico, [-1] si no lo es
*
*/
int isAlphanumeric(char* input)
{
    int reply, flagNumber=0, flagLetter=0;
    int replyLetter;
    int value=-1;
    for(int i=0;i<strlen(input);i++)
        {
            reply = isNumeric(&input[i]);
            replyLetter = isLetter(&input[i]);
            if(reply==1)
                {
                    flagNumber=1;
                }else if(replyLetter==1)
                {
                    flagLetter=1;
                }
        }
            if(flagLetter==1 && flagNumber==1)
                {
                    value=0;
                }else{

                    return value;
                }
                return value;
        }




/**
* \brief Solicita una fecha y valida el dia, el mes y el año por separado
* \param inputY Se carga el año a validar ingresado
* \param inputM Es el mes a validar
* \param inputD Es el dia a validar
* \param Message Es el mensaje a ser mostrado
* \param yLowLimit Limite inferior que validara el valor del año
* \param yHiLimit Limite superior  que validara el valor del año
* \return Si valido la fecha [0] si no [1]
*
*/

int getDate(int* inputY, int* inputM, int* inputD, char message[], int yLowLimit, int yHiLimit){

    int day, month, year;
    int flag=0;
    int error = 1;
    char messageYear[60]="Ingrese el anio de ";
    char messageMonth[60]="Ingrese el mes de ";
    char messageDay[60]="Ingrese el dia de ";
    strcat(messageYear, message);
    strcat(messageMonth, message);
    strcat(messageDay, message);

    getInt(&year, messageYear, " --El anio que usted ingreso no esta en nuestro rango\n", yLowLimit, yHiLimit);
    //printf("%d", year);
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        flag = 1;
    }
    *inputY = year;
    getInt(&month,messageMonth,"--Se debe elegir uno de los doce meses\n", 1, 12);
    *inputM = month;
    if(flag==0 && month == 2)
    {
        getInt(&day,messageDay," --El dia de este mes debe estar entre los valores 1 y 28\n", 1, 28);
    }
    else if(flag==1 && month == 2)
    {
        getInt(&day,messageDay," --El dia de este mes debe estar entre los valores 1 y 29\n", 1, 29);
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        getInt(&day,messageDay," --El dia de este mes debe estar entre los valores 1 y 30\n", 1, 30);
    }
    else
    {
        getInt(&day,messageDay," --El dia de este mes debe estar entre los valores 1 y 31--\n", 1, 31);
    }
    *inputD = day;
    error = 0;
    return error;

}

/**
* \brief Solicita un número al usuario
* \param message es el mensaje a ser mostrado
* \return el entero ingresado
*
*/
int getData(char message[])
{
    int numero;
    printf(message);
    scanf("%d", &numero);
    return numero;
}


/**
* \brief Solicita una cadena de caracteres al usuario y valida que sea solo letras
* \param input Se carga la cadena ingresada
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0]
*
*/
int getName(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int devolucion, flag=1, value=0;
    do
        {
            getString(input, message, eMessage, lowLimit,hiLimit);
            for(int i=0; i<strlen(input); i++)
                {
                    devolucion=isLetter(&input[i]);
                    if(devolucion==-1)
                        {
                            flag=-1;
                            break;
                        }else
                        {
                            flag=1;
                        }
                }
        }while(flag!=1);
    return value;
}

/**
* \brief Solicita una cadena de caracteres al usuario y valida que sea solo numero
* \param input Se carga la cadena ingresada
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0]
*
*/
int getNumberOfString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int devolucion, flag=1, value=0;
    do
        {
            getString(input, message, eMessage, lowLimit,hiLimit);
            for(int i=0; i<strlen(input); i++)
                {
                    devolucion=isNumeric(&input[i]);
                    if(devolucion==-1)
                        {
                            flag=-1;
                            break;
                        }else
                        {
                            flag=1;
                        }
                }
        }while(flag!=1);
    return value;
}

