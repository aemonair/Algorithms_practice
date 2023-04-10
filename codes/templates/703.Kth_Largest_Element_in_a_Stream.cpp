/*
///////////////////////////////////////////////////////////////
  * 703. Kth Largest Element in a Stream
 * Easy
///////////////////////////////////////////////////////////////
 * Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Implement KthLargest class:
 * 
 * KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
 * int add(int val) Returns the element representing the kth largest element in the stream.
///////////////////////////////////////////////////////////////
 * Example 1:
 * 
 * Input
 * ["KthLargest", "add", "add", "add", "add", "add"]
 * [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
 * Output
 * [null, 4, 5, 5, 8, 8]
 * 
 * Explanation
 * KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
 * kthLargest.add(3);   // return 4
 * kthLargest.add(5);   // return 5
 * kthLargest.add(10);  // return 5
 * kthLargest.add(9);   // return 8
 * kthLargest.add(4);   // return 8
///////////////////////////////////////////////////////////////
 * Constraints:
 * 
 * 1 <= k <= 10^4
 * 0 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * -10^4 <= val <= 10^4
 * At most 10^4 calls will be made to add.
 * It is guaranteed that there will be at least k elements in the array when you search for the k^th element.
///////////////////////////////////////////////////////////////
 */

#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <chrono>
#include <iostream>
#include <queue>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

class KthLargest {
public:
///////////////////////////////////////////////////////////////
    KthLargest(int k, std::vector<int>& nums) 
    {
    }

    int add(int val) 
    {
        return 0;
    }
public:
///////////////////////////////////////////////////////////////
    template <typename T>
    int printvector(std::vector<T> v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";
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
    template <typename T>
    int printstack(std::stack<T> s)
    {
        if (s.empty())
        {
            std::cout << "The stack is empty." << std::endl;
            return 0;
        }
        std::cout <<  "The stack size is: " << s.size() << std::endl;
        std::stack<T> tmp;
        while (!s.empty())
        {
            std::cout << s.top() << ", ";
            s.pop();
        }
        std::cout <<  std::endl;
        return s.size();
    }
///////////////////////////////////////////////////////////////
};
// ==================== TEST Codes====================
int test(KthLargest *kthlargest, int add, int expected)
{
    std::cout << "kthLargest.add(" << add << ") " << std::endl;   // return 5
    int result = kthlargest->add(add);   // return 4
    std::cout << "result:" << result <<  std::endl;
    if(result == expected)
    {
        std::cout << GREEN << "add(" << add << ") passed." << RESET <<  std::endl;
        return 0;
    }
    else
    {
        std::cout << RED << "add(" << add << ") failed." <<  RESET << std::endl;
        std::cout << RED << "expected:" << std::boolalpha  << expected << std::endl;
        std::cout << RESET << std::endl;
        return -1;
    }
}
void Test1()
{
    int result = 0;
    int expected = 0;
    std::cout << "Test1 START:" << std::endl;
    std::vector<int> v{4, 5, 8, 2};
    KthLargest * kthlargest = new KthLargest(3, v ); 
    std::cout << "new KthLargest(3, [4, 5, 8, 2])" << std::endl;
    std::cout << "kthLargest.add(3) " << std::endl;   // return 4
    test(kthlargest, 3, 4);
    test(kthlargest, 5, 5);
    test(kthlargest,10, 5);
    test(kthlargest, 9, 8);
    test(kthlargest, 4, 8);
}
void Test2()
{
    int result = 0;
    int expected = 0;
    std::cout << "Test1 START:" << std::endl;
    std::vector<int> v{};
    KthLargest * kthlargest = new KthLargest(1, v ); 
    std::cout << "new KthLargest(1, [])" << std::endl;
    test(kthlargest, -3, -3);
    test(kthlargest, -2, -2);
    test(kthlargest, -4, -2);
    test(kthlargest, 0, 0);
    test(kthlargest, 4, 4);
}

void Test3()
{
    int result = 0;
    int expected = 0;
    std::cout << "Test1 START:" << std::endl;
    std::vector<int> v{0};
    KthLargest * kthlargest = new KthLargest(2, v ); 
    std::cout << "new KthLargest(2, [0])" << std::endl;
    test(kthlargest, -1, -1);
    test(kthlargest,  1,  0);
    test(kthlargest, -2,  0);
    test(kthlargest, -4, 0);
    test(kthlargest,  3, 1);
}

void Test4()
{
}

void Test5()
{
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;

}

