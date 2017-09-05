#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000000000

int solution(int A[], int N)
{
	int i;
	int result = 0;
	for (i = 0; i < N; i++){
		result ^= A[i];
	}

	return result;
}

int main()
{
	int arr_1[] = {9, 3, 9, 3, 9, 7, 9};
	int arr_2[] = {100, 5, 100, 7, 8, 5, 200, 8, 7};
	int arr_3[] = {-2147483648, 9, 3, 9, 3, 100, 5, 100, 7, 8, 5, 200, 8, 7, 9, 17, 9, 17};

	printf("Unpaired element is %d\n", solution(arr_1, sizeof(arr_1)/sizeof(int)));
	printf("Unpaired element is %d\n", solution(arr_2, sizeof(arr_2)/sizeof(int)));
	printf("Unpaired element is %d\n", solution(arr_3, sizeof(arr_3)/sizeof(int)));

	return 0;
}
