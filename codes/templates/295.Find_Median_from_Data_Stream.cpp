/*
 ****************************************************************
 * 295. Find Median from Data Stream
 * Hard
 ****************************************************************
 * Median is the middle value in an ordered integer list.
 * If the size of the list is even, there is no middle value.
 * So the median is the mean of the two middle value.
 *
 * For example,
 * [2,3,4], the median is 3
 *
 * [2,3], the median is (2 + 3) / 2 = 2.5
 ****************************************************************
 * Design a data structure that supports the following two operations:
 *
 * MedianFinder() initializes the MedianFinder object.
 * + void addNum(int num) -
 *        - Add a integer number from the data stream to the data structure.
 * + double findMedian() -
 *        - Return the median of all elements so far.
 *        - Answers within 10^-5 of the actual answer will be accepted.
 ****************************************************************
 * Example:
 *
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3)
 * findMedian() -> 2
 ****************************************************************
 * Implement the MedianFinder class:
 *
 * Input
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * Output
 * [null, null, null, 1.5, null, 2.0]
 *
 * Explanation
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 *
 ****************************************************************
 * Constraints:
 *
 * -10^5 <= num <= 10^5
 * There will be at least one element in the data structure before calling findMedian.
 * At most 5 * 104 calls will be made to addNum and findMedian.
 ****************************************************************
 * Follow up:
 *
 * 1. If all integer numbers from the stream are between 0 and 100, how would you optimize it?
 * 2. If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
 ****************************************************************
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <limits>
#include <queue>
#include <stack>
#include <deque>
#include <map>


#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
    }

    double findMedian()
    {
    }
public:
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
    template <class... Types>
    int printtuple(std::tuple<Types...>  tu)
    {
        auto size = std::tuple_size<decltype(tu)>::value;
        std::cout << std::get<0>(tu) << ",";
        std::cout << std::get<1>(tu) << ",";
        std::cout << std::get<2>(tu) << ",";
        std::cout << std::get<3>(tu) << ",";
        std::cout << std::get<4>(tu) << ",";
        std::cout << std::get<5>(tu) << ",";

        return size;
    }
    ///////////////////////////////////

    int printqueue()
    {
#if 0
        std::priority_queue<int> Big_queue = big_queue;
        std::priority_queue<int, std::vector<int>, std::greater<int>> Small_queue=small_queue;
        int bsize = Big_queue.size();
        int ssize = Small_queue.size();
        if (Big_queue.empty())
        {
            std::cout << "The big queue is empty. "<< std::endl;
        }
        if (Small_queue.empty())
        {
            std::cout << "The small queue is empty. "<< std::endl;
        }
        while (ssize--)
        {
            std::cout << Small_queue.top() << ", " ;
            Small_queue.pop();
        }
        std::cout << " | ";
        while (bsize--)
        {
            std::cout << Big_queue.top() << ", " ;
            Big_queue.pop();
        }
        std::cout << std::endl ;
        return bsize;
#endif
        return 0;
    }

};

// ==================== TEST Codes====================
template <class... T>
void Test(const std::string& testName,
        std::vector<std::string> &operators,
        std::vector<int>& nums,
        std::tuple<T...>& expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    MedianFinder solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;

    double expec_1 = 0;
    double expec_2 = 0;
    std::tie(std::ignore, std::ignore, std::ignore, expec_1, std::ignore,expec_2) = expected;
    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        //  Input
        // ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
        // [[], [1], [2], [], [3], []]
        // Output
        // [null, null, null, 1.5, null, 2.0]
        MedianFinder* obj = nullptr;
        std::vector<double> result(operators.size(), 0);
       
        for(int i = 0; i< operators.size(); i++)
        {
            auto oper = operators[i];
            auto num  = nums[i];
            std::cout << oper << ": " << num << std::endl;
            if (oper == "MedianFinder")
            {
                if(obj)
                {
                    delete obj;
                }
                obj = ( new MedianFinder());
            }
            else if(oper == "addNum")
            {
                if(obj)
                {
                    obj->addNum(num);
                }
            }
            else if(oper == "findMedian")
            {
                if(obj)
                {
                    double param_2 = obj->findMedian();
                    std::cout << "findMedian:" << param_2 << std::endl;
                    result[i] = param_2;
                }
            }
        }
        delete obj;
        obj = nullptr;

        std::cout << "result:" << std::boolalpha << std::endl;
        solution.printvector(result);

        if(result[3] == expec_1 && result[5] == expec_2)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            solution.printtuple(expected);
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

void Test0()
{
    std::vector<std::string> operators = {"MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"};
    std::vector<int> nums = {{}, {1}, {2}, {}, {3}, {}};
    auto expected = std::make_tuple("null", "null","null", 1.5, "null", 2.0);
    Test("Test0", operators, nums, expected);
}
void Test1()
{
    std::vector<std::string> operators = {"MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"};
    std::vector<int> nums = {{}, {3}, {2}, {}, {1}, {}};
    auto expected = std::make_tuple("null", "null","null", 2.5, "null", 2.0);
    Test("Test1", operators, nums, expected);
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main()
{
    Test0();
    Test1();

    return 0;
}

    template<int n,typename T>
    class tuple_print_helper {
    public:
    	tuple_print_helper(T t) {
    		tuple_print_helper<n - 1, T> tp(t);
            std::cout << ",";
    		tuple_print(std::get<n - 1>(t));
    	}
    };
    template<typename T>
    class tuple_print_helper<0, T>
    {
    public:
    	tuple_print_helper(T t){}
    };
    template<typename T>
    class tuple_print_helper<1, T>
    {
    public:
    	tuple_print_helper(T t) {
            std::cout << "(";
    		tuple_print(std::get<0>(t));
    	}
    };
   
    template<typename T>
    void tuple_print(T t)
    {
    	tuple_print_helper<std::tuple_size<T>::value, T> tph(t);
        std::cout << ")";
    }
    template<>
    void tuple_print<int>(int t)
    {
        std::cout << t;
    }
   
    template<>
    void tuple_print<double>(double t) {
        std::cout << t;
    }
   
    template<>
    void tuple_print<char>(char t) {
        std::cout << t;
    }
    template<>
    void tuple_print<bool>(bool t) {
        std::cout << t;
    }
   
    template<>
    void tuple_print<const char *>(const char* t) {
        std::cout << t;
    }
   
    template<>
    void tuple_print<std::string>(std::string t) {
        std::cout << t;
    }
