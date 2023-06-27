/*
 *********************************************
 * 784. Letter Case Permutation
 * Medium
 *********************************************
 * Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.
 *
 * Return a list of all possible strings we could create. You can return the output in any order.
 *********************************************
 * Example 1:
 *
 * Input: S = "a1b2"
 * Output: ["a1b2","a1B2","A1b2","A1B2"]
 *********************************************
 * Example 2:
 *
 * Input: S = "3z4"
 * Output: ["3z4","3Z4"]
 *********************************************
 * Example 3:
 *
 * Input: S = "12345"
 * Output: ["12345"]
 *********************************************
 * Example 4:
 *
 * Input: S = "0"
 * Output: ["0"]
 *********************************************
 * Constraints:
 *
 * S will be a string with length between 1 and 12.
 * S will consist only of letters or digits.
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
    ////////////////////////////////////////////////////////////////////////////////
    std::vector<std::string> letterCasePermutation0(std::string S)
    {
        std::vector<std::string> result;
        return result;
    }
    ////////////////////////////////////////////////////////////////////////////////
    std::vector<std::string> letterCasePermutation1(std::string S)
    {
        std::vector<std::string> result;
        return std::vector<std::string>();
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
    int printvector(std::vector<std::string> v)
    {
        //std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  "; // << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << "\"" << *iter << "\", ";
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
        std::string &S,
        std::vector<std::string>  expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << " S: " << S << std::endl;
    std::sort(expected.begin(), expected.end());

const static int TEST_TIME = 1;
const static int TEST_0    = 0;
const static int TEST_1    = 1;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        //decltype(expected) &&
            auto result = solution.letterCasePermutation0(S);
        std::cout << "result0:" << std::endl;
        solution.printvector(result);

        std::sort(result.begin(), result.end());
        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            solution.printvector(expected);
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

        //decltype(expected)
        auto result = solution.letterCasePermutation1(S);
        std::cout << "result1:" << std::endl;
        solution.printvector(result);
        std::sort(result.begin(), result.end());

        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            solution.printvector(expected);
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
    std::string S = "a1b2";
    std::vector<std::string> expected = {"a1b2","a1B2","A1b2","A1B2"};
    Test("Test1", S, expected );
}
void Test2()
{
    std::string S = "3z4";
    Test("Test2", S, std::vector<std::string> {"3z4", "3Z4"});
}

void Test3()
{
    std::string S = "12345";
    Test("Test3", S, std::vector<std::string> {"12345"});
}

void Test4()
{
    std::string S = "0";
    Test("Test4", S, std::vector<std::string> {"0"});
}

void Test5()
{
    std::string S = "0";
    Test("Test5", S, std::vector<std::string> {"0"});
}

int main()
{
    Solution solution;

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;

}
