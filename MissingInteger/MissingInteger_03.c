#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 1. Create a B table to run the value which is less than 100,000, and larger than 0.
 * 2. if( A[i] >= 0 && A[i] <= N ), then set a mark on B[A[i]].
 * 3. Search the smallest value from B[i].
 */

void  set_bit(int * A,  int k)
{
	A[k / 32] |= ( (unsigned int) 0x1 << (k % 32) );
}
int test_bit(int * A,  int k)
{
	return ( A[k / 32] & ( (unsigned int) 0x1 << (k % 32) ) ) != 0;
}

int solution(int A[], int N)
{
	int i, tmp;
	size_t unit_N = ((N - 1) / 32) + 1;
	int B[unit_N];
	memset(B, 0, sizeof(B));

	for(i = 0; i < N; i++) {
		if( A[i] >= 0 && A[i] <= N ){
			set_bit(&B, i);
		}
	}

	for(i = 1; i <= N; i++)  {
		if( test_bit(&B, i) )
			// TODO: fix the return value
			return (i*32) + (i%32) - 32 ;
	}

	return N + 1;
}

int main()
{
	int arr_1[6] = {2, 3, 6, 4, 1, 2};
	int arr_2[3] = {1, 2, 3};
	int arr_3[2] = {-1, -3};
        int arr_4[8] = {-1, -3, -5, 2, 4, 8, 1000000, -1000000};

	printf("MissingInteger: %d\n", solution(arr_1, 6));
	printf("MissingInteger: %d\n", solution(arr_2, 3));
	printf("MissingInteger: %d\n", solution(arr_3, 2));
        // printf("MissingInteger: %d\n", solution(arr_4, 8));

	return 0;
}
