#ifndef STUDENT_ABSTRACTION_H
#define STUDENT_ABSTRACTION_H

#include "interface.h"
#include "../../../Core/core.h"

template<typename TValue>
class APersonalInformation abstract
	: public IPersonalInformation<TValue>
{
protected:
	TValue _name;
	TValue _surname;
	unsigned short _age;
public:
	APersonalInformation()
		: _name(DEFAULT_EMPTY_STRING), _surname(DEFAULT_EMPTY_STRING), _age(DEFAULT_EMPTY_NUMBER)
	{
		CREATE_INFO("APersonalInformation <- Default constructor: called;");
	}
	APersonalInformation(TValue name, TValue surname, unsigned short age)
		: _name(name), _surname(surname), _age(age)
	{
		CREATE_INFO("APersonalInformation <- Constructor: called;");
	}

	virtual ~APersonalInformation()
	{
		CREATE_INFO("APersonalInformation <- Destructor: called;");
	}

	virtual TValue getName() const = 0;
	virtual TValue getSurname() const = 0;
	virtual unsigned short getAge() const = 0;
	virtual void setName(const TValue& value) = 0;
	virtual void setSurname(const TValue& value) = 0;
	virtual void setAge(const unsigned short& value) = 0;
};

template<typename TValue>
class AStudentInformation abstract
	: public IStudentInformation<TValue>
{
protected:
	size_t _studentID;
	TValue _email;
	TValue _phoneNumber;
	TValue _address;
public:
	AStudentInformation()
		: _studentID(DEFAULT_EMPTY_NUMBER), _email(DEFAULT_EMPTY_STRING), _phoneNumber(DEFAULT_EMPTY_STRING), _address(DEFAULT_EMPTY_STRING)
	{
		CREATE_INFO("AStudentInformation <- Default constructor: called;");
	}
	AStudentInformation(size_t studentID, TValue email, TValue phoneNumber, TValue address)
		: _studentID(studentID), _email(email), _phoneNumber(phoneNumber), _address(address)
	{
		CREATE_INFO("AStudentInformation <- Constructor: called;");
	}

	virtual ~AStudentInformation()
	{
		CREATE_INFO("AStudentInformation <- Destructor: called;");
	}

	virtual size_t getStudentID() const = 0;
	virtual TValue getEmail() const = 0;
	virtual TValue getPhoneNumber() const = 0;
	virtual TValue getAddress() const = 0;
	virtual void setStudentID(const size_t& value) = 0;
	virtual void setEmail(const TValue& value) = 0;
	virtual void setPhoneNumber(const TValue& value) = 0;
	virtual void setAddress(const TValue& value) = 0;
};

template<typename TValue>
class AClassInformation abstract
	: public IClassInformation<TValue>
{
protected:
	TValue _className;
	TValue _specialization;
	float _gpa;
public:
	AClassInformation()
		: _className(DEFAULT_EMPTY_STRING), _specialization(DEFAULT_EMPTY_STRING), _gpa(DEFAULT_EMPTY_FLOAT)
	{
		CREATE_INFO("AClassInformation <- Default constructor: called;");
	}

	AClassInformation(TValue className, TValue specialization, float gpa)
		: _className(className), _specialization(specialization), _gpa(gpa)
	{
		CREATE_INFO("AClassInformation <- Constructor: called;");
	}

	virtual ~AClassInformation()
	{
		CREATE_INFO("AClassInformation <- Destructor: called;");
	}

	virtual TValue getClassName() const = 0;
	virtual TValue getSpecialization() const = 0;
	virtual float getGPA() const = 0;
	virtual void setClassName(const TValue& value) = 0;
	virtual void setSpecialization(const TValue& value) = 0;
	virtual void setGPA(const float& value) = 0;
};

template<typename TValue>
class AStudent abstract
	: public IStudent<TValue>
{
public:
	APersonalInformation<TValue>* personalInformation = nullptr;
	AStudentInformation<TValue>* studentInformation = nullptr;
	AClassInformation<TValue>* classInformation = nullptr;

	AStudent() = delete;

	AStudent(APersonalInformation<TValue>& personalInformation, AStudentInformation<TValue>& studentInformation, AClassInformation<TValue>& classInformation)
		: personalInformation(&personalInformation), studentInformation(&studentInformation), classInformation(&classInformation)
	{
		CREATE_INFO("AStudent <- Constructor: called;");
	}

	virtual ~AStudent()
	{
		CREATE_INFO("AStudent <- Destructor: called;");
	}
};

#endif