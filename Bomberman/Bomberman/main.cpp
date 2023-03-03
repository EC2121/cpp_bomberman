#define SDL_MAIN_HANDLED
#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
int main(int argc, char** argv)
{
	using namespace Core;
	Game::GetInstance().Init();
	Game::GetInstance().Loop();

}