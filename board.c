#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define N_BOARD	          15
#define N_COINPOS         12
#define MAX_COIN          4

#define MAX_SHARKSTEP      6
#define SHARK_INITPOS     -4

static int board_status[N_BOARD];
static int board_coin[N_BOARD];

static int board_sharkPosition = SHARK_INITPOS;

int board_initBoard(void)
{
	int i;
	for (i=0; i<N_BOARD; i++)
	{
		board_status[i] = BOARDSTATUS_OK;
		board_coin[i] = 0;
	}
	
	//상어 초기 위치 설정 
	board_sharkPosition = SHARK_INITPOS;
	
	for( i=0; i<N_COINPOS; i++)
	{
		int flag = 0;
		while(flag == 0)
		{
			int allocPos = rand() %N_BOARD;
			if (board_coin[allocPos] == 0)
			{
				board_coin[allocPos] = rand() %MAX_COIN+1;
				flag = 1;
			}
		}
	}
	return 0;
}
int board_printBoardStatus(void)
{
	int i;
	
	printf("==================BOARD STATUS==================\n");
	for (i=0; i<N_BOARD; i++)
	{
		printf("|");
		if (board_status[i] == BOARDSTATUS_NOK)
			printf("X");
		else
			printf("O");
	}
	printf("|\n");
	printf("================================================\n");
	
	return 0;
}

int board_getBoardStatus(int pos)
{
	return board_status[pos];
}

int board_getBoardCoin(int pos) //어떤 위치에 있을 떄 습득
{
	int coin = board_coin[pos];
	board_coin[pos] = 0;
	return coin;
}


//상어 좌표 출력
int board_getSharkPosition(void)
{
    return board_sharkPosition;
}

int board_stepShark(void)
{
    int step = rand() % MAX_SHARKSTEP + 1;
    int i;

    for (i = board_sharkPosition + 1; i <= board_sharkPosition + step; i++)
    {
        if (i >= 0 && i < N_BOARD)
            board_status[i] = BOARDSTATUS_NOK;
    }

    board_sharkPosition += step;

    return board_sharkPosition;
}

int game_end(void)
{
	int i;
	int flag_end = 1;
	
	//if all the players are died?
	for (i=0; i<N_PLAYER; i++)
	{
		if (player_status[i] == PLAYERSTATUS_LIVE)
		{
			flag_end = 0;
			break;
		}
	}
	
	return flag_end;
}

int getAlivePlayer(void)
{
	int i;
	int cnt=0;
	for (i=0; i<N_PLAYER; i++)
	{
		if (player_status[i] == PLAYERSTATUS_END)
			cnt++;
	}
	
	return cnt++;
}

int getWinner(void)
{
	int i;
	int winner=0;
	int max_coin=-1;
	
	for (i=0; i<N_PLAYER; i++)
	{
		if (player_coin[i] > max_coin)
		{
			max_coin = player_coin[i];
			winner = i;
		}
	}
	
	return winner;
}

