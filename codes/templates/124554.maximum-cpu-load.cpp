/*
 ******************************************************************
 * 124554. Maximum CPU Load
 ******************************************************************
 * We are given a list of Jobs. Each job has a Start time, an End time, and a CPU load when it is running. Our goal is to find the maximum CPU load at any time if all the jobs are running on the same machine.
 ******************************************************************
 * Example 1:
 *
 * Input:
 * [[1,4,3], [2,5,4], [7,9,6]]
 * Output: 7
 * Explanation:
 * Since [1,4,3] and [2,5,4] overlap, their maximum CPU load (3+4=7) will be when both the jobs are running at the same time i.e., during the time interval (2,4).
 * 1_2_3_4_5_6_7_8_9_
 * ___3__
 *   ___4__
 *             __6_
 ******************************************************************
 * Example 2:
 *
 * Input:
 * [[6,7,10], [2,4,11], [8,12,15]]
 *
 * Output: 15
 * Explanation: None of the jobs overlap, therefore we will take the maximum load of any job which is 15.
 *
 * 1_2_3_4_5_6_7_8_9_A_B_C_D_E_F
 *           _10_
 *   _11_
 *               __15____
 ***************************************************************
 * Example 3:
 * Jobs: [[1,4,2], [2,4,1], [3,6,5]]
 * Output: 8
 * Explanation:
 * Maximum CPU load will be 8 as all jobs overlap during the time interval [3,4].
 * 1_2_3_4_5_6_7_8_9_
 * ___2__
 *   _1__
 *     __5___
 ******************************************************************
 *
 */

// 44 yy
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <climits>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define     RESET   "\033[0m"
#define     RED     "\033[31m"             /*      Red     */
#define     CYAN    "\033[36m"             /*      Cyan    */
#define     BLUE    "\033[34m"             /*      Blue    */
#define     GREEN   "\033[32m"             /*      Green   */
#define     WHITE   "\033[37m"             /*      White   */
#define     BLACK   "\033[30m"             /*      Black   */
#define     YELLOW  "\033[33m"             /*      Yellow  */
#define     MAGENTA "\033[35m"             /*      Magenta */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow  */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black   */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White   */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green   */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue    */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan    */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red     */

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

class Job
{
public:
    int start   = 0;
    int end     = 0;
    int cpuload = 0;
    Job(int start, int end, int cpuload)
    {
        this->start   = start  ;
        this->end     = end    ;
        this->cpuload = cpuload;
    }
    friend std::ostream & operator << (std::ostream &out, Job &job)
    {
        std::cout << "[" << job.start << ", "<< job.end << " ," << job.cpuload << "] " ;
    }
};

class Solution {
public:
    int findMaxCPULoad(std::vector<Job>& jobs)
    {
        return 0;
    }
    int findMaxCPULoad1(std::vector<Job>& jobs)
    {
        return 0;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
          std::vector<Job>& jobs,
          int  expected)
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "jobs:" << jobs << std::endl;
const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.findMaxCPULoad(jobs);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if (TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.findMaxCPULoad1(jobs);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
}
// 76 yy
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
//std::ostream & operator << (std::ostream &out, Job &job)
//{
//    std::cout << "[" << job.start << ", "<< job.end << " ," << job.cpuload << "], " ;
//}

void Test1()
{
    std::vector<Job> jobs  = {{1,4,3},{2,5,4},{7,8,6}};
    int         result     = 7;
    Test("Test1", jobs, result);
}

void Test2()
{
    std::vector<Job> jobs  = {{6,7,10},{2,4,11},{8,12,15}};
    int         result     = 15;
    Test("Test2", jobs, result);
}

void Test3()
{
    std::vector<Job> jobs  = {{1,4,2},{2,4,1},{3,6,5}};
    int         result     = 8;
    Test("Test3", jobs, result);
}

void Test4()
{
}

void Test5()
{
}

void Test6()
{
}

void Test7()
{
}


int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;

}
