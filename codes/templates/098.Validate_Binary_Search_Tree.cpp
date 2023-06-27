/*
 * 98. Validate Binary Search Tree
 * Medium
 *************************************************************************************
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *************************************************************************************
 * Example 1:
 *
 *     2
 *    / \
 *   1   3
 *
 * Input: [2,1,3]
 * Output: true
 *************************************************************************************
 * Example 2:
 *
 *     5
 *    / \
 *   1   4
 *      / \
 *     3   6
 *
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
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
    bool isValidBST(TreeNode* root)
    {
        return true;
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
        bool expected)
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

        std::cout << "isValidBST:" << std::endl;
        decltype(expected) result = solution.isValidBST(root);

        std::cout << "expect:" << std::boolalpha << expected << std::endl;
        if(result == expected)
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
    TreeNode * p_node7 = new TreeNode(7);
    TreeNode * p_node3 = new TreeNode(3);
    TreeNode * p_node2 = new TreeNode(2, nullptr, p_node3);
    TreeNode * p_node1 = new TreeNode(1, nullptr, p_node2);
    TreeNode * p_node8 = new TreeNode(8, p_node7, nullptr);
    TreeNode * p_node6 = new TreeNode(6, p_node1, p_node8);
   
    std::cout << "      6         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   1     8      " << std::endl;
    std::cout << "    \\   /      " << std::endl;
    std::cout << "     2  7       " << std::endl;
    std::cout << "      \\        " << std::endl;
    std::cout << "        3       " << std::endl;
    ////////////////////////////////////
    Test("Test1", p_node6, true);
    std::cout << "----------------" << std::endl;
}
void Test2()
{
    std::cout << "      9         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   7     20     " << std::endl;
    std::cout << "  /      /      " << std::endl;
    std::cout << " 3      15      " << std::endl;
    TreeNode * p_node3 = new TreeNode(3);
    TreeNode * p_node15= new TreeNode(15);
    TreeNode * p_node7 = new TreeNode(7 , p_node3, nullptr);
    TreeNode * p_node20= new TreeNode(20, p_node15,nullptr);
    TreeNode * p_node9 = new TreeNode(9 , p_node7, p_node20);
    Test("Test2", p_node9, true);
    std::cout << "----------------" << std::endl;
}

void Test3()
{
    std::cout << "      3              " << std::endl;
    std::cout << "    /   \\           " << std::endl;
    std::cout << "   1     4           " << std::endl;
    std::cout << "    \\               " << std::endl;
    std::cout << "     2               " << std::endl;
    //      
    TreeNode * p_node2 = new TreeNode(2);
    TreeNode * p_node4 = new TreeNode(4);
    TreeNode * p_node1 = new TreeNode(1, nullptr, p_node2);
    TreeNode * p_node3 = new TreeNode(3, p_node1, p_node4);
    Test("Test3", p_node3, true);
    std::cout << "----------------" << std::endl;
}

void Test4()
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
    Test("Test4", p_node5, true);
    std::cout << "----------------" << std::endl;
}

void Test5()
{
    std::cout << "       2             " << std::endl;
    std::cout << "      / \\           " << std::endl;
    std::cout << "     1    3          " << std::endl;
    TreeNode * p_node1 = new TreeNode(1);
    TreeNode * p_node3 = new TreeNode(3);
    TreeNode * p_node2 = new TreeNode(2 , p_node1, p_node3 );
    Test("Test5", p_node2, true);
    std::cout << "----------------" << std::endl;
}
void Test6()
{
    std::cout << "       5             " << std::endl;
    std::cout << "      / \\           " << std::endl;
    std::cout << "     1    4          " << std::endl;
    std::cout << "         / \\        " << std::endl;
    std::cout << "        3   6        " << std::endl;
    TreeNode * p_node1 = new TreeNode(1);
    TreeNode * p_node3 = new TreeNode(3);
    TreeNode * p_node6 = new TreeNode(6);
    TreeNode * p_node4 = new TreeNode(4 , p_node3, p_node6 );
    TreeNode * p_node5 = new TreeNode(5 , p_node1, p_node4 );
    Test("Test6", p_node5, false);
    std::cout << "----------------" << std::endl;
}
int main()
{
    Solution solution;

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;

}
