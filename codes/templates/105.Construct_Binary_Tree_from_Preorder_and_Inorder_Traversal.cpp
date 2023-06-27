/*
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 * Medium
 *************************************************************************************
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *************************************************************************************
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *************************************************************************************
 * For example, given
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * Return the following binary tree:
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
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
        std::vector<int>& preorder, std::vector<int>& inorder,
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
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "buildTree:" << std::endl;
        TreeNode *root = solution.buildTree(preorder, inorder);
        solution.printtree(root);

        if(solution.isSame(root , expected) == true)
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
    std::vector<int> preorder = {6,3,2,1,5,0};
    std::vector<int> inorder  = {3,2,1,6,0,5};

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
    Test("Test1", preorder, inorder, p_node6);
    std::cout << "----------------" << std::endl;
}
void Test2()
{
    std::vector<int> preorder = {20,9,3,15,7} ;
    std::vector<int> inorder  = {3,9,20,7,15} ;
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
    Test("Test2", preorder, inorder, p_node20);
    std::cout << "----------------" << std::endl;
}

void Test3()
{
    std::vector<int> preorder = {5,4,3,2,1} ;
    std::vector<int> inorder  = {5,4,3,2,1} ;

    std::cout << " 5                   " << std::endl;
    std::cout << "   \\                " << std::endl;
    std::cout << "    4                " << std::endl;
    std::cout << "      \\             " << std::endl;
    std::cout << "       3             " << std::endl;
    std::cout << "         \\          " << std::endl;
    std::cout << "          2          " << std::endl;
    std::cout << "            \\       " << std::endl;
    std::cout << "             1       " << std::endl;
    //      
    TreeNode * p_node1 = new TreeNode(1, nullptr, nullptr);
    TreeNode * p_node2 = new TreeNode(2, nullptr, p_node1);
    TreeNode * p_node3 = new TreeNode(3, nullptr, p_node2);
    TreeNode * p_node4 = new TreeNode(4, nullptr, p_node3);
    TreeNode * p_node5 = new TreeNode(5, nullptr, p_node4);
    Test("Test2", preorder, inorder, p_node5);
    std::cout << "----------------" << std::endl;
}

void Test4()
{
    std::vector<int> preorder = {3,9,20,15,7};
    std::vector<int> inorder  = {9,3,15,20,7};
    std::cout << "     3               " << std::endl;
    std::cout << "    / \\             " << std::endl;
    std::cout << "   9  20             " << std::endl;
    std::cout << "     /  \\           " << std::endl;
    std::cout << "    15   7           " << std::endl;
    TreeNode * p_node7 = new TreeNode(7);
    TreeNode * p_node15= new TreeNode(15);
    TreeNode * p_node20= new TreeNode(20, p_node15, p_node7);
    TreeNode * p_node9 = new TreeNode(9);
    TreeNode * p_node3 = new TreeNode(3 , p_node9, p_node20);
    Test("Test4", preorder, inorder, p_node3);
    std::cout << "----------------" << std::endl;
//                  A
//                /   \
//               B     G
//              / \    / \
//             C   D  H   J
//                / \  \
//               E   F  I
//     先序： ABCDEFGHIJ    确定当前序列中根地位置
//     中序： CBEDFAHIGJ    得到某个节点地左右子树部分
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
