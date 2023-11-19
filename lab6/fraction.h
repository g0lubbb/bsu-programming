#pragma once
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
    void simplify();

public:
    Fraction(int num, int denom);

    Fraction(const Fraction& f);

    void reduceFraction();

    int getNumerator();
    int getDenominator();
    Fraction add(const Fraction& f);
    Fraction multiplication(const Fraction& f);
    Fraction division(const Fraction& f);

    //operator(+,*,/)

    Fraction operator+(const Fraction& f);

    Fraction operator*(const Fraction& f);

    Fraction operator/(const Fraction& f);

    void printFraction();

};
