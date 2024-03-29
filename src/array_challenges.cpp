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
#include "algoexpertcpp.hpp"

/*Two Number Sum
 *Write a function that takes in non-empty array of distinct integers and an
 *integer representing a target sum. If any two numbers in the input array sum
 *up to the target sum, the function should return an empty array.
 *array = [3,5,-4,8,11,1,-1,6]
 *targetSum = 10
 *[-1,11]
 */
std::vector<int> twoNumberSum(std::vector<int> array, int targetSum)
{
    std::unordered_set<int> nums;
    auto it = std::find_if(array.begin(), array.end(), [&](int num){
		//calculating the number that is needed to get the target sum
        int potentialMatch = targetSum - num;
		//find if there is any into the set
        if(nums.find(potentialMatch) != nums.end()) {
            return true;
        }
		//if the target sum is not found the num is inserted and go to the next one
        nums.insert(num);
        return false;
    });

	//return the two numbers that sum the target
    if (it != array.end()) {
        return { *it, targetSum - *it };
    }

    return {};
}

/*Validate Subsequence
 *Given two non empty arrays of integers, write a function that determines
 *whether the second array is a subsequence of the first one.
 *array =[5,1,22,25,6,-1,8,10]
 *sequence = [1,6,-1,10]
 *true
 */
bool isValidSubsequence(std::vector<int> array, std::vector<int> sequence) {
	int j = 0;
	bool flag = false;
	for(int i = 0; i < array.size() ; ++i){
		if(array[i] == sequence[j]){
			j++;
			if(j == sequence.size()){
				flag = true;
				break;
			}
		}
	}
	return flag;
}

/*Sorted Squared Array
 *Write a function that takes a non-empty array of integers that are sorted in
 *ascending order and returns a new array of the same length with the squares
 *of the original integers also sorted in ascending order
 *array = [1,2,3,5,6,8,9]
 *[1,4,9,25,36,64,81]
 */
std::vector<int> sortedSquaredArray(std::vector<int> array) {
	std::vector<int> resultArray(array.size());
	transform(array.begin(), array.end(), resultArray.begin(),
		[](int num){return num*num;});
	std::sort(resultArray.begin(), resultArray.end());
	return resultArray;
}

/* Tournament Winner
 *There's an algorithms tournament taking place in wich teams of programmers
 *compete against each other to solve algorithmic problems as fast as possible.
 *Teams compete in a round robin, where each team faces off against all other
 *teams. Only two teams compete against each other at a time, and for each
 *competition, one team is designated the home team, while the other team is the
 *away team [homeTeam, awayTeam]. In each competition there's always one winner
 *and one loser; there are no ties. A team receives 3 points if it wins and 0
 *points if it loses. The winner of the tournament is the team that receives the
 *most amout of points. There is a vector with an inner vector that contains all
 *the competitions:
 *[["HTML", "C#"],["C#", "Python"],["Python", "HTML"]]
 *another array holds the competition result where 1 means the home team won and
 *0 means the away team won: 
 *[0, 0, 1]
 *the result here is the winner is python as the corresponding points made for each
 *team are:
 *HTML: 0
 *C#: 3
 *Python: 6
*/

std::string tournamentWinner(std::vector< std::vector<std::string> > competitions,
                        std::vector<int> results)
{
	std::map<std::string, int> scores;
	std::map<std::string, int>::iterator itScores;
	int resultIndex = 0;
	
	for (std::vector< std::vector<std::string> >::iterator itCompetitions = competitions.begin();
			 itCompetitions != competitions.end();
			 ++itCompetitions){

		int winnerIndex = ((~results[resultIndex]) & 0x01);
		std::string winner = (*itCompetitions)[winnerIndex];
		itScores = scores.find(winner);
		if(itScores != scores.end())
		{
			scores[winner] += 3;
		}else
		{
			scores[winner] = 3;
		}			
		++resultIndex;			
	}
	
	auto maxPair = *std::max_element(scores.begin(), scores.end(),
		[](const auto& lhs, const auto& rhs) {
        return lhs.second < rhs.second;
    });
	
	return maxPair.first;
}

/*Non Constructible Chnage C++ 11
 *Given an array of positive engineers representing the values of coins in your
 *possesion, write a function that returns the minimum amount of change (the minimum
 *sum of money) that you cannot create. The given coins can have any positive integer
 *value and aren't necessarily unique (i.e. you can have multiple coins of the same value)
 *input
 * coins = [5, 7, 1, 1, 2, 3, 22]
 *output
 *  20
 */
int nonConstructibleChange(std::vector<int> coins) 
{
    std::sort(coins.begin(), coins.end());
    auto counter = 0;
    for(auto i = 0;i != coins.size() ;++i)
    {        
        if((coins[i] - counter) > 1)
        {
            break;
        }
        counter += coins[i];
    }

    return counter + 1;
}

/*Three Number Sum
 *Write a function that takes in a non-empty array of distinct integers and an
 *integer representing a target sum. The function should find all triplets in
 *the array that sum up to the target sum and return a two-dimensional arrat of
 *all the triplets. The number in each triplet should be ordered in ascending
 *order with respect to the numbers they hold.
 *array = [12,3,1,2,-6,5,-8,6]
 *targetSum = 0
 *[[-8,2,6],[-8,3,5],[-6,1,5]]
 */
std::vector<std::vector<int>> threeNumberSum(std::vector<int> array, int targetSum) {
	std::vector<std::vector<int>> result;
	std::sort(array.begin(), array.end());
    for(auto i = 0; i < array.size()-2 ; i++)
	{
	    auto right = array.size()-1;
        auto left = i + 1;
		auto cs = array[left] + array[right] + array[i];
		while(left < right)
		{
			if(cs < targetSum)
			{				
				left++;
			}
			else
			{
				cs = array[left] + array[right] + array[i];
				if(cs == targetSum)
					result.push_back({array[i], array[left], array[right]});
				right--;
			}
            cs = array[left] + array[right] + array[i];
		}
	}
	return result;
}

/*Smallest Difference
 *Write a function that takes in two non-empty arrays of integers, finds the
 *pair of numbers (one from each array) whose absolute difference is closest to
 *zero, and returns an array containing these two numbers, with the number from
 *the first array in the first position.
 * arrayOne = [-1,5,10,20,28,3]
 * arrayTwo = [26,134,135,15,17]
 * [28,26]
 */
int absoluteDiff(int a, int b){
	auto diff = a - b;
	auto pow2 = std::pow(diff,2);
	auto absDiff = std::sqrt(pow2);
	return absDiff;
}

std::vector<int> smallestDifference(std::vector<int> arrayOne, std::vector<int> arrayTwo)
{
	std::sort(arrayOne.begin(), arrayOne.end());
	std::sort(arrayTwo.begin(), arrayTwo.end());
	int in1 = 0, in2 = 0, diff = 0;
  	std::vector<int> temp = {arrayOne[in1], arrayTwo[in2]} ;
	while( in1 < arrayOne.size() && in2 < arrayTwo.size() )
	{
		if(arrayOne[in1] > arrayTwo[in2])
		{
			in2++;
		}
		else if(arrayOne[in1] == arrayTwo[in2])
		{
			temp = {arrayOne[in1], arrayTwo[in2]};
			break;
		}
		else
		{
			in1++;
		}
		if(absoluteDiff(arrayOne[in1],arrayTwo[in2]) < absoluteDiff(temp[0],temp[1]))
		{
			temp = {arrayOne[in1],arrayTwo[in2]};
		}
	}
  return temp;
}

/*Move Element To End
 *You're give an array of integers and an integer. Write a function that moves
 *all instances of that integer in the array to the end of the array an returns
 *the array.
 * array = [2,1,2,2,2,3,4,2]
 * toMove = 2
 * [1,3,4,2,2,2,2,2]
 */
std::vector<int> moveElementToEnd(std::vector<int> array, int toMove) 
{
	int maxIndex = array.size();
	int i = 0;
	while(i < maxIndex)
	{
		if(array[i] == toMove)
		{
			while((array[maxIndex-1] == toMove) &&(i < maxIndex-1))
			{
				--maxIndex;
			}
			array[i] = array[maxIndex-1];
			array[maxIndex-1] = toMove;
			--maxIndex;				
		}
		++i;
	}
  return array;
}
