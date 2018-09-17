#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "misFunciones.h"
#include "Employee.h"

/** \brief Funcion strlwr
 *
 * \param convierte todos los caracteres de un string a minuscula.-
 * \param recibe como parametro un puntero a string.-
 * \return Devuelve un string en letras minusculas.-
 *
 */


char strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p)

   {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return 0;
}


/** \brief Funcion strupper
 *
 * \param convierte todos los caracteres de un string a mayuscula.-
 * \param recibe como parametro un puntero a string.-
 * \return Devuelve un string en letras mayusculas.-
 *
 */

char strupper(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p)
  {
     *p = toupper((unsigned char)*p);
      p++;
  }

  return 0;
}

/** \brief Funcion removeNewLine
 *
 * \param mide la longitud de un string y elimina el caracter de salto de carro del final.-
 * \param recibe como parametro un puntero a string.-
 * \return Devuelve un string con el caracter de salto de carro eliminado.-
 *
 */

void removeNewLine(char* string)

{
  size_t length;

  if( (length = strlen(string) ) >0)
  {
       if(string[length-1] == '\n')
                string[length-1] ='\0';
  }
}


/** \brief removeNewLines
 *
 * \param mide la longitud de un string y elimina los caracteres de salto de carro del final.-
 * \param recibe como parametro un puntero a string.-
 * \return Devuelve un string con los caracteres de salto de carro eliminados.-
 *
 */

void removeNewLines(char* string)

{
  size_t length = strlen(string);

  while(length>0)

  {
       if(string[length-1] == '\n')
       {
                --length;
                string[length] ='\0';
       }
       else
           break;
  }

}

/** \brief Funcion upInitialCharString
 *
 * \param convierte el caracter inicial de un string a mayuscula.-
 * \param recibe como parametro un puntero a string.-
 * \return Devuelve un string con el primer caracter en mayuscula.-
 *
 */

void upInitialCharString (char *str)

{
int i;
int length_string;

length_string = strlen(str);


for(i=0; i<length_string; i++)
    {
        str[0] = toupper(str[0]);

        if(str[i] == ' ')
        {
            str[i+1] = toupper(str[i+1]);
        }
    }

}

/** \brief Funcion sortVectorUp
 *
 * \param ordena los caracteres en orden ascendente.-
 * \param recibe un array de caracteres.-
 * \return Devuelve el array de caracteres ordenado del primero al ultimo de acuerdo a como fueron ingresados.-
 *
 */

void sortVectorUp(char vec[], int tam)
{
    int i;

    printf("\n\nEn orden Ascendente");
    printf("\n==========================\n\n");

    for(i=0; i<tam; i++)
    {

         printf("%c ", vec[i]);
    }
}

/** \brief Funcion sortVectorDown
 *
 * \param ordena los caracteres en orden descendente.-
 * \param recibe un array de caracteres.-
 * \return Devuelve el array de caracteres ordenado del ultimo al primero de acuerdo a como fueron ingresados.-
 *
 */

void sortVectorDown(char vec[], int tam)
{
    int i;

printf("\n\nEn orden descendente");
printf("\n==========================\n\n");

   for(i=tam-1; i>=0; i--)
    {

         printf("%c ", vec[i]);
    }
}

/** \brief Funcion sortVectorChar
 *
 * \param ordena los caracteres en orden de mayor a menor.-
 * \param recibe un array de caracteres.-
 * \return Devuelve el array de caracteres ordenado de mayor a mennor de acuerdo a su valor en la tabla ASCII.-
 *
 */

void sortVectorChar(char vec[], int tam)
{
    char aux;
    int i;
    int j;


    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
           if(vec[i] < vec[j])
           {
               aux = vec[i];
               vec[i] = vec[j];
               vec[j] = aux;
           }
        }
    }
}

/** \brief Funcion getInt
 *
 * \param valida valores ingresados dentro de determinados rangos.-
 * \param recibe mesaje de ingreso de datos.-
 * \param recibe mensaje de error.-
 * \param recibe el limite inferior y superior del rango a determinar.-
 * \param recibe la cantidad de intentos permitidos.-
 * \return devuelve el valor correcto ingresado.-
 *
 */

int getInt(char msj[], char error[], int limInf, int limSup, int attemp)
{
    //int i;
    int dato;
    int flag=0;
    //int intentos;


    printf("\n%s", msj);
    scanf("%d", &dato);

    while((dato<limInf || dato>limSup) && (attemp>0))
    {
        printf("\n=======================================");
        printf("\n%s", error);
        printf("\n=======================================\n");
        attemp--;

        printf("\n%s", msj);
        scanf("%d", &dato);
        flag=1;

    }

    if(flag==1)
    {
        printf("\n=====================================");
        printf("\nHA EXCEDIDO LA CANTIDAD DE INTENTOS");
        printf("\n=====================================");
    }

     if(flag==0)
    {
        printf("\n=====================================");
        printf("\nUSTED INGRESO: %d", dato);
        printf("\n=====================================");

    }



return dato;
}

/** \brief optionMain Function
 *
 * \param prompt the options the task to do, in a numeric main
 * \param call to the available functions
 * \return the action request in main selection.
 *
 */


int optionMain()
{
system("cls");
system("clear");

int opc;

do{
system("cls");
system("clear");

int ok;
int ch;

printf("\n======================================");
printf("\nSeleccione la Operacion a Realizar");
printf("\n======================================\n");
printf("\n1. Altas");
printf("\n2. Modificar");
printf("\n3. Baja");
printf("\n4. Informes");
printf("\n5. Salir");
printf("\n\n======================================\n");

do
    {
      printf("\nOpcion: ");
      fflush(stdout);
      if ((ok = scanf("%d", &opc)) == EOF)
         return EXIT_FAILURE;


      if ((ch = getchar()) != '\n')
      {
         ok = 0;

         while ((ch = getchar()) != EOF && ch != '\n');
      }
   }while(!ok);
printf("\n======================================\n");

switch(opc)
{

case 1:  break;
case 2:  break;
case 3:  break;
case 4:  break;

}
}while(opc != 5);

return 0;

}

