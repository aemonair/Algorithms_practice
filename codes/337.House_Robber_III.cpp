/*
 * 337. House Robber III
 * Medium
 * 
 ********************************************************* 
 * The thief has found himself a new place for his thievery again. 
 * There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. 
 * After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
 * It will automatically contact the police if two directly-linked houses were broken into on the same night.
 * 
 * Determine the maximum amount of money the thief can rob tonight without alerting the police.
 * 
 *********************************************************
 * Example 1:
 * 
 * Input: [3,2,3,null,3,null,1]
 * 
 *      3
 *     / \
 *    2   3
 *     \   \ 
 *      3   1
 * 
 * Output: 7 
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 *********************************************************
 * Example 2:
 * 
 * Input: [3,4,5,1,3,null,1]
 * 
 *      3
 *     / \
 *    4   5
 *   / \   \ 
 *  1   3   1
 * 
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 ********************************************************* 
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
 
/*
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
    int rob(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return 0;
        }
        int do_it = root->val 
            + (root->left  == nullptr? 0: rob(root->left->left ) + rob(root->left->right))
            + (root->right == nullptr? 0: rob(root->right->left) + rob(root->right->right))
            ;
        int not_doit = rob(root->left) + rob(root->right);
        int result = std::max(do_it, not_doit);
        std::cout << "root:" << root->val << ",result:" << result << std::endl;
        return result;
    }

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << "| ";//<<std::endl;
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
};

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        TreeNode * root,
        int expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // getpermutataion
    {
        //start = std::chrono::system_clock::now();

        decltype(expected) result = solution.rob(root);
        std::cout << "result:" << std::boolalpha << result <<  std::endl;

        if(result == expected)
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
        //end = std::chrono::system_clock::now();
        //elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        //std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
    }
}
void Test1()
{
    TreeNode * pnode3_1 = new TreeNode(1);
    TreeNode * pnode3_3 = new TreeNode(3);
    TreeNode * pnode2_2 = new TreeNode(2, nullptr , pnode3_3);
    TreeNode * pnode2_3 = new TreeNode(3, nullptr , pnode3_1);
    TreeNode * pnode1_3 = new TreeNode(3, pnode2_2, pnode2_3);

    std::cout << "   3       " << std::endl;
    std::cout << "  / \\     " << std::endl;
    std::cout << " 2   3     " << std::endl;
    std::cout << "  \\   \\  " << std::endl;
    std::cout << "   3   1   " << std::endl;
    Test("Test1", pnode1_3, 7);
}
void Test2()
{
    TreeNode * pnode3_1 = new TreeNode(1);
    TreeNode * pnode3_3 = new TreeNode(3);
    TreeNode * pnode3_I = new TreeNode(1);
    TreeNode * pnode2_4 = new TreeNode(4, pnode3_1, pnode3_3);
    TreeNode * pnode2_5 = new TreeNode(5, nullptr , pnode3_I);
    TreeNode * pnode1_3 = new TreeNode(1, pnode2_4, pnode2_5);
    
    std::cout << "     3       " << std::endl;
    std::cout << "    / \\     " << std::endl;
    std::cout << "   4   5     " << std::endl;
    std::cout << " /  \\   \\  " << std::endl;
    std::cout << "1    3   1   " << std::endl;
    Test("Test2", pnode1_3, 9);
}

void Test3()
{
}

void Test4()
{
}

void Test5()
{
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
