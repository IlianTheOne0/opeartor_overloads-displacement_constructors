#include "student.h"

PersonalInformation::PersonalInformation() : APersonalInformation() {
    CREATE_INFO("PersonalInformation <- Constructor: called;");
}
PersonalInformation::PersonalInformation(string name, string surname, unsigned short age)
    : APersonalInformation(name, surname, age) {
    CREATE_INFO("PersonalInformation <- Constructor: called;");
}

PersonalInformation::~PersonalInformation() {
    CREATE_INFO("PersonalInformation <- Destructor: called;");
}

string PersonalInformation::getName() const { INFO("PersonalInformation -> Method: getName;"); return this->_name; }
string PersonalInformation::getSurname() const { INFO("PersonalInformation -> Method: getSurname;"); return this->_surname; }
unsigned short PersonalInformation::getAge() const { INFO("PersonalInformation -> Method: getAge;"); return this->_age; }

void PersonalInformation::setName(const string& value) { INFO("PersonalInformation -> Method: setName;"); this->_name = value; }
void PersonalInformation::setSurname(const string& value) { INFO("PersonalInformation -> Method: setSurname;"); this->_surname = value; }
void PersonalInformation::setAge(const unsigned short& value) { INFO("PersonalInformation -> Method: setAge;"); this->_age = value; }

string PersonalInformation::getPersonalInformation() const {
    INFO("PersonalInformation -> Method: getPersonalInformation;");

    return "Personal Information:\n  Name: " + getName()
        + "\n  Surname: " + getSurname()
        + "\n  Age: " + to_string(getAge())
        + "\n";
}

StudentInformation::StudentInformation() : AStudentInformation() {
    CREATE_INFO("StudentInformation <- Constructor: called;");
}
StudentInformation::StudentInformation(size_t studentID, string email, string phoneNumber, string address)
    : AStudentInformation(studentID, email, phoneNumber, address) {
    CREATE_INFO("StudentInformation <- Constructor: called;");
}

StudentInformation::~StudentInformation() {
    CREATE_INFO("StudentInformation <- Destructor: called;");
}

size_t StudentInformation::getStudentID() const { INFO("StudentInformation -> Method: getStudentID;"); return this->_studentID; }
string StudentInformation::getEmail() const { INFO("StudentInformation -> Method: getEmail;"); return this->_email; }
string StudentInformation::getPhoneNumber() const { INFO("StudentInformation -> Method: getPhoneNumber;"); return this->_phoneNumber; }
string StudentInformation::getAddress() const { INFO("StudentInformation -> Method: getAddress;"); return this->_address; }

void StudentInformation::setStudentID(const size_t& value) { INFO("StudentInformation -> Method: setStudentID;"); this->_studentID = value; }
void StudentInformation::setEmail(const string& value) { INFO("StudentInformation -> Method: setEmail;"); this->_email = value; }
void StudentInformation::setPhoneNumber(const string& value) { INFO("StudentInformation -> Method: setPhoneNumber;"); this->_phoneNumber = value; }
void StudentInformation::setAddress(const string& value) { INFO("StudentInformation -> Method: setAddress;"); this->_address = value; }

string StudentInformation::getStudentInformation() const {
    INFO("StudentInformation -> Method: getStudentInformation;");

    return "Student Information:\n  ID: " + to_string(getStudentID())
        + "\n  Email: " + getEmail()
        + "\n  Phone number: " + getPhoneNumber()
        + "\n  Address: " + getAddress()
        + "\n";
}

ClassInformation::ClassInformation() : AClassInformation() {
    CREATE_INFO("ClassInformation <- Constructor: called;");
}
ClassInformation::ClassInformation(string className, string specialization, float gpa)
    : AClassInformation(className, specialization, gpa) {
    CREATE_INFO("ClassInformation <- Constructor: called;");
}

ClassInformation::~ClassInformation() {
    CREATE_INFO("ClassInformation <- Destructor: called;");
}

string ClassInformation::getClassName() const { INFO("ClassInformation -> Method: getClassName;"); return this->_className; }
string ClassInformation::getSpecialization() const { INFO("ClassInformation -> Method: getSpecialization;"); return this->_specialization; }
float ClassInformation::getGPA() const { INFO("ClassInformation -> Method: getGPA;"); return this->_gpa; }

void ClassInformation::setClassName(const string& value) { INFO("ClassInformation -> Method: setClassName;"); this->_className = value; }
void ClassInformation::setSpecialization(const string& value) { INFO("ClassInformation -> Method: setSpecialization;"); this->_specialization = value; }
void ClassInformation::setGPA(const float& value) { INFO("ClassInformation -> Method: setGPA;"); this->_gpa = value; }

string ClassInformation::getClassInformation() const {
    INFO("ClassInformation -> Method: getClassInformation;");

    return "Class Information:\n  Class name: " + getClassName()
        + "\n  Specialization: " + getSpecialization()
        + "\n  GPA: " + to_string(getGPA())
        + "\n";
}

Student::Student(APersonalInformation<string>& personalInformation, AStudentInformation<string>& studentInformation, AClassInformation<string>& classInformation)
    : AStudent(personalInformation, studentInformation, classInformation) {
    CREATE_INFO("Student <- Constructor: called;");
}

Student::~Student() {
    CREATE_INFO("Student <- Destructor: called;");
}

string Student::getStudentInformation() const {
    INFO("Student -> Method: getStudentInformation;");

    string result = "";

    result += personalInformation->getPersonalInformation();
    result += studentInformation->getStudentInformation();
    result += classInformation->getClassInformation();

    return result;
}