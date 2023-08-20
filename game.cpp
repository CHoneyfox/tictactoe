#include "game.h"

Player::Player(char mark, bool turn)
{
	this->mark = mark;
	this->turn = turn;
}
Game::Game(bool understandableMode) {

	this->understandableMode = understandableMode;

	for (short i = 0; i < 9; i++) {
		//understandable mode makes code less understandable... perfect
		if (this->understandableMode)
			this->board[i] = i+48;
		else
			this->board[i] = ' ';
	}

	this->over = false;
	this->winner = NULL;

	this->p1 = new Player('X', true);
	this->p2 = new Player('O', false);
}

void Game::draw() {
/*
	How a board looks if you didn't know:
	. | . | .
	__________
	. | . | .
	__________
	. | . | .
*/

	for (short i = 0; i < 3; i++) {
		//yeah i mean the index was a pain but it kinda makes sense
		cout << this->board[i * 3 + 0] << " | " << this->board[i * 3 + 1] << " | " << this->board[i * 3 + 2] << endl;

		//i don't want seperator under the last row 
		if (i != 2) cout << "__________" << endl;
	}
}

void Game::checkWinner() {
	//most ugly code in existense but you know... never touch a running system

	//checking if there are no free spots left
	for (short i = 0; i < 9; i++) {
		if (this->understandableMode) {
			if (this->board[i] == 'X' || this->board[i] == 'O') break;
		}
		else {
			if (this->board[i] == ' ') break;
		}
		if (i == 8) { this->over = true; this->winner = '_'; }
	}

	//row 1
	if (this->board[0] == this->board[1] && this->board[0] == this->board[2] && this->board[0] != ' ') {
		if (this->p1->mark == this->board[0]) { this->over = true; this->winner = this->p1->mark; }
		else if (this->p2->mark == this->board[0]) { this->over = true; this->winner = this->p2->mark; }
	}
	//row 2
	if (this->board[3] == this->board[4] && this->board[3] == this->board[5] && this->board[3] != ' ') {
		if (this->p1->mark == this->board[3]) { this->over = true; this->winner = this->p1->mark; }
		else if (this->p2->mark == this->board[3]) { this->over = true; this->winner = this->p2->mark; }
	}
	//row 3
	if (this->board[6] == this->board[7] && this->board[6] == this->board[8] && this->board[6] != ' ') {
		if (this->p1->mark == this->board[6]) { this->over = true; this->winner = this->p1->mark; }
		else if (this->p2->mark == this->board[6]) { this->over = true; this->winner = this->p2->mark; }
	}
	//col 1
	if (this->board[2] == this->board[5] && this->board[2] == this->board[8] && this->board[2] != ' ') {
		if (this->p1->mark == this->board[2]) { this->over = true; this->winner = this->p1->mark; }
		else if (this->p2->mark == this->board[2]) { this->over = true; this->winner = this->p2->mark; }
	}
	//col 2
	if (this->board[1] == this->board[4] && this->board[1] == this->board[7] && this->board[1] != ' ') {
		if (this->p1->mark == this->board[1]) { this->over = true; this->winner = this->p1->mark; }
		else if (this->p2->mark == this->board[1]) { this->over = true; this->winner = this->p2->mark; }
	}
	//col 3
	if (this->board[0] == this->board[3] && this->board[0] == this->board[6] && this->board[0] != ' ') {
		if (this->p1->mark == this->board[0]) { this->over = true; this->winner = this->p1->mark; }
		else if (this->p2->mark == this->board[0]) { this->over = true; this->winner = this->p2->mark; }
	}
	//diagonal 1
	if (this->board[0] == this->board[4] && this->board[0] == this->board[8] && this->board[0] != ' ') {
		if (this->p1->mark == this->board[0]) { this->over = true; this->winner = this->p1->mark; }
		else if (this->p2->mark == this->board[0]) { this->over = true; this->winner = this->p2->mark; }
	}
	//diagonal 2
	if (this->board[2] == this->board[4] && this->board[2] == this->board[6] && this->board[2] != ' ') {
		if (this->p1->mark == this->board[2]) { this->over = true; this->winner = this->p1->mark; }
		else if (this->p2->mark == this->board[2]) { this->over = true; this->winner = this->p2->mark;  }
	}
}

void Game::input() {
	//i don't think i have to explain that 

	//ckecks which players turn it is
	char currentPlayer = this->p1->turn ? this->p1->mark : this->p2->mark;
	if (this->p1->turn) {
		currentPlayer = this->p1->mark;
		this->p1->turn = false;
		this->p2->turn = true;
	}
	else if (this->p2->turn) {
		currentPlayer = this->p2->mark;
		this->p2->turn = false;
		this->p1->turn = true;
	}
	//oooh someone used a do while loop in their life... something i had on my bucket list
	//yeah anyway it just places the players mark on the selected spot
	do {
		short pos;
		cout << currentPlayer << ": ";
		cin >> pos;
		
		//had to make this weird for easy mode... now it's shit
		if ( this->understandableMode && (this->board[pos] != 'X' || this->board[pos] != 'O') ) { this->board[pos] = currentPlayer; break; }
		else if ( !this->understandableMode && this->board[pos] == ' ' ) { this->board[pos] = currentPlayer; break; }
		else { cout << "Spot already used" << endl; continue; }
	} while (true);
}