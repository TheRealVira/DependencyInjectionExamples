// writer.h
#ifndef WRITER_H
#define WRITER_H

#include <string>

class writer
{
protected:
	~writer() = default;
public:
	virtual void print_whatever(const std::string& s) = 0;
};

#endif
