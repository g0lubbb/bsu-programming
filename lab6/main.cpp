#include <iostream>
#include "fraction.h"
using namespace std;



int main() {
    int numerator1, denominator1, numerator2, denominator2;
    cout << "Enter numerator1: ";
    cin >> numerator1;
    cout << "Enter denominator1: ";
    cin >> denominator1;
    cout << "Enter numerator2: ";
    cin >> numerator2;
    cout << "Enter denominator2: ";
    cin >> denominator2;

    Fraction fraction1(numerator1, denominator1);
    fraction1.printFraction();
    Fraction fraction2(numerator2, denominator2);
    fraction2.printFraction();

    cout << "------------------------" << endl;

    Fraction sum = fraction1.add(fraction2);
    Fraction multiplication = fraction1.multiplication(fraction2);
    Fraction division = fraction1.division(fraction2);
    sum.printFraction();
    multiplication.printFraction();
    division.printFraction();
    return 0;
}