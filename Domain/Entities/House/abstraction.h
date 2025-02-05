#ifndef HOUSE_ABSTRACTION_H
#define HOUSE_ABSTRACTION_H

#include "../../../lib.h"
#include "../../../Core/core.h"
#include "interface.h"

class AHouse
	: public IHouse<string>
{
private:
	const size_t _maxSize{ 15 };
protected:
	Flat** _flatList = nullptr;
	size_t* _counter = nullptr;
public:
	AHouse()
		: _flatList(new Flat* [_maxSize] {nullptr}), _counter(new size_t(0))
	{ CREATE_INFO("AHouse <- Default Constrctor: called;"); for (size_t i = 0; i < *_counter; i++) { _flatList[i] = nullptr; } }
	AHouse(AHouse&& other) noexcept
		: _counter(new size_t(other.getCounter())), _flatList(new Flat* [_maxSize] {nullptr})
	{ CREATE_INFO("AHouse <- Move constrctor: called;"); for (size_t i = 0; i < *_counter; i++) { _flatList[i] = other._flatList[i]; other._flatList[i] = nullptr; } }

	virtual ~AHouse() { CREATE_INFO("AHouse <- Destructor: called;"); for (size_t i = 0; i < *_counter; i++) { delete _flatList[i]; } delete[] _flatList; delete _counter; }

	size_t getCounter() const override { CREATE_INFO("AHouse -> Method getCounter: called;"); if (_counter != nullptr) { return *_counter; } else { return DEFAULT_EMPTY_NUMBER; } }

	Flat* getObject(const size_t& id) { INFO("AHouse -> Method getObject: called;"); if (id >= *_counter || id < 0) { ERROR("AHouse -> Method getObject: incorrect ID!;"); } return _flatList[id]; }

	bool addFlat(AFlat& flat) override
	{
		INFO("AHouse -> Method addPerson: called;");

		if (*_counter == _maxSize) { ERROR("AHouse -> Method addPerson: the list is full! return false;"); return false; }
		_flatList[*_counter] = new Flat(move(flat));
		(*_counter)++;

		return true;
	}
	bool deleteFlet(const size_t& id) const override
	{
		INFO("AHouse -> Method deletePerson: called;");

		if (id >= *_counter || id < 0) { ERROR("AHouse -> Method deletePerson: incorrect ID! return false;"); return false; }

		delete _flatList[id];
		for (size_t i = id; i < *_counter - 1; i++) { _flatList[i] = _flatList[i + 1]; }
		_flatList[*_counter - 1] = nullptr;
		(*_counter)--;

		return true;
	}
};

#endif