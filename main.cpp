#include "game.h"
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
	Game G = NULL;

	if (argc < 2) G = Game(false);
	else if ( strcmp(argv[1], "--help") == 0) {
		cout << "Usage: " << endl;
		cout << argv[0] << " --help: View this help page" << endl;
		cout << argv[0] << " --easy: Start game in easy mode" << endl;
		cout << argv[0] << " --hard: Start game in normal mode" << endl;
		return 1;
	}
	else if ( strcmp(argv[1], "--easy") == 0) G = Game(true);
	else if ( strcmp(argv[1], "--hard") == 0) G = Game(false);
	else G = Game(false);
	

	//gameloop
	while (!G.over) {
		G.draw();
		G.input();
		G.checkWinner();
		
		cout << "\033[2J\033[H"; //clear screen
		cout.flush();
	}
	G.draw();

	if (G.winner == '_') {
		cout << "The game has ended in a draw..." << endl;
	} else {
		cout << "Yay, Player " << G.winner << " has won!" << endl;
	}

	#ifdef __linux__ //lil easter egg for linux hehe
	cout << "EPIC GAMER MOMENT" << std::endl;
	#endif 

	cout << "Press Enter to Continue...";
	cin.get();
	cin.ignore();
	cout << "\033[2J\033[H"; //clear screen

	return 0;
}
