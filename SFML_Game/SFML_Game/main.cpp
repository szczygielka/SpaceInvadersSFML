#include "Game.h"

int main()
{
	try
	{
		Game game = Game();
		game.Run();
	}
	catch (std::exception& e) //lapanie wyjatku z exception 
	{
		std::cout << e.what() << std::endl;
		system("pause");
	}
	return 0;
}

