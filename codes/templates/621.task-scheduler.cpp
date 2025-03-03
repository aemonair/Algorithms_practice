/*
 ********************************************************************************************
 * 621. Task Scheduler
 * Medium
 ********************************************************************************************
 * Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
 *
 * However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
 *
 * Return the least number of units of times that the CPU will take to finish all the given tasks.
 ********************************************************************************************
 * Example 1:
 *
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation:
 * A -> B -> idle -> A -> B -> idle -> A -> B
 * There is at least 2 units of time between any two same tasks.
 ********************************************************************************************
 * Example 2:
 *
 * Input: tasks = ["A","A","A","B","B","B"], n = 0
 * Output: 6
 * Explanation: On this case any permutation of size 6 would work since n = 0.
 * ["A","A","A","B","B","B"]
 * ["A","B","A","B","A","B"]
 * ["B","B","B","A","A","A"]
 * ...
 * And so on.
 ********************************************************************************************
 * Example 3:
 *
 * Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
 * Output: 16
 * Explanation:
 * One possible solution is
 * A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 ********************************************************************************************
 * Constraints:
 *
 * 1 <= task.length <= 10^4
 * tasks[i] is upper-case English letter.
 * The integer n is in the range [0, 100].
 ********************************************************************************************
 */

#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <chrono>
#include <queue>
#include <iostream>
#include <unordered_map>

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
template <typename T1, typename T2>
std::ostream & operator << (std::ostream &out, std::pair <T1,T2> pair)
{
    out << "{" << pair.first << " ," << pair.second << "}, " ;
    return out;
}

template <typename ...T>
std::ostream & operator << (std::ostream &out, std::queue<T... > queue)
{
    std::queue<T...> _queue = queue;
    int bsize = _queue.size();
    if (_queue.empty())
    {
        out << "The big queue is empty. "<< std::endl;
    }
    out << "<< ";
    while (bsize--)
    {
        out <<  _queue.front();
        _queue.pop();
    }
    out << std::endl ;
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
        out << " " << Big_queue.top() << " " ;
        Big_queue.pop();
    }
    out << std::endl ;
    return out;
}
///////////////////////////////////////////////////////////////
class Solution {
public:
///////////////////////////////////////////////////////////////
    int leastInterval(std::vector<char>& tasks, int n)
    {
        return 0;
    }
    int leastInterval1(std::vector<char>& tasks, int n)
    {
        return 0;
    }
///////////////////////////////////////////////////////////////
};
// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<char>& tasks,
        int n,
        int expected
        )
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "n:" << n << ",tasks:" << tasks << std::endl;

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    // getpermutataion
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.leastInterval(tasks, n);
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
    if (TEST_1)
    {
    }
}
void Test1()
{
    std::vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    int expect = 8;
    Test("Test1.1", tasks, n, expect);
    n = 0;
    expect = 6;
    Test("Test1.2", tasks, n, expect);
}
void Test2()
{
    std::vector<char> tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'};
    int n = 2;
    int expect = 16;
    Test("Test2", tasks, n, expect);
}

void Test3()
{
    std::vector<char> tasks = {'a', 'a', 'a', 'b', 'c', 'c'};
    int n = 2;
    int expect = 7;
    Test("Test3", tasks, n, expect);
}

void Test4()
{
    std::vector<char> tasks = {'a', 'b', 'a'};
    int n = 3;
    int expect = 5;
    Test("Test4", tasks, n, expect);
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

