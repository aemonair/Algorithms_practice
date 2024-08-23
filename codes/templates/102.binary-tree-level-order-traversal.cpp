/*
 * 102. Binary Tree Level Order Traversal
 * Medium
 ************************************************************
 * Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
 ************************************************************
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 ************************************************************
 * Example 2:
 * Input: root = [1]
 * Output: [[1]]
 ************************************************************
 * Example 3:
 * Input: root = []
 * Output: []
 ************************************************************
 * Constraints:
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
 ************************************************************
 */
#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <thread>
#include <queue>
#include <map>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
/**
 * Definition for a binary tree node.
 */
template<typename T>
class TreeNode {
public:
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(T x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);
template<typename T>
std::ostream & operator << (std::ostream &out, TreeNode<T> *root);
template <typename T>
bool isSame(TreeNode<T> *T1, TreeNode<T> *T2);

class Solution {
public:
    template <typename T>
    std::vector<std::vector<int>> levelOrder(TreeNode<T>* root)
    {
        return {};
    }
};
// ==================== TEST Codes====================
template<typename T>
void Test(const std::string& testName,
        TreeNode<T> * root,
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

    std::cout << "Tree:" << root << std::endl;
const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.levelOrder(root);

        std::cout << "result: " << result << std::endl;
        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
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
template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec)
{
    out << "[  ";
    for(auto v: _vec)
    {
        out << v << ", ";
    }
    out << "\b\b ]" ;
    return out;
}
template<typename T>
std::ostream & operator << (std::ostream &out, TreeNode<T> *root)
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
template <typename T>
bool isSame(TreeNode<T> *T1, TreeNode<T> *T2)
{
    if (T1 == nullptr && T2==nullptr)
    {
        return true;
    }
    if(T1 == nullptr || T2 == nullptr)
    {
        return false;
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
void Test0()
{
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    std::cout << "    \\   /      " << std::endl;
    std::cout << "     4  5       " << std::endl;
    TreeNode<int> * p_node4 = new TreeNode<int>(4);
    TreeNode<int> * p_node5 = new TreeNode<int>(5);
    TreeNode<int> * p_node2 = new TreeNode<int>(2, nullptr, p_node4);
    TreeNode<int> * p_node3 = new TreeNode<int>(3, p_node5, nullptr);
    TreeNode<int> * p_node1 = new TreeNode<int>(1, p_node2, p_node3);

    std::vector<std::vector<int>> expected = {{1},{2,3},{4,5}};
    Test("Test0", p_node1, expected );
}

void Test1()
{
    //Input: root = [3,9,20,null,null,15,7]
    //Output: [[3],[9,20],[15,7]]
    std::cout << "      3         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   9     20     " << std::endl;
    std::cout << "         / \\   " << std::endl;
    std::cout << "        15  7   " << std::endl;

    TreeNode<int> * p_node15= new TreeNode<int>(15);
    TreeNode<int> * p_node7 = new TreeNode<int>(7 );
    TreeNode<int> * p_node9 = new TreeNode<int>(9 );
    TreeNode<int> * p_node20= new TreeNode<int>(20, p_node15, p_node7 );
    TreeNode<int> * p_node3 = new TreeNode<int>(3 , p_node9 , p_node20);

    std::vector<std::vector<int>> expected = {{3},{9,20},{15,7}};
    Test("Test1", p_node3, expected);
}

void Test2()
{
    TreeNode<int> * p_node1 = new TreeNode<int>(1 );

    std::vector<std::vector<int>> expected = {{1}};

    Test("Test2", p_node1, expected);
}

void Test3()
{
    std::vector<std::vector<int>> expected = {};
    TreeNode<int> * p_node1 = nullptr; //new TreeNode<int>(1 );

    Test("Test3", p_node1, expected);
}

void Test4()
{
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    std::cout << " /   \\  / \\   " << std::endl;
    std::cout << "4     5 6   7   " << std::endl;

    TreeNode<int> * p7 = new TreeNode<int>(7);
    TreeNode<int> * p6 = new TreeNode<int>(6);
    TreeNode<int> * p5 = new TreeNode<int>(5);
    TreeNode<int> * p4 = new TreeNode<int>(4);
    TreeNode<int> * p3 = new TreeNode<int>(3, p6, p7);
    TreeNode<int> * p2 = new TreeNode<int>(2, p4, p5);
    TreeNode<int> * p1 = new TreeNode<int>(1, p2, p3);

    std::vector<std::vector<int>> expected = {{1},{2,3},{4,5,6,7}};
    Test("Test1", p1, expected);
}
void Test5()
{
    std::cout << "      12        " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   7     1      " << std::endl;
    std::cout << "     \\  / \\   " << std::endl;
    std::cout << "      9 10  5   " << std::endl;
    TreeNode<int> * p9 = new TreeNode<int>(9 );
    TreeNode<int> * p10= new TreeNode<int>(10);
    TreeNode<int> * p5 = new TreeNode<int>(5 );
    TreeNode<int> * p7 = new TreeNode<int>(7, nullptr, p9);
    TreeNode<int> * p1 = new TreeNode<int>(1, p10, p5);
    TreeNode<int> * p12= new TreeNode<int>(12,p7 , p1);

    std::vector<std::vector<int>> expected = {{12},{7,1},{9,10,5}};
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
