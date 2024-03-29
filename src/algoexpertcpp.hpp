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
#ifndef ALGOEXPERT_CPP
#define ALGOEXPERT_CPP
#include <algorithm>
#include <any>
#include <assert.h>
#include <iostream>
#include <map>
#include <math.h>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

/* Array Challenges*/
std::vector<int> twoNumberSum(std::vector<int> array, int targetSum);
bool isValidSubsequence(std::vector<int> array, std::vector<int> sequence);
std::vector<int> sortedSquaredArray(std::vector<int> array);
std::string tournamentWinner(std::vector< std::vector<std::string> > competitions,
            std::vector<int> results);

/* Recursion Challenges */
int getNthFib(int n);
int productSum(std::vector<std::any> array);
std::vector<std::vector<int>> getPermutations(std::vector<int> array);
std::vector<std::vector<int>> noneRecursivePowerset(std::vector<int> array);
std::vector<std::vector<int>> powerset(std::vector<int> array);
std::vector<std::string> phoneNumberMnemonics(std::string phoneNumber);

/* Stack Challenges */
bool balancedBrackets(std::string str);
std::vector<int> sunsetViews(std::vector<int> buildings, std::string direction);
std::string bestDigits(std::string number, int numDigits);
std::vector<int> sortStack(std::vector<int>& stack);
std::vector<int> nextGreaterElement(std::vector<int> array);

struct data{
    data* next;
    int value;

    data(){
        next = nullptr;
        value =-1;
    }
};
class MinMaxStack {
    private:
        int min = -1;
        int max = -1;        
        std::stack<data> innerStack; 
    public:
        MinMaxStack() = default;
        int peek();
        int pop();
        void push(int number);
        int getMin();
        int getMax();
};

/* Binary Search Tree */
template<typename T>
class BST {
public:
    T value;
    BST* left;
    BST* right;

    BST(T val) : value {val}, left{nullptr}, right{nullptr} {}
};

int findClosestValueInBst(BST<int>* tree, int target);
#endif /*ALGOEXPERT_CPP*/