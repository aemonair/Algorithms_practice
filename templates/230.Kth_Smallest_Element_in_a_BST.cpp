/*
 * 230. Kth Smallest Element in a BST
 * Medium
 *************************************************************************************
 * 
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 * 
 *************************************************************************************
 * Example 1:
 * 
 * Input: root = [3,1,4,null,2], k = 1
 *    3
 *   / \
 *  1   4
 *   \
 *    2
 * Output: 1
 *************************************************************************************
 * Example 2:
 * 
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 *        5
 *       / \
 *      3   6
 *     / \
 *    2   4
 *   /
 *  1
 * Output: 3
 *************************************************************************************
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 *************************************************************************************
 * Constraints:
 * 
 * The number of elements of the BST is between 1 to 10^4.
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
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
    int kthSmallest(TreeNode* root, int k)
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
        TreeNode * root, int k,
        int expected)
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

        std::cout << "kthSmallest:" << std::endl;
        int result = solution.kthSmallest(root, k);

        std::cout << "expect:" << expected << std::endl;
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
    Test("Test1", p_node6, 3, 3);
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
    Test("Test2", p_node9, 2, 7);
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
    Test("Test3", p_node3, 1, 1);
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
    Test("Test4", p_node5, 3 ,3);
    std::cout << "----------------" << std::endl;
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
