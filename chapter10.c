/*
* 手牌分类
* 说明:改程序会对一手牌进行读取和分类
* 手中的每张牌都有花色(方块c，梅花d，红桃h和黑桃s) 等级(2,3,4,5,6,7,8,9,10t,Jj,Qq,Kk,Aa) 不允许使用王牌 假设A是最高等级
* 程序将读取一手5张牌 然后把手中的牌分为下列某一类
同花顺(顺序又是同花色)
四张(4张牌等级相同) 
葫芦(三张牌同样等级 另外两张同样等级) 
同花(5张牌是同花色) 
顺子(5张牌等级顺序相连) 
三张(3张牌等级相同) 
两对() 
一对() 
其他()
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>



void rand_card(void);
void analyze_hand(void);
void print_result(void);

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 5

int num_in_rank[NUM_RANKS] = {0};//牌的等级
int num_in_suit[NUM_SUITS] = {0};//牌的花色

bool straight;//顺子
bool flush;//同花
bool four;//四张
bool three;//三张
int pairs;//对子(一对 两对 或者没有)



int main(void)
{
	int i = 0;
	long time_count;
	while(i < 100)
	{
		time_count = 500000000;
		
		rand_card();
		analyze_hand();
		print_result();
		i++;
		while(time_count--);
	}
	
	return 0;
}

/*
*rand_card:随机产生一手牌
*
*/
void rand_card(void)
{
	bool card_exist[NUM_RANKS][NUM_SUITS] = {false};
	//bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
	int num_cards = 0;
	int rank,suit;


	const char rank_code[] = {'2','3','4','5','6','7','8','9','t','j','q','k','a'};
	const char suit_code[] = {'c','d','h','s'};

	srand((unsigned)time(NULL));

	// 初始化
	straight = false;//顺子
	flush = false;//同花
	four = false;//四张
	three = false;//三张
	pairs = 0;//对子(一对 两对 或者没有)
	for(rank = 0;rank < NUM_RANKS;rank++)
	{
		num_in_rank[rank] = 0;
		for(suit = 0;suit < NUM_SUITS;suit++)
		{
			card_exist[rank][suit] = false;
		}
	}
	for(suit = 0; suit < NUM_SUITS;suit++)
	{
		num_in_suit[suit] = 0;
	}

	//printf("Your hand:");
	while(num_cards < NUM_CARDS)
	{
		rank = rand() % NUM_RANKS;
		suit = rand() % NUM_SUITS;
		if(!card_exist[rank][suit])
		{
			num_in_rank[rank]++;
			num_in_suit[suit]++;
			printf(" %c%c",rank_code[rank],suit_code[suit]);
			card_exist[rank][suit] = true;
			num_cards++;
		}

		
	}

	printf("\n");
}

/*
*analyze_hand:分析
*
*/
void analyze_hand(void)
{
	int suit;
	int rank;
	int num_consec = 0;
	//分析是不是同花(同花的话num_in_suit数组中有一个下表为5)
	for(suit = 0; suit < NUM_SUITS;suit++)
	{
		if(num_in_suit[suit] == NUM_CARDS)
		{
			flush = true;
		}
	}
	//分析是不是顺子
	rank = 0;
	while(num_in_rank[rank] == 0 && rank < NUM_RANKS)
	{
		rank++;
	}

	for(;rank < NUM_RANKS && num_in_rank[rank] > 0;rank++)
	{
		num_consec++;
	}
	if(num_consec == NUM_CARDS)
	{
		straight = true;
		return;
	}

	for(rank = 0; rank < NUM_RANKS;rank++)
	{
		if(num_in_rank[rank] == 4)
		{
			four = true;
		}
		if(num_in_rank[rank] == 3)
		{
			three = true;
		}
		if(num_in_rank[rank] == 2)
		{
			pairs++;
		}

	}
}

/*
*print_result:打印结果
*
*/
void print_result(void)
{
	if(straight && flush)
	{
		//同花顺
		printf("同花顺\n");
	}
	else if(four)
	{
		//四张
		printf("四张\n");
	}
	else if(three == true && pairs == 1)
	{
		//葫芦
		printf("葫芦\n");
	}
	else if(flush)
	{
		//同花
		printf("同花\n");
	}
	else if(straight)
	{
		//顺子
		printf("顺子\n");
	}
	else if(three)
	{
		//三张
		printf("三张\n");
	}
	else if(pairs == 2)
	{
		//两对
		printf("两对\n");
	}
	else if(pairs == 1)
	{
		//一对
		printf("一对\n");
	}
	else
	{
		printf("高牌\n");
	}
}