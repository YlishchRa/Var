#include "var.h"

// Constructors
var::var() : typeVar{-1}, Int{-1}, Double{-1}, myString{} {}
var::var(int _Int) : typeVar{0}, Int{_Int}, Double{-1} {}
var::var(double _Double) : typeVar{1}, Double{_Double}, Int{-1} {}
var::var(const char* str) : myString{str}, typeVar{2}, Double{-1}, Int{-1} {}
var::var(const MyString& str)
{
    myString = str;
    typeVar = 2;
}
var::var(const var& value)
{
    Int = value.Int;
    Double = value.Double;
    typeVar = value.typeVar;
    myString = value.myString;
}
// Methods
ostream& operator<<(ostream& output, var& value)
{

    if (value.typeVar == 0)
        output << value.Int;
    else if (value.typeVar == 1)
        output << value.Double;
    else if (value.typeVar == 2)
        output << value.myString;
    else
        output << "Error: output var.h";
    return output;
}
// Opeator=
var& var::operator=(var value)
{
    Int = value.Int;
    Double = value.Double;
    typeVar = value.typeVar;
    myString = value.myString;

    return *this;
}
var& var::operator=(const MyString& value)
{

    typeVar = 2;
    myString = value;

    return *this;
}
var& var::operator=(int value)
{

    typeVar = 0;
    Int = value;

    return *this;
}
var& var::operator=(double value)
{

    typeVar = 1;
    Double = value;

    return *this;
}
var& var::operator=(const char* value)
{
    typeVar = 2;
    myString = value;

    return *this;
}
// Operator+
var var::operator+(const var& valueR)
{
    if (typeVar == 0)
    {
        if (valueR.typeVar == typeVar)
        {
            return var(Int + valueR.Int);
        }
        else if (valueR.typeVar == 1)
        {
            return var(Int + valueR.Double);
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            return var(Int + tmp);
        }
    }
    else if (typeVar == 1)
    {
        if (valueR.typeVar == typeVar)
        {
            return var(Double + valueR.Double);
        }
        else if (valueR.typeVar == 0)
        {
            return var(Double + valueR.Int);
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            return var(Double + tmp);
        }
    }
    else if (typeVar == 2)
    {
        if (valueR.typeVar == 0)
        {
            return var(myString + valueR.Int);
        }
        else if (valueR.typeVar == 1)
        {
            return var(myString + valueR.Double);
        }
        else if (valueR.typeVar == 2)
        {
            MyString tempStr = valueR.myString;
            return var(myString + tempStr);
        }
    }
}
var var::operator+(const int value)
{
    if (typeVar == 0)
    {
        return var(Int + value);
    }
    else if (typeVar == 1)
    {
        return var(Double + value);
    }
    else if (typeVar == 2)
    {
        return var(myString + value);
    }
}
var var::operator+(const double value)
{
    if (typeVar == 0)
    {
        return var(Int + value);
    }
    else if (typeVar == 1)
    {
        return var(Double + value);
    }
    else if (typeVar == 2)
    {
        return var(myString + value);
    }
}
var operator+(const int value, const var& valueR)
{
    if (valueR.typeVar == 0)
    {
        return var(valueR.Int + value);
    }
    else if (valueR.typeVar == 1)
    {
        return var(valueR.Double + value);
    }
    else if (valueR.typeVar == 2)
    {
        MyString tpmStr = valueR.myString;
        return var(value + tpmStr);
    }
}
var operator+(const double value, const var& valueR)
{
    if (valueR.typeVar == 0)
    {
        return var(valueR.Int + value);
    }
    else if (valueR.typeVar == 1)
    {
        return var(valueR.Double + value);
    }
    else if (valueR.typeVar == 2)
    {
        MyString tpmStr = valueR.myString;
        return var(tpmStr + value);
    }
}
var operator+(const char* value, const var& valueR)
{

    MyString tmpChar = value;
    MyString tpmStr;
    if (valueR.myString.GetLine(valueR.myString) == nullptr)
    {
        tpmStr = " ";
    }
    else
    {
        tpmStr = valueR.myString;
    }
    if (valueR.typeVar == 0)
    {
        return var(tmpChar + valueR.Int);
    }
    else if (valueR.typeVar == 1)
    {
        return var(tmpChar + valueR.Double);
    }
    else if (valueR.typeVar == 2)
    {
        return var(tmpChar + tpmStr);
    }
}

// Operator -
var var::operator-(const var& valueR)
{
    if (typeVar == 0)
    {
        if (valueR.typeVar == typeVar)
        {
            return var(Int - valueR.Int);
        }
        else if (valueR.typeVar == 1)
        {
            return var(Int - valueR.Double);
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            return var(Int - tmp);
        }
    }
    else if (typeVar == 1)
    {
        if (valueR.typeVar == typeVar)
        {
            return var(Double - valueR.Double);
        }
        else if (valueR.typeVar == 0)
        {
            return var(Double - valueR.Int);
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            return var(Double - tmp);
        }
    }
    else if (typeVar == 2)
    {
        return var("NaN");
    }
}
var var::operator-(const int value)
{
    if (typeVar == 0)
    {
        return var(Int - value);
    }
    else if (typeVar == 1)
    {
        return var(Double - value);
    }
    else if (typeVar == 2)
    {
        return var("NaN");
    }
}
var var::operator-(const double value)
{
    if (typeVar == 0)
    {
        return var(Int - value);
    }
    else if (typeVar == 1)
    {
        return var(Double - value);
    }
    else if (typeVar == 2)
    {
        return var("NaN");
    }
}
var operator-(const int value, const var& valueR)
{
    if (valueR.typeVar == 0)
    {
        return var(value - valueR.Int);
    }
    else if (valueR.typeVar == 1)
    {
        return var(value - valueR.Double);
    }
    else if (valueR.typeVar == 2)
    {
        return var("NaN");
    }
}
var operator-(const double value, const var& valueR)
{
    if (valueR.typeVar == 0)
    {
        return var(value - valueR.Int);
    }
    else if (valueR.typeVar == 1)
    {
        return var(value - valueR.Double);
    }
    else if (valueR.typeVar == 2)
    {
        return var("NaN");
    }
}
var operator-(const char* value, const var& valueR) { return var("NaN"); }
// Operator *
var var::operator*(const var& valuerR)
{

    if (typeVar == 0)
    {
        if (valuerR.typeVar == typeVar)
        {
            return var(Int * valuerR.Int);
        }
        else if (valuerR.typeVar == 1)
        {
            return var(Int * valuerR.Double);
        }
        else if (valuerR.typeVar == 2)
        {
            stringstream temp;

            temp << valuerR.myString;
            double tmp;
            temp >> tmp;
            if (tmp != 0)
                return var(Int * tmp);
            else
                return var("NaN");
        }
    }
    else if (typeVar == 1)
    {
        if (valuerR.typeVar == 0)
        {
            return var(Double * valuerR.Int);
        }
        else if (valuerR.typeVar == 1)
        {
            return var(Double * valuerR.Double);
        }
        else if (valuerR.typeVar == 2)
        {
            stringstream temp;

            temp << valuerR.myString;
            double tmp;
            temp >> tmp;
            if (tmp != 0)
                return var(Double * tmp);
            else
                return var("NaN");
        }
    }
    else if (typeVar == 2)
    {
        if (valuerR.typeVar == 0)
        {
            return var("NaN");
        }
        else if (valuerR.typeVar == 1)
        {
            return var("NaN");
        }
        else if (valuerR.typeVar == 2)
        {
            MyString tempStr = valuerR.myString;
            return var(myString * tempStr);
        }
    }
}
var var::operator*(const int value)
{
    if (typeVar == 0)
    {
        return var(Int * value);
    }
    else if (typeVar == 1)
    {
        return var(Double * value);
    }
    else if (typeVar == 2)
    {
        return var("NaN");
    }
}
var var::operator*(const double value)
{
    if (typeVar == 0)
    {
        return var(Double * value);
    }
    else if (typeVar == 1)
    {
        return var(Double * value);
    }
    else if (typeVar == 2)
    {
        return var("NaN");
    }
}
var operator*(const int value, const var& valueR)
{
    if (valueR.typeVar == 0)
    {
        return var(value * valueR.Int);
    }
    else if (valueR.typeVar == 1)
    {
        return var(value * valueR.Double);
    }
    else if (valueR.typeVar == 2)
    {
        return var("NaN");
    }
}
var operator*(const double value, const var& valueR)
{
    if (valueR.typeVar == 0)
    {
        return var(value * valueR.Int);
    }
    else if (valueR.typeVar == 1)
    {
        return var(value * valueR.Double);
    }
    else if (valueR.typeVar == 2)
    {
        return var("NaN");
    }
}
var operator*(const char* value, const var& valueR)
{
    if (valueR.typeVar == 2)
    {
        MyString tmp = valueR.myString;
        return var(tmp * value);
    }
    return var("NaN");
}

// Operator /
var var::operator/(const var& valuerR)
{
    if (valuerR.Int == 0 || valuerR.Double == 0)
        return var("You can`t divide on ZERO");
    if (typeVar == 0)
    {
        if (valuerR.typeVar == typeVar)
        {
            double tempT = Int;
            double tempV = valuerR.Int;
            return var(tempT / tempV);
        }
        else if (valuerR.typeVar == 1)
        {
            double tempT = Int;
            double tempV = valuerR.Double;
            return var(tempT / tempV);
        }
        else if (valuerR.typeVar == 2)
        {
            stringstream temp;

            temp << valuerR.myString;
            double tmp;
            temp >> tmp;
            return var(Int / tmp);
        }
    }
    else if (typeVar == 1)
    {
        if (valuerR.typeVar == 0)
        {
            double tempT = Double;
            double tempV = valuerR.Int;
            return var(tempT / tempV);
        }
        else if (valuerR.typeVar == 1)
        {
            double tempT = Double;
            double tempV = valuerR.Double;
            return var(tempT / tempV);
        }
        else if (valuerR.typeVar == 2)
        {
            stringstream temp;

            temp << valuerR.myString;
            double tmp;
            temp >> tmp;
            return var(Double / tmp);
        }
    }
    else if (typeVar == 2)
    {
        if (valuerR.typeVar == 0)
        {
            return var("NaN");
        }
        else if (valuerR.typeVar == 1)
        {
            return var("NaN");
        }
        else if (valuerR.typeVar == 2)
        {
            MyString tempStr = valuerR.myString;
            return var(myString / tempStr);
        }
    }
}
var var::operator/(const int value)
{
    if (value == 0)
        return var("You can`t divide on ZERO");
    if (typeVar == 0)
    {
        return var(Int / value);
    }
    else if (typeVar == 1)
    {
        return var(Double / value);
    }
    else if (typeVar == 2)
    {
        return var("NaN");
    }
}
var var::operator/(const double value)
{
    if (value == 0)
        return var("You can`t divide on ZERO");
    if (typeVar == 0)
    {
        return var(Double / value);
    }
    else if (typeVar == 1)
    {
        return var(Double / value);
    }
    else if (typeVar == 2)
    {
        return var("NaN");
    }
}
var operator/(const double value, const var& valueR)
{
    if (valueR.typeVar == 0)
    {
        return var(value / valueR.Int);
    }
    else if (valueR.typeVar == 1)
    {
        return var(value / valueR.Double);
    }
    else if (valueR.typeVar == 2)
    {
        return var("NaN");
    }
}
var operator/(const char* value, const var& valueR)
{
    if (valueR.typeVar == 2)
    {
        MyString tmp = valueR.myString;
        return var(tmp / value);
    }
    return var("NaN");
}
var operator/(const int value, const var& valueR)
{
    if (valueR.typeVar == 0)
    {
        return var(value / valueR.Int);
    }
    else if (valueR.typeVar == 1)
    {
        return var(value / valueR.Double);
    }
    else if (valueR.typeVar == 2)
    {
        return var("NaN");
    }
}
// Operator +=
var var::operator+=(const var& valueR)
{
    if (typeVar == -1)
    {
        typeVar = 1;
        Double = 0;
        if (valueR.typeVar == 0)
        {
            Double += valueR.Int;
            return *this;
        }
        else if (valueR.typeVar == 1)
        {
            Double += valueR.Double;
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            Double += tmp;
            return *this;
        }
    }
    else if (typeVar == 0)
    {
        if (valueR.typeVar == typeVar)
        {
            Int += valueR.Int;
            return *this;
        }
        else if (valueR.typeVar == 1)
        {
            typeVar = 1;
            Double = Int;
            Double += valueR.Double;
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            Double = Int;
            Double += tmp;
            typeVar = 1;
            return *this;
        }
    }
    else if (typeVar == 1)
    {
        if (valueR.typeVar == 0)
        {
            Double += valueR.Int;
            return *this;
        }
        else if (valueR.typeVar == 1)
        {

            Double += valueR.Double;
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            Double += tmp;
            return *this;
        }
    }
    else if (typeVar == 2)
    {
        if (valueR.typeVar == 0)
        {
            typeVar = 2;
            MyString temp = myString + valueR.Int;
            myString = temp;
            return *this;
        }
        else if (valueR.typeVar == 1)
        {
            typeVar = 2;

            MyString temp = myString + valueR.Double;
            myString = temp;
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            typeVar = 2;
            MyString tempStr = valueR.myString;
            MyString tempSumStr = myString + tempStr;
            myString = tempSumStr;
            return *this;
        }
    }
}
var var::operator+=(const int value)
{
    if (typeVar == 0)
    {
        Int += value;
        return *this;
    }
    else if (typeVar == 1)
    {
        Double += value;
        return *this;
    }
    else if (typeVar == 2)
    {
        myString = myString + value;
        return *this;
    }
}
var var::operator+=(const double value)
{
    if (typeVar == 0)
    {
        Double = Int + value;
        typeVar = 1;

        return *this;
    }
    else if (typeVar == 1)
    {
        Double += value;
        return *this;
    }
    else if (typeVar == 2)
    {
        myString = myString + value;
        return *this;
    }
}
var var::operator+=(const char* str)
{

    if (typeVar == 0)
    {
        typeVar = 2;
        myString = str;
        myString = Int + myString;
        return *this;
    }
    else if (typeVar == 1)
    {

        typeVar = 2;
        myString = str;
        myString = Double + myString;
        return *this;
    }
    else if (typeVar == 2)
    {
        typeVar = 2;
        myString = myString + str;
        return *this;
    }
}
// Operator -=
var var::operator-=(const var& valueR)
{
    if (typeVar == -1)
    {
        typeVar = 1;
        Double = 0;
        if (valueR.typeVar == 0)
        {
            Double -= valueR.Int;
            return *this;
        }
        else if (valueR.typeVar == 1)
        {
            Double -= valueR.Double;
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            Double -= tmp;
            return *this;
        }
    }
    else if (typeVar == 0)
    {
        if (valueR.typeVar == typeVar)
        {
            Int -= valueR.Int;
            return *this;
        }
        else if (valueR.typeVar == 1)
        {
            typeVar = 1;
            Double = Int;
            Double -= valueR.Double;
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            Double = Int;
            Double -= tmp;
            typeVar = 1;
            return *this;
        }
    }
    else if (typeVar == 1)
    {
        if (valueR.typeVar == 1)
        {
            Double -= valueR.Double;
            return *this;
        }
        else if (valueR.typeVar == 0)
        {

            Double -= valueR.Int;
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            Double -= tmp;
            return *this;
        }
    }
    else if (typeVar == 2)
    {
        if (valueR.typeVar == 0)
        {
            typeVar = 2;
            MyString temp = myString - valueR.Int;
            myString = temp;
            return *this;
        }
        else if (valueR.typeVar == 1)
        {
            typeVar = 2;

            MyString temp = myString - valueR.Double;
            myString = temp;
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            typeVar = 2;
            MyString tempStr = valueR.myString;
            MyString tempSumStr = myString - tempStr;
            myString = tempSumStr;
            return *this;
        }
    }
}
var var::operator-=(const int value)
{
    if (typeVar == 0)
    {
        Int -= value;
        return *this;
    }
    else if (typeVar == 1)
    {
        Double -= value;
        return *this;
    }
    else if (typeVar == 2)
    {
        myString = myString - value;
        return *this;
    }
}
var var::operator-=(const double value)
{
    if (typeVar == 0)
    {
        Double = Int - value;
        typeVar = 1;

        return *this;
    }
    else if (typeVar == 1)
    {
        Double -= value;
        return *this;
    }
    else if (typeVar == 2)
    {
        myString = myString - value;
        return *this;
    }
}
var var::operator-=(const char* str)
{

    if (typeVar == 0)
    {
        typeVar = 2;
        myString = str;
        myString = myString - Int;
        return *this;
    }
    else if (typeVar == 1)
    {

        typeVar = 2;
        myString = str;
        myString = myString - Double;
        return *this;
    }
    else if (typeVar == 2)
    {
        typeVar = 2;
        myString = myString - str;
        return *this;
    }
}
// Operator /=
var var::operator/=(const var& valueR)
{
    if (valueR.Int == 0 || valueR.Double == 0)
    {
        return var("You can`t divide on ZEROs");
    }
    if (typeVar == -1)
    {
        typeVar = 1;
        Double = 0;
        if (valueR.typeVar == 0)
        {
            Double /= valueR.Int;
            return *this;
        }
        else if (valueR.typeVar == 1)
        {
            Double /= valueR.Double;
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            Double /= tmp;
            return *this;
        }
    }
    else if (typeVar == 0)
    {
        if (valueR.typeVar == typeVar)
        {
            Int /= valueR.Int;
            return *this;
        }
        else if (valueR.typeVar == 1)
        {
            typeVar = 1;
            Double = Int;
            Double /= valueR.Double;
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            Double = Int;
            Double /= tmp;
            typeVar = 1;
            return *this;
        }
    }
    else if (typeVar == 1)
    {
        if (valueR.typeVar == 0)
        {
            Double /= valueR.Int;
            return *this;
        }
        else if (valueR.typeVar == 1)
        {

            Double /= valueR.Double;
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            Double /= tmp;
            return *this;
        }
    }
    else if (typeVar == 2)
    {
        if (valueR.typeVar == 0)
        {
            typeVar = 2;
            myString = "NaN";
            return *this;
        }
        else if (valueR.typeVar == 1)
        {
            typeVar = 2;
            myString = "NaN";
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            typeVar = 2;
            MyString tempStr = valueR.myString;
            MyString tempSumStr = myString / tempStr;
            myString = tempSumStr;
            return *this;
        }
    }
}
var var::operator/=(const int value)
{
    if (value == 0)
    {
        return var("You can`t divide on ZERO");
    }
    if (typeVar == 0)
    {
        typeVar == 1;
        Double = Int;
        Double /= value;
        return *this;
    }
    else if (typeVar == 1)
    {
        Double /= value;
        return *this;
    }
    else if (typeVar == 2)
    {
        myString = myString / value;
        return *this;
    }
}
var var::operator/=(const double value)
{
    if (value == 0)
        return var("You can`t divide on ZERO");
    if (typeVar == 0)
    {
        Double = Int / value;
        typeVar = 1;

        return *this;
    }
    else if (typeVar == 1)
    {
        Double /= value;
        return *this;
    }
    else if (typeVar == 2)
    {
        myString = myString / value;
        return *this;
    }
}
var var::operator/=(const char* str)
{

    if (typeVar == 0)
    {
        typeVar = 2;
        myString = str;
        myString = myString / Int;
        return *this;
    }
    else if (typeVar == 1)
    {

        typeVar = 2;
        myString = str;
        myString = myString / Double;
        return *this;
    }
    else if (typeVar == 2)
    {
        typeVar = 2;
        myString = myString / str;
        return *this;
    }
}
// Operator *=
var var::operator*=(const var& valueR)
{

    if (typeVar == -1)
    {
        typeVar = 1;
        Double = 0;
        if (valueR.typeVar == 0)
        {
            Double *= valueR.Int;
            return *this;
        }
        else if (valueR.typeVar == 1)
        {
            Double *= valueR.Double;
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            Double *= tmp;
            if (tmp != 0)
                return *this;
            else
            {
                myString = "NaN";
                typeVar == 2;
                return *this;
            }
        }
    }
    else if (typeVar == 0)
    {
        if (valueR.typeVar == typeVar)
        {
            Int *= valueR.Int;
            return *this;
        }
        else if (valueR.typeVar == 1)
        {
            typeVar = 1;
            Double = Int;
            Double *= valueR.Double;
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            Double = Int;
            Double *= tmp;
            typeVar = 1;
            if (tmp != 0)
                return *this;
            else
            {
                myString = "NaN";
                typeVar = 2;
                return *this;
            }
        }
    }
    else if (typeVar == 1)
    {
        if (valueR.typeVar == 0)
        {
            Double *= valueR.Int;
            return *this;
        }
        else if (valueR.typeVar == 1)
        {

            Double *= valueR.Double;
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            stringstream temp;

            temp << valueR.myString;
            double tmp;
            temp >> tmp;
            Double *= tmp;
            if (tmp != 0)
                return *this;
            else
            {
                myString = "NaN";
                typeVar = 2;
                return *this;
            }
            return *this;
        }
    }
    else if (typeVar == 2)
    {
        if (valueR.typeVar == 0)
        {
            typeVar = 2;
            myString = "NaN";
            return *this;
        }
        else if (valueR.typeVar == 1)
        {
            typeVar = 2;
            myString = "NaN";
            return *this;
        }
        else if (valueR.typeVar == 2)
        {
            typeVar = 2;
            MyString tempStr = valueR.myString;
            MyString tempSumStr = myString * tempStr;
            myString = tempSumStr;
            return *this;
        }
    }
}
var var::operator*=(const int value)
{
    if (typeVar == 0)
    {
        typeVar == 1;
        Double = Int;
        Double *= value;
        return *this;
    }
    else if (typeVar == 1)
    {
        Double *= value;
        return *this;
    }
    else if (typeVar == 2)
    {
        myString = myString * value;
        return *this;
    }
}
var var::operator*=(const double value)
{
    if (typeVar == 0)
    {
        Double = Int * value;
        typeVar = 1;

        return *this;
    }
    else if (typeVar == 1)
    {
        Double *= value;
        return *this;
    }
    else if (typeVar == 2)
    {
        myString = myString * value;
        return *this;
    }
}
var var::operator*=(const char* str)
{

    if (typeVar == 0)
    {
        typeVar = 2;
        myString = str;
        myString = myString * Int;
        return *this;
    }
    else if (typeVar == 1)
    {

        typeVar = 2;
        myString = str;
        myString = myString * Double;
        return *this;
    }
    else if (typeVar == 2)
    {
        typeVar = 2;
        myString = myString * str;
        return *this;
    }
}
// Operator >
bool var::operator>(const var& value)
{

    if (typeVar == 0)
    {
        if (value.typeVar == 0)
        {
            return Int > value.Int;
        }
        else if (value.typeVar == 1)
        {
            return Int > value.Double;
        }
        else if (value.typeVar == 2)
        {
            return false;
        }
    }
    else if (typeVar == 1)
    {
        if (value.typeVar == 0)
        {
            return Double > value.Int;
        }
        else if (value.typeVar == 1)
        {
            return Double > value.Double;
        }
        else if (value.typeVar == 2)
        {
            return false;
        }
    }
    else if (typeVar == 2)
    {
        if (value.typeVar == 0)
        {
            return false;
        }
        else if (value.typeVar == 1)
        {
            return false;
        }
        else if (value.typeVar == 2)
        {
            return myString > value.myString;
        }
    }
}
bool var::operator>(const int value)
{

    if (typeVar == 0)
    {
        return Int > value;
    }
    else if (typeVar == 1)
    {
        return Double > value;
    }
    else if (typeVar == 2)
    {
        return false;
    }
}
bool var::operator>(const double value)
{

    if (typeVar == 0)
    {
        return Int > value;
    }
    else if (typeVar == 1)
    {
        return Double > value;
    }
    else if (typeVar == 2)
    {
        return false;
    }
}
bool var::operator>(const char* value)
{

    if (typeVar == 0)
    {
        return false;
    }
    else if (typeVar == 1)
    {
        return false;
    }
    else if (typeVar == 2)
    {
        return myString > value;
    }
}
// Operator <
bool var::operator<(const var& value)
{

    if (typeVar == 0)
    {
        if (value.typeVar == 0)
        {
            return Int < value.Int;
        }
        else if (value.typeVar == 1)
        {
            return Int < value.Double;
        }
        else if (value.typeVar == 2)
        {
            return false;
        }
    }
    else if (typeVar == 1)
    {
        if (value.typeVar == 0)
        {
            return Double < value.Int;
        }
        else if (value.typeVar == 1)
        {
            return Double < value.Double;
        }
        else if (value.typeVar == 2)
        {
            return false;
        }
    }
    else if (typeVar == 2)
    {
        if (value.typeVar == 0)
        {
            return false;
        }
        else if (value.typeVar == 1)
        {
            return false;
        }
        else if (value.typeVar == 2)
        {
            return myString < value.myString;
        }
    }
}
bool var::operator<(const int value)
{

    if (typeVar == 0)
    {
        return Int < value;
    }
    else if (typeVar == 1)
    {
        return Double < value;
    }
    else if (typeVar == 2)
    {
        return false;
    }
}
bool var::operator<(const double value)
{

    if (typeVar == 0)
    {
        return Int < value;
    }
    else if (typeVar == 1)
    {
        return Double < value;
    }
    else if (typeVar == 2)
    {
        return false;
    }
}
bool var::operator<(const char* value)
{

    if (typeVar == 0)
    {
        return false;
    }
    else if (typeVar == 1)
    {
        return false;
    }
    else if (typeVar == 2)
    {
        return myString < value;
    }
}
// Operator >=
bool var::operator>=(const var& value)
{

    if (typeVar == 0)
    {
        if (value.typeVar == 0)
        {
            return Int >= value.Int;
        }
        else if (value.typeVar == 1)
        {
            return Int >= value.Double;
        }
        else if (value.typeVar == 2)
        {
            return false;
        }
    }
    else if (typeVar == 1)
    {
        if (value.typeVar == 0)
        {
            return Double >= value.Int;
        }
        else if (value.typeVar == 1)
        {
            return Double >= value.Double;
        }
        else if (value.typeVar == 2)
        {
            return false;
        }
    }
    else if (typeVar == 2)
    {
        if (value.typeVar == 0)
        {
            return false;
        }
        else if (value.typeVar == 1)
        {
            return false;
        }
        else if (value.typeVar == 2)
        {
            return myString >= value.myString;
        }
    }
}
bool var::operator>=(const int value)
{

    if (typeVar == 0)
    {
        return Int >= value;
    }
    else if (typeVar == 1)
    {
        return Double >= value;
    }
    else if (typeVar == 2)
    {
        return false;
    }
}
bool var::operator>=(const double value)
{

    if (typeVar == 0)
    {
        return Int >= value;
    }
    else if (typeVar == 1)
    {
        return Double >= value;
    }
    else if (typeVar == 2)
    {
        return false;
    }
}
bool var::operator>=(const char* value)
{

    if (typeVar == 0)
    {
        return false;
    }
    else if (typeVar == 1)
    {
        return false;
    }
    else if (typeVar == 2)
    {
        return myString >= value;
    }
}
// Operator <=
bool var::operator<=(const var& value)
{

    if (typeVar == 0)
    {
        if (value.typeVar == 0)
        {
            return Int <= value.Int;
        }
        else if (value.typeVar == 1)
        {
            return Int <= value.Double;
        }
        else if (value.typeVar == 2)
        {
            return false;
        }
    }
    else if (typeVar == 1)
    {
        if (value.typeVar == 0)
        {
            return Double <= value.Int;
        }
        else if (value.typeVar == 1)
        {
            return Double <= value.Double;
        }
        else if (value.typeVar == 2)
        {
            return false;
        }
    }
    else if (typeVar == 2)
    {
        if (value.typeVar == 0)
        {
            return false;
        }
        else if (value.typeVar == 1)
        {
            return false;
        }
        else if (value.typeVar == 2)
        {
            return myString <= value.myString;
        }
    }
}
bool var::operator<=(const int value)
{

    if (typeVar == 0)
    {
        return Int <= value;
    }
    else if (typeVar == 1)
    {
        return Double <= value;
    }
    else if (typeVar == 2)
    {
        return false;
    }
}
bool var::operator<=(const double value)
{

    if (typeVar == 0)
    {
        return Int <= value;
    }
    else if (typeVar == 1)
    {
        return Double <= value;
    }
    else if (typeVar == 2)
    {
        return false;
    }
}
bool var::operator<=(const char* value)
{

    if (typeVar == 0)
    {
        return false;
    }
    else if (typeVar == 1)
    {
        return false;
    }
    else if (typeVar == 2)
    {
        return myString <= value;
    }
}
// Operator ==
bool var::operator==(const var& value)
{

    if (typeVar == 0)
    {
        if (value.typeVar == 0)
        {
            return Int == value.Int;
        }
        else if (value.typeVar == 1)
        {
            return Int == value.Double;
        }
        else if (value.typeVar == 2)
        {
            return false;
        }
    }
    else if (typeVar == 1)
    {
        if (value.typeVar == 0)
        {
            return Double == value.Int;
        }
        else if (value.typeVar == 1)
        {
            return Double == value.Double;
        }
        else if (value.typeVar == 2)
        {
            return false;
        }
    }
    else if (typeVar == 2)
    {
        if (value.typeVar == 0)
        {
            return false;
        }
        else if (value.typeVar == 1)
        {
            return false;
        }
        else if (value.typeVar == 2)
        {
            return myString == value.myString;
        }
    }
}
bool var::operator==(const int value)
{

    if (typeVar == 0)
    {
        return Int == value;
    }
    else if (typeVar == 1)
    {
        return Double == value;
    }
    else if (typeVar == 2)
    {
        return false;
    }
}
bool var::operator==(const double value)
{

    if (typeVar == 0)
    {
        return Int == value;
    }
    else if (typeVar == 1)
    {
        return Double == value;
    }
    else if (typeVar == 2)
    {
        return false;
    }
}
bool var::operator==(const char* value)
{

    if (typeVar == 0)
    {
        return false;
    }
    else if (typeVar == 1)
    {
        return false;
    }
    else if (typeVar == 2)
    {
        return myString == value;
    }
}
// Operator !=
bool var::operator!=(const var& value)
{

    if (typeVar == 0)
    {
        if (value.typeVar == 0)
        {
            return Int != value.Int;
        }
        else if (value.typeVar == 1)
        {
            return Int != value.Double;
        }
        else if (value.typeVar == 2)
        {
            return false;
        }
    }
    else if (typeVar == 1)
    {
        if (value.typeVar == 0)
        {
            return Double != value.Int;
        }
        else if (value.typeVar == 1)
        {
            return Double != value.Double;
        }
        else if (value.typeVar == 2)
        {
            return false;
        }
    }
    else if (typeVar == 2)
    {
        if (value.typeVar == 0)
        {
            return false;
        }
        else if (value.typeVar == 1)
        {
            return false;
        }
        else if (value.typeVar == 2)
        {
            return myString != value.myString;
        }
    }
}
bool var::operator!=(const int value)
{

    if (typeVar == 0)
    {
        return Int != value;
    }
    else if (typeVar == 1)
    {
        return Double != value;
    }
    else if (typeVar == 2)
    {
        return false;
    }
}
bool var::operator!=(const double value)
{

    if (typeVar == 0)
    {
        return Int != value;
    }
    else if (typeVar == 1)
    {
        return Double != value;
    }
    else if (typeVar == 2)
    {
        return false;
    }
}
bool var::operator!=(const char* value)
{

    if (typeVar == 0)
    {
        return false;
    }
    else if (typeVar == 1)
    {
        return false;
    }
    else if (typeVar == 2)
    {
        return myString != value;
    }
}
// AllOperators < > Friend
///////////////////////////////////
bool operator>(const int value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return varV.Int > value;
    }
    else if (varV.typeVar == 1)
    {
        return varV.Double > value;
    }
    else if (varV.typeVar == 2)
    {
        return false;
    }
}
bool operator>(const double value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return varV.Int > value;
    }
    else if (varV.typeVar == 1)
    {
        return varV.Double > value;
    }
    else if (varV.typeVar == 2)
    {
        return false;
    }
}
bool operator>(const char* value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return false;
    }
    else if (varV.typeVar == 1)
    {
        return false;
    }
    else if (varV.typeVar == 2)
    {
        MyString tmp = varV.myString;
        return value > tmp;
    }
}
///////////////////////////////////
bool operator<(const int value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return varV.Int < value;
    }
    else if (varV.typeVar == 1)
    {
        return varV.Double < value;
    }
    else if (varV.typeVar == 2)
    {
        return false;
    }
}
bool operator<(const double value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return varV.Int < value;
    }
    else if (varV.typeVar == 1)
    {
        return varV.Double < value;
    }
    else if (varV.typeVar == 2)
    {
        return false;
    }
}
bool operator<(const char* value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return false;
    }
    else if (varV.typeVar == 1)
    {
        return false;
    }
    else if (varV.typeVar == 2)
    {
        MyString tmp = varV.myString;
        return tmp < value;
    }
}
///////////////////////////////////
bool operator>=(const int value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return varV.Int >= value;
    }
    else if (varV.typeVar == 1)
    {
        return varV.Double >= value;
    }
    else if (varV.typeVar == 2)
    {
        return false;
    }
}
bool operator>=(const double value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return varV.Int >= value;
    }
    else if (varV.typeVar == 1)
    {
        return varV.Double >= value;
    }
    else if (varV.typeVar == 2)
    {
        return false;
    }
}
bool operator>=(const char* value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return false;
    }
    else if (varV.typeVar == 1)
    {
        return false;
    }
    else if (varV.typeVar == 2)
    {
        MyString tmp = varV.myString;
        return tmp >= value;
    }
}
///////////////////////////////////
bool operator<=(const int value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return varV.Int <= value;
    }
    else if (varV.typeVar == 1)
    {
        return varV.Double <= value;
    }
    else if (varV.typeVar == 2)
    {
        return false;
    }
}
bool operator<=(const double value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return varV.Int <= value;
    }
    else if (varV.typeVar == 1)
    {
        return varV.Double <= value;
    }
    else if (varV.typeVar == 2)
    {
        return false;
    }
}
bool operator<=(const char* value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return false;
    }
    else if (varV.typeVar == 1)
    {
        return false;
    }
    else if (varV.typeVar == 2)
    {
        MyString tmp = varV.myString;
        return tmp <= value;
    }
}
///////////////////////////////////
bool operator==(const int value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return varV.Int == value;
    }
    else if (varV.typeVar == 1)
    {
        return varV.Double == value;
    }
    else if (varV.typeVar == 2)
    {
        return false;
    }
}
bool operator==(const double value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return varV.Int == value;
    }
    else if (varV.typeVar == 1)
    {
        return varV.Double == value;
    }
    else if (varV.typeVar == 2)
    {
        return false;
    }
}
bool operator==(const char* value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return false;
    }
    else if (varV.typeVar == 1)
    {
        return false;
    }
    else if (varV.typeVar == 2)
    {
        MyString tmp = varV.myString;
        return tmp == value;
    }
}
///////////////////////////////////
bool operator!=(const int value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return varV.Int != value;
    }
    else if (varV.typeVar == 1)
    {
        return varV.Double != value;
    }
    else if (varV.typeVar == 2)
    {
        return false;
    }
}
bool operator!=(const double value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return varV.Int != value;
    }
    else if (varV.typeVar == 1)
    {
        return varV.Double != value;
    }
    else if (varV.typeVar == 2)
    {
        return false;
    }
}
bool operator!=(const char* value, const var& varV)
{

    if (varV.typeVar == 0)
    {
        return false;
    }
    else if (varV.typeVar == 1)
    {
        return false;
    }
    else if (varV.typeVar == 2)
    {
        MyString tmp = varV.myString;
        return tmp != value;
    }
}
///////////////////////////////////
//Provadina Typiv
    var::operator int()
    {
        if (typeVar == 0)
            return (int)Int;
        else if (typeVar == 1)
            return (int)Double;
        else if (typeVar == 2)
        {
            stringstream temp;
            temp << myString;
            double tmp;
            temp >> tmp;
            return int(tmp);
        }
    }
    var::operator double()
    {
        if (typeVar == 0)
            return (double)Int;
        else if (typeVar == 1)
            return (double)Double;
        else if (typeVar == 2)
        {
            stringstream temp;
            temp << myString;
            double tmp;
            temp >> tmp;
            return double(tmp);
        }
    }
    var::operator char*()
    {
        if (typeVar == 0)
        {
            return MyString::ConvertIntToChar(Int);
        }
        else if (typeVar == 1)
        {
            return MyString::ConvertIntToChar(Double);
        }
        else if (typeVar == 2)
        {
            
            return myString.GetLine(myString);
        }
    }