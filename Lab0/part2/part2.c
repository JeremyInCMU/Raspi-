#include <stdlib.h>
#include <stdio.h>
/**
 * Function: oddball
 * Description: Baseline implementation for finding the number that
 *   occurs only once in the array.
 * Arguments:
 *   arr - pointer to start of integer array
 *   len - number of elements in array
 * Return:
 *   The number that occurs only once
 *   with the maximum index.
 */
#ifdef DEFAULT
int oddball(int *arr, int len) {
	int i, j;
	int foundInner;
	int result = 0;

	for (i = 0; i < len; i++) {
		foundInner = 0;
		for (j = 0; j < len; j++) {
			if (i == j) {
				continue;
			}
			if (arr[i] == arr[j]) {
				foundInner = 1;
			}
		}
		if (foundInner != 1) {
			result = arr[i];
		}
	}
	return result;
}
#endif

#ifdef OPTIMIZE1
int oddball(int *arr, int len) {
	/* Put your code here */
	int i, j;
        int foundInner_0;
        int foundInner_1;
        int foundInner_2;
        int foundInner_3;
        int result = 0;
       
        for (i = len - 1; i >=0; i--) {
		foundInner_0 = 0;
                foundInner_1 = 0;
                foundInner_2 = 0;
                foundInner_3 = 0;
		for (j = len - 1; j >= 0; j-=4) {
			if (i == j) {
				continue;
			}
			if (arr[i] == arr[j]) {
				foundInner_0 = 1;
			}
                        if (arr[i] == arr[j+1]) {
                                foundInner_1 = 1;
                        }
                        if (arr[i] == arr[j+2]) {
                                foundInner_2 = 1;
                        }
                        if (arr[i] == arr[j+3]) {
                                foundInner_3 = 1;
                        }
		}
		if (foundInner_0 == 0 && foundInner_1 == 0 
                    && foundInner_2 == 0 && foundInner_3 == 0) {
			result = arr[i];
		}
        }
	return result;
}
#endif

#ifdef OPTIMIZE2
int oddball(int *arr, int len) {
	/* Put your code here */
	return 0;
}
#endif

/**
 * Function: randGenerator
 * Description: Generate a random array that is in compliance with
 *   lab specification
 * Arguments:
 *   arr - pointer to start of integer array
 *   len - number of elements in array
 * Return:
 *   Unused, but feel free to utilize it.
 */
#ifndef RNG
int randGenerator(int *arr, int len) {
	int i, j, r, rcount;
	for (i = 0; i < len; i++) {
		do {
			rcount = 0;
			r = rand()%(len/2 + 1) + 1;
			for (j = 0; j < i && rcount < 2; j++) {
				if (arr[j] == r) {
					rcount++;
				}
			}
		} while(rcount >= 2);
		arr[i] = r;
		printf("%d ", r);
	}
	printf("\nDone generating\n");
	return 0;
}

#else
int randGenerator(int *arr, int len) {
	/* Put your code here */
	return 0;
}
#endif


