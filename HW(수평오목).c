#include <stdio.h> 
#define BOARD_SIZE 5
int winCheck (char b[][BOARD_SIZE], int r, int c)
{
	int j;
	int count = 0;

	for (j = 0; j < BOARD_SIZE; j++){
		if (b[r][j] == 'X' && c <= 5){ //X의 경우//경우 나눌 필요 없고'X'대신 b[r][c]이렇게 쓰면 코드 줄일 수 있음
			while(count < 5) {
				if (b[r][j++] == 'X')
					count++;
				else
					break;
			}
			if (count == 5)
				return 1;
			count = 0;
			return 0;
		}
		else if (b[r][j] == 'O' && c <= 5){ //O의 경우
			while(count < 5) {
				if (b[r][j++] == 'O')
					count++;
				else
					break;
			}
			if (count == 5)
				return 1;
			count = 0;
			return 0;
		}
	}
	return 0;
}
void display(char b[][BOARD_SIZE]) 
{
	char ch; 
	int i, j;
	int count;
	
	printf("     "); 
	for (i= 0; i< BOARD_SIZE; i++) 
		printf("%2d", i); //가로로 차근히 프린트
	printf("\n     ---------------------\n");
	
	for (i= 0; i< BOARD_SIZE; i++) 
	{
		printf("%3d |", i);
		for (j = 0; j < BOARD_SIZE; j++) 
			printf(" %c", b[i][j]); printf("\n");
	}
}

void main() 
{
	char board[BOARD_SIZE][BOARD_SIZE]; 
	char turn = 'X';
	int r, c;
	int i, j; 
	int count;

	for(i = 0; i< BOARD_SIZE ; i++ ) 
		for(j = 0 ; j < BOARD_SIZE ; j++)
			board[i][j] = ' '; //* + 가로로 프린트

	count = 1;
	display(board); 

	printf("Player %c(행열):", turn); 
	scanf("%d %d", &r, &c);
	while(count <= BOARD_SIZE * BOARD_SIZE)
	{
		if (count % 2 == 0)
			turn = 'O';
		else if (count % 2 == 1)
			turn = 'X';

		if (board[r][c] == ' '){
			board[r][c] = turn; 
			display(board);
			count++;
			if (winCheck(board, r, c)){
				printf("Player %c wins!\n", turn);
				break;
			}
		}
		else {
			 printf("Player %c(행열):", turn); 
			scanf("%d %d", &r, &c);
		}
	}

	if (winCheck(board, r, c) == 0)
		printf("Nobody wins\n");
}
