//writer1.cpp

#include "stdafx.h"
#include "writer1.h"
#include <iostream>

void writer1::print_whatever(const std::string s) const
{
	std::cout << "["+s+"]";
}
