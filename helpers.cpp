#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define N 30  // max char for username
void lowercase(char*);
void lowercase(char* lower)
{
	for (unsigned int i = 0; i < (strlen(lower)); i++) // to lowercase the chars
	{
		lower[i] = tolower(lower[i]);
	}
}