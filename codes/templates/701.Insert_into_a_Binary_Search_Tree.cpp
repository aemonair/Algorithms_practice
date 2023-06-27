/*
 * 701. Insert into a Binary Search Tree
 * Medium
 *************************************************************************************
 * You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
 *
 * Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
 *************************************************************************************
 * Example 1:
 *       4              4   
 *      /  \          /   \
 *     2    7        2     7
 *    / \           / \   /
 *   1   3         1   3 5   
 *
 * Input: root = [4,2,7,1,3], val = 5
 * Output: [4,2,7,1,3,5]
 * Explanation: Another accepted tree is:
 *************************************************************************************
 * Example 2:
 *
 *        40              40   
 *      /    \          /    \
 *     20     60       20     60
 *    / \     / \     / \    / \
 *   10  30  50 70   10  30 50  70
 *                      / 
 *                     25
 * Input: root = [40,20,60,10,30,50,70], val = 25
 * Output: [40,20,60,10,30,50,70,null,null,25]
 *************************************************************************************
 * Example 3:
 *
 * Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
 * Output: [4,2,7,1,3,5]
 *
 *************************************************************************************
 * Constraints:
 *
 * The number of nodes in the tree will be in the range [0, 104].
 * -108 <= Node.val <= 108
 * All the values Node.val are unique.
 * -108 <= val <= 108
 * It's guaranteed that val does not exist in the original BST.
 *
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
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
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
        TreeNode * root, int val,
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

        std::cout << "value:" << val <<", insertIntoBST:" << std::endl;
        decltype(expected) result = solution.insertIntoBST(root, val);

        std::cout << "result:" << result <<","<< (result==nullptr?"N": std::to_string(result->val)) << std::endl;
        std::cout << "After Insert Tree :" << std::endl;
        solution.printtree(root);
        std::cout << "Expected Tree :" << std::endl;
        solution.printtree(expected);
        if(solution.isSame(root ,expected))
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
    TreeNode * p_node4 = new TreeNode(4);
    TreeNode * p_node2 = new TreeNode(2, nullptr, p_node4);
    TreeNode * p_node1 = new TreeNode(1, nullptr, p_node2);
    TreeNode * p_node8 = new TreeNode(8, p_node7, nullptr);
    TreeNode * p_node6 = new TreeNode(6, p_node1, p_node8);
   
    std::cout << "      6         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   1     8      " << std::endl;
    std::cout << "    \\   /      " << std::endl;
    std::cout << "     2  7       " << std::endl;
    std::cout << "      \\        " << std::endl;
    std::cout << "        4       " << std::endl;
    TreeNode * r_node7 = new TreeNode(7);
    TreeNode * r_node3 = new TreeNode(3);
    TreeNode * r_node4 = new TreeNode(4, r_node3, nullptr);
    TreeNode * r_node2 = new TreeNode(2, nullptr, r_node4);
    TreeNode * r_node1 = new TreeNode(1, nullptr, r_node2);
    TreeNode * r_node8 = new TreeNode(8, r_node7, nullptr);
    TreeNode * r_node6 = new TreeNode(6, r_node1, r_node8);
    ////////////////////////////////////
    Test("Test1", p_node6, 3, r_node6);
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

    TreeNode * r_node3 = new TreeNode(3);
    TreeNode * r_node16= new TreeNode(16);
    TreeNode * r_node15= new TreeNode(15, nullptr, r_node16);
    TreeNode * r_node7 = new TreeNode(7 , r_node3, nullptr );
    TreeNode * r_node20= new TreeNode(20, r_node15,nullptr );
    TreeNode * r_node9 = new TreeNode(9 , r_node7, r_node20);
    Test("Test2", p_node9, 16, r_node9);
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

    TreeNode * r_node0 = new TreeNode(0);
    TreeNode * r_node2 = new TreeNode(2);
    TreeNode * r_node4 = new TreeNode(4);
    TreeNode * r_node1 = new TreeNode(1, r_node0, r_node2);
    TreeNode * r_node3 = new TreeNode(3, r_node1, r_node4);
    Test("Test3", p_node3, 0, r_node3);
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

    TreeNode * r_node1 = new TreeNode(1);
    TreeNode * r_node4 = new TreeNode(4);
    TreeNode * r_node2 = new TreeNode(2 , r_node1 , nullptr);
    TreeNode * r_node7 = new TreeNode(7);
    TreeNode * r_node6 = new TreeNode(6 , nullptr, r_node7);
    TreeNode * r_node3 = new TreeNode(3 , r_node2, r_node4 );
    TreeNode * r_node5 = new TreeNode(5 , r_node3, r_node6 );
    Test("Test4", p_node5, 7 ,r_node5);
    std::cout << "----------------" << std::endl;
}

void Test5()
{
    std::cout << "       4             " << std::endl;
    std::cout << "      / \\           " << std::endl;
    std::cout << "     2    7          " << std::endl;
    std::cout << "    / \\             " << std::endl;
    std::cout << "   1   3             " << std::endl;
    TreeNode * p_node1 = new TreeNode(1);
    TreeNode * p_node3 = new TreeNode(3);
    TreeNode * p_node2 = new TreeNode(2 , p_node1 , p_node3);
    TreeNode * p_node7 = new TreeNode(7);
    TreeNode * p_node4 = new TreeNode(4 , p_node2, p_node7 );

    TreeNode * r_node1 = new TreeNode(1);
    TreeNode * r_node5 = new TreeNode(5);
    TreeNode * r_node3 = new TreeNode(3 , r_node5 , nullptr);
    TreeNode * r_node2 = new TreeNode(2 , r_node1 , r_node3);
    TreeNode * r_node7 = new TreeNode(7);
    TreeNode * r_node4 = new TreeNode(4 , r_node2, r_node7 );
    Test("Test5", p_node4, 5 , r_node4);
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
