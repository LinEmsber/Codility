#include <stdio.h>
#include <stdlib.h>

int cmp_fun (const void * a, const void * b)
{
        return ( *(int*)a - *(int*)b );
}

int solution(int A[], int N)
{
	int i = 0;
	/* Set ret as 1, if the numbers of array are all negative. */
	int ret = 1;

	qsort(A, N, sizeof(int), cmp_fun);

	/* Start from the index of positive number. */
	while (i < N && A[i] < 1 )
		i++;

	while (i < N && ret == A[i]) {
		while (i < N - 1 && A[i] == A[i + 1] ) {
			i++;
		}
		i++;
		ret++;
	}

	return ret;
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
