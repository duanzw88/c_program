/*
horner称作“霍纳法则”
作用：多项式求值的一个高效方法
本例求3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
*/
#include<stdio.h>

#define SIZE 6
/*
运用递归实现霍纳法则
*/
float horner_rule3(float a[],int n,float x)
{
	if(n == 1)
	{
		return a[n-1];
	}

	return horner_rule3(a,n-1,x) * x + a[n-1];
}
float horner_rule2(float a[],int n,float x)
{
	int ret = 0.0f;
	printf("a[%d] = %.2f\t",n,a[n]);
	if(n == SIZE - 1)
	{
		printf("########%f\n",a[n] );
		return a[n];
	}
	//printf("ret = %f\n",horner_rule2(a,n,i+1,x) * x + a[i]);
	return horner_rule2(a,n+1,x) * x + a[n];
}

float horner_rule(float a[],int n,float x)
{
	float ret = 0.0f;
	int i;
	printf("x = %f\n",x);
	for(i = 0 ;i < n ;i++)
	{
		ret = x * ret + a[i];
		printf("a[%d] = %.2f\tret = %.2f\n",i,a[i],ret);
	}

	return ret;

}
int main(int argc,char* argv[])
{
	float a[6] = {3,2,-5,-1,7,-6};
	//float a[6] = {3,2};
	float a1[6] = {-6,7,-1,-5,2,3};
	float x = 2;
	//printf("input the x:\n");
	//scanf("%f",&x);
	printf("result = %f\n",horner_rule3(a,6,x));

	return 0;
}