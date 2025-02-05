#ifndef PERSON_H
#define PERSON_H

#include "abstraction.h"

class Person
	: public APerson<string>
{
public:
	Person()
		: APerson()
	{ CREATE_INFO("Person <- Default constructor: called;"); }
	Person(string name)
		: APerson(name)
	{ CREATE_INFO("Person <- Constructor: called;"); }
	Person(Person&& other) noexcept
		: APerson(move(other))
	{ CREATE_INFO("Person <- Move constructor: called;"); }
	Person(APerson&& other) noexcept
		: APerson(move(other))
	{ CREATE_INFO("Person <- Move constructor: called;"); }

	virtual ~Person() override
	{ CREATE_INFO("Person <- Destructor: called;"); }
};

#endif