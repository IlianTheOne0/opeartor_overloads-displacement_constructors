#include "../view.h"
#include "../../../Domain/domain.h"

void View::Intro0()
{
	Person* person0 = new Person("Joe");
	Person* person1 = move(person0);
	Person* person2 = new Person("Joe");

	person1->setName("Jhon");

	cout << person1->getName() << endl
		<< person2->getName() << endl;

	delete person1;
	delete person2;
}