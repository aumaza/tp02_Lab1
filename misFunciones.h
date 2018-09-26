#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED

char stringToLwr(char* str);
char stringToUpper(char* str);
void removeNewLine(char* string);
void removeNewLines(char* string);
void upInitialCharString (char *str);
void sortVectorUp(char vec[], int tam);
void sortVectorDown(char vec[], int tam);
void sortVectorChar(char vec[], int tam);
int getInt(char msj[], char error[], int limInf, int limSup, int attemp);
int optionMain();
void getString(char* string, int lengh);
void osDetect(char* string);
void wait(char* string);
int optionValid();
int intValid(char* string);
int openFileRead(char* string);
int openFileWrite(char* string, void* x, int tam);

#endif // MISFUNCIONES_H_INCLUDED
