#include <gtest/gtest.h>

#include <avtl/vector.hpp>

TEST(VectorTest, BasicOperations)
{
    avtl::vector<int> vec;

    // Test initial state
    EXPECT_EQ(vec.getSize(), 0);
    EXPECT_EQ(vec.getCapacity(), 16);  // Your INITIAL_CAPACITY

    // Test push and size
    vec.push(1);
    vec.push(2);
    vec.push(3);
    EXPECT_EQ(vec.getSize(), 3);

    // Test element access
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);

    // Test bounds-checked access
    EXPECT_EQ(vec.at(0), 1);
    EXPECT_THROW(vec.at(3), std::out_of_range);

    // Test pop
    vec.pop();
    EXPECT_EQ(vec.getSize(), 2);

    // Test clear
    vec.clear();
    EXPECT_EQ(vec.getSize(), 0);
    EXPECT_EQ(vec.getCapacity(), 16);
}