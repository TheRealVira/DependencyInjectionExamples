//genericWriter.cpp

#include "stdafx.h"
#include "genericWriter.h"

genericWriter::genericWriter(writer* writer): _methodOfWriting(writer)
{
}

void genericWriter::print_whatever(const std::string& s)
{
	(*_methodOfWriting).print_whatever(s);
}

genericWriter::~genericWriter()
{
	_methodOfWriting = nullptr;
}
