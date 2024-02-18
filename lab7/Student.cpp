#include <iostream>
#include "Student.h"
#include <time.h>
using namespace std;
const vector <char> CreateID() {
    srand(time(NULL));
    vector<char> ID = {};
    for (int i = 0; i < 11; ++i) {
        ID.push_back(rand() % 10);
    }
    return ID;
}

