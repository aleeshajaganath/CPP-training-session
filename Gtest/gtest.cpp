
/*########################################
      pgm to demonstrate gtest working
########################################*/

#include<gtest/gtest.h>
#include<iostream>
using namespace std;


int factorial(int n) {
  if(n > 1)
    return n * factorial(n - 1);
  else
    return 1;
}

TEST(FactorialTest1, FactorialOfZeroShouldBeOne){
    // Tests use assertions to verify the tested code’s behavior. 
    ASSERT_EQ(1, factorial(0));
}

TEST(FactorialTest, FactorialOfPositiveNos){
    /* A test program can contain multiple test suites.
     ASSERT_* versions generate fatal failures when they fail,
     and abort the current function
    */
    ASSERT_EQ(1, factorial(1));
    ASSERT_EQ(24, factorial(4));
    ASSERT_EQ(125, factorial(5));
    ASSERT_TRUE(121==factorial(5));
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}