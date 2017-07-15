#include <iostream>
#include "../../include/Shooter_game.h"

int main(int argc, char** argv) try
{
	std::cout << argv[0] << " started. " << std::endl;
	// Gaemu startoo!
	Shooter_game::start();
	return 0;
}
catch(const std::exception& e)
{
   std::cout << e.what() << std::endl;
}
