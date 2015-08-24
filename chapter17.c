
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 5
#define MAX_REMIND 50
#define MSG_LEN		60

//函数指针
void tabulate(double (*f)(double),double first,double last,double incr);
/*
自己的输入函数
跳过开头的空白符
遇到第一个换行符停止
忽略额外的字符
str 存储输入的数组
n	读入字符的最大数量
return 实际存储在str中的字符数
*/
int read_line(char str[],int n)
{
	int ch,i = 0;
	while((ch = getchar()) != '\n')
	{
		if(i < n)
		{
			str[i++] = ch;
		}
	}
	str[i] = '\0';
	return i;

}

void date_notepad()
{
	char *reminders[MAX_REMIND];
	int day,num_remind = 0;
	char day_str[3],msg_str[MSG_LEN + 1];
	int i,j;

	while(1)
	{
		if(num_remind == MAX_REMIND)
		{
			printf("-- No Space left -- \n");
			break;
		}
		printf("Enter day and reminder: ");
		scanf("%2d",&day);
		if(day == 0)
		{
			break;
		}
		sprintf(day_str,"%2d",day);
		read_line(msg_str,MSG_LEN);
		//排序
		for(i = 0;i < num_remind;i++)
		{
			if(strcmp(day_str,reminders[i]) < 0)
			{
				break;
			}
		}
		for(j = num_remind;j > i;j--)
		{
			reminders[j] = reminders[j - 1];
			//strcpy(reminders[j],reminders[j - 1]);
		}

		reminders[i] = malloc(2 + strlen(msg_str) + 1);
		if(reminders[i] == NULL)
		{
			printf("-- malloc failed --\n");
			break;
		}

		strcpy(reminders[i],day_str);
		strcat(reminders[i],msg_str);

		num_remind++;
	}

	printf("\n Day Reminder\n");
	for(i = 0; i < num_remind;i++)
	{
		printf("%s\n",reminders[i]);
	}
	
}


/*
*利用函数指针来显示cos函数、sin函数和tan函数
*/
void tabulate(double (*f)(double),double first,double last,double incr)
{
	double x;
	int i,num_intervals;

	num_intervals = ceil((last - first) / incr);
	for(int i = 0;i <= num_intervals;i++)
	{
		x = first + i * incr;
		printf("\t    %10.5f    \t%10.5f\n",x,(*f)(x));
	}
}
double xx(double x)
{
	return x + 2.0;
}
void tabulate_test()
{
	double final,increment,initial;
	printf("Enter initial value:");
	scanf("%lf",&initial);

	printf("Enter final value:");
	scanf("%lf",&final);

	printf("Enter increment:");
	scanf("%lf",&increment);


	printf("\n 		   x		cos(x)");
	printf("\n 		------   	-------\n");
	tabulate(cos,initial,final,increment);
	printf("\n 		   x		sin(x)");
	printf("\n 		------   	-------\n");
	tabulate(sin,initial,final,increment);
	printf("\n 		   x		tan(x)");
	printf("\n 		------   	-------\n");
	tabulate(xx,initial,final,increment);
	
}

/*
*测试受限指针restrict
*两个内存拷贝的函数原型如下：
*void *memcpy(void * restrict s1,const void * restrict s2,size_t n)
*void *memmove(void * s1,const void * s2,size_t n)
*memcpy中形参为restrict类型，说明复制的源和目的不应互相重叠
*memmove可以保证当源和目的相互重叠是依然执行复制过程
*/
void testRestrict()
{
	// int a[100];
	// for(int i = 0;i < 100;i++)
	// {
	// 	a[i] = i;
	// }

	// //使用memcpy复制
	// //memcpy(&a[0],&a[1],99 * sizeof(int));
	// memmove(&a[0],&a[1],99 * sizeof(int));
	// for(int i = 0;i < 100;i++)
	// {
	// 	printf("a[%d] = %d\n",i,a[i]);
	// }

	//int x = 1;
	int * restrict p;
	int * restrict q;
	p = malloc(sizeof(int));
	printf("*p = %d\n",*p);
	q = p;
	*q = 2;
	printf("*p = %d\n",*p);
}

/*
*qsort测试
*
*/
int compart_parts(const void *p,const void *q)
{
	//const int *p1 = p;
	//const int *q1 = q;

	//return *(int *)p1 - *(int *)q1;
	return strcmp(p,q);
}
void qsort_test()
{
	int a[20];
	for(int i = 0;i < 100;i++)
	{
		a[i] = 100 - i;
	}

	qsort(a,100,sizeof(a[0]),compart_parts);

	for(int i = 0;i < 100;i++)
	{
		printf("a[%d] = %d\n",i,a[i]);
	}
}
int main()
{
	//char s[15] = "234";
	// char dst[25];

	// strncpy(dst,s,sizeof(dst));
	// dst[24] = '\0';
	// // char *str;
	// // int num = 0;
	// // num = read_line(str,N);
	// // printf("%s  %d\n",str,num);
	// printf("%sT\n",dst);;
	//date_notepad();
	//函数指针测试
	//tabulate_test();
	//qsort测试
	qsort_test();
	//受限指针测试
	//testRestrict();
	return 0;
}