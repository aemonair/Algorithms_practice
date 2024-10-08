/*
 *************************************
 * 347. Top K Frequent Elements
 * Medium
 *************************************
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 *************************************
 * Example 1:
 *
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *************************************
 * Example 2:
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 *************************************
 * Constraints:
 *
 * 1 <= nums.length <= 10^5
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 * Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 *************************************
 */

#include <unordered_map>
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
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec)
{
    out << "[  ";
    for(auto v: _vec)
    {
        out << v << ", ";
    }
    out << "\b\b ]" ;
    return out;
}
template <typename ...T>
std::ostream & operator << (std::ostream &out, std::priority_queue<T... > big_queue)
{
    std::priority_queue<T...> Big_queue = big_queue;
    int bsize = Big_queue.size();
    if (Big_queue.empty())
    {
        out << "The big queue is empty. "<< std::endl;
    }
    out << " | ";
    while (bsize--)
    {
        out << "{" << Big_queue.top().first << " ," << Big_queue.top().second << "}, " ;
        Big_queue.pop();
    }
    out << std::endl ;
    return out;
}
class Solution {
public:
    //
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        return std::vector<int>{};
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, std::vector<int> & nums,int k, std::vector<int> expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;
    std::cout << "k " << k << " in nums:" << nums << std::endl;
    sort(expected.begin(), expected.end());
    // solution.printvector(nums);

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

        std::cout << "find k:" << k << std::endl;

        std::vector<int> && result = solution.topKFrequent(nums, k);
        std::cout << "result:" << result << std::endl;
        sort(result.begin(), result.end());
        // solution.printvector(result);

        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            // solution.printvector(expected);
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
    std::vector<int> nums ={-1,1,1,1,2,2,3};
    Test("Test1",nums, 2,std::vector<int>{1,2});
}
void Test2()
{
    std::vector<int> nums ={1};
    Test("Test2",nums, 1,std::vector<int> {1});
}

void Test3()
{
    std::vector<int> nums ={5,7,7,8,8,10};
    Test("Test3",nums, 2,std::vector<int> {7,8});
}

void Test4()
{
}

void Test5()
{
    //Test("Test5", deadends, k, -1);
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
