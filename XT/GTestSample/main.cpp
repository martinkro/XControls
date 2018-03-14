#include <iostream>
#include <cmath>

using namespace std;

#include "gtest/gtest.h"
double cubic(double d)
{
    return pow(d, 3);
}

TEST(testMath, myCubeTest)
{
    EXPECT_EQ(1000, cubic(10));
}

int main(int argc, char* argv[])
{
    cout << "Hello" << endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}