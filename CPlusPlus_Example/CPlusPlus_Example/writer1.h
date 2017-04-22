// writer.h
#ifndef WRITER1_H
#define WRITER1_H
#include "writer.h"
#include <boost/serialization/export.hpp>

class writer1 : public writer
{
public:
	inline writer1(){}

	void print_whatever(const std::string s) const override;

	template<class Archive>
	void serialize(Archive & ar, unsigned int file_version)
	{
		ar.template register_type<writer1>();
		ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(writer);
	}
};
BOOST_SERIALIZATION_ASSUME_ABSTRACT(writer1)

#endif
