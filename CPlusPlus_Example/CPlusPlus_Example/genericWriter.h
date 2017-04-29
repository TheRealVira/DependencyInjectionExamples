// genericWriter.h
#ifndef GENERICWRITER_H
#define GENERICWRITER_H

#include "writer.h"

// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include "writer1.h"
#include "writer2.h"

class genericWriter : public writer
{
public:
	genericWriter::genericWriter(writer* w) : _methodOfWriting( w )
	{
	}

	genericWriter::genericWriter(void) : _methodOfWriting(new writer1 ) {}

	void print_whatever(const std::string s) const override;

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar.template register_type<genericWriter>();
		ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(writer);

		ar & boost::serialization::make_nvp("_methodOfWriting", *(new writer2)/*dynamic_cast<auto&>(*_methodOfWriting)*/);
	}

	boost::shared_ptr<writer> _methodOfWriting;
};


#endif
