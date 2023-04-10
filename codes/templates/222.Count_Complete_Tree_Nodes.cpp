/*
 * 222. Count Complete Tree Nodes
 * Medium
 * 
 *************************************************************************************
 * Given a complete binary tree, count the number of nodes.
 * 
 *************************************************************************************
 * Note:
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 * 
 *************************************************************************************
 * Example:
 * 
 * Input:
 *     1
 *    / \
 *   2   3
 *  / \  /
 * 4  5 6
 * 
 * Output: 6
 *************************************************************************************
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    int countNodes0(TreeNode* root)
    {
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    int countNodes1(TreeNode* root) 
    {
        return 0;
    }
    int printtree  (const TreeNode * head)
    {
        if (head==nullptr)
        {
            std::cout << "null tree. " << std::endl;
            return 0;
        }
        std::cout << "head->val: " << head->val << std::endl;
        printtreenode(head);
        std::cout << std::endl;
        return 0;
    }
    int printtreenode (const TreeNode * head)
    {
        if(head==nullptr)
        {
            std::cout << "N" << ",";
        }
        else
        {
            std::cout << head->val << ",";
            printtreenode(head->left);
            printtreenode(head->right);
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
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "counted tree:" << std::endl;
    solution.printtree(root);
    // getpermutataion
const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "countNodes0:" << std::endl;
        decltype(expected) result = solution.countNodes0(root);

        //if(solution.isSame(root , expected) == true)
        if(result ==  expected)
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
    if (TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "countNodes1:" << std::endl;
        decltype(expected) result = solution.countNodes1(root);

        //if(solution.isSame(root , expected) == true)
        if(result ==  expected)
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
}

void Test1()
{
    TreeNode * p_node4 = new TreeNode(4);
    TreeNode * p_node5 = new TreeNode(5);
    TreeNode * p_node6 = new TreeNode(6);

    TreeNode * p_node2 = new TreeNode(2, p_node4, p_node5);
    TreeNode * p_node3 = new TreeNode(3, p_node6, nullptr);

    TreeNode * p_node1 = new TreeNode(1, p_node2, p_node3);
    
    std::cout << "      1               " << std::endl;
    std::cout << "     / \\             " << std::endl;
    std::cout << "    2   3             " << std::endl;
    std::cout << "   / \\ /             " << std::endl;
    std::cout << "  4  5 6              " << std::endl;
    ////////////////////////////////////
    Test("Test1", p_node1, 6);
    std::cout << "----------------" << std::endl;
}

void Test2()
{
    TreeNode * p_node2 = new TreeNode(2);
    TreeNode * p_node6 = new TreeNode(6);

    TreeNode * p_node1 = new TreeNode(1);

    TreeNode * p_node5 = new TreeNode(5, p_node6, p_node2);

    TreeNode * p_node3 = new TreeNode(3, p_node5, p_node1);
    
    std::cout << "      3        " << std::endl;
    std::cout << "    /   \\     " << std::endl;
    std::cout << "   5     1     " << std::endl;
    std::cout << "  / \\         " << std::endl;
    std::cout << " 6   2         " << std::endl;
    ////////////////////////////////////
    Test("Test2", p_node3, 5);
    std::cout << "----------------" << std::endl;
}
void Test3()
{
}

void Test4()
{
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
