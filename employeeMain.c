#include <stdio.h>
#include <string.h>
#include "employee.h"

// “extern” references to the global table & size
extern Employee EmployeeTable[];
extern const int EmployeeTableEntries;

// Prototypes for two of the search functions in employeeOne.c
extern PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee, int, const char*);
extern PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee, int, double);

int main(void) {
	PtrToEmployee matchPtr;


	//Search by Phone - MATCH
	matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "989-555-1255");
	if (matchPtr != NULL)
		printf("[PHONE MATCH] Found: %s (ID=%ld)\n", matchPtr->name, matchPtr->number);
	else
		printf("[PHONE MATCH] No record found.\n");

	//Search by Phone - NO MATCH
	matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "999-999-9999");
	if (matchPtr != NULL)
		printf("[PHONE NO MATCH] Unexpectedly found: %s\n", matchPtr->name);
	else
		printf("[PHONE NO MATCH] Correct - not in table.\n");

	//Search by Salary - MATCH
	matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.32);
	//implement later

	//Search by Salary - NO MATCH
	matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 99.99);
	//implement later
	return 0;
}
