#pragma once
#include <iostream>
#include <sstream>
using namespace std;
#include "MyString.h"

class var
{
public:
    int typeVar;
    int Int;
    double Double;
    MyString myString;
public:
    var();
    var(int _Int);
    var(double _Double);
    var(const char* str);
    var(const MyString& str);
    var(const var& value);
    friend ostream& operator<<(ostream& output, var& value);
    
#pragma region Opertor=
    var& operator=(var value);
    var& operator=(const MyString& value);
    var& operator=(int value);
    var& operator=(double value);
    var& operator=(const char* value);
    
#pragma endregion
#pragma region Operator +
    var operator+(const var& valueR);
    var operator+(const int value);
    var operator+(const double value);
    friend var operator+(const int value, const var& valueR);
    friend var operator+(const double value, const var& valueR);
    friend var operator+(const char* value, const var& valueR);
#pragma endregion
#pragma region Operator -
    var operator-(const var& valueR);
    var operator-(const int value);
    var operator-(const double value);
    friend var operator-(const int value, const var& valueR);
    friend var operator-(const double value, const var& valueR);
    friend var operator-(const char* value, const var& valueR);
#pragma endregion
#pragma region Operator*
    var operator*(const var& valuerR);
    var operator*(const int value);
    var operator*(const double value);
    friend var operator*(const int value, const var& valueR);
    friend var operator*(const double value, const var& valueR);
    friend var operator*(const char* value, const var& valueR);
#pragma endregion
#pragma region Operator /
    var operator/(const var& valuerR);
    var operator/(const int value);
    var operator/(const double value);
    friend var operator/(const int value, const var& valueR);
    friend var operator/(const double value, const var& valueR);
    friend var operator/(const char* value, const var& valueR);
#pragma endregion
#pragma region Operator +=
    var operator+=(const var& valueR);
    var operator+=(const int value);
    var operator+=(const double value);
    var operator+=(const char* str);
#pragma endregion
#pragma region Operator -=
    var operator-=(const var& valueR);
    var operator-=(const int value);
    var operator-=(const double value);
    var operator-=(const char* str);
    
#pragma endregion
#pragma region Operator /=
    var operator/=(const var& valueR);
    var operator/=(const int value);
    var operator/=(const double value);
    var operator/=(const char* str);
#pragma endregion
#pragma region Operator *=
    var operator*=(const var& valueR);
    var operator*=(const int value);
    var operator*=(const double value);
    var operator*=(const char* str);
#pragma endregion
#pragma region Operator>
    bool operator>(const var& value);
    bool operator>(const int value);
    bool operator>(const double value);
    bool operator>(const char* value);
#pragma endregion
#pragma region Operator <
    bool operator<(const var& value);
    bool operator<(const int value);
    bool operator<(const double value);
    bool operator<(const char* value);

#pragma endregion
#pragma region Operator >=
    bool operator>=(const var& value);
    bool operator>=(const int value);
    bool operator>=(const double value);
    bool operator>=(const char* value);
#pragma endregion
#pragma region Operator <=
    bool operator<=(const var& value);
    bool operator<=(const int value);
    bool operator<=(const double value);
    bool operator<=(const char* value);
#pragma endregion
#pragma region Operator ==
    bool operator==(const var& value);
    bool operator==(const int value);
    bool operator==(const double value);
    bool operator==(const char* value);
#pragma endregion
#pragma region Operator !=
    bool operator!=(const var& value);
    bool operator!=(const int value);
    bool operator!=(const double value);
    bool operator!=(const char* value);
#pragma endregion
#pragma region AllOperators < > Friend
    ///////////////////////////////////
    friend bool operator>(const int value, const var& varV);
    friend bool operator>(const double value, const var& varV);
    friend bool operator>(const char* value, const var& varV);
    ///////////////////////////////////
    friend bool operator<(const int value, const var& varV);
    friend bool operator<(const double value, const var& varV);
    friend bool operator<(const char* value, const var& varV);
    ///////////////////////////////////
    friend bool operator>=(const int value, const var& varV);
    friend bool operator>=(const double value, const var& varV);
    friend bool operator>=(const char* value, const var& varV);
    ///////////////////////////////////
    friend bool operator<=(const int value, const var& varV);
    friend bool operator<=(const double value, const var& varV);
    friend bool operator<=(const char* value, const var& varV);
    ///////////////////////////////////
    friend bool operator==(const int value, const var& varV);
    friend bool operator==(const double value, const var& varV);
    friend bool operator==(const char* value, const var& varV);
    ///////////////////////////////////
    friend bool operator!=(const int value, const var& varV);
    friend bool operator!=(const double value, const var& varV);
    friend bool operator!=(const char* value, const var& varV);
    ///////////////////////////////////
#pragma endregion
#pragma region Provadina Typiv
    operator int();
    operator double();
    operator char*();
#pragma endregion
};
