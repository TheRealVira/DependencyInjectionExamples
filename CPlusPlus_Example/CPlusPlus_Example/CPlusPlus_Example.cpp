// CPlusPlus_Example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <string>

#include "genericWriter.h"
#include "writer1.h"
#include "writer2.h"

using namespace std;

int main()
{
	genericWriter gW{new writer1};

	gW.print_whatever("Just some testing... Yay :)");

	getch();

	return 0;
}
