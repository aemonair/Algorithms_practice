/*
 * 130. Surrounded Regions
 * Medium
 *********************************************
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *********************************************
 *
 * Example:
 *
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * After running your function, the board should be:
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *********************************************
 * Explanation:
 *
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
 * Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.
 * Two cells are connected if they are adjacent cells connected horizontally or vertically.
 *
 *********************************************
 */

#include <stack>
#include <queue>
#include <chrono>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <algorithm>

class UF{
private:
    // 记录连通分量
    int _count;
    // 节点 x 的节点是 parent[x]
    //int[] parent;
    std::vector<int> parent;
    std::vector<int> size;
public:
    /* 构造函数，n 为图的节点总数 */
    UF(int n)
    {
        // 一开始互不连通
        this->_count = n;
        // 父节点指针初始指向自己
        //parent = new int[n];
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = i;
        }
    }
    void Union1(int p, int q)
    {
        int rootP = find1(p);
        int rootQ = find1(q);
        if (rootP == rootQ)
            return;
        // 将两棵树合并为一棵
        parent[rootP] = rootQ;
        // parent[rootQ] = rootP 也一样
        _count--; // 两个分量合二为一
    }
    void Union2(int p, int q)
    {
        int rootP = find2(p);
        int rootQ = find2(q);
        if (rootP == rootQ)
            return;

        // 小树接到大树下面，较平衡
        if (size[rootP] > size[rootQ])
        {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else
        {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        _count--;
    }
   
    /* 返回某个节点 x 的根节点 */
    int find1(int x)
    {
        // 根节点的 parent[x] == x
        while (parent[x] != x)
        {
            x = parent[x];
        }
        return x;
    }
   
    int find2(int x)
    {
        while (parent[x] != x)
        {
            // 进行路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    /* 返回当前的连通分量个数 */
    int count()
    {
        return _count;
    }
    bool connected(int p, int q)
    {
        int rootP = find2(p);
        int rootQ = find2(q);
        return rootP == rootQ;
    }
};

class Solution {
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

/////////////////////////////////////////////////////////////
//https://leetcode.com/problems/surrounded-regions/discuss/691675/C%2B%2B-Beginner-Friendly-or-Boundary-DFS-or-inPlace
    void DFS(std::vector<std::vector<char>> &board, int i, int j ,int m, int n)
    {
    }
    void solve_dfs(std::vector<std::vector<char>>& board)
    {
    }
    void solve_uf(std::vector<std::vector<char>>& board)
    {
    }
/////////////////////////////////////////////////////////////

};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        std::vector<std::vector<char>> &board,
        std::vector<std::vector<char>> &expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printvectorvector(board);
    // getpermutataion
const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        auto temp1(board);
        solution.solve_uf(temp1);
        std::cout << "solve_uf result:" << std::boolalpha << std::endl;
        solution.printvectorvector(temp1);

        if(temp1 == expected)
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        auto temp1(board);
        solution.solve_dfs(temp1);
        std::cout << "solve_dfs result:" << std::boolalpha << std::endl;
        solution.printvectorvector(temp1);

        if(temp1 == expected)
            std::cout << "Solution1 passed." << std::endl;
        else
            std::cout << "Solution1 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    std::cout << "---------------------------------------------------" << std::endl;
}

void Test1()
{
    std::vector<std::vector<char>> boards  = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    std::vector<std::vector<char>> result =
    {
        {'X','X','X','X'},
        {'X','X','X','X'},
        {'X','X','X','X'},
        {'X','O','X','X'}
    };
    Test("Test1", boards, result);
}

void Test2()
{
    std::vector<std::vector<char>> boards  = {
        {'X','X','X','X'},
        {'O','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    std::vector<std::vector<char>> result =
    {
        {'X','X','X','X'},
        {'O','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    Test("Test1", boards, result);
}

void Test3()
{
}

void Test4()
{
}

int main()
{
    Solution solution;

    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
