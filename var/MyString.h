#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class MyString
{
    char* line;
    int size;

public:
    MyString();
    MyString(const char* value);
    MyString(const MyString& value);
    MyString& operator=(const MyString& myString);
    friend ::ostream& operator<<(ostream& output, const MyString& mString);
    static char* GetLine(const MyString& value);
    static char* ConvertIntToChar(long n);

#pragma region Operators + -* /

    friend char* operator+(MyString& mStr, const char* value);
    friend char* operator+(const char* value, MyString& mStr);
    friend char* operator+(MyString& mStr, MyString& mstrR);
    friend MyString operator+(MyString& mStr, const int value);
    friend MyString operator+(const int value, MyString& mStr);
    friend MyString operator+(const double value, MyString& mStr);

    MyString operator-(MyString& valueR);
    MyString operator-(const int valueR);
    MyString operator-(const char* valueR);
    MyString operator-(const double valueR);
    MyString operator*(const int valueR);
    MyString operator*(const double valueR);
    MyString operator*(MyString& valueR);
    MyString operator*(const char* valueR);
    MyString operator/(MyString& valueR);
    MyString operator/(const char* valueR);
    MyString operator/(const int valueR);
    MyString operator/(const double valueR);
#pragma endregion

#pragma region Operators < >
    bool operator>(const MyString& value);
    bool operator>(const char* value);
    bool operator<(const MyString& value);
    ///////////////////////////////////////////////////////////////////////////
    friend bool operator<(const char* value, const MyString& str);
    friend bool operator>(const char* value, const MyString& str);
    friend bool operator>=(const char* value, const MyString& str);
    friend bool operator<=(const char* value, const MyString& str);
    friend bool operator!=(const char* value, const MyString& str);
    friend bool operator==(const char* value, const MyString& str);
    ///////////////////////////////////////////////////////////////////////////
    bool operator>=(const MyString& value);
    bool operator<=(const MyString& value);
    bool operator==(const MyString& value);
    bool operator!=(const MyString& value);

#pragma endregion
};
