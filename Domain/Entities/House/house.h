#ifndef HOUSE_H
#define HOUSE_H

#include "abstraction.h"

class House
	: public AHouse
{
public:
	House()
		: AHouse()
	{
		CREATE_INFO("House <- Default Constrctor: called;"); for (size_t i = 0; i < *_counter; i++) { _flatList[i] = nullptr; }
	}
	House(House&& other) noexcept
		: AHouse(move(other))
	{
		CREATE_INFO("House <- Move constrctor: called;");
	}
	House(AHouse&& other) noexcept
		: AHouse(move(other))
	{
		CREATE_INFO("House <- Move constrctor: called;");
	}

	~House() override { CREATE_INFO("House <- Destructor: called;"); }
};

#endif