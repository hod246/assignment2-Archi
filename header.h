//
// Created by hod on 11/04/18.
//

#ifndef ASSIGNMENT2_ARCHIT_HEADER_H
#define ASSIGNMENT2_ARCHIT_HEADER_H

#include <stdbool.h>

typedef struct {
    long double real;
    long double imagine;
} complexNumber; // 16 byte = 0x10

typedef struct {
    int order;
    complexNumber* coeffs;
} polynom; // 4+6=12 but! compiler adds room for padding.. so: 0x10

typedef struct{
    long double epsilon;
    complexNumber initial;
} initData; // 16+8=24 byte = 0x18

extern void readInput(initData* init, polynom* pol);// reading input
long double getEpsilonValue(char *line);
int getOrderValue(char *line);
int getCoeffIndex(char *line);
complexNumber getNumber(char *line);

extern complexNumber calcF(polynom* pol, complexNumber z);

polynom* getDeriv(polynom* pol);

extern complexNumber getNextZ(complexNumber z, polynom* pol_f, polynom* pol_f_deriv);

extern long double squareAbs(complexNumber z);//?? not neccesery ??

//arithmetic operations
extern complexNumber power(complexNumber z, int power);
extern complexNumber divide(complexNumber dividend, complexNumber divisor);// (Dividend/Divisor) = quotient.remainder hod
extern complexNumber mult(complexNumber first, complexNumber second);
extern complexNumber sum(complexNumber first, complexNumber second);
extern complexNumber subtract(complexNumber first, complexNumber second);

// for debugging
void printNumber(complexNumber z);
void printPolynom(polynom* pol);
int getCoeffPower();
void arithmaticTests();


#endif //ASSIGNMENT2_ARCHIT_HEADER_H
