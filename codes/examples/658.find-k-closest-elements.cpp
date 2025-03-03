/*
 *************************************
 * 658. Find K Closest Elements
 * Medium
 *************************************
 * Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
 *
 * An integer a is closer to x than an integer b if:
 *
 * |a - x| < |b - x|, or
 * |a - x| == |b - x| and a < b
 *************************************
 * Example 1:
 *
 * Input: arr = [1,2,3,4,5], k = 4, x = 3
 * Output: [1,2,3,4]
 *************************************
 * Example 2:
 *
 * Input: arr = [1,2,3,4,5], k = 4, x = -1
 * Output: [1,2,3,4]
 *************************************
 * Constraints:
 *
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 104
 * arr is sorted in ascending order.
 * -10^4 <= arr[i], x <= 10^4
 *************************************
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

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

class Solution {
public:
    //
    std::vector<int> findClosestElements(std::vector<int>& arr, int k,int x)
    {
        int left = 0;
        int size = arr.size();
        int right = size-k;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (mid+k < size && x - arr[mid] > arr[mid+k]-x) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return std::vector<int>(arr.begin()+left, arr.begin()+left +k);
        return {};
    }
    std::vector<int> findClosestElements1(std::vector<int>& arr, int k,int x)
    {
        return {};
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, std::vector<int> & arr,int k,int x, std::vector<int> expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;
    std::cout << "k: " << k << ",x:"<< x << " in arr:" << arr << std::endl;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::vector<int> && result = solution.findClosestElements(arr, k, x);
        std::cout << "result:" << result << std::endl;

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
    if(TEST_1)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::vector<int> && result = solution.findClosestElements1(arr, k, x);
        std::cout << "result1:" << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    std::cout << "-----------------------------" << std::endl;
}
template<typename T>
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
void Test1()
{
    std::vector<int> arr ={1, 2, 3, 4, 5};
    Test("Test1.1",arr, 4,  3, std::vector<int>{1,2,3,4});
    Test("Test1.2",arr, 4, -1, std::vector<int>{1,2,3,4});
    Test("Test1.3",arr, 3,  3, std::vector<int>{2,3,4});
}
void Test2()
{
    std::vector<int> arr ={4, 6, 10};
    Test("Test2.1",arr, 1,  7,std::vector<int> {6});
    Test("Test2.2",arr, 1,  4,std::vector<int> {4});
    Test("Test2.3",arr, 1, 17,std::vector<int> {10});
}

void Test3()
{
    std::vector<int> arr ={1, 3, 8, 10, 15};
    Test("Test3",arr, 1, 12,std::vector<int> {10});
}

void Test4()
{
    std::vector<int> arr ={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15};
    Test("Test4.1",arr, 3, 10,std::vector<int> {9,10,11});
    Test("Test4.2",arr, 3, 12,std::vector<int> {9,10,11});
    Test("Test4.3",arr, 3, 3,std::vector<int> {2,3,4});
}

void Test5()
{
    std::vector<int> arr ={1, 3, 8, 10, 15, 16,19,34, 56,68,79};
    Test("Test5",arr, 3, 40,std::vector<int> {19,34,56});
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
