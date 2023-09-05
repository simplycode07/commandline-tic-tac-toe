#include <stdio.h> 

char checkWin(char *board){
	if (board[0] == board[4] && board[4] == board[8] && board[0] != ' '){ return board[0]; }
	if (board[0] == board[3] && board[3] == board[6] && board[0] != ' '){ return board[0]; }
	if (board[0] == board[1] && board[1] == board[2] && board[0] != ' '){ return board[0]; }
	if (board[1] == board[4] && board[4] == board[7] && board[1] != ' '){ return board[1]; }
	if (board[2] == board[4] && board[4] == board[6] && board[2] != ' '){ return board[2]; }
	if (board[2] == board[5] && board[5] == board[8] && board[2] != ' '){ return board[2]; }
	if (board[6] == board[7] && board[7] == board[8] && board[6] != ' '){ return board[6]; }
	return ' ';
}

void drawBoard(char *board){
	int i = 0;
	printf("\t");
	while (i<9){
		if (!(i%3) && i){
			printf("\n\t---------\n\t");
		}
		else{
			if (i != 0){
				printf(" | ");
			}
		}

		if (board[i] == ' '){
			printf("%d", i+1);
		}
		else{
			printf("%c", board[i]);
		}
		i++;
	}
	printf("\n\n");
}

int not_in(int move, int moves_done[9]){
	for (int i=0; i<9; i++){
		if (moves_done[i] == move){
			return 0;
		}
	}
	return 1;
}

int main(){
	printf("\e[1;H\e[2J");
	int player;
	char board[] = "         ";
	int move;
	char win_player;
	char players[] = "XO";
	int moves_done[9];
	for (int i=0; i<9; i++){
		drawBoard(board);

		if (!(i%2)){
			player = 0;
		}
		else{
			player = 1;
		}

		printf("player %i enter position: ", player+1);
		scanf("%d", &move);
		printf("\e[1;1H\e[2J"); // clears terminal
		
		if (move>9 || board[move-1] != ' '){
			printf("move not allowed\n");
			i--;
		}

		if (board[move-1] == ' '){
			board[move-1] = players[player];
		}
		win_player = checkWin(board);
		if (win_player != ' ' && win_player){
			printf("%c won the game\n", win_player);
			break;

		}
	}

	if (win_player == ' '){
		printf("DRAW!!\n");
	}

	printf("game ended\n");
	drawBoard(board);
}
