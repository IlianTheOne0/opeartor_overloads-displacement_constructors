#ifndef STUDENT_INTERFACE_H
#define STUDENT_INTERFACE_H

template<typename TReturn>
class IPersonalInformation
{
public:
	virtual TReturn getPersonalInformation() const = 0;
};

template<typename TReturn>
class IStudentInformation
{
public:
	virtual TReturn getStudentInformation() const = 0;
};

template<typename TReturn>
class IClassInformation
{
public:
	virtual TReturn getClassInformation() const = 0;
};

template<typename TReturn>
class IStudent
{
public:
	virtual TReturn getStudentInformation() const = 0;
};

#endif