// genericWriter.h
#ifndef GENERICWRITER_H
#define GENERICWRITER_H

#include "writer.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/shared_ptr.hpp>

template <typename T>
class genericWriter : public writer
{
public:

	genericWriter(): _methodOfWriting(new T)
	{
		// Yes, the double parentheses are needed, otherwise the comma will be seen as macro argument separator
		BOOST_STATIC_ASSERT((boost::is_base_of<writer, T>::value));
	}

	void print_whatever(const std::string s) const override;

private:
	writer* _methodOfWriting;

	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive & ar, unsigned int file_version)
	{
		ar.template register_type<genericWriter<T>>();
		ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(writer);
		ar & BOOST_SERIALIZATION_NVP(_methodOfWriting);
	}
};


//================== TESTING =======================

//class genericWriter;
//namespace boost {
//	namespace serialization {
//		template<class Archive>
//		inline void save_construct_data(Archive & ar, const genericWriter * t, const unsigned int file_version);
//	}
//}
//
//struct genericWriter : public writer
//{
//public:
//	genericWriter::genericWriter(writer* w)
//	{
//		_methodOfWriting = *new std::shared_ptr<writer>(w);
//	}
//
//	/*genericWriter::genericWriter(writer* w):_methodOfWriting(w)
//	{
//	}*/
//
//	void print_whatever(const std::string s) const override;
//
//private:
//	friend class boost::serialization::access;
//
//	template<class Archive>
//	friend void boost::serialization::save_construct_data(Archive & ar, const genericWriter * t, const unsigned int file_version);
//
//	template<class Archive>
//	void genericWriter::serialize(Archive & ar, const unsigned int version) {
//		ar.template register_type<genericWriter>();
//		ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(writer);
//
//		//ar.template register_type<genericWriter>();
//		//ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(writer);
//
//		////_methodOfWriting = *new boost::shared_ptr<writer>(new writer2);
//
//		//std::cout << typeid(*_methodOfWriting.at(0)).name();
//		//ar & boost::serialization::make_nvp("_methodOfWriting", *_methodOfWriting.at(0));
//
//
//		////std::cout << typeid(dynamic_cast<decltype(*_methodOfWriting.get())>(*_methodOfWriting.get())).name();
//		////ar & boost::serialization::make_nvp("_methodOfWriting", dynamic_cast<decltype(*_methodOfWriting.get())>(*_methodOfWriting.get())/*dynamic_cast<auto&>(*_methodOfWriting)*/);
//	}
//
//	std::shared_ptr<writer> _methodOfWriting;
//
//};
//
////Save and load the data required for the constructor.
//namespace boost {
//	namespace serialization {
//		template <class Archive>
//		void genericWriter::save_construct_data(
//			Archive & ar, const genericWriter * gW, const unsigned int file_version
//		)
//		{
//			// save data required to construct instance
//			std::cout << typeid(*gW->_methodOfWriting.get()).name();
//			ar << boost::serialization::make_nvp("_methodOfWriting", *gW->_methodOfWriting.get());
//		}
//
//		template<class Archive>
//		void genericWriter::load_construct_data(
//			Archive & ar, genericWriter * t, const unsigned int file_version
//		) {
//			// retrieve data from archive required to construct new instance
//			writer* wr;
//			ar >> boost::serialization::make_nvp("_methodOfWriting", wr);
//
//			// invoke inplace constructor to initialize instance of my_class
//			::new(t)genericWriter(wr);
//		}
//
//
//	}
//}

#endif
