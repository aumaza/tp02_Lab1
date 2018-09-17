#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Employee.h"


int menuGeneral()
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
