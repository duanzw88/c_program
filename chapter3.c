#include <stdio.h>
#include <stdlib.h>

int checkSum();
void reverse();

#define REVERSE 5

int main()
{
	//double x = 500000;
	//printf("x = %.2g\n",x);

	//printf("checksum = %d\n",checkSum());

	//4.4 不推荐的语句(会因机器的不同产生不同的后果)
	/*
	int a = 5;
	int b,c;
	c = (b = a + 2) - (a = 1);
	printf("c = %d\n",c);
	int i = 2;
	int j = 0;
	//j = i * i++;  //j = 4
	j = i * (++i);  //j = 6
	printf("j = %d\n",j);
	*/
	reverse();
}

/*
计算条形码最后一位检验码
*/
int checkSum()
{
	
	int first;
	int m1,m2,m3,m4,m5;
	int l1,l2,l3,l4,l5;
	printf("input first num:");
	scanf("%d",&first);
	printf("\ninput 5 middle num:");
	scanf("%1d%1d%1d%1d%1d",&m1,&m2,&m3,&m4,&m5);
	printf("\ninput the 5 last num:");
	scanf("%1d%1d%1d%1d%1d",&l1,&l2,&l3,&l4,&l5);

	int first_sum = first + m2 + m4 + l1 + l3 + l5;
	int second_sum = m1 + m3 + m5 + l2 + l4;
	int total = 3 * first_sum + second_sum;

	int result = 9 - ((total - 1) % 10);

	return result;
}
void reverse()
{
	char *a = (char *)malloc(REVERSE * sizeof(char));
	scanf("%s",a);
	
	for(int i = REVERSE - 1;i >= 0; i--)
	{
		printf("%d",a[i] - 48);
	}
	printf("\n");
}