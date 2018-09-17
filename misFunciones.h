#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED

char strlwr(char *str);
char strupper(char *str);
void removeNewLine(char* string);
void removeNewLines(char* string);
void upInitialCharString (char *str);
void sortVectorUp(char vec[], int tam);
void sortVectorDown(char vec[], int tam);
void sortVectorChar(char vec[], int tam);
int getInt(char msj[], char error[], int limInf, int limSup, int attemp);
int optionMain();

#endif // MISFUNCIONES_H_INCLUDED
