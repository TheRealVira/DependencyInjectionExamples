// CPlusPlus_Example.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "conio.h"
#include <string>
#include <boost/serialization/assume_abstract.hpp>

#include "genericWriter.h"
#include "writer2.h"
#include <fstream>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

using namespace std;

int main()
{

	// create and open a character archive for output
	std::ofstream ofs("CPlusPlus_example.xml");

	writer* test = new genericWriter<writer2>();
	test->print_whatever("test");

	// save data to archive
	{
		boost::archive::xml_oarchive oa(ofs);
		// write class instance to archive
		oa << BOOST_SERIALIZATION_NVP(test);
		// archive and stream closed when destructors are called
	}

	{
		// open the archive
		std::ifstream ifs("CPlusPlus_example.xml");
		assert(ifs.good());
		boost::archive::xml_iarchive ia(ifs);

		// restore the schedule from the archive
		ia >> BOOST_SERIALIZATION_NVP(test);
	}

	test->print_whatever("test");

	getch();

	return 0;
}