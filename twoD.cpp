#include <stdio.h>
#include <stdlib.h>
#include "twoD.h"
#include "Organism.h"

/** Make a 2D array of integers (this is an example)
 *
 * @param nrows Number of rows
 * @param ncolumns Number of columns
 * @return Pointer to the array of pointers to the rows.
 * 	  or null pointer if unable to allocate memory.
 * 	  Note: Will not free partially-allocated memory.
 *
 * @author Mike Ciaraldi
 */

int** make2Dint(int nrows, int ncolumns) {

	int **a; // Array of pointers to rows
	unsigned int i; // Loop counter

	// First allocate the array of pointers to rows
	a = (int **) malloc(nrows * sizeof(int *));
	if (!a) { // Unable to allocate the array
		return (int **) NULL;
	}

	// Now allocate array for each row
	for (i = 0; i < nrows; i++) {
		// i is the row we are about to allocate
		a[i] = malloc(ncolumns * sizeof (int));
		if (!a[i]) {
			return (int **) NULL; // Unable to allocate
		}
	}
	return a;
}

/**
 * You need to fill in this function and its header comment.
 * It should be quite similar to make2Dint
 */
char** make2Dchar(int size) {

	char **a; // Array of pointers to rows
	unsigned int i; // Loop counter

	// First allocate the array of pointers to rows
	a = (char**) malloc(size * sizeof(char*));
	if (!a) { // Unable to allocate the array
		return (char**) NULL;
	}

	// Now allocate array for each row
	for (i = 0; i < size; i++) {
		// i is the row we are about to allocate
		a[i] = malloc(size * sizeof (char));
		if (!a[i]) {
			return (char**) NULL; // Unable to allocate
		}
	}
	return a;
}

Organism** make2Dorg(int size) {

	Organism **a; // Array of pointers to rows
	unsigned int i; // Loop counter

	// First allocate the array of pointers to rows
	a = (Organism**) malloc(size * sizeof(Organism*));
	if (!a) { // Unable to allocate the array
		return (Organism**) NULL;
	}

	// Now allocate array for each row
	for (i = 0; i < size; i++) {
		// i is the row we are about to allocate
		a[i] = malloc(size * sizeof (Organism));
		if (!a[i]) {
			return (Organism**) NULL; // Unable to allocate
		}
	}
	return a;
}
