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

	ok = ok1 && ok2 && ok3 && ok4 && ok5 && ok6; // Did all tests pass?
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

bool testRandomInteger(){
	int number = randomNumber();
	bool ok = false;

	if (number >= 1000 && number <= 3000){
		ok = true;
		printf("Random integer is: %d\n", number);
	}

	return ok;
}

bool testRandomChar(){
	char letter = randomCharacter();
	bool ok = true;

	printf("Random letter is: %c\n", letter);
	return ok;
}

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

bool testRandomEmployee(){
	struct Employee *e;

	e = randomStruct(12);
	printEmployee(e);

	return true;
}
