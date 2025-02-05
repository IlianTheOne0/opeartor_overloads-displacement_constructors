#ifndef HOUSE_INTERFACE_H
#define HOUSE_INTERFACE_H

#include "../Flat/flat.h"

template<typename TReturn>
class IHouse
{
	virtual size_t getCounter() const = 0;
	virtual Flat* getObject(const size_t& id) = 0;

	virtual bool addFlat(AFlat& flat) = 0;
	virtual bool deleteFlet(const size_t& id) const = 0;

#endif