#include "my_lib.hpp"
#include "gtest/gtest.h"

TEST(my_lib, multiplication)
{
  EXPECT_EQ(multiplication(3, 4), 12);
}
