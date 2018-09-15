#pragma once

#include <curses.h>
#include <string>
#include <random>

namespace Elysium
{
	class rgb
	{
	public:
		int r, g, b;
		rgb(int r, int g, int b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}
	};

	class vec2
	{
	public:
		int x, y;
		vec2(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
	};

	class Rand
	{
	private:
		long long seed;
		std::mt19937 gen;
	public:
		Rand();
		int range(int min, int max);
	};

	namespace Colours
	{
		static rgb Black(0, 0, 0);
		static rgb White(255, 255, 255);
		static rgb Red(255, 0, 0);
		static rgb Green(0, 255, 0);
		static rgb Blue(0, 0, 255);
		static rgb Yellow(255, 255, 0);
		static rgb Cyan(0, 255, 255);
		static rgb Magenta(255, 0, 255);
	}

	void init(unsigned short targetFPS, void (*onFrame)());
	void init(unsigned short targetFPS, void(*onFrame)(), void (*onStart)());
	void print(std::string contents, int x, int y);
	void print(std::string contents, rgb fgColour, int x, int y);
	void print(std::string contents, rgb fgColour, rgb bgColour, int x, int y);
}