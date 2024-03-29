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
#include <numeric>
#include <iostream>
#include "algoexpertcpp.hpp"

TEST(recursion_callenges, Fibonacci_Sequence) {
    EXPECT_EQ(0, getNthFib(1));
    EXPECT_EQ(1, getNthFib(2));
    EXPECT_EQ(1, getNthFib(3));
    EXPECT_EQ(2, getNthFib(4));
    EXPECT_EQ(3, getNthFib(5));
    EXPECT_EQ(4181, getNthFib(20));
}

TEST(recursion_callenges, Product_Sum){
    std::vector<std::any> array{-13,8};
    std::vector<std::any> array1{6,array,4};
    std::vector<std::any> array2{7,-1};
    std::vector<std::any> array3{5,2,array2,3,array1};
    EXPECT_EQ(12, productSum(array3));
}

TEST(recursion_challenges,Get_Permutations){
    std::vector<int> array{1,2,3};
    std::vector<std::vector<int>> expected{{3,1,2},{3,2,1},{2,1,3},{2,3,1}, 
            {1,2,3},{1,3,2}};
    auto result = getPermutations(array);
    EXPECT_THAT(expected, testing::ContainerEq(result));
}

TEST(recursion_callenges, Power_Set) {
    std::vector<int> array{1,2};
    std::vector<std::vector<int>> expected{{},{1},{2},{1,2}};
    std::vector<std::vector<int>> result = powerset(array);
    EXPECT_EQ(expected.size(), result.size());
    EXPECT_THAT(expected, testing::ContainerEq(result));
}

TEST(recursion_challenges, Phone_Number_Mnemonics){
    std::string param = "1905";
    std::vector<std::string> expected {"1w0j","1w0k","1w0l","1x0j","1x0k","1x0l",
                            "1y0j","1y0k","1y0l","1z0j","1z0k","1z0l"};
    auto result = phoneNumberMnemonics(param);
    EXPECT_THAT(expected, testing::ContainerEq(result));
}