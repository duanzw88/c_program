#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>



//void rand_card(void);
//void analyze_hand(void);
//void print_result(void);

//#define NUM_SUITS 4
#define NUM_RANKS 10


//int test[NUM_SUITS][NUM_RANKS];

int main()
{
	int a[NUM_RANKS] = {1,2,3,4,5,6,7,8,9,10};
	int *p = &a[0];
	int *q = &a[NUM_RANKS - 1];
	int temp;

	while(p < q)
	{
		temp = *p;
		*p++ = *q;
		*q-- = temp;
	}

	for(p = &a[0];p <= &a[NUM_RANKS - 1];p++)
	{
		printf("%d\n",*p );
	}

	return 0;
}