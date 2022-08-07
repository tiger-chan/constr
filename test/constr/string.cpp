#include <gtest/gtest.h>
#include <constr/constr.hpp>

TEST(String, Construct) {
	constr::string str{"Hello World"};
	ASSERT_STREQ(str.c_str(), "Hello World");
}