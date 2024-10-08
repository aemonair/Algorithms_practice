/*
 ************************************************************
 * 95. Unique Binary Search Trees II
 * Medium
 ************************************************************
 * Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
 ************************************************************
 * Example 1:
 *      1       1          2          3       3
 *       \       \       /   \       /       /
 *        3       2     1     3     2       1
 *       /         \               /         \
 *      2           3             1            2
 *
 * Input: n = 3
 * Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 ************************************************************
 * Example 2:
 *
 * Input: n = 1
 * Output: [[1]]
 ************************************************************
 * Constraints:
 *
 * 1 <= n <= 8
 ************************************************************
 *
 *     -10
 *     /  \
 *    9    20
 *        / \
 *       15  7
 *
 ************************************************************
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
    std::vector<TreeNode*> generateTrees(int n)
    {
        return {};
    }
    std::vector<TreeNode*> generateTrees1(int n)
    {
        return std::vector<TreeNode *>{};
    }
};
bool isSimilar(TreeNode *r1, TreeNode *r2)
{
    if(r1==nullptr && r2 == nullptr)
    {
        return true;
    }
    if(r1 ==nullptr || r2 == nullptr)
    {
        return false;
    }
    if(r1->val != r2->val )
    {
        return false;
    }
    return isSimilar(r1->left, r2->left) && isSimilar(r1->right, r2->right);
}
bool isSimilar(std::vector<TreeNode*>& v1,std::vector<TreeNode*> &v2)
{
    int size = v1.size();
    if(size != v2.size())
    {
        return false;
    }
    for(int i = 0; i< size; i++)
    {
        if(isSimilar(v1[i], v2[i]) == false)
        {
            return false;
        }
    }
    return true;
}

// ==================== TEST Codes====================
void Test(const std::string& testName,
        int n,
        std::vector<TreeNode *> expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 0;

    if(TEST__)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.generateTrees(n);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(isSimilar(result ,expected))
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
    if(TEST_1)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.generateTrees1(n);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(isSimilar(result ,expected))
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
std::ostream & operator << (std::ostream &out, TreeNode *root)
{
    if (root == nullptr) {
        out << "N" << ",";
        return out;
    }
    out << root->val << ",";
    out << (root->left) ;
    out << (root->right);
    return out;
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
    TreeNode * pnode2 = new TreeNode(2);
    TreeNode * pnode1 = new TreeNode(1, nullptr, pnode2);

    TreeNode * p_node1 = new TreeNode(1);
    TreeNode * p_node2 = new TreeNode(2, p_node1, nullptr);
    std::vector<TreeNode *> expected = {pnode1, p_node2};
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
    TreeNode * p1node3 = new TreeNode(3);
    TreeNode * p1node2 = new TreeNode(2, nullptr, p1node3);
    TreeNode * p1node1 = new TreeNode(1, nullptr, p1node2);

    TreeNode * p2node2 = new TreeNode(2);
    TreeNode * p2node3 = new TreeNode(3, p2node2, nullptr);
    TreeNode * p2node1 = new TreeNode(1, nullptr, p2node3);

    TreeNode * p3node1 = new TreeNode(1);
    TreeNode * p3node3 = new TreeNode(3);
    TreeNode * p3node2 = new TreeNode(2, p3node1, p3node3);

    TreeNode * p4node2 = new TreeNode(2);
    TreeNode * p4node1 = new TreeNode(1, nullptr, p4node2);
    TreeNode * p4node3 = new TreeNode(3, p4node1, nullptr);

    TreeNode * p5node1 = new TreeNode(1);
    TreeNode * p5node2 = new TreeNode(2, p5node1, nullptr);
    TreeNode * p5node3 = new TreeNode(3, p5node2, nullptr);

    std::vector<TreeNode *> expected = {p1node1, p2node1, p3node2, p4node3, p5node3};

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
