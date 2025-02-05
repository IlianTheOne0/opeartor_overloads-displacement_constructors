#include "../view.h"
#include "../../../Domain/domain.h"

void View::Intro0()
{
    size_t counter = 0;

    APersonalInformation<string>* personalInformation = nullptr;
    AStudentInformation<string>* studentInformation = nullptr;
    AClassInformation<string>* classInformation = nullptr;
    AStudent<string>* student = nullptr;
    counter++;

    personalInformation = new PersonalInformation("Michael", "Brown", 21);
    studentInformation = new StudentInformation(counter, "michael.brown@example.com", "+1234567890", "101 Maple St.");
    classInformation = new ClassInformation("CS-201", "Computer Science", 3.6f);

    student = new Student(personalInformation, studentInformation, classInformation);

    cout << student->getStudentInformation() << endl;

    delete student;

    APersonalInformation<string>* personalInformation1 = new PersonalInformation();
    AStudentInformation<string>* studentInformation1 = new StudentInformation();
    AClassInformation<string>* classInformation1 = new ClassInformation();
    AStudent<string>* student1 = new Student(personalInformation1, studentInformation1, classInformation1);
    counter++;

    student1->personalInformation->setName("Emily");
    student1->personalInformation->setSurname("Davis");
    student1->personalInformation->setAge(23);
    cout << student1->getStudentInformation() << endl;

    student1->studentInformation->setStudentID(counter);
    student1->studentInformation->setEmail("emily.davis@example.com");
    student1->studentInformation->setPhoneNumber("+0987654321");
    student1->studentInformation->setAddress("202 Pine St.");
    cout << student1->getStudentInformation() << endl;

    student1->classInformation->setClassName("EE-303");
    student1->classInformation->setSpecialization("Electrical Engineering");
    student1->classInformation->setGPA(3.7f);
    cout << student1->getStudentInformation() << endl;

    delete student1;
}

void View::Intro1()
{
    size_t size = 5;
    size_t counter = 0;
    Student** aspirants = new Student * [size];

    aspirants[counter] = new Aspirant(
        new PersonalInformation("John", "Doe", 20),
        new StudentInformation(counter, "john.doe@example.com", "+1234567890", "123 Main St."),
        new ClassInformation("CS-101", "Computer Science", 3.5f)
    );
    counter++;

    aspirants[counter] = new Aspirant(
        new PersonalInformation("Jane", "Smith", 22),
        new StudentInformation(counter, "jane.smith@example.com", "+0987654321", "456 Elm St."),
        new ClassInformation("EE-202", "Electrical Engineering", 3.8f)
    );
    counter++;

    aspirants[counter] = new Aspirant(
        new PersonalInformation("Alice", "Johnson", 19),
        new StudentInformation(counter, "alice.johnson@example.com", "+1122334455", "789 Oak St."),
        new ClassInformation("ME-303", "Mechanical Engineering", 3.9f)
    );
    counter++;

    for (size_t i = 0; i < counter; i++)
    {
        cout << "Aspirant Num. " << i + 1 << endl;
        cout << aspirants[i]->getStudentInformation() << endl << endl;
    }

    for (size_t i = 0; i < counter; ++i) {
        delete aspirants[i];
    }
    delete[] aspirants;
}

void View::Intro2()
{
    size_t counter = 0;

    APersonalInformation<string>* personalInformation = nullptr;
    AStudentInformation<string>* studentInformation = nullptr;
    AClassInformation<string>* classInformation = nullptr;
    AStudent<string>* student = nullptr;

    personalInformation = new PersonalInformation("Michael", "Brown", 21);
    studentInformation = new StudentInformation(counter, "michael.brown@example.com", "+1234567890", "101 Maple St.");
    classInformation = new ClassInformation("CS-201", "Computer Science", 3.6f);

    student = new Student(personalInformation, studentInformation, classInformation);

    cout << student->getStudentInformation() << endl;

    AStudent<string>* student1 = move(student);
    cout << student1->getStudentInformation() << endl;
    counter++;

    delete student1;
}