#ifndef FLAT_ABSTRACTION_H
#define FLAT_ABSTRACTION_H

#include "../../../lib.h"
#include "../../../Core/core.h"
#include "interface.h"

class AFlat
	: public IFlat<string>
{
private:
	const size_t _maxSize{ 4 }; 
protected:
	Person<string>** _peopleList = nullptr;
	size_t* _counter = nullptr;
public:
	AFlat()
		: _peopleList(new Person<string>*[_maxSize] {nullptr}), _counter(new size_t(0))
	{ CREATE_INFO("AFlat <- Default Constrctor: called;"); for (size_t i = 0; i < *_counter; i++) { _peopleList[i] = nullptr; } }
	AFlat(AFlat&& other) noexcept
		: _counter(new size_t(other.getCounter())), _peopleList(new Person<string>* [_maxSize] {nullptr})
	{ CREATE_INFO("AFlat <- Move constrctor: called;"); for (size_t i = 0; i < *_counter; i++) { _peopleList[i] = other._peopleList[i]; other._peopleList[i] = nullptr; } }

	virtual ~AFlat() { CREATE_INFO("AFlat <- Destructor: called;"); for (size_t i = 0; i < *_counter; i++) { delete _peopleList[i]; } delete[] _peopleList; delete _counter; }

	size_t getCounter() const override { CREATE_INFO("AFlat -> Method getCounter: called;"); if (_counter != nullptr) { return *_counter; } else { return DEFAULT_EMPTY_NUMBER; } }

	Person<string>* getObject(const size_t& id) override { INFO("AFlat -> Method getObject: called;"); if (id >= *_counter || id < 0) { ERROR("AFlat -> Method getObject: incorrect ID!;"); } return _peopleList[id]; }

	string getList() const override { INFO("AFlat -> Method getList: called;"); string result; for (size_t i = 0; i < *_counter; i++) { result += to_string(i + 1) + ". " + _peopleList[i]->getName() + "\n"; } return result; }
	bool addPerson(APerson<string>& person) override
	{
		INFO("AFlat -> Method addPerson: called;");

		if (*_counter == _maxSize) { ERROR("AFlat -> Method addPerson: the list is full! return false;"); return false; }
		_peopleList[*_counter] = new Person<string>(person.getName());
		(*_counter)++;
	
		return true;
	}
	bool deletePerson(const size_t& id) const override
	{
		INFO("AFlat -> Method deletePerson: called;");
		
		if (id >= *_counter || id < 0) { ERROR("AFlat -> Method deletePerson: incorrect ID! return false;"); return false; }
		
		delete _peopleList[id];
		for (size_t i = id; i < *_counter - 1; i++) { _peopleList[i] = _peopleList[i + 1]; }
		_peopleList[*_counter - 1] = nullptr;
		(*_counter)--;
		
		return true;
	}
};

#endif