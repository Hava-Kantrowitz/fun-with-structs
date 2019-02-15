/*
 * mystring.c
 *
 *  Created on: Feb 4, 2019
 *      Author: Hava Kantrowitz
 */
#include <stdlib.h>
#include <stdio.h>
#include "mystring.h"

/**
 * Calculate the length of the string,
 * excluding the terminating null byte ('\0')
 * @param s constant character array to determine length of
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen1(const char* s)
{
	size_t n = 0;//initialize size to zero

	// Step through the array, counting up until we find the null terminator
	while (s[n] != '\0') {
		n++;//increment size
	}

	return n;//return the length of string
}
/**
 * Calculate the length of the string
 * excluding the terminating null byte ('\0')
 * @param s constant character array to determine length of
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen2(const char* s)
{
	size_t n = 0;//initialize size to zero

	// Keep incrementing the pointer until we find it is pointing to the null terminator
	while (*s != '\0') {
		n++;//increment size
		s++;//increment array pointer
	}

	return n;//return length of string
}

/** Duplicates a character string into a freshly-allocated block of memory.
 * @param s The string to duplicate.
 * @return Pointer to the new string.
 *         NULL if unable to allocate memory, errno holds the error code.
 */
char* mystrdup(char* s) {
	size_t length = mystrlen1(s); // Length of the original string

	// Allocate a block of memory big enough to hold all the characters of the original string,
	// plus the null terminator.
	char* newstr = (char*) malloc(length + 1);
	if (newstr) { // If allocation succeeded, copy into it
		mystrcpy(newstr, s);
	}
	return newstr;//return pointer to array created
}

/**
 * Copies the string from one location to another
 * @param dest: pointer to the first character in the array the string will be copied to
 * @param src: pointer to the first character in the string that is being copied
 * @return pointer to the first array element in the destination
 */
char* mystrcpy(char* dest, char* src) {

	char* firstDest = dest;//store pointer to first of destination array

	//Keep incrementing pointer until we hit null terminator
	while(*src != '\0'){
		*dest = *src;//set what dest is pointing to towards what src is pointing to
		//increment src and dest to move through arrays
		src++;
		dest++;
	}
	*dest = '\0';//put null terminator at end
	return firstDest;//return pointer to destination array
}

/**
 * Copies a specified amount of characters in a string string from one location to another
 * @param dest: pointer to the first character in the array the string will be copied to
 * @param src: pointer to the first character in the string that is being copied
 * @param n: number of characters to be copied
 * @return pointer to the first array element in the destination
 * 						If n is greater than the length of src, pad the difference with nulls
 * 						If n is less than or equal to the length of src, it copies over n characters
 * 							and doesn't null terminate
 */
char* mystrncpy(char* dest, char* src, size_t n) {

		char* firstDest = dest;//store pointer to first of destination array
		int j = 0;//counter for number of times around array, initialized to 0
		//Keep incrementing pointer until we hit null terminator
		//Or until the max n is reached
		while(*src != '\0' && j < n){
			*dest = *src;//set what dest is pointing to towards what src is pointing to
			//increment src and dest to move through arrays
			//increment j to move up in number of elements copied
			src++;
			dest++;
			j++;
		}
		//If the number of elements to copy hasn't been reached yet
		if (j < n){
			//Keep going until it is reached, putting nulls in the space
			while (j < n){
				*dest = '\0';
				j++;
			}
		}

		return firstDest;//return pointer to destination array
}

/**
 * Concatenates a specified amount of characters in a string into the end of another string
 * @param dest: pointer to the first character in the array the string will be copied to
 * @param src: pointer to the first character in the character array (string) that is being copied
 * @param n: number of characters to be copied
 * @return pointer to the first array element in the destination
 * 						Resulting string is always null terminated
 */
char* mystrncat(char* dest, char* src, size_t n) {

		char* firstDest = dest;//store pointer to first of destination array
		int j = 0;//counter for number of times around array, initialized to 0

		//Keep incrementing pointer to destination array until null terminator is hit
		while (*dest != '\0'){
			dest++;
		}
		//If null terminator has been hit
		//Keep incrementing pointer until we hit null terminator of src
		//Or until the max n is reached
		if (*dest == '\0'){
		while(*src != '\0' && j < n){
			*dest = *src;//set what dest is pointing to towards what src is pointing to
			//increment src and dest to move through arrays
			//increment j to move up in number of elements copied
			src++;
			dest++;
			j++;

		}
		}

		*dest = '\0';//put a null terminator at the end

		return firstDest;//return pointer to zeroth element of dest
}

/**
 * Concatenates a specified amount of characters in a string into the end of another string
 * @param dest: pointer to the first character in the array the string will be copied to
 * @param src: pointer to the first character in the character array (string) that is being copied
 * @return pointer to the first array element in the destination
 */
char* mystrcat(char* dest, char* src) {
		char* firstDest = dest;//store pointer to first of destination array

		//Keep incrementing pointer to dest until we hit null terminator
		while (*dest != '\0'){
			dest++;
		}
		//Overwrite null terminator, and
		//Keep incrementing pointer until we hit null terminator of src
		if (*dest == '\0'){
		while(*src != '\0'){
			*dest = *src;//set what dest is pointing to towards what src is pointing to
			//increment src and dest to move through arrays
			src++;
			dest++;

		}
		}

		*dest = '\0';//put a null terminator at the end

		return firstDest;//return pointer to zeroth element of dest
}

/** Duplicates n bytes of a character string into a freshly-allocated block of memory.
 * @param s The string to duplicate.
 * @param n number of bytes in source string to duplicate
 * @return Pointer to the new string.
 *         NULL if unable to allocate memory, errno holds the error code.
 *         If n is longer than s, the space will be padded with nulls
 *         If n is shorter than s, only n bytes will be duplicated, and a null character will be added to the end
 *         If n is the same length as s, all n bytes will be duplicated and a null character will be added to the end
 */
char* mystrndup(char* s, size_t n) {

	// Allocate a block of memory big enough to n characters of the original string,
	// plus the null terminator.
	char* newstr = (char*) malloc(n + 1);
	if (newstr) { // If allocation succeeded, copy into it
		//copy only the first n characters
		mystrncpy(newstr, s, n);
		//Already has nulls from mystrncpy
	}
	char* startNew = newstr;
	for (int i = 0; i < n; i++){
		newstr++;
	}
	newstr = '\0';
	return startNew;//return pointer to allocated array
}
