#include "fraction.h"
using namespace std;

fraction::fraction(int numerator, int denominator) {
    //this->numerator = new int(numerator);
    //this->denominator = new int(denominator);
    this->numerator = numerator;
    this->denominator = denominator;
}

void fraction::add(fraction f) {
    int* newNumerator = new int((this->numerator*f.denominator)+(f.numerator*this->denominator));
    int* newDenominator = new int(this->denominator*f.denominator);
 
    //delete this->numerator;
    //delete this->denominator;

    this->numerator = *newNumerator;
    this->denominator = *newDenominator;
    
    int common_factor;
    for (int i = 1; i <= this->numerator && i <= this->denominator; i++) {
        if (this->numerator % i == 0 && this->denominator % i == 0) {
            common_factor = i;
        }
    }
    this->numerator /= common_factor;
    this->denominator /= common_factor;
    // simplification needed !!!!
}

void fraction::mult(fraction f) {
    int* newNumerator = new int(this->numerator*f.numerator);
    int* newDenominator = new int(this->denominator*f.denominator);
    //delete this->numerator;
    //delete this->denominator;

    this->numerator = *newNumerator;
    this->denominator = *newDenominator;
    
    int common_factor;
    for (int i = 1; i <= this->numerator && i <= this->denominator; i++) {
        if (this->numerator % i == 0 && this->denominator % i == 0) {
            common_factor = i;
        }
    }
    this->numerator /= common_factor;
    this->denominator /= common_factor;
}

void fraction::div(fraction f) {
    int* newNumerator = new int(this->numerator*f.denominator);
    int* newDenominator = new int(this->denominator*f.numerator);
    //delete this->numerator;
    //delete this->denominator;

    this->numerator = *newNumerator;
    this->denominator = *newDenominator;

    int common_factor;
    for (int i = 1; i <= this->numerator && i <= this->denominator; i++) {
        if (this->numerator % i == 0 && this->denominator % i == 0) {
            common_factor = i;
        }
    }
    this->numerator /= common_factor;
    this->denominator /= common_factor;
}

void fraction::display(void) {
    cout << this->numerator << " / " << this->denominator << endl;
}
