#ifndef INTRO_H
#define INTRO_H

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#include "date.h"

class View
{
public:
	static void Intro()
	{
		Date* date = new Date(1, 1, 1);
		Date* date1 = new Date(1, 1, 1);

		cout << "Basic functionality:" << endl;
		cout << "  getDate: " << date->getDate() << endl
			<< endl
			<< "  getDay: " << date->getDay() << endl
			<< "  getMonth: " << date->getMonth() << endl
			<< "  getYear: " << date->getYear() << endl
			<< endl;
		cout << "  setDay(27)" << endl; date->setDay(27);
		cout << "  setMonth(2)" << endl; date->setMonth(2);
		cout << "  setYear(2)" << endl; date->setYear(2);
		cout << "  Result: " << date->getDate() << endl;
		cout << endl
			<< endl;

		cout << "Normal operator overload:" << endl;
		cout << "  Postfix ++ = "; (*date)++; cout << *date << endl;
		cout << "  Postfix -- = "; (*date)--; cout << *date << endl
			<< endl;
		cout << "  != = "; (*date != *date1) ? cout << "true" : cout << "false"; cout << endl;
		cout << "  == = "; (*date == *date1) ? cout << "true" : cout << "false"; cout << endl;
		cout << "  > = "; (*date > *date1) ? cout << "true" : cout << "false"; cout << endl;
		cout << "  < = "; (*date < *date1) ? cout << "true" : cout << "false"; cout << endl
			<< endl;
		cout << "  = (29-02-2024) = "; *date = Date(29, 02, 2024); cout << *date << endl;
		cout << "  += (50) = "; *date += 50; cout << *date << endl;
		cout << "  -= (100) = "; *date -= 100; cout << *date << endl
			<< endl;
		cout << "  () = "; cout << (*date)() << endl;
		cout << endl
			<< endl;
 
		cout << "Friendly operator overloading:" << endl;
		cout << "  Prefix ++ = "; ++(*date); cout << *date << endl;
		cout << "  Prefix -- = "; --(*date); cout << *date << endl
			<< endl;
		cout << "  >> = Enter the date (dd-mm-yyyy): "; cin >> *date; cout << "       Result: " << *date << endl;
		cout << "  << = " << *date << endl;
		cout << endl
			<< endl;

		delete date;
		delete date1;
	}
};

#endif