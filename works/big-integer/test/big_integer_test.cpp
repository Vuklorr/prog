#include <gtest/gtest.h>

TEST(BigInt, Constructor) {
    BigInteger zero;
    BigInteger another_zero(0);

    BigInteger thousand("1000");

    EXPECT_EQ(zero, another_zero);
    EXPECT_EQ(thousand, BigInteger(1000));

    std::string num = "123123123123123123123123";
    BigInteger very_big_integer(num);
    EXPECT_EQ(num, very_big_integer.ToString());
}
