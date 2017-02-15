// Tic-Tac-Toe game
// 3x3 grid
// Accepts diagonal, row and collumn wins

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Given the string of the game board, will draw it to the console
void drawGame(string game){
	for(int i = 0; i <= 9; i++){
		// if it drew 3 characters will start drawing on the next line, otherwise places a space before next number
		cout << ((i % 3 == 0) ? "\n": " ") << game[i]; 
	}
}

// Makes compiler play nice instead of original idea of just calling once "game.replace(move-1, 1, id)" during main
// Could have fix but too insignificant to bother
// Makes change to game board with current player sign
string getMove(int play, int move, string game){
	if(play%2 == 0){
		game.replace(move-1, 1, "X");
	} else{
		game.replace(move-1, 1, "O");
	}
	return game;
}

// Checks if 3 given positions have the same sign
bool hasThree(char player,string game, int t1, int t2, int t3){
	return (game[t1]==player && game[t2]==player && game[t3]==player);
}

// Checks if any of the possible winning outcomes has occured
bool checkMove(char player, string game){
	return( 
		hasThree(player, game, 0, 1, 2) ||
		hasThree(player, game, 3, 4, 5) ||
		hasThree(player, game, 6, 7, 8) ||

		hasThree(player, game, 0, 3, 6) ||
		hasThree(player, game, 1, 4, 7) ||
		hasThree(player, game, 2, 5, 8) ||

		hasThree(player, game, 0, 4, 8) ||
		hasThree(player, game, 2, 4, 7)
		);
}

int main(){
	int move;
	int play = 0;				 // Number of plays
	char id;
	string game = "---------";   // Game board (originaly empty)
	vector<int> usedMoves(9, 0); // Simply to keep track of positions already taken

	while(play < 9){
		cout << "Your move: ";
		cin >> move;
		// Keeps asking for input if invalid (assumes user inputs an INT)
		if(move > 9 || move < 0){
			cout << "Invalid Entry! Your move (1-9): ";
			cin >> move;
		}
		else if(usedMoves[move-1] == 1){
			cout << "Already Played! Your Move: ";
			cin >> move;
		}

		if(play%2==0){
			id='X';
		}else{ id='O';}

		game = getMove(play,move,game);
		usedMoves[move-1] = 1;
		drawGame(game);

		// Checks if move wins the game
		if(checkMove(id, game)){
			cout << "\n" << "///////" << endl;
			cout << id << " Wins!" << endl;
			cout << "///////" << endl;
			break;
		}
		play++;
	}
	return 0;
}