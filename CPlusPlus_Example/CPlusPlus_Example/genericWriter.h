// genericWriter.h
#ifndef GENERICWRITER_H
#define GENERICWRITER_H

#include "writer.h"

// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/export.hpp>
#include "writer1.h"

class genericWriter : public writer
{
public:
	genericWriter::genericWriter(writer& w): _methodOfWriting(w)
	{
	}

	genericWriter::genericWriter(void): _methodOfWriting(*new writer){}

	void print_whatever(const std::string s) const override;

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar.template register_type<genericWriter>();
		ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(writer);
		ar & BOOST_SERIALIZATION_NVP(_methodOfWriting);
	}

	writer _methodOfWriting;
};
BOOST_SERIALIZATION_ASSUME_ABSTRACT(genericWriter)

#endif
