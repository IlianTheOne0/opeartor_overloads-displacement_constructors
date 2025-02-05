#ifndef FLAT_H
#define FLAT_H

#include "abstraction.h"

class Flat
	: public AFlat
{
public:
	Flat()
		: AFlat()
	{ CREATE_INFO("Flat <- Default Constrctor: called;"); for (size_t i = 0; i < *_counter; i++) { _peopleList[i] = nullptr; } }
	Flat(Flat&& other) noexcept
		: AFlat(move(other))
	{ CREATE_INFO("Flat <- Move constrctor: called;"); }
	Flat(AFlat&& other) noexcept
		: AFlat(move(other))
	{ CREATE_INFO("Flat <- Move constrctor: called;"); }

	~Flat() override { CREATE_INFO("Flat <- Destructor: called;"); }
};

#endif