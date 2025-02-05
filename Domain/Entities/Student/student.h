#ifndef STUDENT_H
#define STUDENT_H

#include "abstraction.h"

class PersonalInformation
    : public APersonalInformation<string> {
public:
    PersonalInformation();
    PersonalInformation(string name, string surname, unsigned short age);
    PersonalInformation(PersonalInformation&& other) noexcept;

    ~PersonalInformation() override;

    string getName() const override;
    string getSurname() const override;
    unsigned short getAge() const override;

    void setName(const string& value) override;
    void setSurname(const string& value) override;
    void setAge(const unsigned short& value) override;

    string getPersonalInformation() const override;
};

class StudentInformation
    : public AStudentInformation<string> {
public:
    StudentInformation();
    StudentInformation(size_t studentID, string email, string phoneNumber, string address);
    StudentInformation(StudentInformation&& other) noexcept;

    ~StudentInformation() override;

    size_t getStudentID() const override;
    string getEmail() const override;
    string getPhoneNumber() const override;
    string getAddress() const override;

    void setStudentID(const size_t& value) override;
    void setEmail(const string& value) override;
    void setPhoneNumber(const string& value) override;
    void setAddress(const string& value) override;

    string getStudentInformation() const override;
};

class ClassInformation
    : public AClassInformation<string> {
public:
    ClassInformation();
    ClassInformation(string className, string specialization, float gpa);
    ClassInformation(ClassInformation&& other) noexcept;

    ~ClassInformation() override;

    string getClassName() const override;
    string getSpecialization() const override;
    float getGPA() const override;

    void setClassName(const string& value) override;
    void setSpecialization(const string& value) override;
    void setGPA(const float& value) override;

    string getClassInformation() const override;
};

class Student
    : public AStudent<string> {
public:
    Student(APersonalInformation<string>* personalInformation, AStudentInformation<string>* studentInformation, AClassInformation<string>* classInformation);
    Student(Student&& other) noexcept;
    Student(AStudent&& other) noexcept;
    ~Student() override;

    string getStudentInformation() const override;
};

#endif