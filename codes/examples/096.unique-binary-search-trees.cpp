/*
 ************************************************************
 * 96. Unique Binary Search Trees
 * Medium
 ************************************************************
 * Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
 ************************************************************
 * Example 1:
 *      1       1          2          3       3
 *       \       \       /   \       /       /
 *        3       2     1     3     2       1
 *       /         \               /         \
 *      2           3             1            2
 * Input: n = 3
 * Output: 5
 ************************************************************
 * Example 2:
 *
 * Input: n = 1
 * Output: 1
 ************************************************************
 * Constraints:
 *
 * 1 <= n <= 19
 *
 ************************************************************
 */

#include <unordered_map>
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
/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);
std::ostream & operator << (std::ostream &out, TreeNode *root);

class Solution {
public:
    int numTrees(int left, int right) {
        int res = 0;
        if (left > right) {
            return 0;
        }
        if (left == right) {
            return 1;
        }
        for (int i = left; i <= right; ++i) {
            auto leftres = numTrees(left, i-1);
            auto rightres = numTrees(i+1, right);
            if (leftres * rightres) {
                res += leftres * rightres;
            } else if (leftres) {
                res += leftres;
            } else if (rightres) {
                res += rightres;
            }
        }
        return res;
    }
    int numTrees(int n)
    {
        return numTrees(1, n);
        return 0;
    }
    std::unordered_map<int,int>umap;
    int numTrees1(int n)
    {
        int res = 0;
        if (n <= 1) {
            return 1;
        }
        if (umap.count(n) ) {
            return umap[n];
        }
        for(int i=1; i<= n; ++i) {
            auto left = numTrees1(i-1);
            auto right= numTrees1(n-i);
            res += left * right;
        }
        umap[n] = res;
        return res;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        int n,
        int expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }
    std::cout << "n:" << n << std::endl;

    Solution solution;

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

        decltype(expected) result = solution.numTrees(n);
        std::cout << "result:" << std::boolalpha << result << std::endl;

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

        decltype(expected) result = solution.numTrees1(n);
        std::cout << "result:" << std::boolalpha << result << std::endl;

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

void Test0()
{
}
void Test1()
{
    int n = 2;
    std::cout << "      1        2" << std::endl;
    std::cout << "        \\    / " << std::endl;
    std::cout << "         2  1   " << std::endl;
    //TreeNode * pnode2 = new TreeNode(2);
    //TreeNode * pnode1 = new TreeNode(1, nullptr, pnode2);

    //TreeNode * p_node1 = new TreeNode(1);
    //TreeNode * p_node2 = new TreeNode(2, p_node1, nullptr);
    int expected = 2;
    Test("Test1", n, expected);
}
void Test2()
{
    int n = 3;
    std::cout << "   1       1          2         3        3         " << std::endl;
    std::cout << "    \\       \\       /   \\      /       /           " << std::endl;
    std::cout << "     2       3     1     3    1       2            " << std::endl;
    std::cout << "      \\     /                  \\    /             " << std::endl;
    std::cout << "       3   2                    2  1              " << std::endl;
    // TreeNode * p1node3 = new TreeNode(3);
    // TreeNode * p1node2 = new TreeNode(2, nullptr, p1node3);
    // TreeNode * p1node1 = new TreeNode(1, nullptr, p1node2);

    // TreeNode * p2node2 = new TreeNode(2);
    // TreeNode * p2node3 = new TreeNode(3, p2node2, nullptr);
    // TreeNode * p2node1 = new TreeNode(1, nullptr, p2node3);

    // TreeNode * p3node1 = new TreeNode(1);
    // TreeNode * p3node3 = new TreeNode(3);
    // TreeNode * p3node2 = new TreeNode(2, p3node1, p3node3);

    // TreeNode * p4node2 = new TreeNode(2);
    // TreeNode * p4node1 = new TreeNode(1, nullptr, p4node2);
    // TreeNode * p4node3 = new TreeNode(3, p4node1, nullptr);

    // TreeNode * p5node1 = new TreeNode(1);
    // TreeNode * p5node2 = new TreeNode(2, p5node1, nullptr);
    // TreeNode * p5node3 = new TreeNode(3, p5node2, nullptr);

    int expected = 5;

    Test("Test2", n, expected);
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
void Test6()
{
}
void Test7()
{
}
void Test8()
{
}
int main()
{

    Test0();
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();

    return 0;

}
