#pragma once

#include <vector>
#include <ostream>
#include <iostream>
#include <string>
#include <istream>

class BigInteger {
private:
    std::vector<int> num;
    std::string str;//для >>
public:
    BigInteger(const int& val);
    BigInteger(const std::string& str);

    BigInteger operator+(const BigInteger& val) const;
    BigInteger operator-(const BigInteger& val) const;
    BigInteger operator*(const BigInteger& val) const;
    BigInteger operator/(const BigInteger& val) const;
    BigInteger operator%(const BigInteger& val) const;

    bool operator <(const BigInteger& val) const;
    bool operator >(const BigInteger& val) const;
    bool operator ==(const BigInteger& val) const;

    BigInteger operator+() const;
    BigInteger operator-() const;

    BigInteger operator+=(const BigInteger& val) const;
    BigInteger operator-=(const BigInteger& val) const;
    BigInteger operator*=(const BigInteger& val) const;
    BigInteger operator/=(const BigInteger& val) const;
    BigInteger operator%=(const BigInteger& val) const;

    bool operator <=(const BigInteger& val) const;
    bool operator >=(const BigInteger& val) const;

    int operator+(const int& val) const;
    int operator-(const int& val) const;
    int operator*(const int& val) const;
    int operator/(const int& val) const;
    int operator%(const int& val) const;

    int operator+=(const int& val) const;
    int operator-=(const int& val) const;
    int operator*=(const int& val) const;
    int operator/=(const int& val) const;
    int operator%=(const int& val) const;

    bool operator <(const int& val) const;
    bool operator >(const int& val) const;
    bool operator ==(const int& val) const;

    bool operator <=(const int& val) const;
    bool operator >=(const int& val) const;

    std::string ToString();

    BigInteger toInt(BigInteger& val) {//добавил для >>
        for(int i = val.str.size() - 1; i >= 0; i--) {
            val.num.emplace_back(val.str[i] - '0');
        }
        return val;
    }
    friend std::ostream& operator<<(std::ostream& out, const BigInteger& val);
    friend std::istream& operator>>(std::istream& in, BigInteger& val);
    //Rule of Five
};

std::ostream& operator<<(std::ostream& out, const BigInteger& val) {
    for(int i = val.num.size() - 1; i >= 0; --i) {
        out << val.num[i];
    }
    return out;
}

std::istream& operator>>(std::istream& in, BigInteger& val) {//криво - косо, с костылями, но работает
    in >> val.str;

    val.toInt(val);

    return in;
}
