#include "types/postfix.hpp"

#include "gtest/gtest.h"

TEST(to_postfix, postfix) {
    std::string exp_str1("AB*CD/+");
    auto pf1 = qsts::exp::as_postfix("A*B+C/D");
    ASSERT_EQ(pf1.as_string(), exp_str1);
}

