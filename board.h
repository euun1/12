
#define BOARDSTATUS_OK     1
#define BOARDSTATUS_NOK    0



int board_initBoard(void);
int board_printBoardStatus(void);

int borad_getBoardStatus(int pos); 
int board_getBoardCoin(int pos); //� ��ġ�� ���� �� ����

int board_getSharkPosition(void); //��� ��ǥ ���
int board_stepShark(void);

