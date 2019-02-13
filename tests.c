/*
 * tests.c
 *
 *  Created on: 2/8/19
 *      Author: Hava Kantrowitz
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include "mystruct.h"

/**
 * determines if all tests run properly
 * @return true if all tests run successfully, false otherwise
 */
bool tests(void)
{
	srand(time(0));
	bool ok = false;

	bool ok1 = testPrintEmployee();
	if (ok1) {
		puts("printEmployee() passed.");
	}

	bool ok2 = testMakeEmployee();
	if (ok2) {
		puts("makeEmployee() passed.");
	}

	bool ok3 = testRandomInteger();
	if (ok3){
		puts("randomInteger() passed.");
	}

	bool ok4 = testRandomChar();
	if(ok4){
		puts("randomCharacter() passed.");
	}

	bool ok5 = testRandomString();
	if(ok5){
		puts("randomString() passed.");
	}

	bool ok6 = testRandomEmployee();
	if(ok6){
		puts("randomEmployee() passed.");
	}

	bool ok7 = testArrayEmployees();
	if(ok7){
		puts("arrayEmployee() passed.");
	}

	bool ok8 = testDuplicateEmployees();
	if(ok8){
		puts("duplicateEmployees() passed.");
	}

	bool ok9 = testFreeArray();
	if(ok9){
		puts("freeStructs() passed.");
	}

	bool ok10 = testDuplicateDeep();
	if(ok10){
		puts("duplicateDeep() passed.");
	}

	ok = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10; // Did all tests pass?
	return ok;
}

/**
 * Test the printEmployee() function by creating a known struct and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output.
 */

bool testPrintEmployee() {

	struct Employee e; // Variable to hold employee
	e.birth_year = 1952; // Put data into numeric fields
	e.start_year = 1999;
	// Copy into string field. Be sure not to overflow it.
	strncpy(e.name, "Mike Ciaraldi", MAX_NAME);
	e.name[MAX_NAME] = '\0'; // Be sure string is terminated.

	printEmployee(&e);

	return true;
}


/** Test the make Employee() function by making an employee with known data and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testMakeEmployee() {
	struct Employee *e;

	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	printEmployee(e);

	return true;
}

/**
 * Tests that a random integer is generated
 * @return true if an integer between 1000 and 3000 inclusive is generated
 * 		false otherwise
 */
bool testRandomInteger(){
	int number = randomNumber();
	bool ok = false;

	if (number >= 1000 && number <= 3000){
		ok = true;
		printf("Random integer is: %d\n", number);
	}

	return ok;
}

/**
 * Tests that a random character is generated
 * Prints letter
 * @return true, only way to tell if worked is to look at output
 */
bool testRandomChar(){
	char letter = randomCharacter();
	bool ok = true;

	printf("Random letter is: %c\n", letter);
	return ok;
}

/**
 * Tests that a random string is generated
 * Prints string
 * @return true if string is of given length, false otherwise
 */
bool testRandomString(){
	char* string = randomString(6);
	bool ok = false;

	int len = strlen(string);

	if (len == 6){
		ok = true;
	}

	printf("Random string is %s\n", string);
	return ok;
}

/**
 * Tests the creation of an employee struct filled with random data
 * Prints the employee
 * @return true, only way to tell if worked is to look at output
 */
bool testRandomEmployee(){
	struct Employee *e;

	e = randomStruct(12);
	printEmployee(e);

	return true;
}

/**
 * Tests the creation of an array of employee structs
 * Prints them out, thereby testing the printing of an array of employees
 * @return true, only way to tell if worked is to look at output
 */
bool testArrayEmployees(){
	bool ok = true;
	struct Employee* emp = arrayEmployees(4);
	printArray(emp, 4);
	return ok;
}

/**
 * Tests whether duplication of employee pointers works
 * @true if duplicated array is same as original array, false otherwise
 */
bool testDuplicateEmployees(){
	bool ok = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;

	struct Employee* emp = arrayEmployees(4);
	printArray(emp, 4);
	struct Employee* emp2 = duplicateArray(emp, 4);
	printArray(emp2, 4);

	if(emp[1].birth_year == emp2[1].birth_year){
		ok1 = true;
	}

	if(emp[2].start_year == emp2[2].start_year){
		ok2 = true;
	}

	if(strcmp(emp[3].name, emp2[3].name) == 0){
		ok3 = true;
	}

	ok = ok1 && ok2 && ok3;
	return ok;
}

bool testFreeArray(){
	bool ok = true;
	struct Employee* emp = arrayEmployees(4);
	freeStructs(emp, 4);


	return ok;
}

/**
 * Tests whether duplication of employee content works
 * @true if duplicated array is same as original array, false otherwise
 */
bool testDuplicateDeep(){
	bool ok = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;

	struct Employee* emp = arrayEmployees(4);
	printArray(emp, 4);
	struct Employee* emp2 = duplicateDeepArray(emp, 4);
	printArray(emp2, 4);

	if(emp[1].birth_year == emp2[1].birth_year){
		ok1 = true;
	}

	if(emp[2].start_year == emp2[2].start_year){
		ok2 = true;
	}

	if(strcmp(emp[3].name, emp2[3].name) == 0){
		ok3 = true;
	}

	ok = ok1 && ok2 && ok3;
	return ok;
}
