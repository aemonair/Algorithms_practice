/*
 ************************************************************
 * 113. Path Sum II
 * Medium
 ************************************************************
 * Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.
 * A leaf is a node with no children.
 ************************************************************
 * Example 1:
 *          5
 *         / \
 *        4   8
 *       /   / \
 *      11  13  4
 *     / \     / \
 *    7   2   5   1
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: [[5,4,11,2],[5,8,4,5]]
 ************************************************************
 * Example 2:
 *
 *      1
 *     / \
 *    2   3
 * Input: root = [1,2,3], targetSum = 5
 * Output: []
 ************************************************************
 * Example 3:
 *
 *      1
 *     /
 *    2
 * Input: root = [1,2], targetSum = 0
 * Output: []
 *
 ************************************************************
 * Constraints:
 *
 * The number of nodes in the tree is in the range [0, 5000].
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
 ************************************************************
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
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
    std::vector<std::vector<int>>  pathSum(TreeNode* root, int targetSum)
    {
        std::vector<std::vector<int>> result;
        return result;
    }
    std::vector<std::vector<int>>  pathSum1(TreeNode* root, int targetSum)
    {
        std::vector<std::vector<int>> result;
        return result;
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
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        TreeNode *root,
        int targetSum,
        std::vector<std::vector<int>>  expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "find targetSum:" << targetSum << " ";
    solution.printtree(root);
const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;

    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.pathSum(root, targetSum);
        std::cout << "result:" << std::boolalpha << std::endl;
        solution.printvectorvector(result);

        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            solution.printvectorvector(expected);
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

        decltype(expected) result = solution.pathSum1(root, targetSum);
        std::cout << "result:" << std::boolalpha << std::endl;
        solution.printvectorvector(result);

        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << std::endl;
            solution.printvectorvector(expected);
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
    std::vector<std::vector<int>> expected = {};
    Test("Test0", nullptr, 0, expected);
}
void Test1()
{
    std::cout << "      3         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   9     20     " << std::endl;
    std::cout << "         / \\   " << std::endl;
    std::cout << "       15   7   " << std::endl;
    TreeNode * pnode3 = new TreeNode(3);
    TreeNode * pnode9 = new TreeNode(9);
    TreeNode * pnode20= new TreeNode(20);
    TreeNode * pnode15= new TreeNode(15);
    TreeNode * pnode7 = new TreeNode(7);
    pnode3 ->left  = pnode9 ;
    pnode3 ->right = pnode20;
    pnode20->left  = pnode15;
    pnode20->right = pnode7 ;

    std::vector<std::vector<int>> expected = {};

    Test("Test1", pnode3, 25, expected);
}
void Test2()
{
    // [2,null,3,null,4,null,5,null,6]
    //    2
    //   n  3
    //      n 4
    //       n 5
    //         n 6
    std::cout << "      2           " << std::endl;
    std::cout << "        \\        " << std::endl;
    std::cout << "         3        " << std::endl;
    std::cout << "           \\     " << std::endl;
    std::cout << "            4     " << std::endl;
    std::cout << "             \\   " << std::endl;
    std::cout << "              5   " << std::endl;
    std::cout << "               \\ " << std::endl;
    std::cout << "                6 " << std::endl;
    TreeNode * pnode6 = new TreeNode(6);
    TreeNode * pnode5 = new TreeNode(5, nullptr, pnode6);
    TreeNode * pnode4 = new TreeNode(4, nullptr, pnode5);
    TreeNode * pnode3 = new TreeNode(3, nullptr, pnode4);
    TreeNode * pnode2 = new TreeNode(2, nullptr, pnode3);
    std::vector<std::vector<int>> expected = {};
    Test("Test2", pnode2, 34, expected);
}

void Test3()
{
    std::cout << "      1         " << std::endl;
    std::cout << "        \\      " << std::endl;
    std::cout << "         2      " << std::endl;
    std::cout << "         / \\   " << std::endl;
    std::cout << "        3   4   " << std::endl;
    std::cout << "           /    " << std::endl;
    std::cout << "          5     " << std::endl;
    TreeNode * pnode1 = new TreeNode(1);
    TreeNode * pnode2 = new TreeNode(2);
    TreeNode * pnode3 = new TreeNode(3);
    TreeNode * pnode4 = new TreeNode(4);
    TreeNode * pnode5 = new TreeNode(5);

    //    1
    //     2
    //    3  4
    //      5
    //      
    pnode1->right  = pnode2;
    pnode2->left   = pnode3;
    pnode2->right  = pnode4;
    pnode4->left   = pnode5;
    std::vector<std::vector<int>> expected = {{1,2,4,5}};
    Test("Test3", pnode1, 12, expected);
}

void Test4()
{
    //Test("Test4", 6, 6, 3);
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    std::cout << " /   \\  / \\   " << std::endl;
    std::cout << "4     5 6   7   " << std::endl;

    TreeNode * p7 = new TreeNode(7);
    TreeNode * p6 = new TreeNode(6);
    TreeNode * p5 = new TreeNode(5);
    TreeNode * p4 = new TreeNode(4);
    TreeNode * p3 = new TreeNode(3, p6, p7);
    TreeNode * p2 = new TreeNode(2, p4, p5);
    TreeNode * p1 = new TreeNode(1, p2, p3);

    std::vector<std::vector<int>> expected = {};
    Test("Test1", p1, 23, expected);
}
void Test5()
{
    //Test("Test4", 6, 6, 3);
    std::cout << "      12        " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   7     1      " << std::endl;
    std::cout << " /       / \\   " << std::endl;
    std::cout << "9       10  5   " << std::endl;

    struct TreeNode * p9 = new TreeNode(9 );
    struct TreeNode * p5 = new TreeNode(5 );
    struct TreeNode * p10= new TreeNode(10);
    struct TreeNode * p7 = new TreeNode(7, p9, nullptr);
    struct TreeNode * p1 = new TreeNode(1, p10, p5);
    struct TreeNode * p12= new TreeNode(12,p7 , p1);
    std::vector<std::vector<int>> expected = {{12,1,10}};
    Test("Test2", p12, 23,  expected );
}
void Test6()
{
    std::cout << "      5         " << std::endl;
    std::cout << "     / \\       " << std::endl;
    std::cout << "    4   8       " << std::endl;
    std::cout << "   /   / \\     " << std::endl;
    std::cout << "  11  13  4     " << std::endl;
    std::cout << " / \\    / \\   " << std::endl;
    std::cout << "7   2   5   1   " << std::endl;

    struct TreeNode * p7 = new TreeNode(7 );
    struct TreeNode * p2 = new TreeNode(2 );
    struct TreeNode * p_5= new TreeNode(5 );
    struct TreeNode * p1 = new TreeNode(1 );
    struct TreeNode * p13= new TreeNode(13);
    struct TreeNode * p11= new TreeNode(11, p7, p2);
    struct TreeNode * p4 = new TreeNode(4 , p_5, p1);
    struct TreeNode * p_4= new TreeNode(4 , p11, nullptr);
    struct TreeNode * p8 = new TreeNode(8, p13, p4 );
    struct TreeNode * p5 = new TreeNode(5 ,p_4, p8);
    std::vector<std::vector<int>> expected = {{5,4,11,2},{5,8,4,5}};
    Test("Test2", p5, 22,  expected );
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

    return 0;

}
