
#define BOARDSTATUS_OK     1
#define BOARDSTATUS_NOK    0



int board_initBoard(void);
int board_printBoardStatus(void);

int borad_getBoardStatus(int pos); 
int board_getBoardCoin(int pos); //어떤 위치에 있을 떄 습득

int board_getSharkPosition(void); //상어 좌표 출력
int board_stepShark(void);

