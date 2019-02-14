#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "mystruct.h"

/**
 * Main function to start program and ensure production and tests
 * go smoothly
 * @param argc Number of words on the command line
 * @param argv Array of pointers to character strings representing the words on the command line.
 * @return exit_success if all code in main ran successfully
 */
int main(int argc, char *argv[]) {
	puts("!!!Hello class, we are working HW3B!!!"); /* prints !!!Hello World!!! */
	//If tests pass, let user know and start production
	if(tests())
	{
		puts("Tests succeeded.");
		if(production(argc, argv))
		{
			puts("Production successful.");
		}
		else
		{
			puts("Tests succeeded, but production didn't");
		}
	}
	//Tests don't pass, let user know
	else
	{
		puts("Tests did not succeed.");
	}

	return EXIT_SUCCESS;//return if success
}
