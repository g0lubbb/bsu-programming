#include "student.h"

int Student::lastId = 0;

Student::Student(const string& name, int course, const string& group, const string& recordBookNumber)
{
    this->id = to_string(++lastId);
    this->name = name;
    this->course = course;
    this->group = group;
    this->recordBookNumber = recordBookNumber;
}

Student::Student(const Student& other)
{
    this->id = other.id;
    this->name = other.name;
    this->course = other.course;
    this->group = other.group;
    this->recordBookNumber = other.recordBookNumber;
}

Student::~Student()
{
}

const string& Student::getId() const
{
    return id;
}

const string& Student::getName() const
{
    return name;
}

int Student::getCourse() const
{
    return course;
}

const string& Student::getGroup() const
{
    return group;
}

const string& Student::getRecordBookNumber() const
{
    return recordBookNumber;
}

void Student::setName(const string& name)
{
    this->name = name;
}

void Student::setCourse(int course)
{
    this->course = course;
}

void Student::setGroup(const string& group)
{
    this->group = group;
}

ostream& operator<<(ostream& os, const Student& student)
{
    os << "Id: " << student.id << endl;
    os << "Name: " << student.name << endl;
    os << "Course: " << student.course << endl;
    os << "Group: " << student.group << endl;
    os << "Record Book Number: " << student.recordBookNumber << endl;

    return os;
}

FirstSessionStudent::FirstSessionStudent(const string& name, int course, const string& group, const string& recordBookNumber)
        : Student(name, course, group, recordBookNumber)
{
}

FirstSessionStudent::FirstSessionStudent(const FirstSessionStudent& other)
        : Student(other)
{
    for (int i = 0; i < 4; i++)
    {
        this->grades[i] = other.grades[i];
    }
}

FirstSessionStudent::~FirstSessionStudent()
{
}

void FirstSessionStudent::setValueAt(int index, double value)
{
    if (index >= 0 && index < 4)
    {
        grades[index] = value;
    }
}

double FirstSessionStudent::getValueAt(int index) const
{
    if (index >= 0 && index < 4)
    {
        return grades[index];
    }
    return 0;
}

double FirstSessionStudent::calculateAverageGrade() const {
    double sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += grades[i];
    }
    return sum;
}