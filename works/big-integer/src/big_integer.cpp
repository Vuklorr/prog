#include "big_integer.hpp"

/*BigInteger BigInteger::toInt(std::string& str) {//добавил для >>
    for(int i = str.size() - 1; i >= 0; i--) {
        num.emplace_back(str[i] - '0');
    }
    return *this;
}*/

BigInteger::BigInteger(const int &val) {
    int temp = val;

    while(temp != 0) {
        num.emplace_back(temp % 10);
        temp /= 10;
    }
}

BigInteger::BigInteger(const std::string_view &str) {
    for(int i = str.size() - 1; i >= 0; i--) {
        num.emplace_back(str[i] - '0');
    }
}

BigInteger BigInteger::operator+(const BigInteger &val) const {
    BigInteger sum;
    int size = std::max(num.size(),val.num.size());
    int carry = 0;
    int temp = 0;

    for(int i = 0; i < size; ++i) {
        temp = num[i] + val.num[i] + carry;
        carry = temp / 10;
        sum.num.emplace_back(temp % 10);
    }
    return sum;
}

BigInteger BigInteger::operator-(const BigInteger &val) const {
    BigInteger diff; //работает, если a > val
    int carry = 0;

    if(*this == val) {
        return 0;
    }

    if(*this > val) {
        for(int i = 0; i < num.size(); ++i) {
            int temp = num[i] - carry;

            if(temp < val.num[i]) {
                temp += 10 - val.num[i];
                carry = 1;
            } else {
                carry = 0;
            }

            diff.num.emplace_back(temp);
        }
        return diff;
    } else {
        for(int i = 0; i < val.num.size(); ++i) {
            int temp = val.num[i] - carry;

            if(temp < num[i]) {
                temp += 10 - num[i];
                carry = 1;
            } else {
                carry = 0;
            }

            diff.num.emplace_back(temp);
        }
        return -diff;
    }
}

BigInteger BigInteger::operator*(const BigInteger& val) const {

}

BigInteger BigInteger::operator/(const BigInteger& val) const {

}

BigInteger BigInteger::operator%(const BigInteger& val) const {

}

BigInteger& BigInteger::operator+=(const BigInteger& val) {
    *this = *this + val;
    return *this;
}

BigInteger& BigInteger::operator-=(const BigInteger& val) {
    *this = *this - val;
    return *this;
}

BigInteger& BigInteger::operator*=(const BigInteger& val) {

}

BigInteger& BigInteger::operator/=(const BigInteger& val) {

}

BigInteger& BigInteger::operator%=(const BigInteger& val) {

}

BigInteger BigInteger::operator+(const int &val) const {
   BigInteger secondNum(val);

   return *this + secondNum;
}

BigInteger BigInteger::operator-(const int &val) const {
    BigInteger secondNum(val);
    return *this - secondNum;
}

BigInteger BigInteger::operator*(const int &val) const {

}

BigInteger BigInteger::operator/(const int &val) const {

}

int BigInteger::operator%(const int &val) const {

}

BigInteger& BigInteger::operator+=(const int& val) {
    *this = *this + val;
    return *this;
}

BigInteger& BigInteger::operator-=(const int& val) {
    *this = *this - val;
    return *this;
}

BigInteger& BigInteger::operator*=(const int& val) {

}

BigInteger& BigInteger::operator/=(const int& val) {

}

int& BigInteger::operator%=(const int& val) {

}

bool BigInteger::operator <(const BigInteger& val) const {
    if(num.size() < val.num.size()) {
        return true;
    } else if(num.size() > val.num.size()) {
        return false;
    } else {
        for(int i = num.size() - 1; i >= 0; i--) {
            if(num[i] < val.num[i]) {
                return true;
            } else if(num[i] > val.num[i]) {
                return false;
            }
        }
        return false;
    }
}

bool BigInteger::operator >(const BigInteger& val) const {
    if(num.size() > val.num.size()) {
        return true;
    } else if(num.size() < val.num.size()) {
        return false;
    } else {
        for(int i = num.size() - 1; i >= 0; i--) {
            if(num[i] > val.num[i]) {
                return true;
            } else if(num[i] < val.num[i]) {
                return false;
            }
        }
        return false;
    }
}

bool BigInteger::operator ==(const BigInteger& val) const {
    if((*this > val) || (*this < val)) {
        return false;
    }
    return true;

}

bool BigInteger::operator <=(const BigInteger& val) const {
    if ((*this < val) || (*this == val)) {
        return true;
    }
    return false;

}

bool BigInteger::operator >=(const BigInteger& val) const {
    if ((*this > val) || (*this == val)) {
        return true;
    }
    return false;
}

bool BigInteger::operator <(const int& val) const {
    BigInteger temp(val);
    return *this < temp;
}

bool BigInteger::operator >(const int& val) const {
    BigInteger temp(val);
    return *this > temp;
}

bool BigInteger::operator ==(const int& val) const {
    BigInteger temp(val);
    return *this == temp;
}

bool BigInteger::operator <=(const int& val) const {
    BigInteger temp(val);
    return *this <= temp;
}

bool BigInteger::operator >=(const int& val) const {
    BigInteger temp(val);
    return *this >= temp;
}

BigInteger BigInteger::operator+() const {
    return *this;
}

BigInteger BigInteger::operator-() const {//не уверен, очень сильно не уверен
    return -*this;
}

std::string BigInteger::ToString() const {
    std::string str;

    for(int i = num.size() - 1; i >= 0; i--) {
        str += num[i] - '0';
    }
    return str;
}

 std::ostream& operator<<(std::ostream& out, const BigInteger& val) {
    for(int i = val.num.size() - 1; i >= 0; --i) {
        out << val.num[i];
    }
    return out;
}

std::istream& operator>>(std::istream& in, BigInteger& val) {
    std::string str;
    in >> str;

    val = BigInteger(str);

    return in;
}

