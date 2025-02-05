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

	delete flat1;
}

void View::Intro2()
{
	bool _return{};
	auto return_ = [](const bool& value) { if (!value) { return "ERROR\n"; } return "PASSED\n"; };

	APerson<string>* person0 = new Person<string>("Joe");
	APerson<string>* person1 = new Person<string>("Hoe");
	APerson<string>* person2 = new Person<string>("Noe");
	APerson<string>* person3 = new Person<string>("Moe");

	AFlat* flat0 = new Flat();

	_return = flat0->addPerson(*person0); delete person0;
	_return = flat0->addPerson(*person1); delete person1;
	_return = flat0->addPerson(*person2); delete person2;
	_return = flat0->addPerson(*person3); delete person3;
	AFlat* flat1 = new Flat(move(*flat0));
	AFlat* flat2 = new Flat(move(*flat0));
	AFlat* flat3 = new Flat(move(*flat0));
	AFlat* flat4 = new Flat(move(*flat0));

	AHouse* house0 = new House();
	_return = house0->addFlat(*flat0); cout << "0. " << return_(_return); delete flat0;
	_return = house0->addFlat(*flat1); cout << "1. " << return_(_return); delete flat1;
	_return = house0->addFlat(*flat2); cout << "2. " << return_(_return); delete flat2;
	_return = house0->addFlat(*flat3); cout << "3. " << return_(_return); delete flat3;
	_return = house0->addFlat(*flat4); cout << "4. " << return_(_return); delete flat4;

	cout << house0->getCounter() << endl;

	cout << house0->getObject(0)->getList() << endl;
	cout << house0->getObject(1)->getList() << endl;
	cout << house0->getObject(2)->getList() << endl;
	cout << house0->getObject(3)->getList() << endl;
	cout << house0->getObject(4)->getList() << endl;
}