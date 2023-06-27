/*
 ************************************************************
 * 124. Binary Tree Maximum Path Sum
 * Hard
 ************************************************************
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
 *
 * The path sum of a path is the sum of the node's values in the path.
 *
 * Given the root of a binary tree, return the maximum path sum of any path.
 ************************************************************
 * Example 1:
 *
 *      1
 *     / \
 *    2   3
 *
 * Input: root = [1,2,3]
 * Output: 6
 * Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
 ************************************************************
 * Example 2:
 *
 *     -10
 *     /  \
 *    9    20
 *        / \
 *       15  7
 *
 * Input: root = [-10,9,20,null,null,15,7]
 * Output: 42
 * Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 ************************************************************
 * Constraints:
 *
 * The number of nodes in the tree is in the range [1, 3 * 104].
 * -1000 <= Node.val <= 1000
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
    int maxPathSum(TreeNode* root)
    {
        return 0;
    }
    int maxPathSum1(TreeNode* root)
    {
        return 0;
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
        int expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printtree(root);
const static int TEST_TIME = 1;
const static int TEST_0    = 0;
const static int TEST_1    = 1;

    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.maxPathSum(root);
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

        decltype(expected) result = solution.maxPathSum1(root);
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
    int expected = 0;
    Test("Test0", nullptr, expected);
}
void Test1()
{
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    TreeNode * pnode2 = new TreeNode(2);
    TreeNode * pnode3 = new TreeNode(3);
    TreeNode * pnode1 = new TreeNode(1, pnode2, pnode3);

    int expected = 6;

    std::cout << "The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6." << std::endl;
    Test("Test1", pnode1, expected);
}
void Test2()
{
    std::cout << "    -10         " << std::endl;
    std::cout << "    /  \\       " << std::endl;
    std::cout << "   9    20      " << std::endl;
    std::cout << "       / \\     " << std::endl;
    std::cout << "      15  7     " << std::endl;
    TreeNode * pnode7 = new TreeNode(7);
    TreeNode * pnode15= new TreeNode(15);
    TreeNode * pnode20= new TreeNode(20, pnode15, pnode7);
    TreeNode * pnode9 = new TreeNode(9);
    TreeNode * pnode10= new TreeNode(-10, pnode9, pnode20);
    int expected = 42;
    std::cout << "The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42." << std::endl;
    Test("Test2", pnode10, expected);
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
    int expected =  14;
    Test("Test3", pnode1, expected);
}

void Test4()
{
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    std::cout << "  /     / \\    " << std::endl;
    std::cout << " 4     5   6    " << std::endl;

    TreeNode * p6 = new TreeNode(6);
    TreeNode * p5 = new TreeNode(5);
    TreeNode * p4 = new TreeNode(4);
    TreeNode * p3 = new TreeNode(3, p5, p6);
    TreeNode * p2 = new TreeNode(2, p4, nullptr);
    TreeNode * p1 = new TreeNode(1, p2, p3);

    std::cout << "The path with maximum sum is: [4, 2, 1, 3, 6]" << std::endl;
    int expected = 16;
    Test("Test1", p1, expected);
}
void Test5()
{
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    std::cout << "  / \\   / \\    " << std::endl;
    std::cout << " 1   3 5   6    " << std::endl;
    std::cout << "      / \\  \\  " << std::endl;
    std::cout << "     7   8   9  " << std::endl;

    struct TreeNode * p11= new TreeNode(11);
    struct TreeNode * p10= new TreeNode(10);
    struct TreeNode * p9 = new TreeNode(9 );
    struct TreeNode * p8 = new TreeNode(8 );
    struct TreeNode * p7 = new TreeNode(7 );
    struct TreeNode * p6 = new TreeNode(6 ,nullptr, p9);
    struct TreeNode * p5 = new TreeNode(5 , p7 , p8);
    struct TreeNode * p3 = new TreeNode(3 , p5 , p6);
    struct TreeNode * p2 = new TreeNode(2 );
    struct TreeNode * p1 = new TreeNode(1, p2 , p3);
    std::cout << "The path with maximum sum is: [8, 5, 3, 6, 9]" << std::endl;
    int expected = 31;
    Test("Test2", p1, expected );
}
void Test6()
{
    std::cout << "      -5         " << std::endl;
    std::cout << "     / \\       " << std::endl;
    std::cout << "   -4   -8       " << std::endl;
    std::cout << "   /   / \\     " << std::endl;
    std::cout << "  -3  9   4     " << std::endl;
    std::cout << " / \\    / \\   " << std::endl;
    std::cout << "7   2   5   1   " << std::endl;

    struct TreeNode * p7 = new TreeNode(7 );
    struct TreeNode * p2 = new TreeNode(2 );
    struct TreeNode * p_5= new TreeNode(5 );
    struct TreeNode * p1 = new TreeNode(1 );
    struct TreeNode * p9 = new TreeNode(9 );
    struct TreeNode * p3 = new TreeNode(-3 , p7, p2);
    struct TreeNode * p4 = new TreeNode(4 , p_5, p1);
    struct TreeNode * p_4= new TreeNode(-4 , p3 , nullptr);
    struct TreeNode * p8 = new TreeNode(-8, p9 , p4 );
    struct TreeNode * p5 = new TreeNode(-5 ,p_4, p8);
    int expected = 10;
    Test("Test6", p5, expected );
}
void Test7()
{
    std::cout << "      1          " << std::endl;
    std::cout << "     / \\       " << std::endl;
    std::cout << "   -2   -3       " << std::endl;
    std::cout << "   / \\         " << std::endl;
    std::cout << "  4   5         " << std::endl;
    std::cout << " / \\           " << std::endl;
    std::cout << "-6  -7           " << std::endl;

    struct TreeNode * p7 = new TreeNode(-7 );
    struct TreeNode * p6 = new TreeNode(-6 );
    struct TreeNode * p5 = new TreeNode( 5 );
    struct TreeNode * p4 = new TreeNode( 4 ,p6, p7);
    struct TreeNode * p3 = new TreeNode(-3 );
    struct TreeNode * p2 = new TreeNode(-2, p4, p5);
    struct TreeNode * p1 = new TreeNode(1 ,p2, p3);
    int expected = 7 ;
    Test("Test7", p1, expected );
}
void Test8()
{
    std::cout << "      -2         " << std::endl;
    std::cout << "     /          " << std::endl;
    std::cout << "   -1            " << std::endl;

    struct TreeNode * p1 = new TreeNode(-1 );
    struct TreeNode * p2 = new TreeNode(-2, p1, nullptr);
    int expected = -1;
    Test("Test8", p2, expected );
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
