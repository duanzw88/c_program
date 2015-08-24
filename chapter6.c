#include <stdio.h>

/**
*求两个数的最大公约数(欧几里得算法)
*无递归版本
*/
int gcd1(int m,int n)
{
	int c;
	while(n)
	{
		c = m % n;
		m = n;
		n = c;
	}

	return m;
}
/*
*使用递归求最大公约数(欧几里得算法)
*/
int gcd(int m,int n)
{
	return n ? gcd(n,m % n) : m;
}
int main()
{
	//int a = 12;
	//int b = 6;
	//printf("%d\n",gcd(a,b));

	unsigned short x = 1;

	scanf("%d",&x);
	printf("%d\n",x);
}