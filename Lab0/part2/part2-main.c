#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int oddball(int *arr, int len);
int randGenerator(int *arr, int len);

#ifndef N
	#define N (40)
#endif

#define ARRLEN (2*(N) - 1)

int main()
{
        clock_t start, finish;
	/* Keep this line here */
	srand(time(NULL));

	int *arr = malloc(ARRLEN*sizeof(int));
	int num;

	if (!arr) {
		return -1;
	}

	randGenerator(arr, ARRLEN);
        start = clock();
	num = oddball(arr, ARRLEN);
        finish = clock();
	printf("Oddball is %d\n", num);
        printf("Execution time: %f seconds\n", (double)(finish-start)/CLOCKS_PER_SEC); 
	return 0;
}

