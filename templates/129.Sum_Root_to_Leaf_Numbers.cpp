/*
 ************************************************************
 * 129. Sum Root to Leaf Numbers
 * Medium
 ************************************************************
 * You are given the root of a binary tree containing digits from 0 to 9 only.
 * 
 * Each root-to-leaf path in the tree represents a number.
 * 
 * For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
 * Return the total sum of all root-to-leaf numbers.
 * 
 * A leaf node is a node with no children.
 ************************************************************
 * Example 1:
 * 
 *      1
 *     / \
 *    2   3
 * 
 * Input: root = [1,2,3]
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 ************************************************************
 * Example 2:
 * 
 * 
 *      4
 *     / \
 *    9   0
 *   / \
 *  5   1
 * Input: root = [4,9,0,5,1]
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
 ************************************************************
 * Constraints:
 * 
 * The number of nodes in the tree is in the range [1, 1000].
 * 0 <= Node.val <= 9
 * The depth of the tree will not exceed 10.
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
    int sumNumbers(TreeNode* root) 
    {
        if(root==nullptr)
        {
            return 0;
        }
        unsigned int nums = 0;
        unsigned int result = 0;
        sumNumbers(root, nums, result);
        return result;
    }
    int sumNumbers(TreeNode *root, unsigned int &nums, unsigned int &result)
    {
        return 0;
    }
    int sumNumbers1(TreeNode* root) 
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

        decltype(expected) result = solution.sumNumbers(root);
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

        decltype(expected) result = solution.sumNumbers1(root);
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
    std::cout << "      4         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   9     0      " << std::endl;
    std::cout << "  / \\          " << std::endl;
    std::cout << " 5   1          " << std::endl;
    TreeNode * pnode5 = new TreeNode(5);
    TreeNode * pnode1 = new TreeNode(1);
    TreeNode * pnode9 = new TreeNode(9, pnode5, pnode1);
    TreeNode * pnode0 = new TreeNode(0);
    TreeNode * pnode4 = new TreeNode(4, pnode9, pnode0);

    int expected = 1026;

    Test("Test1", pnode4, expected);
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
    int expected = 23456;
    Test("Test2", pnode2, expected);
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
    int expected =  123+1245;
    Test("Test3", pnode1, expected);
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

    int expected = 124+125+136+137; 
    Test("Test4", p1, expected);
}
void Test5()
{
    //Test("Test4", 6, 6, 3);
    std::cout << "      2         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   7     1      " << std::endl;
    std::cout << " /       / \\   " << std::endl;
    std::cout << "9       3   5   " << std::endl;

    struct TreeNode * p9 = new TreeNode(9 );
    struct TreeNode * p5 = new TreeNode(5 );
    struct TreeNode * p3 = new TreeNode(3 );
    struct TreeNode * p7 = new TreeNode(7, p9, nullptr);
    struct TreeNode * p1 = new TreeNode(1, p3 , p5);
    struct TreeNode * p2 = new TreeNode(2 ,p7 , p1);
    int expected = 279+213+215;
    Test("Test5", p2, expected );
}
void Test6()
{
    std::cout << "      5         " << std::endl;
    std::cout << "     / \\       " << std::endl;
    std::cout << "    4   8       " << std::endl;
    std::cout << "   /   / \\     " << std::endl;
    std::cout << "  3   9   4     " << std::endl;
    std::cout << " / \\    / \\   " << std::endl;
    std::cout << "7   2   5   1   " << std::endl;

    struct TreeNode * p7 = new TreeNode(7 );
    struct TreeNode * p2 = new TreeNode(2 );
    struct TreeNode * p_5= new TreeNode(5 );
    struct TreeNode * p1 = new TreeNode(1 );
    struct TreeNode * p9 = new TreeNode(9 );
    struct TreeNode * p3 = new TreeNode(3 , p7, p2);
    struct TreeNode * p4 = new TreeNode(4 , p_5, p1);
    struct TreeNode * p_4= new TreeNode(4 , p3 , nullptr);
    struct TreeNode * p8 = new TreeNode(8, p9 , p4 );
    struct TreeNode * p5 = new TreeNode(5 ,p_4, p8);
    int expected = 5437+5432+589+5845+5841; 
    Test("Test2", p5, expected );
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
