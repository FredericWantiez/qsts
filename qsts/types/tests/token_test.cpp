#include "types/token.hpp"

#include "gtest/gtest.h"

using namespace qsts;

TEST(token, basic) {
    exp::token t1 = "this_is_a_variable";
    std::string e1 = "this_is_a_variable";
    ASSERT_EQ(t1.as_string(), e1);
    ASSERT_EQ(t1.type(), exp::token::token_type::variable);
    ASSERT_NE(t1.type(), exp::token::token_type::constant);
    ASSERT_NE(t1.type(), exp::token::token_type::binary_operation);

    exp::token t2 = "+";
    ASSERT_NE(t2.type(), exp::token::token_type::variable);
    ASSERT_NE(t2.type(), exp::token::token_type::constant);
    ASSERT_EQ(t2.type(), exp::token::token_type::binary_operation);

    std::string s = "10.0 + e-f * 123.9";
    auto tks  = exp::tokenise(s);
    ASSERT_EQ(tks.size(), 7);
}

