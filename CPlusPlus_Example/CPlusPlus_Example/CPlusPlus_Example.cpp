// CPlusPlus_Example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <string>
#include <boost/serialization/assume_abstract.hpp>

#include "genericWriter.h"
#include "writer1.h"
#include "writer2.h"
#include <fstream>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

using namespace std;

int main()
{
	//genericWriter* gW = new genericWriter{new writer1};

	//(*gW).print_whatever("Just some testing... Yay :)");

	//// create and open a character archive for output
	//std::ofstream ofs("example.xml");

	//// save data to archive
	//{
	//	boost::archive::xml_oarchive oa(ofs);
	//	// write class instance to archive
	//	oa << BOOST_SERIALIZATION_NVP(gW);
	//	// archive and stream closed when destructors are called
	//}

	//getch();

	//return 0;

	// create and open a character archive for output
	std::ofstream ofs("CPlusPlus_example.xml");

	// create class instance
	/*writer2 wTEMP;
	writer& wATR = wTEMP;*/
	const genericWriter* test = new genericWriter(new writer2);

	// save data to archive
	{
		boost::archive::xml_oarchive oa(ofs);
		// write class instance to archive
		oa << BOOST_SERIALIZATION_NVP(test);
		// archive and stream closed when destructors are called
	}

	genericWriter newW;
	{
		// open the archive
		std::ifstream ifs("CPlusPlus_example.xml");
		assert(ifs.good());
		boost::archive::xml_iarchive ia(ifs);

		// restore the schedule from the archive
		ia >> BOOST_SERIALIZATION_NVP(newW);
	}

	newW.print_whatever("test");

	getch();

	return 0;
}
