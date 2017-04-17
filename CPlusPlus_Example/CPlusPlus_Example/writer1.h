// writer.h
#ifndef WRITER1_H
#define WRITER1_H
#include "writer.h"

class writer1 : public writer
{
protected:
	~writer1() = default;
public:
	void print_whatever(const std::string& s) override;
};

#endif
