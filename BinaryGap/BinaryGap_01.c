#include <stdio.h>

/* 1. Find the first 1, and start to count the number of 0.
 * 2. If meet 0, add the gap_count.
 * 3. When meet the next 1, check if need to update max_gap, and reset gap_count as 0.
 */
int solution(int N)
{
	int is_one = 0, gap_count = 0, max_gap = 0;
	int tmp = N;

	for ( ; tmp > 0; tmp >>= 1 ){

		if ( (tmp & 1) ){
			if ( max_gap < gap_count )
				max_gap = gap_count;
			is_one = 1;
			gap_count = 0;
		}
		else {
			if (is_one == 1)
				gap_count++;
		}
	}

	return max_gap;
}


int main()
{
        // 1, no gap
	printf("Binary gap is %d\n", solution(1));

        // 10, no gap
	printf("Binary gap is %d\n", solution(2));

        // 101, gap is 1
	printf("Binary gap is %d\n", solution(5));

        // 100001000, gap is 4
        printf("Binary gap is %d\n", solution(264));

        // 1000001000010, gap is 5
        printf("Binary gap is %d\n", solution(4162));

        // 10000010001, gap is 5
        printf("Binary gap is %d\n", solution(1041));

        return 0;
}
