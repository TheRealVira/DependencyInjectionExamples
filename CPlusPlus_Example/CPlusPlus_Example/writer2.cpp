//writer2.cpp

#include "stdafx.h"
#include "writer2.h"
#include <iostream>

void writer2::print_whatever(const std::string s) const
{
	std::cout << "-=" + s + "=-";
}
BOOST_CLASS_EXPORT_GUID(writer2, "writer2")