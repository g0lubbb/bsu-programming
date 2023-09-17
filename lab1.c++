#include <iostream>
#include <cmath>


using namespace std;
const double PI = 3.141592653589793;

int main()
{
    setlocale(LC_ALL, "Russian");
    int k;
    bool isEnd = false; // чтобы выйти из цикла
    int counter = 0; // чтобы пон€ть + или - у числа в цикле
    long double x, sum = 0, n = 1, eps = 0;
    cout << "¬ведите k" << endl;

    cin >> k;
    eps = powl(10, -k) - powl(10, -(k + 1));
    cout << "¬ведите x   -1 < x < 1" << endl;
    cin >> x;
    while ((x < -1) && (x > 1)) {
        cout << "¬ведите x подход€щий условию       -1 < x > 1 :";
        cin >> x;
    }
    cout << "јрккотангенс =" << PI/2 - atan(x) << endl;
    while (isEnd == false) // isEnd = true
    {
        long double number = powl(x, n) / n;
        if (abs(number) < eps)
            isEnd = true;
        if (counter % 2 == 0)
            sum += number;
        else
            sum -= number;
        n += 2;
        counter++;
    }
    sum = PI / 2 - sum;
    cout << "—умма равна " << sum << endl;
}
