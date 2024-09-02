/*
 ************************************************************
 * 543. Diameter of Binary Tree
 * Easy
 ************************************************************
 * Given the root of a binary tree, return the length of the diameter of the tree.
 *
 * The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
 *
 * The length of a path between two nodes is represented by the number of edges between them.
 ************************************************************
 * Example 1:
 *
 *      1
 *     / \
 *    2   3
 *   / \
 *  4   5
 * Input: root = [1,2,3,4,5]
 * Output: 3
 * Explanation: 3is the length of the path [4,2,1,3] or [5,2,1,3].
 ************************************************************
 * Example 2:
 *
 *      1
 *     /
 *    2
 * Input: root = [1,2]
 * Output: 1
 ************************************************************
 * Constraints:
 *
 * The number of nodes in the tree is in the range [1, 104].
 * -100 <= Node.val <= 100
 ************************************************************
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
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

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);
std::ostream & operator << (std::ostream &out, TreeNode *root);

class Solution {
public:
    //
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (!root) {
            return 0;
        }
        int max = 0;
        diameterOfBinaryTree(root, max);
        return max;
    }
    int diameterOfBinaryTree(TreeNode* root, int &max) {
        if(!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        int lefthight = diameterOfBinaryTree(root->left, max);
        int righthight = diameterOfBinaryTree(root->right,max);
        max = std::max(max, lefthight + righthight);
        return 1 + std::max(lefthight, righthight);
    }
    int diameterOfBinaryTree1(TreeNode* root)
    {
        return 0;
    }
};

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec)
{
    out << "[  ";
    for(auto v: _vec)
    {
        out << "(" << v << "), ";
    }
    out << "\b\b ]" ;
    return out;
}
std::ostream & operator << (std::ostream &out, TreeNode *root)
{
    if (root == nullptr) {
        out << "N" << ",";
        return out;
    }
    out << root->val << ",";
    out << (root->left) ;
    out << (root->right);
    return out;
}
// ==================== TEST Codes====================
void Test(const std::string& testName,
        TreeNode *root,
        int expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Tree:" << root << std::endl;
    //solution.printtree(root);
const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;

    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.diameterOfBinaryTree(root);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if(TEST_1)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.diameterOfBinaryTree1(root);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    std::cout << "-----------------------------" << std::endl;
}

void Test0()
{
    int expected = 0;
    Test("Test0", nullptr, expected);
}
void Test1()
{
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    std::cout << "  / \\          " << std::endl;
    std::cout << " 4   5          " << std::endl;
    TreeNode * pnode4 = new TreeNode(4);
    TreeNode * pnode5 = new TreeNode(5);
    TreeNode * pnode2 = new TreeNode(2, pnode4, pnode5);
    TreeNode * pnode3 = new TreeNode(3);
    TreeNode * pnode1 = new TreeNode(1, pnode2, pnode3);

    int expected = 3;

    std::cout << "3 is the length of the path [4,2,1,3] or [5,2,1,3]." << std::endl;
    Test("Test1", pnode1, expected);
}
void Test2()
{
    // [2,null,3,null,4,null,5,null,6]
    //    2
    //   n  3
    //      n 4
    //       n 5
    //         n 6
    std::cout << "      2           " << std::endl;
    std::cout << "       \\        " << std::endl;
    std::cout << "        3        " << std::endl;
    std::cout << "          \\     " << std::endl;
    std::cout << "           4     " << std::endl;
    std::cout << "             \\   " << std::endl;
    std::cout << "              5   " << std::endl;
    std::cout << "                \\ " << std::endl;
    std::cout << "                 6 " << std::endl;
    TreeNode * pnode6 = new TreeNode(6);
    TreeNode * pnode5 = new TreeNode(5, nullptr, pnode6);
    TreeNode * pnode4 = new TreeNode(4, nullptr, pnode5);
    TreeNode * pnode3 = new TreeNode(3, nullptr, pnode4);
    TreeNode * pnode2 = new TreeNode(2, nullptr, pnode3);
    int expected = 4;
    Test("Test2", pnode2, expected);
}

void Test3()
{
    std::cout << "      1         " << std::endl;
    std::cout << "        \\      " << std::endl;
    std::cout << "         2      " << std::endl;
    std::cout << "         / \\   " << std::endl;
    std::cout << "        3   4   " << std::endl;
    std::cout << "           /    " << std::endl;
    std::cout << "          5     " << std::endl;
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
    int expected =  3;
    Test("Test3", pnode1, expected);
}

void Test4()
{
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    std::cout << "  /     / \\    " << std::endl;
    std::cout << " 4     5   6    " << std::endl;

    TreeNode * p6 = new TreeNode(6);
    TreeNode * p5 = new TreeNode(5);
    TreeNode * p4 = new TreeNode(4);
    TreeNode * p3 = new TreeNode(3, p5, p6);
    TreeNode * p2 = new TreeNode(2, p4, nullptr);
    TreeNode * p1 = new TreeNode(1, p2, p3);

    int expected = 4;
    Test("Test1", p1, expected);
}
void Test5()
{
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    std::cout << "        / \\    " << std::endl;
    std::cout << "       5   6    " << std::endl;
    std::cout << "      / \\  \\  " << std::endl;
    std::cout << "     7   8   9  " << std::endl;
    std::cout << "        /   /   " << std::endl;
    std::cout << "       10  11   " << std::endl;

    struct TreeNode * p11= new TreeNode(11);
    struct TreeNode * p10= new TreeNode(10);
    struct TreeNode * p9 = new TreeNode(9 ,p11, nullptr);
    struct TreeNode * p8 = new TreeNode(8 ,p10, nullptr);
    struct TreeNode * p7 = new TreeNode(7 );
    struct TreeNode * p6 = new TreeNode(6 ,nullptr, p9);
    struct TreeNode * p5 = new TreeNode(5 , p7 , p8);
    struct TreeNode * p3 = new TreeNode(3 , p5 , p6);
    struct TreeNode * p2 = new TreeNode(2 );
    struct TreeNode * p1 = new TreeNode(1, p2 , p3);
    int expected = 6;
    Test("Test2", p1, expected );
}
void Test6()
{
    std::cout << "      5         " << std::endl;
    std::cout << "     / \\       " << std::endl;
    std::cout << "    4   8       " << std::endl;
    std::cout << "   /   / \\     " << std::endl;
    std::cout << "  3   9   4     " << std::endl;
    std::cout << " / \\    / \\   " << std::endl;
    std::cout << "7   2   5   1   " << std::endl;

    struct TreeNode * p7 = new TreeNode(7 );
    struct TreeNode * p2 = new TreeNode(2 );
    struct TreeNode * p_5= new TreeNode(5 );
    struct TreeNode * p1 = new TreeNode(1 );
    struct TreeNode * p9 = new TreeNode(9 );
    struct TreeNode * p3 = new TreeNode(3 , p7, p2);
    struct TreeNode * p4 = new TreeNode(4 , p_5, p1);
    struct TreeNode * p_4= new TreeNode(4 , p3 , nullptr);
    struct TreeNode * p8 = new TreeNode(8, p9 , p4 );
    struct TreeNode * p5 = new TreeNode(5 ,p_4, p8);
    int expected = 6;
    Test("Test6", p5, expected );
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
    Test6();

    return 0;

}
