#include "../view.h"
#include "../../../Domain/domain.h"

void View::Intro0()
{
	APerson<string>* person0 = new Person<string>("Joe");
	APerson<string>* person1 = new Person<string>(move(*person0)); delete person0;
	
	cout << person1->getName() << endl;

	person1->setName("Hello world!");
	cout << person1->getName() << endl;
	
	delete person1;
}

void View::Intro1()
{
	bool _return{};
	auto return_ = [](const bool& value) { if (!value) { return "ERROR\n"; } return "PASSED\n"; };

	APerson<string>* person0 = new Person<string>("Joe");
	APerson<string>* person1 = new Person<string>("Hoe");
	APerson<string>* person2 = new Person<string>("Noe");
	APerson<string>* person3 = new Person<string>("Moe");
	APerson<string>* person4 = new Person<string>("Koe");

	AFlat* flat0 = new Flat();

	_return = flat0->addPerson(*person0); cout << "0. " << return_(_return); delete person0;
	_return = flat0->addPerson(*person1); cout << "1. " << return_(_return); delete person1;
	_return = flat0->addPerson(*person2); cout << "2. " << return_(_return); delete person2;
	_return = flat0->addPerson(*person3); cout << "3. " << return_(_return); delete person3;
	_return = flat0->addPerson(*person4); cout << "4. " << return_(_return); delete person4;
	AFlat* flat1 = new Flat(move(*flat0)); delete flat0;

	cout << flat1->getList() << endl;
	cout << flat1->getCounter() << endl;

	cout << flat1->getObject(0)->getName() << endl;
	cout << flat1->getObject(1)->getName() << endl;
	cout << flat1->getObject(2)->getName() << endl;
	cout << flat1->getObject(3)->getName() << endl;

	flat1->getObject(0)->setName("hello world 0");
	flat1->getObject(1)->setName("hello world 1");
	flat1->getObject(2)->setName("hello world 2");
	flat1->getObject(3)->setName("hello world 3");

	cout << flat1->getList() << endl;

	delete flat1;
}

void View::Intro2()
{
	AHouse* house = new House();
	bool _return{};
	auto return_ = [](const bool& value) -> string { if (!value) { return "ERROR\n"; } return "PASSED\n"; };

	string names[5] = { "Joe", "Hoe", "Noe", "Moe", "Koe" };

	for (size_t i = 0; i < 15; i++)
	{
		AFlat* flat = new Flat();
		
		for (size_t j = 0; j < 4; j++)
		{
			APerson<string>* person = new Person<string>(names[j % 5]);
			_return = flat->addPerson(*person); cout << i << "." << j << ". " << return_(_return); delete person;
		}

		_return = house->addFlat(*flat); cout << "Flat " << i << ". " << return_(_return); delete flat; cout << endl;
	}

	cout << endl << endl;

	AHouse* house0 = new House(move(*house)); delete house;

	for (size_t i = 0; i < house0->getCounter(); ++i) { cout << "Flat " << i << " contains: " << endl << house0->getObject(i)->getList() << endl; }

	house0->getObject(5)->getObject(3)->setName("Anton");
	cout << house0->getObject(5)->getObject(3)->getName() << endl;
	cout << "Flat 5 contains: " << endl << house0->getObject(5)->getList() << endl;

	delete house0;
}