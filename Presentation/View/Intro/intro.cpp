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