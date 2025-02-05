#ifndef ASPIRANT_H
#define ASPIRANT_H

#include "../Student/student.h"

class Aspirant : public Student
{
public:
    Aspirant(APersonalInformation<string>* personalInformation, AStudentInformation<string>* studentInformation, AClassInformation<string>* classInformation);

    ~Aspirant() override;
};

#endif