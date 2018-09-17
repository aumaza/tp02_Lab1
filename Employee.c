#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Employee.h"
#include "misFunciones.h"

#define lenghMax 1000

/** \brief to indicate that all position in the array are empty,
 *         this function put the flag (isEmpty) in TRUE in all position of the array.
 * \param  list Employee* pointer to array of employees
 * \param  len int array lenght
 * \return int Return (-1) if error (invalid lenght or NULL pointer) 0 if all OK.
 *
 */


int initEmployees(Employee* list, int len)

{
int i;
int retorno = -1;


Employee* returnAux = NULL;
//Employee* pEmployee = malloc(sizeof(Employee));

if(len>0 && returnAux != NULL)
{
    for(i=0; i<len; i++)
    {
        retorno=0;
        returnAux->id=0;
        returnAux->isEmpty=0;
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

