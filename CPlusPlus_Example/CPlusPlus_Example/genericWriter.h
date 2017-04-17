// genericWriter.h
#ifndef GENERICWRITER_H
#define GENERICWRITER_H

#include "writer.h"

class genericWriter : public writer
{
public:
	genericWriter(writer* writer);
	void print_whatever(const std::string& s) override;
	writer* _methodOfWriting;
	virtual ~genericWriter();
};

#endif
