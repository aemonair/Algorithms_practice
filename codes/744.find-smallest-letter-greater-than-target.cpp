/*
 **************************************************************
 * 744. Find Smallest Letter Greater Than Target
 * Easy
 **************************************************************
 * Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.
 *
 * Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
 *
 **************************************************************
 * Examples:
 * Input:
 * letters = ["c", "f", "j"]
 * target = "a"
 * Output: "c"
 **************************************************************
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "c"
 * Output: "f"
 **************************************************************
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "d"
 * Output: "f"
 **************************************************************
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "g"
 * Output: "j"
 **************************************************************
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "j"
 * Output: "c"
 **************************************************************
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "k"
 * Output: "c"
 **************************************************************
 * Note:
 * letters has a length in range [2, 10000].
 * letters consists of lowercase letters, and contains at least 2 unique letters.
 * target is a lowercase letter.
 **************************************************************
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
class Solution {
public:
    //
    char nextGreatestLetter(std::vector<char>& letters, char target)
    {
        int size = letters.size();
        if (target < letters[0]|| target > letters[size-1]) {
            return letters[0];
        }
        int left = 0;
        int right = size-1;
        int result = -1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (letters[mid] > target) {
                right = mid -1;
            } else {   // if (letters[mid] <= target)
                left = mid + 1;
            }
        }
        return letters[left % size];
    }
    char nextGreatestLetter1(std::vector<char>& letters, char target)
    {
        if (target < letters[0]
        || target > letters[letters.size()-1]) {
            return letters[0];
        }
        int left = 0;
        int right = letters.size()-1;
        int size = letters.size();
        int result = -1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (letters[mid] == target) {
                left = mid + 1;
                result = mid;
            } else if (letters[mid] < target) {
                left = mid + 1;
            } else {
                right = mid -1;
            }
        }
        if (result != -1) {
            return letters[(result + 1) % size];
        }
        return letters[left];//' ';
    }

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  " ;//<< std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", "; // <<std::endl;
        }
        std::cout << "\b\b]" << std::endl;
        return v.size();
    }

    template <typename T>
    int printvectorvector(const std::vector<T> &v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvector( *iter );
        }
        std::cout << std::endl;
        return v.size();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<char> & letters,
        char target,
        char expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;
    std::cout << "target " << target << " in letters:" << std::endl;
    solution.printvector(letters);

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.nextGreatestLetter(letters, target);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    std::cout << "-----------------------------" << std::endl;
}
void Test1()
{
    std::vector<char> letters ={'c', 'f', 'j'};
    Test("Test1",letters, 'a','c');
    Test("Test2",letters, 'c','f');
    Test("Test3",letters, 'd','f');
    Test("Test4",letters, 'g','j');
    Test("Test5",letters, 'j','c');
    Test("Test6",letters, 'k','c');
}
void Test2()
{
    std::vector<char> letters ={'a', 'c', 'f', 'h'};
    Test("Test1",letters, 'f','h');
    Test("Test2",letters, 'b','c');
    Test("Test3",letters, 'm','a');
    Test("Test4",letters, 'h','a');
}

void Test3()
{
    std::vector<char> letters ={'e','e','e','e','e','e','n','n','n','n'};
    Test("Test5",letters, 'e','n');
}

void Test4()
{
}

void Test5()
{
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
