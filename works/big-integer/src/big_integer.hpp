#ifndef BIG_INTEGER_HPP
#define BIG_INTEGER_HPP

#include <vector>
#include <string>

class BigInteger {
    std::vector<int> num;
public:
    BigInteger(int& val);
    BigInteger(std::string& str);

    BigInteger operator+(BigInteger& val);
    BigInteger operator-(BigInteger& val);
    BigInteger operator*(BigInteger& val);
    BigInteger operator/(BigInteger& val);
    BigInteger operator%(BigInteger& val);

    bool operator <(BigInteger& val);
    bool operator >(BigInteger& val);
    bool operator ==(BigInteger& val);
    BigInteger operator+();
    BigInteger operator-();

    BigInteger operator+=(BigInteger& val);
    BigInteger operator-=(BigInteger& val);
    BigInteger operator*=(BigInteger& val);
    BigInteger operator/=(BigInteger& val);
    BigInteger operator%=(BigInteger& val);

    bool operator <=(BigInteger& val);
    bool operator >=(BigInteger& val);

    int operator+(int& val);
    int operator-(int& val);
    int operator*(int& val);
    int operator/(int& val);
    int operator%(int& val);

    bool operator <(int& val);
    bool operator >(int& val);
    bool operator ==(int& val);

    int operator+=(int& val);
    int operator-=(int& val);
    int operator*=(int& val);
    int operator/=(int& val);
    int operator%=(int& val);

    bool operator <=(int& val);
    bool operator >=(int& val);

    void ToString();

    friend std::ostream operator<<(std::ostream& out, const BigInteger& val);//??????????friend???
    friend std::istream& operator>>(std::istream& in, const BigInteger& val);
    //Rule of Five
};

#endif