#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    char stroka[300],
        answer[300] = "\0";
    cout << "Write down the string (max 300 symbols):" << endl;
    bool isInOreder;
    cin.getline(stroka, 300, '\n');
    int i = 0, j = 1, start_of_word;
    for (int i = 0; stroka[i] != '\0'; i++)
    {
        isInOreder = true;
        while (stroka[i] == ' ')
        {
            ++i;
        };
        start_of_word = i;
        for (int j = i + 1; stroka[j] != ' ' && stroka[j] != '\0'; i++, j++)
        {
            if (stroka[i] + 1 != stroka[j])
            {
                isInOreder = false;
            }
        }
        if (isInOreder && answer[0] == '\0')
        {
            int j = 0;
            for (; stroka[start_of_word] != '\0' && stroka[start_of_word] != ' '; j++, start_of_word++)
            {
                answer[j] = stroka[start_of_word];
            }
            answer[j] = '\0';
        }

    }
    if (answer[0] != '\0')
        cout << "The answer is " << answer << endl;
    else
        cout << "There's now answer.\n";
    return 0;
}