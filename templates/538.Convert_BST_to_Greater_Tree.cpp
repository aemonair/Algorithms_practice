/*
 * 538. Convert BST to Greater Tree
 * Medium
 * 
 *************************************************************************************
 * Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
 * 
 * As a reminder, a binary search tree is a tree that satisfies these constraints:
 * 
 * - The left subtree of a node contains only nodes with keys less than the node's key.
 * - The right subtree of a node contains only nodes with keys greater than the node's key.
 * - Both the left and right subtrees must also be binary search trees.
 *************************************************************************************
 * Note: This question is the same as 1038: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
 *************************************************************************************
 * Example 1:
 *                4
 *               / \
 *              1   6
 *             /\   /\
 *            0  2 5  7
 *                \    \
 *                 3    8
 *Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
 *Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
 *************************************************************************************
 *Example 2:
 *
 *Input: root = [0,null,1]
 *Output: [1,null,1]
 *************************************************************************************
 *Example 3:
 *
 *Input: root = [1,0,2]
 *Output: [3,3,2]
 *************************************************************************************
 *Example 4:
 *
 *Input: root = [3,2,4,1]
 *Output: [7,9,4,10]
 *************************************************************************************
 * 
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
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
    int current = 0;
    TreeNode* convertBST(TreeNode* root)
    {
        if (root==nullptr)
        {
            return nullptr;
        }
        convertBST(root->right);
        current += root->val;
        root->val = current;
        convertBST(root->left);
        return root;
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
    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << "| "<<std::endl;
        }
        std::cout << std::endl;
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
    bool isSame(TreeNode *T1, TreeNode *T2)
    {
        if(T1 == nullptr ^ T2 == nullptr)
        {
            // T1 ==nullptr && T2 != nullptr
            // T1 !=nullptr && T2 == nullptr
            return false;
        }
        else
        {
            if (T1 == nullptr && T2==nullptr)
            {
                return true;
            }
        }
        if(T1->val==T2->val)
        {
            return isSame(T1->left,T2->left) && isSame(T1->right,T2->right);
        }
        else
        {
            return false;
        }
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        TreeNode * root,
        TreeNode * expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Tree :" << std::endl;
    solution.printtree(root);
    // getpermutataion
const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "convertBST:" << std::endl;
        decltype(expected) result = solution.convertBST(root);

        std::cout << "Tree result:" << std::endl;
        solution.printtree(result);
        std::cout << "expected result:" << std::endl;
        solution.printtree(expected);
        if(solution.isSame(result , expected))
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
}
void Test1()
{
    TreeNode * p_node8 = new TreeNode(8);
    TreeNode * p_node3 = new TreeNode(3);

    TreeNode * p_node0 = new TreeNode(0);
    TreeNode * p_node5 = new TreeNode(5);
    TreeNode * p_node2 = new TreeNode(2, nullptr, p_node3);
    TreeNode * p_node7 = new TreeNode(7, nullptr, p_node8);

    TreeNode * p_node1 = new TreeNode(1, p_node0, p_node2);
    TreeNode * p_node6 = new TreeNode(6, p_node5, p_node7);

    TreeNode * p_node4 = new TreeNode(4, p_node1, p_node6);
    
    std::cout << "     4          " << std::endl;
    std::cout << "    / \\        " << std::endl;
    std::cout << "   1    6       " << std::endl;
    std::cout << "  /\\  /\\      " << std::endl;
    std::cout << " 0  2 5   7     " << std::endl;
    std::cout << "     \\   \\    " << std::endl;
    std::cout << "      3     8   " << std::endl;

    ////////////////////////////////////
    TreeNode * r_node8 = new TreeNode(8);
    TreeNode * r_node3 = new TreeNode(33);

    TreeNode * r_node0 = new TreeNode(36);
    TreeNode * r_node5 = new TreeNode(26);
    TreeNode * r_node2 = new TreeNode(35, nullptr, r_node3);
    TreeNode * r_node7 = new TreeNode(15, nullptr, r_node8);

    TreeNode * r_node1 = new TreeNode(36, r_node0, r_node2);
    TreeNode * r_node6 = new TreeNode(21, r_node5, r_node7);

    TreeNode * r_node4 = new TreeNode(30, r_node1, r_node6);
    std::cout << "       4(30)              " << std::endl;
    std::cout << "    /        \\           " << std::endl;
    std::cout << "   1(36)      6(21)       " << std::endl;
    std::cout << "  /    \\      /  \\      " << std::endl;
    std::cout << " 0(36)  2(35) 5(26)7(15)  " << std::endl;
    std::cout << "          \\         \\   " << std::endl;
    std::cout << "           3(33)       8  " << std::endl;
    Test("Test1", p_node4, r_node4);
    std::cout << "----------------" << std::endl;
}
void Test2()
{
    std::cout << "      0         " << std::endl;
    std::cout << "        \\      " << std::endl;
    std::cout << "         1      " << std::endl;
    TreeNode * p_node1 = new TreeNode(1);
    TreeNode * p_node0 = new TreeNode(0,nullptr, p_node1);

    std::cout << "      0(1)      " << std::endl;
    std::cout << "        \\      " << std::endl;
    std::cout << "         1(1)   " << std::endl;
    TreeNode * r_node1 = new TreeNode(1);
    TreeNode * r_node0 = new TreeNode(1,nullptr, r_node1);
    Test("Test2", p_node0, r_node0);
    std::cout << "----------------" << std::endl;
}

void Test3()
{
    std::cout << "      1         " << std::endl;
    std::cout << "     /  \\      " << std::endl;
    std::cout << "    0    2      " << std::endl;
    TreeNode * p_node2 = new TreeNode(2);
    TreeNode * p_node0 = new TreeNode(0);
    TreeNode * p_node1 = new TreeNode(1,p_node0, p_node2);

    std::cout << "      1(3)      " << std::endl;
    std::cout << "     /  \\      " << std::endl;
    std::cout << "    0(3) 2(2)   " << std::endl;
    TreeNode * r_node0 = new TreeNode(3);
    TreeNode * r_node2 = new TreeNode(2);
    TreeNode * r_node1 = new TreeNode(3,r_node0, r_node2);
    Test("Test3", p_node1, r_node1);
    std::cout << "----------------" << std::endl;
}
void Test4()
{
    std::cout << "      3              " << std::endl;
    std::cout << "    /   \\           " << std::endl;
    std::cout << "   2     4           " << std::endl;
    std::cout << "  /                  " << std::endl;
    std::cout << " 1                   " << std::endl;
    //       
    TreeNode * p_node1 = new TreeNode(1);
    TreeNode * p_node4 = new TreeNode(4);
    TreeNode * p_node2 = new TreeNode(2, p_node1, nullptr);
    TreeNode * p_node3 = new TreeNode(3, p_node2, p_node4);

    std::cout << "      3(7)           " << std::endl;
    std::cout << "    /   \\           " << std::endl;
    std::cout << "   2(9)  4(4)        " << std::endl;
    std::cout << "  /                  " << std::endl;
    std::cout << " 1(10)                " << std::endl;
    //       
    TreeNode * r_node1 = new TreeNode(10);
    TreeNode * r_node4 = new TreeNode(4);
    TreeNode * r_node2 = new TreeNode(9, r_node1, nullptr);
    TreeNode * r_node3 = new TreeNode(7, r_node2, r_node4);
    Test("Test4", p_node3, r_node3);
    std::cout << "----------------" << std::endl;
}

void Test5()
{
    std::cout << "       5             " << std::endl;
    std::cout << "      / \\           " << std::endl;
    std::cout << "     3    6          " << std::endl;
    std::cout << "    / \\             " << std::endl;
    std::cout << "   2   4             " << std::endl;
    std::cout << "  /                  " << std::endl;
    std::cout << " 1                   " << std::endl;
    TreeNode * p_node1 = new TreeNode(1);
    TreeNode * p_node4 = new TreeNode(4);
    TreeNode * p_node2 = new TreeNode(2 , p_node1 , nullptr);
    TreeNode * p_node6 = new TreeNode(6);
    TreeNode * p_node3 = new TreeNode(3 , p_node2, p_node4 );
    TreeNode * p_node5 = new TreeNode(5 , p_node3, p_node6 );
    std::cout << "       5(11)          " << std::endl;
    std::cout << "      / \\           " << std::endl;
    std::cout << "     3(18) 6(6)       " << std::endl;
    std::cout << "    /  \\             " << std::endl;
    std::cout << "   2(20)4(15)          " << std::endl;
    std::cout << "  /                  " << std::endl;
    std::cout << " 1(21)                " << std::endl;
    TreeNode * r_node1 = new TreeNode(21);
    TreeNode * r_node4 = new TreeNode(15);
    TreeNode * r_node2 = new TreeNode(20 , r_node1 , nullptr);
    TreeNode * r_node6 = new TreeNode(6);
    TreeNode * r_node3 = new TreeNode(18 , r_node2, r_node4 );
    TreeNode * r_node5 = new TreeNode(11 , r_node3, r_node6 );
    Test("Test5", p_node5, r_node5);
    std::cout << "----------------" << std::endl;
    //5,17,19,20,N,N,N,15,N,N,6,N,N,
}

int main()
{
    Solution solution;

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;

}
