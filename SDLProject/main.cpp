//bacon pancakes makin bacon pancakes

#include "ExampleGame.h"

using namespace std;

int main(int argc, char* argv[])
{
	ExampleGame* game = new ExampleGame();
	game->InitSDL();
	game->Run();
	game->Clean();
	return 0;
}