#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part
{
	int number;
	char name[NAME_LEN + 1];
	int on_hand;

}inventory[MAX_PARTS];

int num_parts = 0;
//声明函数 
int find_parts(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

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
	
	while(isspace(ch = getchar()));
	//printf("read_line\n");
	while(ch != '\n' && ch != EOF)
	{
	//	printf("#");
		if(i < n)
		{
			
			str[i++] = ch;
		}
		ch = getchar();
	}
	str[i] = '\0';
	//printf("read_line end: %s\n",str);
	
	return i;

}

int main()
{
	char c;
	while(1)
	{
		printf("\n\n输入操作码:(i 插入 s 搜索 u 更新 p 显示 q 退出)\n");

		scanf(" %c",&c);
		while(getchar() != '\n');
		printf("输入参数:%c\n",c);
		switch(c)
		{
			case 'i':
				printf("插入\n");
				insert();
				break;
			case 'u':
				printf("搜索\n");
				break;
			case 's':
				printf("更新\n");
				break;
			case 'p':
				printf("显示\n");
				print();
				break;
			case 'q':
				printf("退出\n");
				break;
			default:
				printf("error input\n");
				break;
		}

		printf("\n");
	}

	return 0;
}
/*
*find_parts:查找对应的零件编号
*return -1 没有对应的零件编号
*		其他 零件编号
*/
int find_parts(int number)
{
	int i;
	for(i = 0;i < num_parts;i++)
	{
		if(inventory[i].number == number)
		{
			return i;
		}
	}

	return -1;
}

/*
*insert:插入数据

*/
void insert(void)
{
	int  part_number;

	if(num_parts == MAX_PARTS)
	{
		printf("数据库已满,不能在增加\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d",&part_number);

	if(find_parts(part_number) >= 0)
	{
		printf("Part already exist.\n");
		return;
	}

	printf("number = %d\n",part_number);
	inventory[num_parts].number = part_number;
	printf("Enter name: ");
	read_line(inventory[num_parts].name,NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d",&inventory[num_parts].on_hand);
	num_parts++;
}
void search(void){}
void update(void){}
void print(void)
{
	printf("Part Number\tPart Name\t\tQuantity on Hand\n");
	for(int i = 0;i < num_parts;i++)
	{
		printf("%8d\t%s\t\t\t%d\n",inventory[i].number,inventory[i].name,inventory[i].on_hand);
	}
}