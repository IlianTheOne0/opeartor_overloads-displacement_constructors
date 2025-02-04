#ifndef DATE_H
#define DATE_H

#include <string>
#include <iomanip>
#include <sstream>
#include <istream>

using std::string;
using std::to_string;
using std::setw;
using std::setfill;
using std::ostringstream;
using std::ostream;
using std::istream;

class IDate
{
public:
	virtual unsigned short getDay() const = 0;
	virtual unsigned short getMonth() const = 0;
	virtual unsigned long long getYear() const = 0;

	virtual void setDay(const unsigned short& value) = 0;
	virtual void setMonth(const unsigned short& value) = 0;
	virtual void setYear(const unsigned long long& value) = 0;

	virtual string getDate() const = 0;
	virtual void increase() = 0;
};

class ADate abstract
	: public IDate
{
protected:
	unsigned short _day;
	unsigned short _month;
	unsigned long long _year;

	unsigned short _daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
	ADate() = delete;
	ADate(unsigned short day, unsigned short month, unsigned long long year);
	virtual ~ADate() = default;

	unsigned short getDay() const override;
	unsigned short getMonth() const override;
	unsigned long long getYear() const override;

	void setDay(const unsigned short& value) override;
	void setMonth(const unsigned short& value) override;
	void setYear(const unsigned long long& value) override;
};

class Date
	: public ADate
{
public:
	Date(unsigned short day, unsigned short month, unsigned long long year);
	~Date() override = default;

	string getDate() const override;
	void increase() override;

	Date operator ++ (int);
	Date operator -- (int);

	bool operator != (const Date& other) const;
	bool operator == (const Date& other) const;
	bool operator > (const Date& other) const;
	bool operator < (const Date& other) const;
	
	Date operator = (const Date& other);
	Date operator += (const unsigned short day);
	Date operator -= (const unsigned short day);

	string operator () ();

	friend Date& operator ++ (Date& date);
	friend Date& operator -- (Date& date);
	friend istream& operator >> (istream& is, Date& date);
	friend ostream& operator << (ostream& os, const Date& date);
};

#endif