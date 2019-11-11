#include <stdio.h> 
#define BOARD_SIZE 3
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
		}
		else {
			 printf("Player %c(행열):", turn); 
			scanf("%d %d", &r, &c);
		}
	}
	
}
