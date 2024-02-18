#include <iostream>
#include "fraction.h"
using namespace std;


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void Fraction:: reduceFraction() {
    int gcdVal = gcd(numerator, denominator);
    numerator /= gcdVal;
    denominator /= gcdVal;
}
Fraction::Fraction(int num, int denom) {
    if (denom == 0) {
        cout << "Division by zero is not allowed" << endl;
    }
    this->numerator = num;
    this->denominator = denom;
    reduceFraction();
}
Fraction::Fraction(const Fraction& f) { // copy
    numerator = f.numerator;
    denominator = f.denominator;
}
int Fraction::getNumerator() {
    return numerator;
}
int Fraction::getDenominator() {
    return denominator;
}
Fraction Fraction::add(const Fraction& f) {
    int num = numerator * f.denominator + f.numerator * denominator;
    int denom = denominator * f.denominator;
    return Fraction(num, denom);
}
Fraction Fraction::multiplication(const Fraction& f) {
    int num = numerator * f.numerator;
    int denom = denominator * f.denominator;
    return Fraction(num, denom);
}
Fraction Fraction::division(const Fraction& f) {
    int num = numerator * f.denominator;
    int denom = denominator * f.numerator;
    return Fraction(num, denom);
}

//operator(+,*,/)

Fraction Fraction::operator+(const Fraction& f) {
    int num = numerator * f.denominator + f.numerator * denominator;
    int denom = denominator * f.denominator;
    return Fraction(num, denom);
}

Fraction Fraction::operator*(const Fraction& f) {
    int num = numerator * f.numerator;
    int denom = denominator * f.denominator;
    return Fraction(num, denom);
}

Fraction Fraction:: operator/(const Fraction& f) {
    int num = numerator * f.denominator;
    int denom = denominator * f.numerator;
    return Fraction(num, denom);
}
void Fraction::printFraction() {
    if (numerator == 0) {
        cout << "0" << endl;
    }
    else if (denominator == 1) {
        cout << numerator << endl;
    }
    else {
        cout << numerator << "/" << denominator << endl;
    }
}

