#pragma once
#include <iostream>
#include <vector>
using namespace std;

const vector<char> CreateID();

class Student {
private:
    Student() = default;

protected:
    const vector<char> ID = CreateID ();
    vector<char> _name;
    int _year_of_study;
    int _group;
    int _num_of_record_book;
public:

};