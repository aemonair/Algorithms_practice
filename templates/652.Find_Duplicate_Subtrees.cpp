/*
 * 652. Find Duplicate Subtrees
 * Medium
 * 
 *************************************************************************************
 * Given the root of a binary tree, return all duplicate subtrees.
 * 
 * For each kind of duplicate subtrees, you only need to return the root node of any one of them.
 * 
 * Two trees are duplicate if they have the same structure with the same node values.
 *************************************************************************************
 * 
 * Example 1:
 * 
 *           1
 *          / \
 *         2   3 
 *        /   / \
 *       4   2   4
 *          /
 *         4 
 * Input: root = [1,2,3,4,null,2,4,null,null,4]
 * Output: [[2,4],[4]]
 *************************************************************************************
 * Example 2:
 * 
 *     2
 *    / \
 *   1   1
 * 
 * Input: root = [2,1,1]
 * Output: [[1]]
 *************************************************************************************
 * Example 3:
 * 
 *       2
 *      / \
 *     2   2
 *    /   /
 *   3   3    
 * 
 * Input: root = [2,2,2,3,null,3,null]
 * Output: [[2,3],[3]]
 *************************************************************************************
 * Constraints:
 * 
 * The number of the nodes in the tree will be in the range [1, 10^4]
 * -200 <= Node.val <= 200
 *************************************************************************************
 * 
 */

#include <unordered_map>
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
class TreeNode ;
class TreeNode 
{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    std::ostream& operator<<(std::ostream& os )//,const TreeNode &a)
    {
        os <<val<<",";
        return os;
    }
};
 
class Solution {
public:
    // 
    std::vector<TreeNode*> res = {};
    std::unordered_map<std::string ,int> memo;
    std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        return res;
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
    template <typename T1, typename T2>
    int printunordered_map(const std::unordered_map<T1,T2> &v)
    {
        std::cout << "unordered_map size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << " " << iter->first << ":" << iter->second<<std::endl;
        }
        std::cout << std::endl;
        return v.size();
    }
    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << (*iter)->val << "| "<<std::endl;
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
        TreeNode *root,
        std::vector<TreeNode*> expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Tree:" << std::endl;
    solution.printtree(root);
    std::cout << "expected:" << std::endl;
    solution.printvector(expected);
    // getpermutataion
const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "findDuplicateSubtrees:" << std::endl;
        std::vector<TreeNode *> result = solution.findDuplicateSubtrees(root);

        if (result == expected)
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
    TreeNode * p_node3_4  = new TreeNode(4);
    TreeNode * p_node2_4  = new TreeNode(4);
    TreeNode * p_node2_4_ = new TreeNode(4);
    TreeNode * p_node2_2  = new TreeNode(2, p_node3_4, nullptr);
    TreeNode * p_node1_2  = new TreeNode(2, p_node2_4, nullptr);
    TreeNode * p_node1_3  = new TreeNode(3, p_node2_2, p_node2_4_);
    TreeNode * p_node0_1  = new TreeNode(1,p_node1_2, p_node1_3);
    
    std::cout << "        1       " << std::endl;
    std::cout << "       / \\     " << std::endl;
    std::cout << "      2   3     " << std::endl;
    std::cout << "     /   / \\   " << std::endl;
    std::cout << "    4   2   4   " << std::endl;
    std::cout << "       /        " << std::endl;
    std::cout << "      4         " << std::endl;
    ////////////////////////////////////
    std::vector<TreeNode*> expect = {p_node3_4, p_node2_2};
    Test("Test1", p_node0_1,expect);
    std::cout << "----------------" << std::endl;
}
void Test2()
{
    std::cout << "      2         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   1     1      " << std::endl;
    TreeNode * p_node1_1 = new TreeNode(1);
    TreeNode * p_node2_1 = new TreeNode(1);
    TreeNode * p_node2   = new TreeNode(2, p_node1_1, p_node2_1);
    std::vector<TreeNode*> expect = {p_node2_1};
    Test("Test2", p_node2, expect);
    std::cout << "----------------" << std::endl;
}

void Test3()
{
    std::vector<int> inorder   = {9,3,15,20,7};
    std::vector<int> postorder = {9,15,7,20,3};
    std::cout << "     2               " << std::endl;
    std::cout << "    / \\             " << std::endl;
    std::cout << "   2   2             " << std::endl;
    std::cout << "  /   /              " << std::endl;
    std::cout << " 3   3               " << std::endl;
    TreeNode * p_node2_3 = new TreeNode(3);
    TreeNode * p_node2_3_= new TreeNode(3);
    TreeNode * p_node1_2 = new TreeNode(2,p_node2_3 ,nullptr);
    TreeNode * p_node1_2_= new TreeNode(2,p_node2_3_,nullptr);
    TreeNode * p_node0_2 = new TreeNode(2,p_node1_2 ,p_node1_2_);
    std::vector<TreeNode*> expect = {p_node2_3_,p_node1_2_};
    Test("Test3", p_node0_2, expect);
    std::cout << "----------------" << std::endl;
}

void Test4()
{
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
