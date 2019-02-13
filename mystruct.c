/** mystruct.c
 * @author Hava Kantrowitz
 * @date 2/8/19
*/


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mystruct.h"

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the employee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {

	struct Employee emp;
	int empLength = sizeof(emp);

	struct Employee* emp2 = malloc(empLength);
	emp2->birth_year = birth;
	emp2->start_year = start;
	int i = 0;
	while (*name != '\0'){
		emp2->name[i] = *name;
		name++;
		i++;
	}
	emp2->name[i+1] = '\0';

	return emp2; // Replace this with a pointer to the allocated struct
}

/**
 * Prints out birth year, starting year, and name for employee
 * @param e pointer to first location in memory of given employee
 * @return void, prints employee information to console
 */
void printEmployee(struct Employee *e) {

	int birthYear = e->birth_year;
	int startYear = e->start_year;
	char* name = e->name;


	printf("Birth year = %d\n", birthYear);
	printf("Starting year = %d\n", startYear);
	printf("Name = %s\n", name);


}

/**
 * Generates a random number
 * @return a number between 1000 and 3000 inclusive
 * 			This program assumes that the person will
 * 			Be born and start working sometime between that time frame
 */
int randomNumber(){
	int number = rand() % 2001;
	int usefulNumber = number + 1000;
	return usefulNumber;
}

/**
 * Generates a random character
 * @return a capital letter, A-Z
 */
char randomCharacter(){
	int number = rand() % 26;
	char letter = *(letters+number);
	return letter;
}

/**
 * Generates a random string
 * @param stringLen : length of string to be generated
 * @return pointer to string generated
 * 		String could contain letters A-Z
 */
char* randomString(int stringLen){
	int charSize = sizeof(char);
	char* randString = malloc((charSize*stringLen) + 1);
	for (int i = 0; i < stringLen; i++){
		randString[i] = randomCharacter();
	}
	randString[stringLen] = '\0';

	return randString;

}

/**
 * Generates an employee struct with random data
 * @param stringLen: length of string to be generated for name field
 * @return pointer to created employee struct
 */
struct Employee* randomStruct(int stringLen){
	int birth = randomNumber();
	int start = randomNumber();
	char* name = randomString(stringLen);

	struct Employee* emp = makeEmployee(birth, start, name);
	return emp;
}
