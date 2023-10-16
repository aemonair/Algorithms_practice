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
class Solution {
public:
    //
    std::vector<int> findClosestElements1(std::vector<int>& arr, int k,int x)
    {
        int size = arr.size();
        int left = 0;
        int right = size-1;
        int result = -1;
        while (left <= right ) { //&& right - left > k)
            int mid = left +(right-left)/2;
            if (arr[mid] == x) {
                result = mid;
                left = mid;
                std::cout << "size:" << right-left+1 << std::endl;
                break;
            } else if (arr[mid] < x) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
#if 0
        right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        std::cout << "left:" << left << "right" << right << std::endl;
        left = right - 1;
        while (k--) {
            if (left < 0) {
                right++;
            } else if (right >= arr.size()) {
                left--;
            } else if (x - arr[left] <= arr[right] - x) {
                left--;
            } else {
                right++;
            }
        }
        return std::vector<int>(arr.begin() + left + 1, arr.begin() + right);

        if (arr[left] > x &&  left > 0 &&  x - arr[left - 1] <= arr[left] - x) {
            left -= 1;
        }
        int i = left;
        int j = left;
        while (j - i +1 < k){
            // # 结果边界达到数组边界
            if (j == size - 1) {
                i -= 1;
                continue;
            }
            if(i == 0) {
                j += 1;
                continue;
            }
            // # 比较并扩展,若相等则向左扩展
            if(x - arr[i - 1] <= arr[j + 1] - x) {
                i -= 1;
            }
            else if( x - arr[i - 1] > arr[j + 1] - x) {
                j += 1;
            }
        }
        std::cout << i << " " <<j << std::endl;
        return {arr.begin()+i, arr.begin()+j+1};
#endif

        if (result == -1) {
            std::cout << "result -1 left:" <<left << ",right:" << right << std::endl;
            //扩展(right,left)
            auto temp = left;
            left = right;
            right = temp;
            while (right - left < k) {
                if (left <= 0) {
                    left = 0;
                    right++;
                    continue;
                }
                if (right >= size) {
                    right = size-1;
                    left--;
                    continue;
                }
                if (x - arr[right] < arr[left] -x) {
                    right--;
                } else {
                    left++;
                }
            }
        } else { // size =k 1
            // 扩展result
            //right = x+1;
            //left = x-1;
            if (k==1) {
                return {x};
            }
            std::cout << "result :" << x << " left:" <<left << ",right:" << right << std::endl;
            while (right - left < k) {
                if (left == 0) {
                    right++;
                    continue;
                }
                if (right == size-1) {
                    left--;
                    continue;
                }
                if (x - arr[right] < arr[left] -x) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        std::cout << "left:" <<left << ",right:" << right << std::endl;
        return std::vector<int>(arr.begin()+left,arr.begin()+right);
    }
    std::vector<int> findClosestElements(std::vector<int>& arr, int k,int x)
    {
        int size = arr.size();
        int left = 0;
        int right = size-1;
        int result = -1;
        while (left <= right ) { //&& right - left > k)
            int mid = left +(right-left)/2;
            if (arr[mid] == x) {
                result = mid;
                left = mid;
                std::cout << "size:" << right-left+1 << std::endl;
                break;
            } else if (arr[mid] < x) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        if (result == -1) {
            std::cout << "result -1 left:" <<left << ",right:" << right << std::endl;
            //交换(right,left)
            auto temp = left;
            left = right;
            right = temp;
        }
        std::cout << "result " << result << " left:" <<left << ",right:" << right << std::endl;
        while (right - left < k) {
            if (left <= 0) {
                left = 0;
                right++;
                continue;
            }
            if (right >= size) {
                right = size-1;
                left--;
                continue;
            }
            if (abs(arr[right] -x) < abs(x- arr[left]) ) {
                right++;
            } else {
                left--;
            }
            std::cout << "result " << result << " left:" <<left << ",right:" << right << std::endl;
        }
        std::cout << "left:" <<left << ",right:" << right << std::endl;
        return std::vector<int>(arr.begin()+left,arr.begin()+right);
#if 0
        right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        std::cout << "left:" << left << "right" << right << std::endl;
        left = right - 1;
        while (k--) {
            if (left < 0) {
                right++;
            } else if (right >= arr.size()) {
                left--;
            } else if (x - arr[left] <= arr[right] - x) {
                left--;
            } else {
                right++;
            }
        }
        return std::vector<int>(arr.begin() + left + 1, arr.begin() + right);
#endif
    }

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        //std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << "| ";//<<std::endl;
        }
        std::cout << std::endl;
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
void Test(const std::string& testName, std::vector<int> & arr,int k,int x, std::vector<int> expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;
    std::cout << "k: " << k << ",x:"<< x << " in arr:" << std::endl;
    solution.printvector(arr);

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
        std::cout << "result:" <<  std::endl;
        solution.printvector(result);

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
    if(TEST_1)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::vector<int> && result = solution.findClosestElements1(arr, k, x);
        std::cout << "result1:" <<  std::endl;
        solution.printvector(result);

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
    std::cout << "-----------------------------" << std::endl;
}
void Test1()
{
    std::vector<int> arr ={1, 2, 3, 4, 5};
    Test("Test1.1",arr, 4,  3, std::vector<int>{1,2,3,4});
    Test("Test1.2",arr, 4, -1, std::vector<int>{1,2,3,4});
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
