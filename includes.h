#pragma once
#include <thread>
#include <iostream>
#include <conio.h>
#include <random>
#include <Windows.h>
#include <string>

static constexpr int KEY_UP = 72;
static constexpr int KEY_DOWN = 80;
static constexpr int KEY_LEFT = 75;
static constexpr int KEY_RIGHT = 77;
static constexpr int Space = 32;
static constexpr int Esc = 27;

bool checkUnder(char(&Design)[22][22], int(&block), short(&pos), short(&pos2));
int getrandom();

void loadEmptyBlock(char(&Design)[22][22], int(&block), short(&pos), short(&pos2));

void loadtetris(char(&Design)[22][22], int(&block), short(&pos), short(&pos2),int(&value), char(&key), bool(&stop));

void loadBlock(char(&Design)[22][22], int(&block), short(&pos), short(&pos2));

void moveBlockright(char(&Design)[22][22], int(&block), short(&pos), short(&pos2));

void moveBlockleft(char(&Design)[22][22], int(&block), short(&pos), short(&pos2));

void sideways(char(&Design)[22][22], int(&block), short(&pos), short(&pos2), int(&value), char(&key), bool(&stop));

void fallBlock(char(&Design)[22][22], int(&block), short(&pos), short(&pos2), bool(&stop));

