// writer.h
#ifndef WRITER2_H
#define WRITER2_H
#include "writer.h"

class writer2 : public writer
{
protected:
	~writer2() = default;
public:
	void print_whatever(const std::string& s) override;
};

#endif
