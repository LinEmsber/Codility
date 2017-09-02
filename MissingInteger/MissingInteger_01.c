#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(int A[], int N)
{
	int i, B[N];
	memset(B, 0, sizeof(B));

	/* 1. Create a B table to run the value which is less than 100,000, and larger than 0.
	 * 2. if( A[i] >= 0 && A[i] <= N ), then set a mark on B[A[i]].
	 * 3. Search the smallest value from B[i].
	 */
	for(i = 0; i < N; i++) {
		if( A[i] >= 0 && A[i] <= N )
			B[A[i]] = -1;
	}

	for(i = 1; i <= N; i++)  {
		if(B[i] != -1)
			return i;
	}

	return N + 1;
}

int main()
{
	int arr_1[6] = {1, 3, 6, 4, 1, 2};
	int arr_2[3] = {1, 2, 3};
	int arr_3[2] = {-1, -3};
        int arr_4[8] = {-1, -3, -5, 2, 4, 8, 1000000, -1000000};

	printf("MissingInteger: %d\n", solution(arr_1, 6));
	printf("MissingInteger: %d\n", solution(arr_2, 3));
	printf("MissingInteger: %d\n", solution(arr_3, 2));
        printf("MissingInteger: %d\n", solution(arr_4, 8));

	return 0;
}
