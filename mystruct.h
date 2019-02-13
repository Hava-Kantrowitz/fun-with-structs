/** mystruct.h
 * @author Hava Kantrowitz
 * @date 2/8/19
 * Sample structs
*/

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employe started with the company.
	char name[MAX_NAME + 1];
};

//All the letters
static const char* letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function prototype(s):
struct Employee *makeEmployee(int birth, int start, const char* name);
void printEmployee(struct Employee *e);
int randomNumber();
char randomCharacter();
char* randomString(int stringLen);
struct Employee* randomStruct(int stringLen);
struct Employee* arrayEmployees(int count);
void printArray(struct Employee* e, int count);
struct Employee* duplicateArray(struct Employee* e, int count);
void freeStructs(struct Employee* e, int count);
