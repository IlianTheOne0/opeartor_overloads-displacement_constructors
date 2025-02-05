#ifndef STUDENT_ABSTRACTION_H
#define STUDENT_ABSTRACTION_H

#include "interface.h"
#include "../../../Core/core.h"

template<typename TValue>
class APersonalInformation abstract
	: public IPersonalInformation<TValue>
{
protected:
	TValue* _name = nullptr;
	TValue* _surname = nullptr;
	unsigned short* _age = nullptr;
public:
	APersonalInformation()
		: _name(nullptr), _surname(nullptr), _age(nullptr)
	{
		CREATE_INFO("APersonalInformation <- Default constructor: called;");
	}
	APersonalInformation(TValue name, TValue surname, unsigned short age)
		: _name(new TValue(name)), _surname(new TValue(surname)), _age(new unsigned short(age))
	{
		CREATE_INFO("APersonalInformation <- Constructor: called;");
	}

	APersonalInformation(APersonalInformation&& other) noexcept
		: _name(other._name), _surname(other._surname), _age(other._age)
	{
		CREATE_INFO("APersonalInformation <- Move constructor: called;");
		other._name = nullptr;
		other._surname = nullptr;
		other._age = nullptr;
	}

	virtual ~APersonalInformation()
	{
		CREATE_INFO("APersonalInformation <- Destructor: called;");

		if (_name != nullptr) { delete _name; _name = nullptr; }
		if (_surname != nullptr) { delete _surname; _surname = nullptr; }
		if (_age != nullptr) { delete _age; _age = nullptr; }
	}

	virtual TValue getName() const = 0;
	virtual TValue getSurname() const = 0;
	virtual unsigned short getAge() const = 0;

	virtual void setName(const string& value) = 0;
	virtual void setSurname(const string& value) = 0;
	virtual void setAge(const unsigned short& value) = 0;
};

template<typename TValue>
class AStudentInformation abstract
	: public IStudentInformation<TValue>
{
protected:
	size_t* _studentID = nullptr;
	TValue* _email = nullptr;
	TValue* _phoneNumber = nullptr;
	TValue* _address = nullptr;
public:
	AStudentInformation()
		: _studentID(nullptr), _email(nullptr), _phoneNumber(nullptr), _address(nullptr)
	{
		CREATE_INFO("AStudentInformation <- Default constructor: called;");
	}
	AStudentInformation(size_t studentID, TValue email, TValue phoneNumber, TValue address)
		: _studentID(new size_t(studentID)), _email(new TValue(email)), _phoneNumber(new TValue(phoneNumber)), _address(new TValue(address))
	{
		CREATE_INFO("AStudentInformation <- Constructor: called;");
	}

	AStudentInformation(AStudentInformation&& other) noexcept
		: _studentID(other._studentID), _email(other._email), _phoneNumber(other._phoneNumber), _address(other._address)
	{
		CREATE_INFO("AStudentInformation <- Move constructor: called;");

		other._studentID = nullptr;
		other._email = nullptr;
		other._phoneNumber = nullptr;
		other._address = nullptr;
	}

	virtual ~AStudentInformation()
	{
		CREATE_INFO("AStudentInformation <- Destructor: called;");

		if (_studentID != nullptr) { delete _studentID; _studentID = nullptr; }
		if (_email != nullptr) { delete _email; _email = nullptr; }
		if (_phoneNumber != nullptr) { delete _phoneNumber; _phoneNumber = nullptr; }
		if (_address != nullptr) { delete _address; _address = nullptr; }
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
	TValue* _className = nullptr;
	TValue* _specialization = nullptr;
	float* _gpa = nullptr;
public:
	AClassInformation()
		: _className(nullptr), _specialization(nullptr), _gpa(nullptr)
	{
		CREATE_INFO("AClassInformation <- Default constructor: called;");
	}

	AClassInformation(TValue className, TValue specialization, float gpa)
		: _className(new TValue(className)), _specialization(new TValue(specialization)), _gpa(new float(gpa))
	{
		CREATE_INFO("AClassInformation <- Constructor: called;");
	}

	AClassInformation(AClassInformation&& other) noexcept
		: _className(other._className), _specialization(other._specialization), _gpa(other._gpa)
	{
		CREATE_INFO("AClassInformation <- Move constructor: called;");

		other._className = nullptr;
		other._specialization = nullptr;
		other._gpa = nullptr;
	}

	virtual ~AClassInformation()
	{
		CREATE_INFO("AClassInformation <- Destructor: called;");

		if (_className != nullptr) { delete _className; _className = nullptr; }
		if (_specialization != nullptr) { delete _specialization; _specialization = nullptr; }
		if (_gpa != nullptr) { delete _gpa; _gpa = nullptr; }
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

	AStudent(APersonalInformation<TValue>* personalInformation, AStudentInformation<TValue>* studentInformation, AClassInformation<TValue>* classInformation)
		: personalInformation(personalInformation), studentInformation(studentInformation), classInformation(classInformation)
	{
		CREATE_INFO("AStudent <- Constructor: called;");
	}

	AStudent(AStudent&& other) noexcept
		: personalInformation(other.personalInformation),
		studentInformation(other.studentInformation),
		classInformation(other.classInformation)
	{
		CREATE_INFO("AStudent <- Move constructor: called;");

		other.personalInformation = nullptr;
		other.studentInformation = nullptr;
		other.classInformation = nullptr;
	}

	virtual ~AStudent()
	{
		CREATE_INFO("AStudent <- Destructor: called;");

		if (personalInformation != nullptr) { delete personalInformation; personalInformation = nullptr; }
		if (studentInformation != nullptr) { delete studentInformation; studentInformation = nullptr; }
		if (classInformation != nullptr) { delete classInformation; classInformation = nullptr; }
	}
};

#endif