// writer.h
#ifndef WRITER_H
#define WRITER_H

#include <string>

#include <boost/serialization/assume_abstract.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/nvp.hpp>

class writer
{
public:
	writer::writer(void){}
	virtual ~writer() {};

	virtual void print_whatever(const std::string s) const = 0;

private:
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) { }
};

BOOST_SERIALIZATION_ASSUME_ABSTRACT(writer)

#endif