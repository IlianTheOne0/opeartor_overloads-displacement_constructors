#ifndef FLAT_INTERFACE_H
#define FLAT_INTERFACE_H

#include "../Person/person.h"

template<typename TReturn>
class IFlat
{
	virtual size_t getCounter() const = 0;
	virtual Person<TReturn>* getObject(const size_t& id) = 0;

	virtual TReturn getList() const = 0;
	virtual bool addPerson(APerson<TReturn>& person) = 0;
	virtual bool deletePerson(const size_t& id) const = 0;
};

#endif