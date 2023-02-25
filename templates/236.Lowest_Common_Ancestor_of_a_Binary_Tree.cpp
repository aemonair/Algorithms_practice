/*
 * 117. Populating Next Right Pointers in Each Node II
 * Medium
 *************************************************************************************
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * 
 * According to the definition of LCA on Wikipedia: 
 * “The lowest common ancestor is defined between two nodes p and q as the lowest node in T 
 *  that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
 *************************************************************************************
 * Example 1:
 * 
 *        3
 *      /   \
 *     5     1
 *    / \   / \
 *   6   2 0   8
 *     /  \
 *    7    4
 *          
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 *************************************************************************************
 * Example 2:
 * 
 *        3
 *      /   \
 *     5     1
 *    / \   / \
 *   6   2 0   8
 *     /  \
 *    7    4
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 *************************************************************************************
 * Example 3:
 *
 * Input: root = [1,2], p = 1, q = 2
 * Output: 1
 *************************************************************************************
 * Constraints:
 * 
 * The number of nodes in the tree is in the range [2, 10^5].
 * -10^9 <= Node.val <= 10^9
 * All Node.val are unique.
 * p != q
 * p and q will exist in the tree.
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
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
    TreeNode *pfind;
    TreeNode* lowestCommonAncestor0(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return nullptr;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return nullptr;
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
        TreeNode *root, TreeNode * p, TreeNode *q,
        TreeNode *expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "expected:" << std::endl;
    solution.printtree(expected);
    // getpermutataion
const static int TEST_TIME = 1;
const static int TEST_0    = 0;
const static int TEST_1    = 1;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "lowestCommonAncestor0:" << std::endl;
        TreeNode *result = solution.lowestCommonAncestor0(root, p ,q);

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

        std::cout << "lowestCommonAncestor1:" << std::endl;
        TreeNode *result = solution.lowestCommonAncestor1(root, p ,q);

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
    TreeNode * p_node7 = new TreeNode(7);

    TreeNode * p_node2 = new TreeNode(2, p_node7, p_node4);
    TreeNode * p_node6 = new TreeNode(6);
    TreeNode * p_node0 = new TreeNode(0);
    TreeNode * p_node8 = new TreeNode(8);

    TreeNode * p_node1 = new TreeNode(1, p_node0, p_node8);
    TreeNode * p_node5 = new TreeNode(5, p_node6, p_node2);

    TreeNode * p_node3 = new TreeNode(3, p_node5, p_node1);
    
    std::cout << "      3        " << std::endl;
    std::cout << "    /   \\     " << std::endl;
    std::cout << "   5     1     " << std::endl;
    std::cout << "  / \\  / \\   " << std::endl;
    std::cout << " 6   2 0   8   " << std::endl;
    std::cout << "   /  \\       " << std::endl;
    std::cout << "  7    4       " << std::endl;
    ////////////////////////////////////
    Test("Test1", p_node3, p_node5, p_node1, p_node3);
    std::cout << "----------------" << std::endl;
}

void Test2()
{
    TreeNode * p_node4 = new TreeNode(4);
    TreeNode * p_node7 = new TreeNode(7);

    TreeNode * p_node2 = new TreeNode(2, p_node7, p_node4);
    TreeNode * p_node6 = new TreeNode(6);
    TreeNode * p_node0 = new TreeNode(0);
    TreeNode * p_node8 = new TreeNode(8);

    TreeNode * p_node1 = new TreeNode(1, p_node0, p_node8);
    TreeNode * p_node5 = new TreeNode(5, p_node6, p_node2);

    TreeNode * p_node3 = new TreeNode(3, p_node5, p_node1);
    
    std::cout << "      3        " << std::endl;
    std::cout << "    /   \\     " << std::endl;
    std::cout << "   5     1     " << std::endl;
    std::cout << "  / \\  / \\   " << std::endl;
    std::cout << " 6   2 0   8   " << std::endl;
    std::cout << "   /  \\       " << std::endl;
    std::cout << "  7    4       " << std::endl;
    ////////////////////////////////////
    Test("Test2", p_node3, p_node5, p_node4, p_node5);
    std::cout << "----------------" << std::endl;
}
void Test3()
{
    TreeNode * p_node0 = new TreeNode(0);
    TreeNode * p_node1 = new TreeNode(1);
    TreeNode * p_node2 = new TreeNode(2, nullptr, p_node1);
    TreeNode * p_node3 = new TreeNode(3, nullptr, p_node2);
    TreeNode * p_node5 = new TreeNode(5, p_node0, nullptr);
    TreeNode * p_node6 = new TreeNode(6, p_node3, p_node5);
    
    std::cout << "      6         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   3     5      " << std::endl;
    std::cout << "    \\   /      " << std::endl;
    std::cout << "     2  0       " << std::endl;
    std::cout << "      \\        " << std::endl;
    std::cout << "        1       " << std::endl;
    ////////////////////////////////////
    Test("Test3",p_node6, p_node1, p_node0, p_node6);
    std::cout << "----------------" << std::endl;
}

void Test4()
{
    std::cout << "      20        " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   9     15     " << std::endl;
    std::cout << "  /      /      " << std::endl;
    std::cout << " 3      7       " << std::endl;
    TreeNode * p_node3 = new TreeNode(3);
    TreeNode * p_node7 = new TreeNode(7);
    TreeNode * p_node15= new TreeNode(15, p_node7, nullptr);
    TreeNode * p_node9 = new TreeNode(9 , p_node3, nullptr);
    TreeNode * p_node20= new TreeNode(20, p_node9, p_node15);
    Test("Test4", p_node20, p_node9, p_node3, p_node9);
    std::cout << "----------------" << std::endl;
}
int main()
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
