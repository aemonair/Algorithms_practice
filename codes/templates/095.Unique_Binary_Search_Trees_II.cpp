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
 
class Solution {
public:
    // 
    std::vector<TreeNode*> generateTrees(int n)
    {
        return std::vector<TreeNode *>{};
    }
    std::vector<TreeNode*> generateTrees1(int n)
    {
        return std::vector<TreeNode *>{};
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
        std::stack<T> tmp(s);
        while (!tmp.empty())
        {
            std::cout << tmp.top() << ", ";
            tmp.pop();
        }
        std::cout <<  std::endl;
        return tmp.size();
    }
    int printstack(std::stack<std::pair <TreeNode *, int>> s)
    {
        if (s.empty())
        {
            std::cout << "The TreeNode pair stack is empty." << std::endl;
            return 0;
        }
        std::cout <<  "The TreeNode stack size is: " << s.size() << std::endl;
        std::stack<std::pair<TreeNode *, int>> tmp(s);
        while (!tmp.empty())
        {
            std::cout << "(" << (tmp.top()).first->val << ", " << tmp.top().second << ");";
            tmp.pop();
        }
        std::cout << "\b]" << std::endl;
        return tmp.size();
    }

    template <typename T>
    int printdeque(const std::deque<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  " ;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", "; //<<std::endl;
        }
        std::cout << "\b\b]" << std::endl;
        return v.size();
    }
    int printdeque(const std::deque<TreeNode *> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  " ;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << (*iter) ->val << ", "; //<<std::endl;
        }
        std::cout << "\b\b]" << std::endl;
        return v.size();
    }
    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  " ;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", "; //<<std::endl;
        }
        std::cout << "\b\b]" << std::endl;
        return v.size();
    }
    int printvector(const std::vector<TreeNode *> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  " ;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printtree(*iter) ;
        }
        std::cout << "\b\b]" << std::endl;
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
    int printtree  (const TreeNode * root)
    {
        if (root==nullptr)
        {
            std::cout << "null tree. " << std::endl;
            return 0;
        }
        std::cout << "root->val: " << root->val << std::endl;
        printtreenode(root);
        std::cout << std::endl;
        return 0;
    }
    int printtreenode (const TreeNode * root)
    {
        if(root==nullptr)
        {
            std::cout << "N" << ",";
        }
        else
        {
            std::cout << root->val << ",";
            printtreenode(root->left);
            printtreenode(root->right);
        }
        return 0;
    }
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
};

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
const static int TEST_0    = 1;
const static int TEST_1    = 0;

    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.generateTrees(n);
        std::cout << "result:" << std::boolalpha << std::endl;
        solution.printvector(result);

        if(solution.isSimilar(result ,expected))
        //if(result == expected)
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

        decltype(expected) result = solution.generateTrees1(n);
        std::cout << "result:" << std::boolalpha << std::endl;
        solution.printvector(result);

        //if(result == expected)
        if(solution.isSimilar(result ,expected))
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
    Solution solution;

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
