//genericWriter.cpp

#include "stdafx.h"
#include "genericWriter.h"

template<typename T>
void genericWriter<T>::print_whatever(const std::string s) const
{
	(*_methodOfWriting).print_whatever(s);
}

//register the derived class with boost.
//BOOST_CLASS_EXPORT_GUID(genericWriter<T>, "genericWriter")