#ifndef PERSON_H
#define PERSON_H

#include "abstraction.h"

template<typename TReturn>
class Person
	: public APerson<TReturn>
{
public:
	Person()
		: APerson()
	{ CREATE_INFO("Person <- Default constructor: called;"); }
	Person(TReturn name)
		: APerson<TReturn>(name)
	{ CREATE_INFO("Person <- Constructor: called;"); }
	Person(Person&& other) noexcept
		: APerson<TReturn>(move(other))
	{ CREATE_INFO("Person <- Move constructor: called;"); }
	Person(APerson<TReturn>&& other) noexcept
		: APerson<TReturn>(move(other))
	{ CREATE_INFO("Person <- Move constructor: called;"); }

	~Person() override
	{ CREATE_INFO("Person <- Destructor: called;"); }
};

#endif