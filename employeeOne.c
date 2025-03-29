#include <string.h>
#include "employee.h"

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber) {
	const PtrToConstEmployee endPtr = ptr + tableSize;

	for (; ptr < endPtr; ptr++) {
		if (ptr->number == targetNumber)
			return (PtrToEmployee) ptr;
	}

	return NULL;
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName) {
	const PtrToConstEmployee endPtr = ptr + tableSize;

	for (; ptr < endPtr; ptr++) {
		if (strcmp(ptr->name, targetName) == 0)
			return (PtrToEmployee) ptr;
	}

	return NULL;
}

static PtrToEmployee searchEmployeeTable(
	PtrToConstEmployee ptr,
	int size,
	const void *targetPtr,
	int (*compareFn)(const void *, PtrToConstEmployee)
) {
	const PtrToConstEmployee endPtr = ptr + size;

	for (; ptr < endPtr; ptr++) {
		if (compareFn(targetPtr, ptr) == 0)
			return (PtrToEmployee) ptr;
	}

	return NULL;
}

// Comparison function for phone number 
static int comparePhone(const void *targetPtr, PtrToConstEmployee employee) {
	const char *targetPhone = (const char *)targetPtr;
	return strcmp(targetPhone, employee->phone);
}

// Comparison function for salary 
static int compareSalary(const void *targetPtr, PtrToConstEmployee employee) {
	double targetSalary = *(const double *)targetPtr;

	if (targetSalary < employee->salary) return -1;
	if (targetSalary > employee->salary) return 1;
	return 0;
}

// Search by phone — uses function pointer to comparePhone()
PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int size, char *targetPhone) {
	return searchEmployeeTable(ptr, size, targetPhone, comparePhone);
}

// Search by salary — uses function pointer to compareSalary()
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double targetSalary) {
	return searchEmployeeTable(ptr, size, &targetSalary, compareSalary);
}
