

#ifndef INHERIT_STUDENT_H
#define INHERIT_STUDENT_H

#include <iostream>
using namespace std;

class Student {
public:
    Student(const string& name, int course, const string& group, const string& recordBookNumber);
    Student(const Student& other);
    virtual ~Student();

    const string& getId() const;
    const string& getName() const;
    int getCourse() const;
    const string& getGroup() const;
    const string& getRecordBookNumber() const;

    void setName(const string& name);
    void setCourse(int course);
    void setGroup(const string& group);

    virtual double calculateAverageGrade() const = 0;
    virtual void setValueAt(int index, double value) = 0;
    virtual double getValueAt(int index) const = 0;

    friend ostream& operator<<(ostream& os, const Student& student);

private:
    string id;
    string name;
    int course;
    string group;
    string recordBookNumber;
    static int lastId;
};

class FirstSessionStudent : public Student {
public:
    FirstSessionStudent(const string& name, int course, const string& group, const string& recordBookNumber);
    FirstSessionStudent(const FirstSessionStudent& other);
    ~FirstSessionStudent();

    void setValueAt(int index, double value);
    double getValueAt(int index) const;

    double calculateAverageGrade() const;

private:
    double grades[4];
};

class SecondSessionStudent : public FirstSessionStudent {
public:
    SecondSessionStudent(const string& name, int course, const string& group, const string& recordBookNumber);
    SecondSessionStudent(const SecondSessionStudent& other);
    ~SecondSessionStudent();

    void setValueAt(int index, double value);
    double getValueAt(int index) const;

    double calculateAverageGrade() const;

private:
    double grades[5];
};


#endif //INHERIT_STUDENT_H
