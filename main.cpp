#include "Elysium.hpp"

using namespace Elysium;

enum directions {
	NONE       = 0,
	RIGHT      = 1,
	LEFT       = 2,
	UP         = 3,
	DOWN       = 4
};

vec2 playerPosition(40, 12);

void onStart() // called at the start of the program
{
	nodelay(stdscr, true);
	curs_set(0);
}

void onFrame() // called every "frame", which is 1/targetFPS (0.1) seconds
{
	print("X", Colours::Red, playerPosition.x, playerPosition.y);

	int key = getch();

	if (key == 119)
	{
		playerPosition.y--;
	}
	else if (key == 97)
	{
		playerPosition.x--;
	}
	else if (key == 115)
	{
		playerPosition.y++;
	}
	else if (key == 100)
	{
		playerPosition.x++;
	}
}

int main()
{
	init(10, onFrame, onStart);

	return 0;
}
