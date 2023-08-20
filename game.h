#ifndef GAME_H
#define GAME_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Player {
	friend class Game;
	char mark;
	bool turn;
public:
	Player(char mark, bool turn);
};

class Game {
	char board[10];
	bool understandableMode;

	Player *p1;
	Player *p2;
public:
	Game(bool understandableMode);
	void draw();
	void checkWinner();
	void input();

	bool over;
	char winner;
};


#endif