#include "date.h"

ADate::ADate(unsigned short day, unsigned short month, unsigned long long year)
	: _day(day), _month(month), _year(year)
{ }
unsigned short ADate::getDay() const { return _day; }
unsigned short ADate::getMonth() const { return _month; }
unsigned long long ADate::getYear() const { return _year; }

void ADate::setDay(const unsigned short& value) { if (value > _daysInMonth[getMonth()]) { return; } _day = value; }
void ADate::setMonth(const unsigned short& value) { if (value > 12) { return; } _month = value; }
void ADate::setYear(const unsigned long long& value) { _year = value; }

Date::Date(unsigned short day, unsigned short month, unsigned long long year)
	: ADate(day, month, year)
{ }

string Date::getDate() const
{
	ostringstream oss;
	oss << setfill('0') << setw(2) << getDay()
		<< "-"
		<< setfill('0') << setw(2) << getMonth()
		<< "-"
		<< setfill('0') << setw(4) << getYear();
	return oss.str();
}
void Date::increase() { ++(*this); }

Date Date::operator ++ (int) { Date temp = *this; ++(*this); return temp; }
Date Date::operator -- (int) { Date temp = *this; --(*this); return temp; }

bool Date::operator != (const Date& other) const { return !(*this == other); }
bool Date::operator == (const Date& other) const { return _day == other._day && _month == other._month && _year == other._year; }
bool Date::operator > (const Date& other) const { return other < *this; }
bool Date::operator < (const Date& other) const
{
	if (_year < other._year) return true;
	if (_year > other._year) return false;
	if (_month < other._month) return true;
	if (_month > other._month) return false;
	return _day < other._day;
}

Date Date::operator = (const Date& other) { if (this != &other) { this->setDay(other.getDay()); this->setMonth(other.getMonth()); this->setYear(other.getYear()); return *this; } }
Date Date::operator += (const unsigned short days) {
	unsigned short newDay = this->getDay() + days;

	while (newDay > _daysInMonth[this->getMonth() - 1])
	{
		newDay -= _daysInMonth[this->getMonth() - 1];
		
		this->setMonth(this->getMonth() + 1);

		if (this->getMonth() > 12) { this->setMonth(1); this->setYear(this->getYear() + 1); }
	}
	this->setDay(newDay);

	return *this;
}
Date Date::operator -= (const unsigned short days) {
	int newDay = this->getDay() - days;

	while (newDay < 1) {
		this->setMonth(this->getMonth() - 1);

		if (this->getMonth() < 1) {	this->setMonth(12); this->setYear(this->getYear() - 1); }
	
		newDay += _daysInMonth[this->getMonth() - 1];
	}
	this->setDay(newDay);

	return *this;
}

string Date::operator () () { return this->getDate(); }

Date& operator ++ (Date& date)
{
	date.setDay(date.getDay() + 1);

	bool isLeapYear = (date.getYear() % 4 == 0 && date.getYear() % 100 != 0) || (date.getYear() % 400 == 0);

	if (isLeapYear && date.getMonth() == 2) { date._daysInMonth[1] = 29; }
	if (date.getDay() > date._daysInMonth[date.getMonth() - 1]) { date.setDay(1); date.setMonth(date.getMonth() + 1); }
	if (date.getMonth() > 12) { date.setMonth(1); date.setYear(date.getYear() + 1); }

	return date;
}
Date& operator -- (Date& date)
{
	date.setDay(date.getDay() - 1);

	unsigned short daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool isLeapYear = (date.getYear() % 4 == 0 && date.getYear() % 100 != 0) || (date.getYear() % 400 == 0);

	if (isLeapYear && date.getMonth() == 2) { daysInMonth[1] = 29; }
	if (date.getDay() < 1)
	{
		date.setMonth(date.getMonth() - 1);
		if (date.getMonth() < 1) { date.setMonth(12); date.setYear(date.getYear() - 1); }
		date.setDay(daysInMonth[date.getMonth() - 1]);
	}

	return date;
}
istream& operator >> (istream& is, Date& date) {
	unsigned short day, month;
	unsigned long long year;
	char char0, char1;

	if ((is >> day >> char0 >> month >> char1 >> year) && (char0 == '-' && char1 == '-')) { date.setDay(day); date.setMonth(month); date.setYear(year); }

	return is;
}
ostream& operator << (ostream& os, const Date& date) { os << date.getDate(); return os; }