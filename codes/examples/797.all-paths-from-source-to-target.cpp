/*
 ******************************************************************************
 *  797. All Paths From Source to Target
 ******************************************************************************
 * Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
 *
 * The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
 ******************************************************************************
 * Example 1:
 *
 *
 * Input: graph = [[1,2],[3],[3],[]]
 * Output: [[0,1,3],[0,2,3]]
 * Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 ******************************************************************************
 * Example 2:
 *
 *
 * Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
 * Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 ******************************************************************************
 * Constraints:
 *
 * n == graph.length
 * 2 <= n <= 15
 * 0 <= graph[i][j] < n
 * graph[i][j] != i (i.e., there will be no self-loops).
 * All the elements of graph[i] are unique.
 * The input graph is guaranteed to be a DAG.
 ******************************************************************************
 */

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
class Solution {
public:
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
        std::vector<int> path;
        std::vector<std::vector<int>> res;
        int size = graph.size();
        auto dfs = [&](auto&& dfs, int start) {
            if (start == size-1) {
                res.push_back(path);
                return;
            }
            //
            int currsize = graph[start].size();
            for (int i = 0; i < currsize; ++i) {
                path.push_back(graph[start][i]);
                dfs(dfs, graph[start][i]);
                path.pop_back();
            }
        };
        path.push_back(0);
        dfs(dfs, 0);
        return res;
    }
};

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<std::vector<int>>& graph,
        std::vector<std::vector<int>> expected
        )
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.allPathsSourceTarget(graph);
        std::cout << "result:" << result << std::endl;

        if(result == expected)
        {
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
    }
}
void Test1()
{
    std::vector<std::vector<int>> graph = {{1,2},{3},{3},{}};
    std::vector<std::vector<int>> expected = {{0,1,3},{0,2,3}};
    Test("Test1", graph, expected);
}
void Test2()
{
    std::vector<std::vector<int>> graph ={{4,3,1},{3,2,4},{3},{4},{}};
    std::vector<std::vector<int>> expected = {{0,4},{0,3,4},{0,1,3,4},{0,1,2,3,4},{0,1,4}};
    Test("Test2", graph, expected);
}

void Test3()
{
}

void Test4()
{
}

void Test5()
{
}

// 27yy
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
int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
