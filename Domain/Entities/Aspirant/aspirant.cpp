#include "aspirant.h"

Aspirant::Aspirant(APersonalInformation<string>& personalInformation, AStudentInformation<string>& studentInformation, AClassInformation<string>& classInformation)
    : Student(personalInformation, studentInformation, classInformation)
{
    CREATE_INFO("Aspirant <- Constructor: called;");
}

Aspirant::~Aspirant()
{
    CREATE_INFO("Aspirant <- Destructor: called;");

    delete personalInformation;
    delete studentInformation;
    delete classInformation;
}