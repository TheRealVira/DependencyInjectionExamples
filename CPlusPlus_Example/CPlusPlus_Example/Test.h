// Test.h
#ifndef TEST_H
#define TEST_H

// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Test {
	private:
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive & ar,
			const unsigned int version) {
			ar & BOOST_SERIALIZATION_NVP(a);
			ar & BOOST_SERIALIZATION_NVP(b);
			ar & BOOST_SERIALIZATION_NVP(c);
			ar & BOOST_SERIALIZATION_NVP(d);
		}

		int a;
		int b;
		float c;
	public:
		inline Test(int a, int b, float c) {
			this->a = a;
			this->b = b;
			this->c = c;
		}

		Test* d;
};


#endif