#include <stdio.h>
#include <string.h>

// Define our Employee struct 
typedef struct {
	long number;        
	char name[50];      
	char phone[20];    
	double salary;      
} Employee;

// Create a global array of Employees + a global integer counting them
Employee employees[] = {
	{1001, "Tyler Bacong", "626-123-2134", 8.78},
	{1011, "Umar Azizadah",  "989-555-5555", 9.50},
	{1140, "Julian Alfonso",   "888-888-8888", 8.32},
	{1241, "Allison Nguyen",     "213-546-9867", 6.47},
	{5045, "Nima Davarpanah",    "111-222-3333", 8.32}
};
int employeesSize = sizeof(employees) / sizeof(employees[0]);


// Generic search function using a function pointer for comparisons
// Return pointer to matching Employee or NULL if not found

static Employee *searchEmployeeTable(
	const Employee *startPtr,
	int size,
	const void *targetPtr,
	int (*compareFn)(const void *, const Employee *)
) {
	for (int i = 0; i < size; i++) {
		if (compareFn(targetPtr, &startPtr[i]) == 0) {
			// “0” means a match
			return (Employee *)&startPtr[i];  // cast away const
		}
	}
	return NULL; // no match
}

// Comparison functions for phone & salary

static int compareEmployeePhone(const void *targetPtr, const Employee *emp) {
	// targetPtr is "const char *" (the phone to find)
	const char *phoneToFind = (const char *)targetPtr;
	return strcmp(phoneToFind, emp->phone);
}

static int compareEmployeeSalary(const void *targetPtr, const Employee *emp) {
	//implement later
}

// public search functions for phone & salary (using function pointers)

Employee *searchEmployeeByPhone(const char *phoneToFind) {
	return searchEmployeeTable(
		employees, 
		employeesSize, 
		phoneToFind, 
		compareEmployeePhone
	);
}

Employee *searchEmployeeBySalary(double salaryToFind) {
	//implement later
}

