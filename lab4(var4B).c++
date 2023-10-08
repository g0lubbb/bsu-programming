#include <iostream>

char* strcpy(char* dest, const char* src) {
    char* ptr = dest;
    while (*src != '\0') {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}

int main() {
    const int MAX_LENGTH = 100;
    char strSource[MAX_LENGTH];
    char strDestination[MAX_LENGTH];

    std::cout << "Enter the line to copy: ";
    std::cin.getline(strSource, MAX_LENGTH);

    strcpy(strDestination, strSource);

    std::cout << "Copy result: " << strDestination << std::endl;

    return 0;
}