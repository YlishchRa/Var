#include "MyString.h"

MyString::MyString() : line{nullptr}, size{0} {}
MyString::MyString(const char* value)
{
    size = strlen(value) + 1;
    line = new char[size];
    strcpy_s(line, size, value);
}
MyString::MyString(const MyString& value)
{
    size = value.size;
    delete[] line;
    line = new char[size];
    strcpy_s(line, size, value.line);
}
MyString& MyString::operator=(const MyString& myString)
{
    if (myString.line != nullptr)
    {
        if (this == &myString)
        {
            return *this;
        }
        size = myString.size;
        delete[] line;
        line = new char[size];
        strcpy_s(line, size, myString.line);
    }

    return *this;
}
char* MyString::GetLine(const MyString& value) { return value.line; }
char* MyString::ConvertIntToChar(long n)
{
    int lengthN = 0;
    int counterN = n;
    while (counterN != 0)
    {
        counterN /= 10;
        lengthN++;
    }
    char* ptr = new char[lengthN + 1];
    ptr[lengthN] = '\0';
    lengthN--;
    int k;
    while (n != 0)
    {
        k = n % 10;
        ptr[lengthN] = static_cast<char>(k + '0');
        n /= 10;
        lengthN--;
    }
    return ptr;
}
MyString MyString::operator-(MyString& valueR) { return MyString("NaN"); }
MyString MyString::operator-(const int valueR) { return MyString("NaN"); }
MyString MyString::operator-(const char* valueR) { return MyString("NaN"); }
MyString MyString::operator-(const double valueR) { return MyString("NaN"); }
MyString MyString::operator*(const int valueR) { return MyString("NaN"); }
MyString MyString::operator*(const double valueR) { return MyString("NaN"); }
MyString MyString::operator*(MyString& valueR) { return MyString("NaN"); }
MyString MyString::operator*(const char* valueR) { return MyString("NaN"); }
MyString MyString::operator/(MyString& valueR) { return MyString("NaN"); }
MyString MyString::operator/(const char* valueR) { return MyString("NaN"); }
MyString MyString::operator/(const int valueR) { return MyString("NaN"); }
MyString MyString::operator/(const double valueR) { return MyString("NaN"); }
bool MyString::operator>(const MyString& value)
{
    int sizeLeft = 0;
    int sizeRight = 0;

    int tmpSize = size > value.size ? value.size : size;

    for (size_t i = 0; i < tmpSize; i++)
    {
        if (line[i] > value.line[i])
        {
            sizeLeft++;
        }
        else if (line[i] < value.line[i])
        {
            sizeRight++;
        }
    }

    return sizeLeft > sizeRight;
}
bool MyString::operator>(const char* value)
{
    int sizeLeft = 0;
    int sizeRight = 0;

    int tmpSize = size > strlen(value) ? strlen(value) : size;

    for (size_t i = 0; i < tmpSize; i++)
    {
        if (line[i] > value[i])
        {
            sizeLeft++;
        }
        else if (line[i] < value[i])
        {
            sizeRight++;
        }
    }

    return sizeLeft > sizeRight;
}
bool MyString::operator<(const MyString& value)
{
    int sizeLeft = 0;
    int sizeRight = 0;

    int tmpSize = size > value.size ? value.size : size;

    for (size_t i = 0; i < tmpSize; i++)
    {
        if (line[i] > value.line[i])
        {
            sizeLeft++;
        }
        else if (line[i] < value.line[i])
        {
            sizeRight++;
        }
    }

    return sizeLeft < sizeRight;
}
bool MyString::operator>=(const MyString& value)
{
    int sizeLeft = 0;
    int sizeRight = 0;

    int tmpSize = size > value.size ? value.size : size;

    for (size_t i = 0; i < tmpSize; i++)
    {
        if (line[i] > value.line[i])
        {
            sizeLeft++;
        }
        else if (line[i] < value.line[i])
        {
            sizeRight++;
        }
    }

    return sizeLeft >= sizeRight;
}
bool MyString::operator<=(const MyString& value)
{
    int sizeLeft = 0;
    int sizeRight = 0;

    int tmpSize = size > value.size ? value.size : size;

    for (size_t i = 0; i < tmpSize; i++)
    {
        if (line[i] > value.line[i])
        {
            sizeLeft++;
        }
        else if (line[i] < value.line[i])
        {
            sizeRight++;
        }
    }

    return sizeLeft <= sizeRight;
}
bool MyString::operator==(const MyString& value)
{
    int leftSize = size;
    int rightSize = value.size;
    if (leftSize != rightSize)
        return false;

    for (size_t i = 0; i < size; i++)
    {
        if (value.line[i] != line[i])
            return false;
    }
    return true;
}
bool MyString::operator!=(const MyString& value)
{
    int leftSize = size;
    int rightSize = value.size;
    if (leftSize != rightSize)
        return true;

    for (size_t i = 0; i < size; i++)
    {
        if (value.line[i] != line[i])
            return true;
    }
    return false;
}
ostream& operator<<(ostream& output, const MyString& mString)
{
    output << mString.line;
    return output;
}
char* operator+(MyString& mStr, const char* value)
{

    int lengthValue = strlen(value) + 1; // Bery dowjiny radka
    char* temp = new char[mStr.size + lengthValue];

    for (int i = 0; i < mStr.size; i++)
    {
        temp[i] = mStr.line[i];
        // prisvoiv pershiy polovini  temp prisvoiv mStr.line
    }
    int j = 0;
    for (int i = mStr.size - 1; i < lengthValue + mStr.size + 1; i++)
    {
        temp[i] = value[j]; // prisvoiv drygii polovini temp value
        j++;
    }

    return temp;
}
char* operator+(const char* value, MyString& mStr)
{

    int lengthValue = strlen(value); // Bery dowjiny radka
    char* temp = new char[mStr.size + lengthValue];

    for (int i = 0; i < lengthValue; i++)
    {
        temp[i] = value[i];
        // prisvoiv pershiy polovini  temp prisvoiv mStr.line
    }
    int j = 0;
    for (int i = lengthValue; i < lengthValue + mStr.size + 1; i++)
    {
        // prisvoiv drygii polovini temp value
        temp[i] = mStr.line[j];
        j++;
    }

    return temp;
}
char* operator+(MyString& mStr, MyString& mstrR)
{

    int lengthValue = strlen(mstrR.line) + 1; // Bery dowjiny radka
    char* temp = new char[mStr.size + lengthValue];

    for (int i = 0; i < mStr.size; i++)
    {
        temp[i] = mStr.line[i];
        // prisvoiv pershiy polovini  temp prisvoiv mStr.line
    }
    int j = 0;
    for (int i = mStr.size - 1; i < lengthValue + mStr.size + 1; i++)
    {
        temp[i] = mstrR.line[j]; // prisvoiv drygii polovini temp value
        j++;
    }

    return temp;
}
MyString operator+(MyString& mStr, const int value)
{
    return MyString(mStr + MyString::ConvertIntToChar(value));
}
MyString operator+(const int value, MyString& mStr)
{
    return MyString(MyString::ConvertIntToChar(value) + mStr);
}
MyString operator+(const double value, MyString& mStr)
{
    return MyString(MyString::ConvertIntToChar(value) + mStr);
}
bool operator<(const char* value, const MyString& str)
{
    int sizeLeft = 0;
    int sizeRight = 0;

    int tmpSize = str.size > strlen(value) ? strlen(value) : str.size;

    for (size_t i = 0; i < tmpSize; i++)
    {
        if (str.line[i] > value[i])
        {
            sizeRight++;
        }
        else if (str.line[i] < value[i])
        {
            sizeLeft++;
        }
    }

    return sizeLeft < sizeRight;
}
bool operator>(const char* value, const MyString& str)
{
    int sizeLeft = 0;
    int sizeRight = 0;

    int tmpSize = str.size > strlen(value) ? strlen(value) : str.size;

    for (size_t i = 0; i < tmpSize; i++)
    {
        if (str.line[i] > value[i])
        {
            sizeRight++;
        }
        else if (str.line[i] < value[i])
        {
            sizeLeft++;
        }
    }

    return sizeLeft > sizeRight;
}
bool operator>=(const char* value, const MyString& str)
{
    int sizeLeft = 0;
    int sizeRight = 0;

    int tmpSize = str.size > strlen(value) ? strlen(value) : str.size;

    for (size_t i = 0; i < tmpSize; i++)
    {
        if (str.line[i] > value[i])
        {
            sizeRight++;
        }
        else if (str.line[i] < value[i])
        {
            sizeLeft++;
        }
    }

    return sizeLeft >= sizeRight;
}
bool operator<=(const char* value, const MyString& str)
{
    int sizeLeft = 0;
    int sizeRight = 0;

    int tmpSize = str.size > strlen(value) ? strlen(value) : str.size;

    for (size_t i = 0; i < tmpSize; i++)
    {
        if (str.line[i] > value[i])
        {
            sizeRight++;
        }
        else if (str.line[i] < value[i])
        {
            sizeLeft++;
        }
    }

    return sizeLeft < sizeRight;
}
bool operator!=(const char* value, const MyString& str)
{
    int leftSize = strlen(str.line);
    int rightSize = strlen(value) + 1;
    if (leftSize != rightSize)
        return true;

    for (size_t i = 0; i < str.size; i++)
    {
        if (str.line[i] != value[i])
            return true;
    }
    return false;
}
bool operator==(const char* value, const MyString& str)
{
    int leftSize = strlen(str.line);
    int rightSize = strlen(value) + 1;
    if (leftSize != rightSize)
        return false;

    for (size_t i = 0; i < str.size; i++)
    {
        if (str.line[i] != value[i])
            return false;
    }
    return true;
}
