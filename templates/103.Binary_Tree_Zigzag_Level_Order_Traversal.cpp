/*
 * 103. Binary Tree Zigzag Level Order Traversal
 * Medium
 ************************************************************
 * Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
 ************************************************************
 * Example 1:
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
 ************************************************************
 * Example 2:
 * 
 * Input: root = [1]
 * Output: [[1]]
 ************************************************************
 * Example 3:
 * 
 * Input: root = []
 * Output: []
 ************************************************************
 * Constraints:
 * 
 * The number of nodes in the tree is in the range [0, 2000].
 * -100 <= Node.val <= 100
 ************************************************************
 */
#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
/**
 * Definition for a binary tree node.
 */
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


    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        return std::vector<std::vector<int>>();
    }
    int printtree  (const TreeNode * root)
    {
        if (root==nullptr)
        {
            std::cout << "null tree. " << std::endl;
            return 0;
        }
        std::cout << "root->val: " << root->val << std::endl;
        printtreenode(root);
        std::cout << std::endl;
        return 0;
    }
    int printtreenode (const TreeNode * root)
    {
        if(root==nullptr)
        {
            std::cout << "N" << ",";
        }
        else
        {
            std::cout << root->val << ",";
            printtreenode(root->left);
            printtreenode(root->right);
        }
        return 0;
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

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        //std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  " ; // << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", ";//<<std::endl;
        }
        std::cout << "\b\b ]" ; // << std::endl;
        //std::cout << std::endl;
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
        std::vector<std::vector<int>> expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Tree:" << std::endl;
    solution.printtree(root);
const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.zigzagLevelOrder(root);

        std::cout << "result: ";
        solution.printvectorvector(result);
        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::endl;
            solution.printvectorvector(expected);
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    std::cout << "-----------------------------" << std::endl;
}
void Test0()
{
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    std::cout << "    \\   /      " << std::endl;
    std::cout << "     4  5       " << std::endl;
    TreeNode * p_node4 = new TreeNode(4);
    TreeNode * p_node5 = new TreeNode(5);
    TreeNode * p_node2 = new TreeNode(2, nullptr, p_node4);
    TreeNode * p_node3 = new TreeNode(3, p_node5, nullptr);
    TreeNode * p_node1 = new TreeNode(1, p_node2, p_node3);

    std::vector<std::vector<int>> expected = {{1},{3,2},{4,5}};
    Test("Test0", p_node1, expected );
}

void Test1()
{
    //Input: root = [3,9,20,null,null,15,7]
    //Output: [[3],[20,9],[15,7]]

    std::cout << "      3         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   9     20     " << std::endl;
    std::cout << "         / \\   " << std::endl;
    std::cout << "        15  7   " << std::endl;

    TreeNode * p_node15= new TreeNode(15);
    TreeNode * p_node7 = new TreeNode(7 );
    TreeNode * p_node9 = new TreeNode(9 );
    TreeNode * p_node20= new TreeNode(20, p_node15, p_node7 );
    TreeNode * p_node3 = new TreeNode(3 , p_node9 , p_node20);

    std::vector<std::vector<int>> expected = {{3},{20,9},{15,7}};
    Test("Test1", p_node3, expected);
}

void Test2()
{
    TreeNode * p_node1 = new TreeNode(1 );

    std::vector<std::vector<int>> expected = {{1}};

    Test("Test2", p_node1, expected);
}

void Test3()
{
    std::vector<std::vector<int>> expected = {};

    Test("Test3", nullptr , expected);
}

void Test4()
{
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    std::cout << " /   \\  / \\   " << std::endl;
    std::cout << "4     5 6   7   " << std::endl;

    TreeNode * p7 = new TreeNode(7);
    TreeNode * p6 = new TreeNode(6);
    TreeNode * p5 = new TreeNode(5);
    TreeNode * p4 = new TreeNode(4);
    TreeNode * p3 = new TreeNode(3, p6, p7);
    TreeNode * p2 = new TreeNode(2, p4, p5);
    TreeNode * p1 = new TreeNode(1, p2, p3);

    std::vector<std::vector<int>> expected = {{1},{3,2},{4,5,6,7}};
    Test("Test1", p1, expected);
}
void Test5()
{
    std::cout << "      12        " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   7     1      " << std::endl;
    std::cout << "     \\  / \\   " << std::endl;
    std::cout << "      9 10  5   " << std::endl;
    std::cout << "       / \\     " << std::endl;
    std::cout << "      20 17     " << std::endl;
    struct TreeNode * p9 = new TreeNode(9 );
    struct TreeNode * p17= new TreeNode(17);
    struct TreeNode * p20= new TreeNode(20);
    struct TreeNode * p5 = new TreeNode(5 );
    struct TreeNode * p10= new TreeNode(10, p20, p17);
    struct TreeNode * p7 = new TreeNode(7, nullptr, p9);
    struct TreeNode * p1 = new TreeNode(1, p10, p5);
    struct TreeNode * p12= new TreeNode(12,p7 , p1);

    std::vector<std::vector<int>> expected = {{12},{1,7},{9,10,5},{17,20}};
    Test("Test2", p12, expected);
}

int main()
{
    Solution solution;

    Test0();
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;

}
