/*
 **********************************************************************
 * Topological Sort of a directed graph (a graph with unidirectional edges) is a linear ordering of its vertices such that for every directed edge (U, V) from vertex U to vertex V, U comes before V in the ordering.
 * 
 * Given a directed graph, find the topological ordering of its vertices.
 **********************************************************************
 * 
 * Example 1:
 * 
 * Input: Vertices=4, Edges=[3, 2], [3, 0], [2, 0], [2, 1]
 * Output: Following are the two valid topological sorts for the given graph:
 * 1) 3, 2, 0, 1
 * 2) 3, 2, 1, 0
 *      3  
 *      | \
 *      |  2  
 *      |/   \
 *      0     1  
 **********************************************************************
 * Example 2:
 * 
 * Input: Vertices=5, Edges=[4, 2], [4, 3], [2, 0], [2, 1], [3, 1]
 * Output: Following are all valid topological sorts for the given graph:
 * 1) 4, 2, 3, 0, 1
 * 2) 4, 3, 2, 0, 1
 * 3) 4, 3, 2, 1, 0
 * 4) 4, 2, 3, 1, 0
 * 5) 4, 2, 0, 3, 1
 *   4  
 *   | \
 *   2  3
 *   | \|
 *   0  1
 **********************************************************************
 * Example 3:
 * 
 * Input: Vertices=7, Edges=[6, 4], [6, 2], [5, 3], [5, 4], [3, 0], [3, 1], [3, 2], [4, 1]
 * Output: Following are all valid topological sorts for the given graph:
 * 1) 5, 6, 3, 4, 0, 1, 2
 * 2) 6, 5, 3, 4, 0, 1, 2
 * 3) 5, 6, 4, 3, 0, 2, 1
 * 4) 6, 5, 4, 3, 0, 1, 2
 * 5) 5, 6, 3, 4, 0, 2, 1
 * 6) 5, 6, 3, 4, 1, 2, 0
 *     5        6
 *     |  \   / |
 *     3    4   |
 *     | \/\    |
 *     0 1      2
 *
 * There are other valid topological ordering of the graph too.
 ******************************************************************* 
 */

#include <unordered_map>
#include <algorithm>
#include <iostream>
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

class TopologicalSort{
public:
    std::vector<int> sort(int vertices, std::vector<std::vector<int>>& edges) 
    {
        //return {};
        std::vector<int> sortedOrder;
        if(vertices <=0 )
        {
            return {};
        }
        std::unordered_map<int, int> inDegree;
        std::unordered_map<int, std::vector<int>> graph;
        for(int i =0; i< vertices; i++)
        {
            inDegree[i]=0;
            graph[i] = std::vector<int>();
        }
        for(int i =0; i < edges.size(); i++)
        {
            int parent = edges[i][0];
            int child  = edges[i][1];
            graph[parent].push_back(child);
            inDegree[child]++;
        }
        std::queue<int> sources;
        for(auto entry: inDegree)
        {
            if(entry.second == 0)
            {
                sources.push(entry.first);
            }
        }
        while(!sources.empty())
        {
            int vertex = sources.front();
            sources.pop();
            sortedOrder.push_back(vertex);
            std::vector<int> children = graph[vertex];
            for(auto child: children)
            {
                inDegree[child]--;
                if(inDegree[child] == 0)
                {
                    sources.push(child);
                }
            }
        }
        if(sortedOrder.size() != vertices)
        {
            return {};
        }
        return sortedOrder;
    }
    //////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////
};
class Graph
{
    int V;
    std::list<int> * adj;
    void topologicalSortUtil(int v, bool visited[], std::stack<int> &Stack);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
                                std::stack<int>& Stack)
{
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices
    // adjacent to this vertex
    std::list<int>::iterator i;
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    // Push current vertex to stack
    // which stores result
    Stack.push(v);
}

// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
    std::stack<int> Stack;

    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false) {
        std::cout << Stack.top() << " ";
        Stack.pop();
    }
}
template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

template<typename T>
int printvector(std::vector<T> v);

/*
template<class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& val);
*/

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        std::vector<std::vector<int>>& edges,
        int vertices,
        std::vector<std::vector<int>> expected)
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    TopologicalSort toplogicsort;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "edges:";
    printvector(edges);
    // getpermutataion
const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        auto result = toplogicsort.sort(vertices, edges);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(find(expected.begin(), expected.end(), result)!=expected.end())
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
    }
    if(TEST_1)
    {
    }
}

void Test1()
{
    std::vector<std::vector<int>> edges= {
        {3, 2}, {3, 0}, {2, 0}, {2, 1}
    }; 
    int vertices = 4;
    std::vector<std::vector<int>> expected = {
        {3, 2, 0, 1},
        {3, 2, 1, 0}
    };
    Test("Test1", edges, vertices, expected);
}

void Test2()
{
    std::vector<std::vector<int>> edges= {
        {4, 2}, {4, 3}, {2, 0}, {2, 1}, {3, 1}
    }; 
    int vertices = 5;
    std::vector<std::vector<int>> expected = {
        { 4, 2, 3, 0, 1},
        { 4, 3, 2, 0, 1},
        { 4, 3, 2, 1, 0},
        { 4, 2, 3, 1, 0},
        { 4, 2, 0, 3, 1}
    };
    Test("Test2", edges, vertices, expected);
}

void Test3()
{
    std::vector<std::vector<int>> edges= {
        {6, 4}, {6, 2}, {5, 3}, {5, 4}, {3, 0}, {3, 1}, {3, 2}, {4, 1}
    }; 
    int vertices = 7;
    std::vector<std::vector<int>> expected = {
        {5, 6, 3, 4, 0, 1, 2},
        {6, 5, 3, 4, 0, 1, 2},
        {5, 6, 4, 3, 0, 2, 1},
        {6, 5, 4, 3, 0, 1, 2},
        {5, 6, 3, 4, 0, 2, 1},
        {6, 5, 3, 4, 0, 2, 1},
        {5, 6, 3, 4, 1, 2, 0}
    };
    Test("Test3", edges, vertices, expected);
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
template<typename T>
int printvector(std::vector<T> v)
{
    if(0 == v.size())
    {
        std::cout << "Empty vector." << std::endl;
        return 0;
    }
    std::cout << "[ " ;
    for(auto i: v)
    {
        std::cout << i << ", ";
    }
    std::cout << "\b\b ]" << std::endl;
    return v.size();
}
/*
template<class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& val)
{
    while(first != last)
    {
        if(*first == val)
        {
            return first;
        }
        ++first;
    }
    return last;
}
*/
