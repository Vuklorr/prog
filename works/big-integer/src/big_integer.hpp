#pragma once

#include <vector>
#include <string>

class BigInteger {
private:
    std::vector<int> num;
public:
    BigInteger(const int& val);
    BigInteger(const std::string& str);

    const BigInteger operator+(const BigInteger& val);
    const BigInteger operator-(const BigInteger& val);
    const BigInteger operator*(const BigInteger& val);
    const BigInteger operator/(const BigInteger& val);
    const BigInteger operator%(const BigInteger& val);

    const bool operator <(const BigInteger& val);
    const bool operator >(const BigInteger& val);
    const bool operator ==(const BigInteger& val);

    const BigInteger operator+();
    BigInteger operator-();

    const BigInteger operator+=(const BigInteger& val);
    const BigInteger operator-=(const BigInteger& val);
    const BigInteger operator*=(const BigInteger& val);
    const BigInteger operator/=(const BigInteger& val);
    const BigInteger operator%=(const BigInteger& val);

    const bool operator <=(const BigInteger& val);
    const bool operator >=(const BigInteger& val);

    const int operator+(const int& val);
    const int operator-(const int& val);
    const int operator*(const int& val);
    const int operator/(const int& val);
    const int operator%(const int& val);

    const int operator+=(const int& val);
    const int operator-=(const int& val);
    const int operator*=(const int& val);
    const int operator/=(const int& val);
    const int operator%=(const int& val);

    const bool operator <(const int& val);
    const bool operator >(const int& val);
    const bool operator ==(const int& val);

    const bool operator <=(const int& val);
    const bool operator >=(const int& val);

    std::string ToString();

    friend std::ostream operator<<(std::ostream& out, const BigInteger& val);
    friend std::istream& operator>>(std::istream& in, const BigInteger& val);
    //Rule of Five
};
