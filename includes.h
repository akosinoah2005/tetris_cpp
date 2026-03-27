#pragma once
#include <thread>
#include <iostream>
#include <conio.h>
#include <random>
#include <Windows.h>
#include <string>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define space 32
#define ESC 27
bool checkUnder(char(&Design)[22][22], int(&block), short(&pos), short(&pos2));
int getrandom();
bool stop = 0;
void loadEmptyBlock(char(&Design)[22][22], int(&block), short(&pos), short(&pos2));
bool Game_Over(char(&Design)[22][22], int(&block), short(&pos), short(&pos2));
void loadtetris(char(&Design)[22][22], int(&block), short(&pos), short(&pos2),int(&value), char(&key));

void loadBlock(char(&Design)[22][22], int(&block), short(&pos), short(&pos2));

void moveBlockright(char(&Design)[22][22], int(&block), short(&pos), short(&pos2));

void moveBlockleft(char(&Design)[22][22], int(&block), short(&pos), short(&pos2));

void sideways(char(&Design)[22][22], int(&block), short(&pos), short(&pos2), int(&value), char(&key));

void fallBlock(char(&Design)[22][22], int(&block), short(&pos), short(&pos2));

