
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define MAX_REMIND 50
#define MSG_LEN		60
char digit_to_hex_char(int digit)
{
	return "0123456789ABCDEF"[digit];
}

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
	char reminders[MAX_REMIND][MSG_LEN + 3];
	int day,num_remind = 0;
	char day_str[3],msg_str[MSG_LEN + 1];
	int i,j;

	while(1)
	{
		if(num_remind == MAX_REMIND)
		{
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
			strcpy(reminders[j],reminders[j - 1]);
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
自己编写strcat
*/
char *mystr_cat(char *dst,const char *src)
{
	char *p = dst;
	while(*p != '\0')
	{
		p++;
	}
	while(*src != '\0')
	{
		printf("%c\n",*p = *src);
		p++;
		src++;
	}
	printf("%c\n",*p = *src);
	//*p = '\0';

	return dst;
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
	//mystr_cat(s,"abcd");
	int i = 0,j;
	char *s;
	printf(i " = %d\n",i);
	return 0;
}