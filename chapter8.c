#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

#define ROW 10
#define COL 10

#define N 5

/*
打印nxn的幻方（每行 每列 每条对角线上的和都相等 n为奇数）
*/
//奇数的幻方
void magic_odd()
{
	int x = 0;
	int y = N / 2;
	int num[N][N] = {0};
	for(int i = 1; i <= N * N;i++)
	{
		num[x][y] = i;
		if(i % N == 0)
		{
			x++;
		}
		else
		{
			x--;
			y++;
		}

		x = (x % N + N) % N;
		y = (y % N + N) % N;
	}

	for(int i = 0;i < N;i++)
	{
		for(int j = 0;j < N;j++)
		{
			printf("%5d\t",num[i][j]);
		}
		printf("\n");
	}
}
/*
我自己的写法
void magic()
{
	int currentX = 0;
	int currentY = N / 2;
	int num[N][N] = {0};
	bool flag[N][N] = {false};

	

	for(int i = 1;i <= N * N;i++)
	{
		
		if(flag[currentX][currentY] == false)
		{
			printf("i = %d, x = %d y = %d\n",i,currentX,currentY);
			num[currentX][currentY] = i;
			flag[currentX][currentY] = true;
			
		}
		else
		{
			currentY = (currentY + N - 1) % N;
			currentX = (currentX + N + 2) % N;

			printf("i = %d, x = %d y = %d\n",i,currentX,currentY);
			num[currentX][currentY] = i;
			flag[currentX][currentY] = true;
		}
		
		//num[currentX][currentY] = i;

		if(currentX == 0)
		{
			currentX = N - 1;
		}
		else
		{
			currentX--;
		}
		if(currentY == N - 1)
		{
			currentY = 0;
		}
		else
		{
			currentY++;
		}

		
	}

	for(int i = 0;i < N;i++)
	{
		for(int j = 0;j < N;j++)
		{
			printf("%5d\t",num[i][j]);
		}
		printf("\n");
	}
}
*/
/*
随机发扑克牌
*/
void rand_card()
{
	bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
	int num_cards,rank,suit;

	const char rank_code[] = {'2','3','4','5','6','7','8','9','t','j','q','k','a'};
	const char suit_code[] = {'c','d','h','s'};

	srand((unsigned)time(NULL));

	printf("Enter number of cards in hand:");
	scanf("%d",&num_cards);

	printf("Your hand:");
	while(num_cards > 0)
	{
		rank = rand() % NUM_RANKS;
		suit = rand() % NUM_SUITS;
		if(!in_hand[suit][rank])
		{
			printf(" %c%c",rank_code[rank],suit_code[suit]);
			in_hand[suit][rank] = true;
			num_cards--;
		}

		
	}

	printf("\n");
}
/*斐波那契数列*/
void  calc_bofei()
{
	int num;
	//int first,second;
	printf("The number:");
	scanf("%d",&num);
	long number[num];
	printf("Input the first and second number:");
	scanf("%ld %ld",&number[0],&number[1]);

	for(int i = 2;i < num;i++)
	{
		number[i] = number[i - 1] + number[i - 2];
	}

	for(int i = 0; i < num ;i++)
	{
		if( i % 5 == 0)
		{
			printf("\n");
		}
		printf("%20ld\t",number[i]);
	}
	printf("\n");
}
/*
随机步法练习
*/
void rand_step()
{
	char box[ROW][COL];
	bool box_flag[4] = {false};//上:box_flag[0],下：box_flag[1]，左：box_flag[2]，右：box_flag[3]

	//现在的行列位置
	int current_row = 0;
	int current_col = 0;
	int move;


	int lettercount = 1;		//已放置字母的个数
	srand((unsigned)time(NULL));

	//初始化数组
 	for(int i = 0 ; i < ROW; i++)
	{
		for(int j = 0; j <  COL;j++)
		{
			box[i][j] = '.';
		}
	}
	//操作数组
	box[current_row][current_col] = 'A';
	while(lettercount < 26)
	{
		move = rand() % 4;
		printf("move = %d\t lettercount = %d\n",move,lettercount);
		if(box_flag[0] == true && box_flag[1] == true && box_flag[2] == true && box_flag[3] == true)
		{
			break;
		}
		switch(move)
		{
			case 0: //向左
				if((current_row - 1 >= 0) && (box[current_row - 1][current_col] == '.') )//&& (box_flag[2] == false)) //判断是否向左走通
				{
					box[current_row - 1][current_col] = 'A' + lettercount;
					current_row --;
					lettercount++;
					box_flag[0] = box_flag[1] = box_flag[2] = box_flag[3] = false;
					
				}
				else
				{
					box_flag[2] = true;
				}
				
				break;
			case 1: //向右
				if((current_row + 1 <  10) && (box[current_row + 1][current_col] == '.') )//&&  (box_flag[3] == false)) //判断向右是否走通
				{
					box[current_row + 1][current_col] = 'A' + lettercount;
					current_row++;
					lettercount++;
					box_flag[0] = box_flag[1] = box_flag[2] = box_flag[3] = false;
				}
				else
				{
					box_flag[3] = true;
				}
				
				break;
			case 2: //向上
				if((current_col - 1 >= 0) && (box[current_row][current_col - 1] == '.'))// && (box_flag[0] == false)) //判断向上是否走通
				{
					box[current_row][current_col - 1] = 'A' + lettercount;
					current_col--;
					lettercount++;
					box_flag[0] = box_flag[1] = box_flag[2] = box_flag[3] = false;
					
				}
				else
				{
					box_flag[0] = true;
				}
				
				break;
			case 3: //向下
				if((current_col + 1 < 10) && (box[current_row][current_col + 1] == '.') )//&& (box_flag[1] == false))//判断向下是否走通
				{
					box[current_row][current_col + 1] = 'A' + lettercount;
					current_col++;
					lettercount++;
					box_flag[0] = box_flag[1] = box_flag[2] = box_flag[3] = false;
				}
				else
				{
					box_flag[1] = true;
				}
				
				break;

		}

	}
	
	for(int i = 0 ; i < ROW; i++)
	{
		for(int j = 0; j <  COL;j++)
		{
			printf("%c\t",box[i][j]);
		}
		printf("\n");
	}

}
int main()
{
	//rand_step();
	//幻方
	magic_odd();
	return 0;
}