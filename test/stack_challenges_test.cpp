/*
MIT License
Copyright (c) 2023 shadai-rafael
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "algoexpertcpp.hpp"

TEST(stack_callenges, Min_Max_Stack) {
    MinMaxStack minMaxStack;
    minMaxStack.push(5);
    EXPECT_EQ(5, minMaxStack.getMin());
    EXPECT_EQ(5, minMaxStack.getMax());
    EXPECT_EQ(5, minMaxStack.peek());
    minMaxStack.push(7);
    EXPECT_EQ(5, minMaxStack.getMin());
    EXPECT_EQ(7, minMaxStack.getMax());
    EXPECT_EQ(7, minMaxStack.peek());
    minMaxStack.push(2);
    EXPECT_EQ(2, minMaxStack.getMin());
    EXPECT_EQ(7, minMaxStack.getMax());
    EXPECT_EQ(2, minMaxStack.peek());
    EXPECT_EQ(2, minMaxStack.pop());
    EXPECT_EQ(7, minMaxStack.pop());
    EXPECT_EQ(5, minMaxStack.getMin());
    EXPECT_EQ(5, minMaxStack.getMax());
    EXPECT_EQ(5, minMaxStack.peek());
}

TEST(stack_callenges, Balanced_Brackets) {
    std::string str = "([])(){}(())()()";
    EXPECT_TRUE(balancedBrackets(str));
    std::string str1 = "([])(){}(())()(";
    std::string str2 = "(])(){}(())()()";
    std::string str3 = "])(){}";
    EXPECT_FALSE(balancedBrackets(str1));
    EXPECT_FALSE(balancedBrackets(str2));
    EXPECT_FALSE(balancedBrackets(str3));
}

TEST(stack_callenges, Sunset_View) {
    std::vector<int> buildings{3,5,4,4,3,1,3,2};
    std::vector<int> output1{1,3,6,7};
    std::vector<int> output2{0,1};
    EXPECT_THAT(output1, ::testing::ContainerEq(sunsetViews(buildings,"EAST")));
    EXPECT_THAT(output2, ::testing::ContainerEq(sunsetViews(buildings,"WEST")));
}

TEST(stack_callenges, Best_Digits) {
    ASSERT_EQ(bestDigits("462839", 2), "6839");
    ASSERT_EQ(bestDigits("321", 1), "32");
    ASSERT_EQ(bestDigits("10000000002",10),"2");
    ASSERT_EQ(bestDigits("1020304050",5), "34050");
    ASSERT_EQ(bestDigits("100300200004",4), "30200004");
}

TEST(stack_callenges, Sort_Stack) {
    std::vector<int> input{-5,2,-2,4,3,1};
    std::vector<int> output{-5,-2,1,2,3,4};
    EXPECT_THAT(sortStack(input), ::testing::ContainerEq(output));
}

/*TEST(stack_callenges, Next_Greater_Element) {
    std::vector<int> array{2,5,-3,-4,6,7,2};
    std::vector<int> output{5,6,6,6,7,-1,5};
    EXPECT_THAT(nextGreaterElement(array), ::testing::ContainerEq(output));
}*/