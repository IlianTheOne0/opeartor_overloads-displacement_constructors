#ifndef PERSON_ABSTRACTION_H
#define PERSON_ABSTRACTION_H

#include "../../../lib.h"
#include "../../../Core/core.h"
#include "interface.h"

template<typename TValue>
class APerson
	: public IPerson<TValue>
{
protected:
	TValue* _name = nullptr;
public:
	APerson()
		: _name(new TValue(DEFAULT_EMPTY_STRING))
	{ CREATE_INFO("APerson <- Default constructor: called;"); }
	APerson(TValue name)
		: _name(new TValue(name))
	{ CREATE_INFO("APerson <- Constructor: called;"); }

	virtual ~APerson()
	{ CREATE_INFO("APerson <- Destructor: called;"); if (_name != nullptr) { delete _name; _name = nullptr; } }

	TValue getName() const override { INFO("APerson -> Method getName: called;"); if (_name != nullptr) { return *_name; } return DEFAULT_EMPTY_STRING; }
	void setName(const TValue& value) override { INFO("APerson -> Method setName: called;"); if (_name != nullptr) { delete _name; } this->_name = new TValue(value); }
};

#endif