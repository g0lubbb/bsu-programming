#include <iostream>
using namespace std;
char* strcpy(char* dest, const char* src) {
    char* ptr = dest;
    while (*src != '\0') {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}

int main() {
    const int MAX_LENGTH = 300;
    char strSource[MAX_LENGTH];
    char strDestination[MAX_LENGTH];

    cout << "Enter the line to copy: ";
    cin.getline(strSource, MAX_LENGTH);

    strcpy(strDestination, strSource);

cout << "Copy result: " << strDestination << endl;

    return 0;
}
