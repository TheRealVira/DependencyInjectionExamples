// writer.h
#ifndef WRITER2_H
#define WRITER2_H
#include "writer.h"
#include <boost/serialization/export.hpp>

class writer2 : public writer
{
public:
	inline writer2(){}

	void print_whatever(const std::string s) const override;

	template<class Archive>
	void serialize(Archive & ar, unsigned int file_version)
	{
		ar.template register_type<writer2>();
		ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(writer);
	}
};
BOOST_SERIALIZATION_ASSUME_ABSTRACT(writer2)

#endif
