/*
 * 114. Flatten Binary Tree to Linked List
 * Medium
 *
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example, given the following tree:
 *
 *     1
 *    / \
 *   2   5
 *  / \   \
 * 3   4   6
 * The flattened tree should look like:
 *
 * 1
 *  \
 *   2
 *    \
 *     3
 *      \
 *       4
 *        \
 *         5
 *          \
 *           6
 *
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
    void flatten(TreeNode* root)
    {
        return;
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
void Test(const std::string& testName, TreeNode *root, TreeNode *expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printtree(root);
    // getpermutataion
const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        solution.flatten(root);

        std::cout << "flatten :" << std::endl;
        solution.printtree(root);
        std::cout << "expected:" << std::endl;
        solution.printtree(expected);
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
    TreeNode * pnode1 = new TreeNode(1);
    TreeNode * pnode3 = new TreeNode(3);
    TreeNode * pnode6 = new TreeNode(6);
    TreeNode * pnode9 = new TreeNode(9);
   
    TreeNode * pnode2 = new TreeNode(2, pnode1, pnode3);
    TreeNode * pnode7 = new TreeNode(7, pnode6, pnode9);

    TreeNode * pnode4 = new TreeNode(4, pnode2, pnode7);
    std::cout << "      4         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     7      " << std::endl;
    std::cout << "  / \\   / \\   " << std::endl;
    std::cout << " 1   3 6   9    " << std::endl;
    ////////////////////////////////////
    TreeNode * p_node9 = new TreeNode(9);
    TreeNode * p_node6 = new TreeNode(6, nullptr, p_node9);
    TreeNode * p_node7 = new TreeNode(7, nullptr, p_node6);
    TreeNode * p_node3 = new TreeNode(3, nullptr, p_node7);
    TreeNode * p_node1 = new TreeNode(1, nullptr, p_node3);
    TreeNode * p_node2 = new TreeNode(2, nullptr, p_node1);
    TreeNode * p_node4 = new TreeNode(4, nullptr, p_node2);
    Test("Test1", pnode4, p_node4);
//    42 1 3769
    std::cout << " 4                   " << std::endl;
    std::cout << "   \\                " << std::endl;
    std::cout << "    2                " << std::endl;
    std::cout << "      \\             " << std::endl;
    std::cout << "       1             " << std::endl;
    std::cout << "         \\          " << std::endl;
    std::cout << "          3          " << std::endl;
    std::cout << "            \\       " << std::endl;
    std::cout << "             7       " << std::endl;
    std::cout << "               \\    " << std::endl;
    std::cout << "                6    " << std::endl;
    std::cout << "                  \\ " << std::endl;
    std::cout << "                   9 " << std::endl;
    std::cout << "----------------" << std::endl;
}
void Test2()
{
    TreeNode * pnode3 = new TreeNode(3);
    TreeNode * pnode9 = new TreeNode(9);
    TreeNode * pnode20= new TreeNode(20);
    TreeNode * pnode15= new TreeNode(15);
    TreeNode * pnode7 = new TreeNode(7);
    pnode3 ->left  = pnode9 ;
    pnode3 ->right = pnode20;
    pnode20->left  = pnode15;
    pnode20->right = pnode7 ;
    //   
    //      3
    //    /   \
    //   9     20
    //        / \
    //       15  7
    std::cout << "      3         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   9     20     " << std::endl;
    std::cout << "         / \\   " << std::endl;
    std::cout << "       15  7    " << std::endl;
    TreeNode * p_node7 = new TreeNode(7);
    TreeNode * p_node15= new TreeNode(15, nullptr, p_node7);
    TreeNode * p_node20= new TreeNode(20, nullptr, p_node15);
    TreeNode * p_node9 = new TreeNode(9 , nullptr, p_node20);
    TreeNode * p_node3 = new TreeNode(3 , nullptr, p_node9 );
    Test("Test2", pnode3, p_node3);
    std::cout << " 3                   " << std::endl;
    std::cout << "   \\                " << std::endl;
    std::cout << "    9                " << std::endl;
    std::cout << "      \\             " << std::endl;
    std::cout << "       20            " << std::endl;
    std::cout << "         \\          " << std::endl;
    std::cout << "          15         " << std::endl;
    std::cout << "            \\       " << std::endl;
    std::cout << "             7       " << std::endl;
    std::cout << "----------------" << std::endl;
}

void Test3()
{
    std::cout << "      1         " << std::endl;
    std::cout << "        \\      " << std::endl;
    std::cout << "         2      " << std::endl;
    std::cout << "        / \\    " << std::endl;
    std::cout << "       3    4   " << std::endl;
    std::cout << "          /     " << std::endl;
    std::cout << "         5      " << std::endl;
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

    TreeNode * p_node5 = new TreeNode(5);
    TreeNode * p_node4 = new TreeNode(4, nullptr, p_node5);
    TreeNode * p_node3 = new TreeNode(3, nullptr, p_node4);
    TreeNode * p_node2 = new TreeNode(2, nullptr, p_node3);
    TreeNode * p_node1 = new TreeNode(1, nullptr, p_node2);
    Test("Test3", pnode1, p_node1);
    std::cout << " 1                   " << std::endl;
    std::cout << "   \\                " << std::endl;
    std::cout << "    2                " << std::endl;
    std::cout << "      \\             " << std::endl;
    std::cout << "       3             " << std::endl;
    std::cout << "         \\          " << std::endl;
    std::cout << "          4          " << std::endl;
    std::cout << "            \\       " << std::endl;
    std::cout << "             5       " << std::endl;
    std::cout << "----------------" << std::endl;
}

void Test4()
{
    TreeNode * pnode3 = new TreeNode(3);
    TreeNode * pnode4 = new TreeNode(4);
    TreeNode * pnode6 = new TreeNode(6);

    TreeNode * pnode2 = new TreeNode(2, pnode3 , pnode4);
    TreeNode * pnode5 = new TreeNode(5, nullptr, pnode6);

    TreeNode * pnode1 = new TreeNode(1, pnode2 , pnode5);

    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     5      " << std::endl;
    std::cout << "  / \\     \\   " << std::endl;
    std::cout << " 3   4      6   " << std::endl;
    TreeNode * p_node6 = new TreeNode(6);
    TreeNode * p_node5 = new TreeNode(5, nullptr, p_node6);
    TreeNode * p_node4 = new TreeNode(4, nullptr, p_node5);
    TreeNode * p_node3 = new TreeNode(3, nullptr, p_node4);
    TreeNode * p_node2 = new TreeNode(2, nullptr, p_node3);
    TreeNode * p_node1 = new TreeNode(1, nullptr, p_node2);
    Test("Test3", pnode1, p_node1);
    std::cout << " 1                   " << std::endl;
    std::cout << "   \\                " << std::endl;
    std::cout << "    2                " << std::endl;
    std::cout << "      \\             " << std::endl;
    std::cout << "       3             " << std::endl;
    std::cout << "         \\          " << std::endl;
    std::cout << "          4          " << std::endl;
    std::cout << "            \\       " << std::endl;
    std::cout << "             5       " << std::endl;
    std::cout << "               \\    " << std::endl;
    std::cout << "                6    " << std::endl;
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
