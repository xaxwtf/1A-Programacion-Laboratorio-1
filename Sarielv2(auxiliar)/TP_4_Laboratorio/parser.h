#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED
#include "LinkedList.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
#endif // parser_H_INCLUDED
