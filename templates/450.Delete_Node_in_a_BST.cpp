/*
 * 450. Delete Node in a BST
 * Medium
 * 
 *************************************************************************************
 * Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
 * 
 * Basically, the deletion can be divided into two stages:
 * 
 * Search for a node to remove.
 * If the node is found, delete the node.
 * Follow up: Can you solve it with time complexity O(height of tree)?
 *************************************************************************************
 * Example 1:
 *          5           5      
 *         / \         / \
 *        3   6  ->   3   6      
 *       / \   \     /     \
 *      2   4   7   2       7       
 *
 * 
 * Input: root = [5,3,6,2,4,null,7], key = 3
 * Output: [5,4,6,2,null,null,7]
 * Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
 * One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
 * Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
 * 
 *      5      
 *     / \
 *    2   6    
 *     \   \
 *      4   7  
 *************************************************************************************
 * Example 2:
 *
 *      5      
 *     / \
 *    3   6    
 *   / \   \
 *  2   4   7  
 * Input: root = [5,3,6,2,4,null,7], key = 0
 * Output: [5,3,6,2,4,null,7]
 * Explanation: The tree does not contain a node with value = 0.
 *************************************************************************************
 * Example 3:
 * 
 * Input: root = [], key = 0
 * Output: []
 * 
 *************************************************************************************
 * 
 * Constraints:
 * 
 * The number of nodes in the tree is in the range [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * Each node has a unique value.
 * root is a valid binary search tree.
 * -10^5 <= key <= 10^5
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
    TreeNode* deleteNode(TreeNode* root, int key)
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

        std::cout << "value:" << val <<", deleteNode:" << std::endl;
        decltype(expected) result = solution.deleteNode(root, val);

        std::cout << "result:" << result <<","<< (result==nullptr?"N": std::to_string(result->val)) << std::endl;
        std::cout << "After delete Tree :" << std::endl;
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
    TreeNode * r_node4 = new TreeNode(4);
    TreeNode * r_node2 = new TreeNode(2, nullptr, r_node4);
    TreeNode * r_node8 = new TreeNode(8, r_node7, nullptr);
    TreeNode * r_node6 = new TreeNode(6, r_node2, r_node8);
    ////////////////////////////////////
    Test("Test1", p_node6, 1, r_node6);
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
    TreeNode * r_node7 = new TreeNode(7 , r_node3, nullptr );
    TreeNode * r_node20= new TreeNode(20);
    TreeNode * r_node15= new TreeNode(15, r_node7, r_node20);
    Test("Test2", p_node9, 9, r_node15);
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

    TreeNode * r_node2 = new TreeNode(2);
    TreeNode * r_node4 = new TreeNode(4);
    TreeNode * r_node3 = new TreeNode(3, r_node2, r_node4);
    Test("Test3", p_node3, 1, r_node3);
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
    TreeNode * r_node2 = new TreeNode(2 , r_node1 , nullptr);
    TreeNode * r_node4 = new TreeNode(4 , r_node2 , nullptr);
    TreeNode * r_node6 = new TreeNode(6);
    TreeNode * r_node5 = new TreeNode(5 , r_node4, r_node6 );
    Test("Test4", p_node5, 3 ,r_node5);
    std::cout << "----------------" << std::endl;
}

void Test5()
{
    std::cout << "       5             " << std::endl;
    std::cout << "      / \\           " << std::endl;
    std::cout << "     3    6          " << std::endl;
    std::cout << "    / \\   \\        " << std::endl;
    std::cout << "   2   4     7       " << std::endl;
    TreeNode * p_node2 = new TreeNode(2);
    TreeNode * p_node4 = new TreeNode(4);
    TreeNode * p_node3 = new TreeNode(3 , p_node2 , p_node4);
    TreeNode * p_node7 = new TreeNode(7);
    TreeNode * p_node6 = new TreeNode(6 , nullptr, p_node7);
    TreeNode * p_node5 = new TreeNode(5 , p_node3, p_node6 );

    TreeNode * r_node2 = new TreeNode(2);
    TreeNode * r_node4 = new TreeNode(4 , r_node2, nullptr);
    TreeNode * r_node7 = new TreeNode(7);
    TreeNode * r_node6 = new TreeNode(6 , nullptr , r_node7);
    TreeNode * r_node5 = new TreeNode(5 , r_node4 , r_node6 );
    Test("Test5", p_node5, 3 , r_node5);
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

    return 0;

}
