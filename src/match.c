/*
 ============================================================================
 Name        : match.c
 Author      : Avi Levy
 Version     :
 Copyright   : AdminTheWeb
 Description : this program get two strings and find the best match between them,
 *      the first string is the pattern for search, the second string is the text
 *      to search inside.
 *
 *      the program return int that represent the position in text that have the best match to
 *      the pattern
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 12	/* the max length for input strings*/

/*
 * Check the matching between to strings and return the position of the best match
 *
 * PARAMS
 * pattern - string to search for
 *
 * text - string to search in it
 *
 * RETURN
 * return integer that represent the position in the text string the has the best match
 * with the pattern string
 */
int string_match(char[MAX_STRING_LENGTH], char[MAX_STRING_LENGTH]);

int main(void) {
	char pattern[MAX_STRING_LENGTH], text[MAX_STRING_LENGTH]; /* Two string to get from user */
	char *p; /* Pointer to replace '/n'*/
	int bestPosition;

	/* Get strings from the user */
	printf("please enter pattern string (max %d chars): ", MAX_STRING_LENGTH-2);
	fgets(text,MAX_STRING_LENGTH,stdin);
	p = strchr(text,'\n');
	*p = '\0';
	printf("please enter text string (max %d chars): ", MAX_STRING_LENGTH-2);
	fgets(pattern,MAX_STRING_LENGTH,stdin);
	p = strchr(pattern,'\n');
	*p = '\0';

	/* print the best location for string matching */
	if ((bestPosition = string_match(text, pattern)) > -1){
		printf("\nThe best match found in: %d\n", bestPosition);
	} else {
		printf("\nNo match found\n");
	}
	return EXIT_SUCCESS;
}

/**
 * string_match: return the the best match between text and pattern
 */
int string_match(char text[MAX_STRING_LENGTH], char pattern[MAX_STRING_LENGTH]) {
	int textLength, patternLength, searchPointer, comperePointer, bestMatch;
	int currentMatch, maxMatch;

	maxMatch = bestMatch = -1; /* reset the paramters */
	textLength = strlen(text); /* get the length of text input */
	patternLength = strlen(pattern); /* get the length of pattern input */

	/* loop to check match for all the text string */
	for (searchPointer = 0; searchPointer < textLength; ++searchPointer) {
		currentMatch = -1; /* reset the number of found matches */

		/* loop to check all the pattern string */
		for (comperePointer = 0; comperePointer < patternLength;
				++comperePointer) {
			/*
			 * test if there is matching between text and pattern chars
			 * if so, it increment the match counter
			 */
			if (pattern[comperePointer]
					== text[searchPointer + comperePointer]) {
				if (currentMatch == -1){
					++currentMatch;
				}
				++currentMatch;
			}
		}

		/* test if the last macth test result is bigger then what saved as the bigger result */
		if (currentMatch > maxMatch) {
			maxMatch = currentMatch;
			bestMatch = searchPointer; /* update the location */
		}
	}

	return bestMatch; /* return the location of the best match */
}
