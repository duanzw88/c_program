#include <stdio.h>
#include <stdlib.h>


void static_test()
{
	static int i = 1;
	printf("i = %d\n",i++);
}
int main()
{

	static_test();
	static_test();
	return 0;
}