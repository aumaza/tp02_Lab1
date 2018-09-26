#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Employee.h"
#include "misFunciones.h"

#ifdef __linux__
#define SO "Linux"
#elif _WIN32
#define SO "Windows"
#elif _WIN64
#define SO "MsWindows"
#endif

#define LENGTH_MAX 100
#define TAM_SECTION 5
#define FREE 0
#define BUSY 1

/** \brief to indicate that all position in the array are empty,
 *         this function put the flag (isEmpty) in TRUE in all position of the array.
 * \param  list Employee* pointer to array of employees
 * \param  len int array lenght
 * \return int Return (-1) if error (invalid lenght or NULL pointer) 0 if all OK.
 *
 */


int initEmployees(Employee* pEmployee, int len)

{
int i;
int retorno = -1;


Employee* returnAux = NULL;
//Employee* pEmployee = malloc(sizeof(Employee));

if(len>0 && returnAux != NULL)
{
    for(i=0; i<len; i++)
    {

        (pEmployee+i)->isEmpty=FREE;
        retorno=0;
    }
}


return retorno;
}

/** \brief add in a existing list of employees the values received as parameters in the first empty position
 *
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int return (-1) if Error [invalid length or NULL pointer or without pointer]
 *
 */


 int showOneEmployee(Employee* pEmployee)
{
    printf("\nLegajo: %d", pEmployee->file);
    printf("\nNombre: %s", pEmployee->name);
    printf("\nApellido: %s", pEmployee->lastName);
    printf("\nSalario: %.2f", pEmployee->salary);
    printf("\nSexo: %c", pEmployee->sex);
    printf("\nSector: %d", pEmployee->idSection);


    return 0;
}

void initEmployee(Employee* pEmployee, int tam)
{
    for(int i=0; i<tam; i++)
    {
        (pEmployee+i)->isEmpty=FREE;
    }
}

int searchFree(Employee* pEmployee, int tam)
{
    int index = -1;

    for(int i=0; i<tam; i++)
    {
        if((pEmployee+i)->isEmpty == FREE)
        {
            index = i;
            break;
        }
    }

    return index;
}


int searchEmployee(Employee* pEmployee, int tam, int file)
{
    int i;
    int index= -1;

    for(i=0; i<tam; i++)
    {
        if((pEmployee+i)->file == file && (pEmployee+i)->isEmpty == BUSY)
        {
            index = i;
            break;
        }
    }

    return index;
}


void addEmployee(Employee* pEmployee, int tam)
{
    Employee newEmployee;
    int index=-1;
    int is;
    int file;

    index = searchFree(pEmployee, tam);

    if(index == -1)
    {
        osDetect(SO);
        printf("\n======================================\n");
        printf("\nNO HAY LUGAR DISPONIBLE!!\n");
        printf("\n======================================\n\n");
        wait(SO);
    }

    else
    {
        osDetect(SO);
        printf("\n======================================\n");
        printf("\nIngrese legajo: ");
        scanf("%d", &file);
        printf("\n======================================\n\n");
        wait(SO);
        is = searchEmployee(pEmployee, tam, file);

        if(is != -1)
        {
            osDetect(SO);
            printf("\n================================================\n");
            printf("\nYa existe un empleado con el Legajo Nro: %d\n\n", file);
            printf("\n================================================\n\n");
            //showEmployee(*(pEmployee + is));
            wait(SO);
        }

        else
        {
            newEmployee.file = file;
            printf("\nIngrese Nombre: ");
            fflush(stdin);
            fgets(newEmployee.name,51,stdin);
            removeNewLine(newEmployee.name);
            stringToUpper(newEmployee.name);

            printf("\nIngrese Apellido: ");
            fflush(stdin);
            fgets(newEmployee.lastName,51,stdin);
            removeNewLine(newEmployee.lastName);
            stringToUpper(newEmployee.lastName);

            printf("\nIngrese sexo: ");
            fflush(stdin);
            scanf("%c", &newEmployee.sex);

            printf("\nIngrese sueldo: ");
            scanf("%f", &newEmployee.salary);

            printf("\nIngrese ID Sector: ");
            fflush(stdin);
            scanf("%d", &newEmployee.idSection);
            newEmployee.isEmpty = BUSY;

            *(pEmployee+index) = newEmployee;

            /**< AGREGAR SECTOR */
        }
    }
}


void showEmployee(Employee* pEmployee, Section* pSection, int tam)
{
    osDetect(SO);
printf("\n==============================================================================");
printf("\n===========================E M P L E A D O====================================");
printf("\n==============================================================================");
printf("\nLegajo    \tNombre    \tApellido  \tSexo  \tSalario   \tSector");
printf("\n==============================================================================");
printf("\n%d", pEmployee->file);
printf("\t%12s", pEmployee->name);
printf("\t%15s", pEmployee->lastName);
printf("\t%10c", pEmployee->sex);
printf("\t%8.2f", pEmployee->salary);
printf("\t%6s", pSection->description);
printf("\n==============================================================================");

    wait(SO);
}


void showEmployees(Employee* pEmployee, int tam)
{
    osDetect(SO);

printf("\n==============================================================================");
printf("\n===========================E M P L E A D O S==================================");
printf("\n==============================================================================");
printf("\nLegajo    \tNombre    \tApellido  \tSexo  \tSalario   \tSector");
printf("\n==============================================================================");

   for(int i=0; i<tam; i++)
    {
        if((pEmployee + i)->isEmpty == 1)
        {

            printf("\n%d", (pEmployee+i)->file);
            printf("\t%12s", (pEmployee+i)->name);
            printf("\t%15s", (pEmployee+i)->lastName);
            printf("\t%10c", (pEmployee+i)->sex);
            printf("\t%8.2f", (pEmployee+i)->salary);
            printf("\t%4d", (pEmployee+i)->idSection);

        }
       }
       printf("\n==============================================================================");
    printf("\n\n");
    wait(SO);
}



void showEmployeeByReference(Employee* oneEmployee)
{
    osDetect(SO);
    printf("\n======================================================================");
    printf("\nLEGAJO    NOMBRE        APELLIDO      SEXO      SALARIO       SECTOR");
    printf("\n======================================================================\n");
    printf("%d   \t%s     \t%7s       \t%c    \t%.2f   \t%d", oneEmployee->file, oneEmployee->name, oneEmployee->lastName, oneEmployee->sex, oneEmployee->salary, oneEmployee->idSection);
    printf("\n======================================================================\n");


}


void eraseEmployee(Employee* pEmployee, int tam)
{
    osDetect(SO);

    int file;
    int indice;
    char resp;

    printf("\nIngrese legajo: ");
    scanf("%d", &file);
    getchar();

    indice = searchEmployee(pEmployee, tam, file);


    if(indice == -1)
    {
        printf("\nNo hay ningun empleado con el legajo %d", file);

    }
    else
    {
        showEmployeeByReference(pEmployee + indice);
         wait(SO);

        printf("\n=======================================================");
        printf("\nATENCION!! -- SE VA A ELIMINAR UN REGISTRO!!");
        printf("\n=======================================================");
        printf("\n\nCONFIRMA BORRADO(s/n): ");
        fflush(stdin);
        scanf("%c", &resp);
        printf("\n=======================================================");

        if(resp != 's')
        {
            printf("\nBorrado cancelado\n");
        }
        else
        {
            (pEmployee + indice)->isEmpty = FREE;
            printf("\nREGISTRO ELIMINADO CON EXITO\n\n");
            printf("\n=======================================================");
        }
    }
    wait(SO);
}


void editEmployeeSalary(Employee* pEmployee, int tam)
{
    osDetect(SO);
    int file;
    int index;
    char resp;
    float newSalary;

    printf("\nIngrese legajo requerido: ");
    scanf("%d", &file);
    getchar();

    index = searchEmployee(pEmployee, tam, file);

    if(index == -1)
    {
        printf("\nNo hay ningun empleado con el legajo %d", file);
    }
    else
    {
        showEmployeeByReference(pEmployee + index);

        printf("\n\nModifica sueldo?(s/n): ");
        fflush(stdin);
        scanf("%c", &resp);
        getchar();

        if(resp != 's')
        {
            printf("\nModificacion cancelada\n");
        }
        else
        {
            printf("\nIngrese nuevo sueldo: ");
            fflush(stdin);
            scanf("%f", &newSalary);
            getchar();

            (pEmployee + index)->salary = newSalary;
            printf("\nPRESIONE [ENTER] PARA APLICAR LOS CAMBIOS");
            getchar();
            printf("\nMODIFICACION EXITOSA. LOS CAMBIOS SE HAN REGISTRADO\nPRESIONE [ENTER] PARA VERIFICAR LOS CAMBIOS\n\n");
            getchar();
            showEmployeeByReference(pEmployee + index);
        }
    }
    wait(SO);
}


void editEmployeeName(Employee* pEmployee, int tam)
{
    osDetect(SO);

    int file;
    int index;
    char resp;
    char newName[51];

    printf("\nIngrese legajo requerido: ");
    scanf("%d", &file);
    getchar();

    index = searchEmployee(pEmployee, tam, file);

    if(index == -1)
    {
        printf("\nNo hay ningun empleado con el legajo %d", file);
    }
    else
    {
        showEmployeeByReference(pEmployee + index);

        printf("\nModifica el Nombre?(s/n): ");
        fflush(stdin);
        scanf("%c", &resp);
        getchar();

        if(resp != 's')
        {
            printf("\nModificacion cancelada\n");
        }
        else
        {
            printf("\nIngrese Nombre: ");
            fflush(stdin);
            fgets(newName,51,stdin);
            removeNewLine(newName);
            stringToUpper(newName);

            strcpy((pEmployee + index)->name,newName);
            printf("\nPRESIONE [ENTER] PARA APLICAR LOS CAMBIOS");
            getchar();
            printf("\nMODIFICACION EXITOSA. LOS CAMBIOS SE HAN REGISTRADO\nPRESIONE [ENTER] PARA VERIFICAR LOS CAMBIOS\n\n");
            getchar();
            showEmployeeByReference(pEmployee + index);
        }
    }
    wait(SO);
}


void editEmployeeLastName(Employee* pEmployee, int tam)
{
    osDetect(SO);

    int file;
    int index;
    char resp;
    char newLastName[51];

    printf("\nIngrese legajo requerido: ");
    scanf("%d", &file);
    getchar();

    index = searchEmployee(pEmployee, tam, file);

    if(index == -1)
    {
        printf("\nNo hay ningun empleado con el legajo %d", file);
    }
    else
    {
        showEmployeeByReference(pEmployee + index);

        printf("\n\nModifica el Apellido?(s/n): ");
        fflush(stdin);
        scanf("%c", &resp);
        getchar();

        if(resp != 's')
        {
            printf("\nModificacion cancelada\n");
        }
        else
        {
            printf("\nIngrese Apellido: ");
            fgets(newLastName,51,stdin);
            fflush(stdin);
            removeNewLine(newLastName);
            stringToUpper(newLastName);

            strcpy((pEmployee + index)->lastName,newLastName);
            printf("\nPRESIONE [ENTER] PARA APLICAR LOS CAMBIOS");
            getchar();
            printf("\nMODIFICACION EXITOSA. LOS CAMBIOS SE HAN REGISTRADO\nPRESIONE [ENTER] PARA VERIFICAR LOS CAMBIOS\n\n");
            getchar();
            showEmployeeByReference(pEmployee + index);

        }
    }
    wait(SO);
}


void editEmployeeSection(Employee* pEmployee, int tam)
{
    osDetect(SO);
    int file;
    int index;
    char resp;
    int newSection;


    printf("\nIngrese legajo a modificar: ");
    scanf("%d", &file);
    getchar();

    index = searchEmployee(pEmployee, tam, file);

    if(index == -1)
    {
        printf("\nNo hay ningun empleado con el legajo %d", file);

    }


    else
    {
        showEmployeeByReference(pEmployee + index);

        printf("\n\nModifica el Sector?(s/n): ");
        fflush(stdin);
        scanf("%c", &resp);
        getchar();

        if(resp != 's')
        {
            printf("\nModificacion cancelada\n");
        }
        else
        {
            printf("\nIngrese ID Sector: ");
            fflush(stdin);
            scanf("%d", &newSection);
            getchar();


            (pEmployee + index)->idSection=newSection;
            printf("\nPRESIONE [ENTER] PARA APLICAR LOS CAMBIOS");
            getchar();
            printf("\nMODIFICACION EXITOSA. LOS CAMBIOS SE HAN REGISTRADO\nPRESIONE [ENTER] PARA VERIFICAR LOS CAMBIOS\n\n");
            getchar();
            showEmployeeByReference(pEmployee + index);
        }
    }
    wait(SO);
}



void hardcoreEmployee(Employee* pEmployee)
{
int i;
Employee employee[]=
{
    {1111, "ANA", "RUIZ",'F', 15000, 1, 1},
    {3333, "LUIS", "MANSILLA",'M', 45000, 3, 1},
    {4444, "ALBERTO", "BOLANIOS", 'M', 46000, 5, 1},
    {2845, "LUCRECIA", "AZCONZABAL",'F', 15000, 1, 1},
    {4589, "LUCIO", "PLAGGER",'M', 45000, 3, 1},
    {7777, "JUAN", "LOPEZ", 'M', 46000, 5, 1},
    {3212, "ROBERTO", "MACHADO", 'M', 46000, 4, 1},
};

for(i=0; i<7; i++)
{
    *(pEmployee+i) = employee[i];
}

}


void hardcoreSection(Section* pSection)
{
    int i;
    Section eSection[]=
    {
        {1,"RR.HH"},
        {2,"SISTEMAS"},
        {3,"CONTABILIDAD"},
        {4,"ADMINISTRACION"},
        {5,"LEGALES"},
    };

    for(i=0; i<5; i++)
    {
        *(pSection+i) = eSection[i];
    }

    }


void showSection(Section* pSection)
{
    osDetect(SO);

        printf("\n========= S E C T O R E S ===========");
        printf("\n\tID    \tSector");
        printf("\n=====================================\n");

    for(int i=0; i<5; i++)
    {

        printf("\n\t%d  \t%s", (pSection+i)->id, (pSection+i)->description);

    }
        printf("\n=====================================\n");

    printf("\n\n");
    wait(SO);
}


void showEmployeeBySection(Employee* pEmployee, int tam, Section* pSection, int tamSection)
{
    int i;
    int idSection;
    char description[20];
    int flag = 0;

    idSection = selectSection(pSection,5);
    osDetect(SO);

    loadDescription(pSection,TAM_SECTION,idSection,description);

    //osDetect(SO);
    //printf("Empleados del sector %s\n\n", description);

        for(i=0; i<5 ; i++)
        {

            if((pEmployee+i)->isEmpty == 1 && (pEmployee+i)->idSection == idSection)
            {
            showEmployee((pEmployee+i), pSection,TAM_SECTION);
            flag = 1;
            }
        }

    if(flag == 0)
    {
        printf("NO HAY EMPLEADOS EN EL SECTOR %s\n\n", description);
    }

    wait(SO);
}


int selectSection(Section* pSection, int tam)
{
    osDetect(SO);

    int idSection;

    printf("\nSectores\n\n");

    for(int i=0; i < tam; i++)
    {
        printf("%d %s\n", (pSection+i)->id, (pSection+i)->description);
    }

    printf("\nSeleccione sector: ");
    fflush(stdin);
    scanf("%d", &idSection);
    getchar();

    return idSection;
}

void loadDescription(Section* pSection, int tam, int idSection, char* string)
{
int i;

    for(i=0; i<5; i++)
    {
        if( (pSection+i)->id == idSection)
        {

            strcpy(string, (pSection+i)->description);
            break;
        }
    }
    printf("\nEmpleados de %s", string);
    wait(SO);
}


void loadDescriptionSection(Section* pSection, int tam, int idSection, char* string)
{
int i;

    for(i=0; i<5; i++)
    {
        if( (pSection+i)->id == idSection)
        {

            strcpy(string, (pSection+i)->description);
            break;
        }
    }
}

void sortEmployeesBySectionByName(Employee* pEmployee,int tam, Section* pSection, int tamSection)
{
    int i;
    int j;
    char descriptionI[20];
    char descriptionJ[20];
    Employee aux[tam];


    for(i=0; i<tam -1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            loadDescriptionSection(pSection,tamSection,(pSection+i)->id, descriptionI);//cargarDescripcion(sectores, tamSector, x[i].idSector, descripcionI);
            loadDescriptionSection(pSection,tamSection, (pSection+j)->id, descriptionJ);//cargarDescripcion(sectores, tamSector, x[j].idSector, descripcionJ);

            if( strcmp(descriptionI, descriptionJ) > 0)
            {
                aux[i] = *(pEmployee+i);
                *(pEmployee+i) = *(pEmployee+j);
                *(pEmployee+j) = aux[i];
            }
            else if( strcmp(descriptionI, descriptionJ) == 0 && strcmp((pEmployee+i)->name, (pEmployee+j)->name) > 0)
            {
                aux[i]=*(pEmployee+i);
                *(pEmployee+i)=*(pEmployee+j);
                *(pEmployee+j)=aux[i];
            }
        }
    }

osDetect(SO);

printf("\n==============================================================================");
printf("\n===========================E M P L E A D O S==================================");
printf("\n==============================================================================");
printf("\nLegajo    \tNombre    \tApellido  \tSexo  \tSalario   \tSector");
printf("\n==============================================================================");

  for(i=0; i<tam; i++)
  {
      if((pEmployee+i)->isEmpty == 1)
      {
        printf("\n%d", (pEmployee+i)->file);
        printf("\t%12s", (pEmployee+i)->name);
        printf("\t%15s", (pEmployee+i)->lastName);
        printf("\t%10c", (pEmployee+i)->sex);
        printf("\t%8.2f", (pEmployee+i)->salary);
        printf("\t%4d", (pEmployee+i)->idSection);

      }
    }
        printf("\n==============================================================================");
    wait(SO);
}

void sortEmployeeByNameOrder(Employee* pEmployee, int cant)
{
    int i;
    int j;
    Employee aux[cant];
        //pauxEmployee=&auxEmployee;

    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(strcmp(pEmployee[i].name,pEmployee[j].name) > 0)
               {
                   aux[i]=*(pEmployee+i);
                   *(pEmployee+i)=*(pEmployee+j);
                   *(pEmployee+j)=aux[i];
               }
        }
  }


osDetect(SO);

printf("\n==============================================================================");
printf("\n===========================E M P L E A D O S==================================");
printf("\n==============================================================================");
printf("\nLegajo    \tNombre    \tApellido  \tSexo  \tSalario   \tSector");
printf("\n==============================================================================");

  for(i=0; i<cant; i++)
  {
      if((pEmployee+i)->isEmpty == 1)
      {
        printf("\n%d", (pEmployee+i)->file);
        printf("\t%12s", (pEmployee+i)->name);
        printf("\t%15s", (pEmployee+i)->lastName);
        printf("\t%10c", (pEmployee+i)->sex);
        printf("\t%8.2f", (pEmployee+i)->salary);
        printf("\t%4d", (pEmployee+i)->idSection);

      }
    }
        printf("\n==============================================================================");
    wait(SO);
}

void showGreatestSalary(Employee* pEmployee, int tam, Section* pSection, int tamSection)
{
    float maxSalary;
    char description[20];
    int flag;
    int i;
    int j;

    for(i=0; i<tamSection; i++)
         {

         loadDescriptionSection(pSection,tamSection,(pSection+i)->id, description);

         //printf("Sector %s\n", description);

         flag = 0;

         for(j=0; j<tam; j++)
         {

            if( (pEmployee[j].salary > maxSalary && pEmployee[j].isEmpty == 1 && pEmployee[j].idSection == pSection[i].id) || flag == 0)

                {
                maxSalary = pEmployee[j].salary;
                flag = 1;
            }
         }


          for(int j=0; j < tam; j++)
            {
                if( pEmployee[j].salary == maxSalary)
                {
                showEmployee((pEmployee+j), pSection, tamSection);
                }
            }


          printf("\n\n");

    }

}

void sortBySalary(Employee* pEmployee, int tam)
{
    int i;
    int j;
    Employee aux[tam];

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(pEmployee[i].salary > pEmployee[j].salary)
            {
                aux[i]=*(pEmployee+i);
                *(pEmployee+i)=*(pEmployee+j);
                *(pEmployee+j)=aux[i];
            }
        }
    }

osDetect(SO);

printf("\n==============================================================================");
printf("\n===========================E M P L E A D O S==================================");
printf("\n==============================================================================");
printf("\nLegajo    \tNombre    \tApellido  \tSexo  \tSalario   \tSector");
printf("\n==============================================================================");

  for(i=0; i<tam; i++)
  {
      if((pEmployee+i)->isEmpty == 1)
      {
        printf("\n%d", (pEmployee+i)->file);
        printf("\t%12s", (pEmployee+i)->name);
        printf("\t%15s", (pEmployee+i)->lastName);
        printf("\t%10c", (pEmployee+i)->sex);
        printf("\t%8.2f", (pEmployee+i)->salary);
        printf("\t%4d", (pEmployee+i)->idSection);

      }
    }
        printf("\n==============================================================================");
    wait(SO);
}


