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

	struct Employee emp;//Create an employee struct
	int empLength = sizeof(emp);//Take size of it

	struct Employee* emp2 = malloc(empLength);//Allocate enough memory for an employee
	emp2->birth_year = birth;//set birth year
	emp2->start_year = start;//set start year
	int i = 0;
	//set name field
	while (*name != '\0'){
		emp2->name[i] = *name;
		name++;
		i++;
	}
	emp2->name[i+1] = '\0';//Make sure name ends with null pointer

	return emp2; // Return pointer to allocated struct
}

/**
 * Prints out birth year, starting year, and name for employee
 * @param e pointer to first location in memory of given employee
 * @return void, prints employee information to console
 */
void printEmployee(struct Employee *e) {

	int birthYear = e->birth_year;//grab birth year
	int startYear = e->start_year;//grab start year
	char* name = e->name;//grab name


	//print all fields
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
	int number = rand() % 2001;//Generates random number between 0-2000
	int usefulNumber = number + 1000;//Makes sure random number is between 1000-3000
	return usefulNumber;//return random number
}

/**
 * Generates a random character
 * @return a capital letter, A-Z
 */
char randomCharacter(){
	int number = rand() % 26;//generates random number 0-25
	//goes through letters constant (see .h) and finds the one at the location pointed to by number
	char letter = *(letters+number);
	return letter;//returns the character
}

/**
 * Generates a random string
 * @param stringLen : length of string to be generated
 * @return pointer to string generated
 * 		String could contain letters A-Z
 */
char* randomString(int stringLen){
	int charSize = sizeof(char);//finds the size of characters
	char* randString = malloc((charSize*stringLen) + 1);//allocates enough room for the string
	//populates the string with random characters
	for (int i = 0; i < stringLen; i++){
		randString[i] = randomCharacter();
	}
	randString[stringLen] = '\0';//makes sure string is null terminated

	return randString;//returns string

}

/**
 * Generates an employee struct with random data
 * @param stringLen: length of string to be generated for name field
 * @return pointer to created employee struct
 */
struct Employee* randomStruct(int stringLen){
	int birth = randomNumber();//generates random birth year
	int start = randomNumber();//generates random start year
	char* name = randomString(stringLen);//generates random string of given length

	struct Employee* emp = makeEmployee(birth, start, name);//creates an employee with this info
	return emp;//returns pointer to the employee
}

/**
 * Allocates an array with a specified number of employees
 * 	filled with random data
 * @param count : number of employee structs to have in array
 * @return pointer to first employee in array
 */
struct Employee** arrayEmployees(int count){

	struct Employee** emp2 = malloc(sizeof(struct Employee*) * count);//allocate enough memory for the array
	struct Employee** emp2begin = emp2;//set pointer to beginning of array

	for(int i = 0; i < count; i++){
		int randLen = (rand() % 10) + 1;//generate random number 1-10 for length of string
		struct Employee* emp3 = randomStruct(randLen);//create random employee
		emp2[i] = emp3;//set randomly created employee struct into array
	}

	return emp2begin;//return pointer to array of employee
}

/**
 * Prints out an array of employee structs
 * @param e : array of employee structs to print out
 * @param count : number of employee structs in given array
 * @return void, prints all arrays
 */
void printArray(struct Employee** e, int count){

	//loop through array
	for(int i = 0; i < count; i++){
		struct Employee *emp = e[i];
		 printf("Employee %d:\n", i+1);//print employee number
		 printEmployee(emp);//print employee
	}
}

/**
 * Duplicates the pointers in an array into another array
 * @param e : array of Employee pointers to be duplicated
 * @param count : size of array to be duplicated
 * @return pointer to duplicated array
 */
struct Employee** duplicateArray(struct Employee** e, int count){
	struct Employee** emp2 = malloc(sizeof(struct Employee*) * count);//allocate enough memory for the array
	struct Employee** emp2begin = emp2;//set pointer to the beginning of array

	//loop through array
	for(int i = 0; i < count; i++){
		emp2[i] = e[i];//set pointers to each other
	}

	return emp2begin;//return pointer to array
}

/**
 * Frees all employee structs in an array
 * @param e : array of employee structs to free
 * @param count : number of employees in array
 * @return void
 */
void freeStructs(struct Employee** e, int count){

	//frees all individual employee structs in array
	for (int i = 0; i < 4; i++){
		free(e[i]);
	}

	free(e);//frees entire array

}

/**
 * Duplicates the content in an array into another array
 * @param e : array of Employee pointers to be duplicated
 * @param count : size of array to be duplicated
 * @return pointer to duplicated array
 */
struct Employee** duplicateDeepArray(struct Employee** e, int count){

	struct Employee** emp2 = malloc(sizeof(struct Employee*) * count);//allocate enough memory for the array
	struct Employee** emp2begin = emp2;//save pointer to beginning of array

	//loop through array
	for(int i = 0; i < count; i++){
		emp2[i] = makeEmployee(e[i]->birth_year, e[i]->start_year, e[i]->name);//Create a new employee at each location with old fields
	}

	return emp2begin;//return pointer to array of employee

}



