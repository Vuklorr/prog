#pragma once

#include <vector>
#include <ostream>
#include <iostream>
#include <string_view>
#include <istream>
#include <string>

class BigInteger {
private:
    std::vector<int> num;

public:
    BigInteger();
    BigInteger(const int& val);
    BigInteger(const std::string_view& str);
    BigInteger(const BigInteger& object);
    BigInteger(BigInteger&& object);

    BigInteger operator+(const BigInteger& val) const;
    BigInteger operator-(const BigInteger& val) const;
    BigInteger operator*(const BigInteger& val) const;
    BigInteger operator/(const BigInteger& val) const;
    BigInteger operator%(const BigInteger& val) const;

    BigInteger& operator+=(const BigInteger& val);
    BigInteger& operator-=(const BigInteger& val);
    BigInteger& operator*=(const BigInteger& val);
    BigInteger& operator/=(const BigInteger& val);
    BigInteger& operator%=(const BigInteger& val);

    BigInteger operator+(const int& val) const;
    BigInteger operator-(const int& val) const;
    BigInteger operator*(const int& val) const;
    BigInteger operator/(const int& val) const;
    int operator%(const int& val) const;

    BigInteger& operator+=(const int& val);
    BigInteger& operator-=(const int& val);
    BigInteger& operator*=(const int& val);
    BigInteger& operator/=(const int& val);
    int& operator%=(const int& val);

    bool operator <(const BigInteger& val) const;
    bool operator >(const BigInteger& val) const;
    bool operator ==(const BigInteger& val) const;

    bool operator <=(const BigInteger& val) const;
    bool operator >=(const BigInteger& val) const;

    bool operator <(const int& val) const;
    bool operator >(const int& val) const;
    bool operator ==(const int& val) const;

    bool operator <=(const int& val) const;
    bool operator >=(const int& val) const;

    BigInteger operator+() const;
    BigInteger operator-() const;

    BigInteger& operator=(const BigInteger& object);
    BigInteger& operator=(BigInteger&& object);

    std::string ToString() const;

    friend std::ostream& operator<<(std::ostream& out, const BigInteger& val);
    friend std::istream& operator>>(std::istream& in, BigInteger& val);

    ~BigInteger();

};

std::ostream& operator<<(std::ostream& out, const BigInteger& val);

std::istream& operator>>(std::istream& in, BigInteger& val);