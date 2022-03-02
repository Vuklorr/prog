#include "big_integer.hpp"

BigInteger::BigInteger(int& val) {

}

BigInteger::BigInteger(std::string &str) {
    for(int i = 0; i < str.size(); ++i) {
        num.emplace_back(str[i] - '0');
    }
}




