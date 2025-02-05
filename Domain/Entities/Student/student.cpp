#include "student.h"

PersonalInformation::PersonalInformation() : APersonalInformation() {
    CREATE_INFO("PersonalInformation <- Constructor: called;");
}
PersonalInformation::PersonalInformation(string name, string surname, unsigned short age)
    : APersonalInformation(name, surname, age) {
    CREATE_INFO("PersonalInformation <- Constructor: called;");
}
PersonalInformation::PersonalInformation(PersonalInformation&& other) noexcept
    : APersonalInformation(move(other)) {
    CREATE_INFO("PersonalInformation <- Move constructor: called;");
}

PersonalInformation::~PersonalInformation() {
    CREATE_INFO("PersonalInformation <- Destructor: called;");

    delete _name; _name = nullptr;
    delete _surname; _surname = nullptr;
    delete _age; _age = nullptr;
}

string PersonalInformation::getName() const { INFO("PersonalInformation -> Method: getName;"); if (_name == nullptr) { return DEFAULT_EMPTY_STRING; } return *_name; }
string PersonalInformation::getSurname() const { INFO("PersonalInformation -> Method: getSurname;"); if (_surname == nullptr) { return DEFAULT_EMPTY_STRING; } return *_surname; }
unsigned short PersonalInformation::getAge() const { INFO("PersonalInformation -> Method: getAge;"); if (_age == nullptr) { return DEFAULT_EMPTY_NUMBER; } return *_age; }

void PersonalInformation::setName(const string& value) { INFO("PersonalInformation -> Method: setName;"); if (_name == nullptr) { _name = new string(value); } else { *_name = value; } }
void PersonalInformation::setSurname(const string& value) { INFO("PersonalInformation -> Method: setSurname;"); if (_surname == nullptr) { _surname = new string(value); } else { *_surname = value; } }
void PersonalInformation::setAge(const unsigned short& value) { INFO("PersonalInformation -> Method: setAge;"); if (_age == nullptr) { _age = new unsigned short (value); } else { *_age = value; } }

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
StudentInformation::StudentInformation(StudentInformation&& other) noexcept
    : AStudentInformation(move(other)) {
    CREATE_INFO("StudentInformation <- Move constructor: called;");
}

StudentInformation::~StudentInformation() {
    CREATE_INFO("StudentInformation <- Destructor: called;");
}

size_t StudentInformation::getStudentID() const { INFO("StudentInformation -> Method: getStudentID;"); if (_studentID == nullptr) { return DEFAULT_EMPTY_NUMBER; } return *_studentID; }
string StudentInformation::getEmail() const { INFO("StudentInformation -> Method: getEmail;"); if (_email == nullptr) { return DEFAULT_EMPTY_STRING; } return *_email; }
string StudentInformation::getPhoneNumber() const { INFO("StudentInformation -> Method: getPhoneNumber;"); if (_phoneNumber == nullptr) { return DEFAULT_EMPTY_STRING; } return *_phoneNumber; }
string StudentInformation::getAddress() const { INFO("StudentInformation -> Method: getAddress;"); if (_address == nullptr) { return DEFAULT_EMPTY_STRING; } return *_address; }

void StudentInformation::setStudentID(const size_t& value) { INFO("StudentInformation -> Method: setStudentID;"); if (_studentID == nullptr) { _studentID = new size_t(value); } else { *_studentID = value; } }
void StudentInformation::setEmail(const string& value) { INFO("StudentInformation -> Method: setEmail;"); if (_email == nullptr) { _email = new string(value); } else { *_email = value; } }
void StudentInformation::setPhoneNumber(const string& value) { INFO("StudentInformation -> Method: setPhoneNumber;"); if (_phoneNumber == nullptr) { _phoneNumber = new string(value); } else { *_phoneNumber = value; } }
void StudentInformation::setAddress(const string& value) { INFO("StudentInformation -> Method: setAddress;"); if (_address == nullptr) { _address = new string(value); } else { *_address = value; } }

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
ClassInformation::ClassInformation(ClassInformation&& other) noexcept
    : AClassInformation(move(other)) {
    CREATE_INFO("ClassInformation <- Move constructor: called;");
}

ClassInformation::~ClassInformation() {
    CREATE_INFO("ClassInformation <- Destructor: called;");
}

string ClassInformation::getClassName() const { INFO("ClassInformation -> Method: getClassName;"); if (_className == nullptr) { return DEFAULT_EMPTY_STRING; } return *_className; }
string ClassInformation::getSpecialization() const { INFO("ClassInformation -> Method: getSpecialization;"); if (_specialization == nullptr) { return DEFAULT_EMPTY_STRING; } return *_specialization; }
float ClassInformation::getGPA() const { INFO("ClassInformation -> Method: getGPA;"); if (_gpa == nullptr) { return DEFAULT_EMPTY_FLOAT; } return *_gpa; }

void ClassInformation::setClassName(const string& value) { INFO("ClassInformation -> Method: setClassName;"); if (_className == nullptr) { _className = new string(value); } *_className = value; }
void ClassInformation::setSpecialization(const string& value) { INFO("ClassInformation -> Method: setSpecialization;"); if (_specialization == nullptr) { _specialization = new string(value); } *_specialization = value; }
void ClassInformation::setGPA(const float& value) { INFO("ClassInformation -> Method: setGPA;"); if (_gpa == nullptr) { _gpa = new float(value); } *_gpa = value; }

string ClassInformation::getClassInformation() const {
    INFO("ClassInformation -> Method: getClassInformation;");

    return "Class Information:\n  Class name: " + getClassName()
        + "\n  Specialization: " + getSpecialization()
        + "\n  GPA: " + to_string(getGPA())
        + "\n";
}

Student::Student(APersonalInformation<string>* personalInformation, AStudentInformation<string>* studentInformation, AClassInformation<string>* classInformation)
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