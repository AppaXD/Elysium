#include "Elysium.hpp"
#include <chrono>
#include <iostream>

void Elysium::init(unsigned short targetFPS, void(*onFrame)())
{
	float frametime = 1.f / targetFPS;

	initscr();
	start_color();
	move(0, 0);

	std::chrono::steady_clock::time_point start = std::chrono::high_resolution_clock::now();

	while (1)
	{
		std::chrono::steady_clock::time_point end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;

		if (diff.count() >= frametime)
		{
			start = std::chrono::high_resolution_clock::now();
			clear();
			onFrame();
			refresh();
		}
	}
}

void Elysium::init(unsigned short targetFPS, void(*onFrame)(), void(*onStart)())
{
	float frametime = 1.f / targetFPS;

	initscr();
	start_color();
	move(0, 0);

	onStart();

	std::chrono::steady_clock::time_point start = std::chrono::high_resolution_clock::now();

	while (1)
	{
		std::chrono::steady_clock::time_point end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;

		if (diff.count() >= frametime)
		{
			start = std::chrono::high_resolution_clock::now();
			clear();
			onFrame();
			refresh();
		}
	}
}

void Elysium::print(std::string contents, int x, int y)
{
	move(y, x);
	printw(contents.c_str());
}

void Elysium::print(std::string contents, rgb fgColour, int x, int y)
{
	fgColour.r *= 3.921;
	fgColour.g *= 3.921;
	fgColour.b *= 3.921;

	init_color(8, fgColour.r, fgColour.g, fgColour.b);
	init_pair(1, 8, COLOR_BLACK);
	move(y, x);
	attron(COLOR_PAIR(1));
	printw(contents.c_str());
}

void Elysium::print(std::string contents, rgb fgColour, rgb bgColour, int x, int y)
{
	fgColour.r *= 3.921;
	fgColour.g *= 3.921;
	fgColour.b *= 3.921;

	bgColour.r *= 3.921;
	bgColour.g *= 3.921;
	bgColour.b *= 3.921;

	init_color(8, fgColour.r, fgColour.g, fgColour.b);
	init_color(9, bgColour.r, bgColour.g, bgColour.b);
	init_pair(1, 8, 9);
	move(y, x);
	attron(COLOR_PAIR(1));
	printw(contents.c_str());
}

Elysium::Rand::Rand()
{
	this->seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	this->gen = std::mt19937(seed);
}

int Elysium::Rand::range(int min, int max)
{
	std::uniform_int_distribution<int> rng(min, max);
	return rng(gen);
}