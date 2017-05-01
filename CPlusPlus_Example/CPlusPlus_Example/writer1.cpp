//writer1.cpp

#include "stdafx.h"
#include "writer1.h"
#include <iostream>

void writer1::print_whatever(const std::string s) const
{
	std::cout << "["+s+"]";
}
BOOST_CLASS_EXPORT_GUID(writer1, "writer1")