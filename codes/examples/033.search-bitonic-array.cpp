/*
 **************************************************************
 * Search Bitonic Array
 * medium
 **************************************************************
 * Given a Bitonic array, find if a given ‘key’ is present in it.
 * An array is considered bitonic if it is monotonically increasing and then monotonically decreasing.
 * Monotonically increasing or decreasing means that for any index i in the array arr[i] != arr[i+1].
 *
 * Write a function to return the index of the ‘key’. If the ‘key’ is not present, return -1.
 *
 **************************************************************
 * Example 1:
 *
 * Input: [1, 3, 8, 4, 3], key=4
 * Output: 3
 **************************************************************
 * Example 2:
 *
 * Input: [3, 8, 3, 1], key=8
 * Output: 1
 **************************************************************
 * Example 3:
 *
 * Input: [1, 3, 8, 12], key=12
 * Output: 3
 **************************************************************
 * Example 4:
 *
 * Input: [10, 9, 8], key=10
 * Output: 0
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
std::ostream& operator<<(std::ostream &out ,std::vector<T> &v);

class Solution {
public:
    int search(std::vector<int>& nums, int target)
    {
        int left = 0;
        int size  = nums.size();
        int right = size-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > nums[mid+1]) {
                right = mid-1;
            } else if (nums[mid] < nums[mid+1]) {
                left = mid+1;
            }
        }
        auto find = [&](auto &&find, int left, int right){
            bool isAsc= nums[left] < nums[right];
            while (left <= right) {
                int mid = left+(right-left)/2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target) {
                    if (isAsc) {
                        left = mid+1;
                    } else {
                        right = mid-1;
                    }
                } else {
                    if (isAsc){
                        right = mid-1;
                    } else {
                        left = mid+1;
                    }
                }
            }
            return -1;
        };
        // 0~left
        int index = find(find, 0, left);
        if (index == -1) {
            index = find(find,left,nums.size()-1);
        }
        return index;
    }

};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<int> & nums,
        int target,
        int expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;
    std::cout << "find target :" << target << " nums:" << nums << std::endl;

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

        decltype(expected) result = solution.search(nums, target);
        std::cout << "result:" << std::boolalpha << result << std::endl;

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
std::ostream & operator << (std::ostream &out ,std::vector<T> &v)
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
    std::vector<int> nums ={1, 3, 8, 4, 3};
    Test("Test1",nums, 4,3);
}
void Test2()
{
    std::vector<int> nums ={3, 8, 3, 1};
    Test("Test0",nums, 8,1);
}

void Test3()
{
    std::vector<int> nums ={1, 3, 8, 12};
    Test("Test1", nums, 12, 3);
}

void Test4()
{
    std::vector<int> nums ={10, 9, 8};
    int target = 10;
    Test("Test2", nums, target, 0);
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
