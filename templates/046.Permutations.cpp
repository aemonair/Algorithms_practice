/*
 *********************************************
 * 46. Permutations
 * Medium
 *********************************************
 * Given a collection of distinct integers, return all possible permutations.@20201210
 * Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 *********************************************
 * Example 1:
 * 
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 *********************************************
 * Example 2:
 * 
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 *********************************************
 * Example 3:
 * 
 * Input: nums = [1]
 * Output: [[1]]
 *********************************************
 * Constraints:
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 *********************************************
 *
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
class Solution {
public:
    // 
    bool hasvalue(int num, std::vector<int> three)
    {
        for (auto one : three)
        {
            if (one == num)
            {
                return true;
            }
        }
        return false;
    }
    std::vector<std::vector<int>> result;
    ////////////////////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>> permute0(std::vector<int>& nums) 
    {
        result.clear();
        return result;
    }
    ////////////////////////////////////////////////////////////////////////////////
    std::vector<std::vector<int>> permute1(std::vector<int>& nums) 
    {
        result.clear();
        return result;
    }
    template <typename T>
    int printvector(std::vector<T> v)
    {
        //std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  "; // << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";
        }
        std::cout << "\b\b]"  ;//std::endl;
        return v.size();
    }

    template <typename T>
    int printvectorvector(std::vector<T> v)
    {
        std::cout << "{  " ; //<< v.size() << std::endl;
        //std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvector( *iter );
        }
        std::cout << "  }" << std::endl;
        return v.size();
    }
    int getpermutataion(std::vector<int> nums, std::vector<std::vector<int>> & permutation)
    {
        std::sort(nums.begin(), nums.end());
        permutation.clear();
        do 
        {
            permutation.push_back(std::vector<int>{nums});
        } while ( std::next_permutation(nums.begin(), nums.end() ));
        //printvectorvector(permutation);
        return permutation.size();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        std::vector<int>  nums , 
        std::vector<std::vector<int>> expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << " nums: "<< std::endl;
    solution.printvector(nums);
    //std::cout << " expected by getpermutataion: "<< std::endl;
    solution.getpermutataion(nums, expected);
    //solution.printvectorvector(expected);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::vector<std::vector<int>> &&result = solution.permute0(nums);
        std::cout << "result:" << std::endl;
        solution.printvectorvector(result);

        std::sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            solution.printvectorvector(expected);
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if (TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::vector<std::vector<int>> &&result = solution.permute1(nums);
        std::cout << "result:" << std::endl;
        solution.printvectorvector(result);
        std::sort(result.begin(), result.end());

        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            solution.printvectorvector(expected);
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
}
void Test1()
{
    Test("Test1", std::vector<int> {1,2,5},{{}});
}
void Test2()
{
    Test("Test2", std::vector<int> {3}, {{}});
}

void Test3()
{
    Test("Test3", std::vector<int> {186,419,83,408},{{}});
}

void Test4()
{
    //Test("Test4", 6, 6, 3);
}



int main()
{
    Solution solution;

    Test1();
    Test2();
    //Test3();

    return 0;

}
