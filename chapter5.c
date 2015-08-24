#include <stdio.h>

void show_date();
//查看输入的数字的位数
void check_number();
//把24小时制时间按照12小时制现售
void show_12time();

typedef struct Time
{
	int hour;
	int min;
}Time;
typedef struct AirTime
{
	Time start;
	Time end;
}
int main()
{
	show_12time();
	return 0;
}

/*
*显示法定格式的日期
*/
void show_date()
{
	int month,day,year;

	printf("Enter date (mm/dd/yy):");
	scanf("%d/%d/%d",&month,&day,&year);
	printf("Dated this %d",day);
	switch(day)
	{
		case 1:printf("st");break;
		case 2:printf("nd");break;
		case 3:printf("rd");break;
		default:printf("th");break;
	}
	printf(" day of ");

	switch(month)
	{
		case 1:printf("January");break;
		case 2:printf("February");break;
		case 3:printf("March");break;
		case 4:printf("April");break;
		case 5:printf("May");break;
		case 6:printf("June");break;
		case 7:printf("July");break;
		case 8:printf("August");break;
		case 9:printf("September");break;
		case 10:printf("October");break;
		case 11:printf("November");break;
		case 12:printf("December");break;

	}

	printf(", 20%.2d.\n",year);

}
void check_number()
{
	int i;

	printf("Enter a number:");
	scanf("%d",&i);
	int num = 0;
	if(i == 0 )
	{
		num = 1;
	}

	for(;i != 0;)
	{
		i /= 10;
		num++;
	}

	printf("%d\n",num);
}
void show_12time()
{
	int hour,min;
	printf("Enter a 24-hour time: ");
	scanf("%d:%d",&hour,&min);
	printf("Equivalent 12-hour time:");
	if(hour <= 12)
	{
		printf("%d:%d  AM\n",hour,min);
	}
	else
	{
		printf("%d:%d  PM\n",hour-12,min);
	}

}

void air_info()
{
	
}