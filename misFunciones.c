#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "misFunciones.h"
#include "Employee.h"

#define LENGTH_MAX 100
#define TAM_SECTION 5


#ifdef __linux__
#define SO "Linux"
#elif _WIN32
#define SO "Windows"
#elif _WIN64
#define SO "MsWindows"
#endif

/** \brief Funcion strlwr
 *
 * \param convierte todos los caracteres de un string a minuscula.-
 * \param recibe como parametro un puntero a string.-
 * \return Devuelve un string en letras minusculas.-
 *
 */


char stringToLwr(char* str)
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

char stringToUpper(char* str)
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
osDetect(SO);

Employee eEmployee, *pEmployee;
pEmployee = &eEmployee;

Section eSection, *pSection;
pSection = &eSection;

//Employee employee, *oneEmployee;
//oneEmployee = &employee;

pEmployee=(Employee*)malloc(sizeof(eEmployee)*LENGTH_MAX);
pSection=(Section*)malloc(sizeof(eSection)*5);


if(pEmployee==NULL)
{
    return 1;
}

if (pSection==NULL)
{
    return 1;
}

initEmployee(pEmployee,LENGTH_MAX);
hardcoreEmployee(pEmployee);
hardcoreSection(pSection);


int opc;

do{
osDetect(SO);

printf("\n======================================");
printf("\nSeleccione la Operacion a Realizar");
printf("\n======================================\n");
printf("\n1. Altas");
printf("\n\n======================================");
printf("\n=====M O D I F I C A C I O N E S======");
printf("\n======================================\n");
printf("\n2. Modifcar Nombre de Empleado");
printf("\n3. Modificar Apellido de Empleado");
printf("\n4. Modificar Sueldo de Empleado");
printf("\n5. Modificar Sector de Empleado");
printf("\n\n======================================");
printf("\n==============B A J A S===============");
printf("\n======================================\n");
printf("\n6. Baja Empleado");
printf("\n\n======================================");
printf("\n=============I N F O R M E S==========");
printf("\n======================================\n");
printf("\n7. Listar Empleados");
printf("\n8. Listar Sectores");
printf("\n9. Listar Empleados por Sector");
printf("\n10.Listar Ordenado por Nombre y Sector");
printf("\n11.Listar Alfabeticamente");
printf("\n12.Listar Sueldos Altos");
printf("\n13.Listar por Salarios");
printf("\n\n======================================\n");
printf("\n14. Salir");
printf("\n\n======================================\n");

opc=optionValid();
printf("\n======================================\n");

switch(opc)
{

case 1: addEmployee(pEmployee,LENGTH_MAX); break;

case 2: editEmployeeName(pEmployee,LENGTH_MAX); break;

case 3: editEmployeeLastName(pEmployee, LENGTH_MAX); break;

case 4: editEmployeeSalary(pEmployee,LENGTH_MAX); break;

case 5: editEmployeeSection(pEmployee,LENGTH_MAX); break;

case 6: eraseEmployee(pEmployee,LENGTH_MAX); break;

case 7: showEmployees(pEmployee,LENGTH_MAX); break;

case 8: showSection(pSection); break;

case 9: showEmployeeBySection(pEmployee,LENGTH_MAX,pSection,TAM_SECTION); break;

case 10: sortEmployeesBySectionByName(pEmployee,LENGTH_MAX,pSection,TAM_SECTION); break;

case 11: sortEmployeeByNameOrder(pEmployee,LENGTH_MAX); break;

case 12: showGreatestSalary(pEmployee,LENGTH_MAX,pSection,TAM_SECTION); break;

case 13: sortBySalary(pEmployee,LENGTH_MAX);
}
}while(opc != 14);

return 0;

}

/** \brief Funcion getString
 *
 * \param recibe una cadena de caracteres.-
 * \param recibe como parametro un puntero a string.-
 * \param recibe la longitud de la cadena de caracteres (cantidad de caracteres+1 caracter del salto de carro).-
 * \return no devuelve nada.-
 *
 */

void getString(char* string, int lengh)
{
char String[lengh];

fgets(String, lengh, stdin);
fflush(stdin);


}

/** \brief Funcion osDetect
 *
 * \param recibe una cadena de caracteres.-
 * \param compara la cadena, si es Linux usa un comando, si es Windows, usa otro comando.-
 * \return no devuelve nada.-
 *
 */


void osDetect(char* string)
{


    if(strcmp(string,"Linux")==0)
    {
        system("clear");
    }

    if(strcmp(string,"Windows")==0)
    {
        system("cls");

    }

    if(strcmp(string,"MsWindows")==0)
    {
        system("pause");
    }

}

void wait(char* string)
{

    if(strcmp(string,"Linux")==0)
    {

    printf("\nPresione una tecla para continuar...");
    getchar();
    getchar();

    }

    if(strcmp(string,"Windows")==0)
    {
        system("pause");
    }

    if(strcmp(string,"MsWindows")==0)
    {
        system("pause");
    }
}


int optionValid()
{
   int ok;
   int ch;
   int opc;

    do
    {
      printf("\nOpcion: ");
      fflush(stdout);
      if ((ok = scanf("%d", &opc)) == EOF)
         return 1;


      if ((ch = getchar()) != '\n')
      {
         ok = 0;

         while ((ch = getchar()) != EOF && ch != '\n');
      }
   }while(!ok);

   return opc;
}


int intValid(char* string)
{
   int ok;
   int ch;
   int num;

    do
    {
      printf("%s: ", string);
      fflush(stdout);

      if ((ok = scanf("%d", &num)) == EOF)
       {
           return 1;
       }

      if ((ch = getchar()) != '\n')
      {
         ok = 0;

         while ((ch = getchar()) != EOF && ch != '\n');
      }
   }while(!ok);

   return num;
}



int openFileWrite(char* string, void* x, int tam)
{
    FILE *pArch;

    if((pArch=fopen("string","wt"))==NULL)
    {
        if((pArch=fopen("string","wt"))==NULL)
        {
            printf("\nNO ES POSIBLE ABRIR EL ARCHIVO!!");
            return 1;
        }

        fclose(pArch);
    }

    fprintf(pArch,"EMPLEADOS");
    for(int i=0; i<tam; i++)
    {
        fprintf(pArch,"\n\nLegajo: ");
        fwrite(x,1,tam,pArch);
        fprintf(pArch,"\nNombre: ");
        fwrite(x,1,tam,pArch);
        fprintf(pArch,"\nApellido: ");
        fwrite(x,1,tam,pArch);
        fprintf(pArch,"\nSalario: ");
        fwrite(x,1,tam,pArch);
        fprintf(pArch,"\nSexo: ");
        fwrite(x,1,tam,pArch);
        fprintf(pArch,"\nSector ID: ");
        fwrite(x,1,tam,pArch);
    }


    return 0;
}

int readWriteOpenMain()
{
osDetect(SO);

int opc;

do{
osDetect(SO);

printf("\n======================================");
printf("\nSeleccione la Operacion a Realizar");
printf("\n======================================\n");
printf("\n1. Crear Archivo");
printf("\n2. Guardar Archivo");
printf("\n3. Abrir Archivo");
printf("\n4. Salir");
printf("\n\n======================================\n");

opc=optionValid();
printf("\n======================================\n");

switch(opc)
{

//case 1: break;
//case 2: break;
//case 3: break;
//case 4: break;

}
}while(opc != 5);

return 0;

}
