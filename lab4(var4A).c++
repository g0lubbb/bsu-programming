#include <iostream>
#include <cstring>
int main() {
    char sentence[300];
    std::cout << "Enter the string: ";
    std::cin.getline(sentence, 300);
    char* nextword;
    char* word = strtok_s(sentence, " ", &nextword);
    char* result = nullptr;

    while (word != nullptr) {
        bool isIncreasing = true;
        int length = strlen(word);

        for (int i = 1; i < length; i++) {
            if (word[i] <= word[i - 1]) {
                isIncreasing = false;
                break;
            }
        }

        if (isIncreasing) {
            result = word;
            break;
        }
        word = strtok_s(nullptr, " ", &nextword);
    }

    if (result != nullptr) {
        std::cout << "The first word has been found whose characters are in strict ascending order of their codes: " << result << std::endl;
    }
    else {
        std::cout << "There are no such words" << std::endl;
    }

    return 0;
}