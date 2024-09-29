/*
 **************************************************************
 * 744. Find largest Letter lesser Than Target
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
 * Output: "j"
 **************************************************************
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "f"
 * Output: "c"
 **************************************************************
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "d"
 * Output: "c"
 **************************************************************
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "g"
 * Output: "f"
 **************************************************************
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "j"
 * Output: "f"
 **************************************************************
 *
 * Input:
 * letters = ["c", "f", "j"]
 * target = "k"
 * Output: "j"
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
template <typename T>
std::ostream & operator <<  (std::ostream & out ,std::vector<T> &v);

class Solution {
public:
    //
    char nextLessLetter(std::vector<char>& letters, char target)
    {
        int left = 0;
        int size = letters.size();
        int right = size-1;
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (letters[mid] < target) {
                if (mid == right || letters[mid+1]>=target) {
                    return letters[mid];
                }
                left = mid+1;
            }
            else if (letters[mid] >= target) {
                right = mid-1;
            }
        }
        return ' ';
        return letters[right];
    }
    char nextLessLetter1(std::vector<char>& letters, char target)
    {
        return ' ';
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
    std::cout << "target " << target << " in letters:" << letters << std::endl;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 1;
    if(TEST__)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.nextLessLetter(letters, target);
        std::cout << "result:\'" << std::boolalpha << result << "\'" << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    std::cout << "-----------------------------" << std::endl;
}
template <typename T>
std::ostream & operator <<  (std::ostream & out ,std::vector<T> &v)
{
    out << "vector size: " << v.size() << std::endl;
    out << "[  " ;//<< std::endl;
    for (auto iter = v.begin(); iter != v.end(); iter++ )
    {
        out << *iter << ", "; // <<std::endl;
    }
    out << "\b\b]" << std::endl;
    return out;
}
void Test1()
{
    std::vector<char> letters ={'c', 'f', 'j'};
    Test("Test1",letters, 'a',' ');
    Test("Test2",letters, 'c',' ');
    Test("Test3",letters, 'd','c');
    Test("Test4",letters, 'g','f');
    Test("Test5",letters, 'j','f');
    Test("Test6",letters, 'k','j');
}
void Test2()
{
    std::vector<char> letters ={'a', 'c', 'f', 'h'};
    Test("Test1",letters, 'f','c');
    Test("Test2",letters, 'b','a');
    Test("Test3",letters, 'm','h');
    Test("Test4",letters, 'h','f');
}

void Test3()
{
    std::vector<char> letters ={'e','e','e','e','e','e','n','n','n','n'};
    Test("Test5",letters, 'e',' ');
    Test("Test5",letters, 'n','e');
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
