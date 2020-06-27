///Validacion y obtencion de datos
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getGenre(char* input, char message[], char eMessage[], char genre, char otherGenre);
int getDate(int* inputY, int* inputM, int* inputD, char message[], int yLowLimit, int yHiLimit);
int getName(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int isChar(char* input);
int isAlphanumeric(char input[]);
int isNumeric(char* input);
int isLetter(char* input);
int getData(char message[]);
int validateInt(int* number, char message[],char eMessage[]);
///carga, inicializacion y obtencion de arrays
void initArray(int aArray[], int cantidad);
void hardcode(int aArray[], int cantidad);
void secuentialChargeArray(int aArray[], int cantidad, char mensaje[]);
///operaciones con arrays
void showArray(int aArray[], int cantidad);
void arraySortMinorToMajor(int aArray[], int cantidad);
int obtainMax(int aArray[], int cantidad);
int obtainMin(int aArray[], int cantidad);
float getAverage(int aArray[], int cantidad);
int getIdMax(int arrayNumeros[], int cantidad);
///utilizacion de arrays matriciales
void chargeString(char aArray[][50], int cantidad);
void showMax(int arrayNumeros[],char arrayPalabras[][50], int cantidad);

