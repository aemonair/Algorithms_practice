/*
 * 107. Binary Tree Level Order Traversal II
 ************************************************************
 * Medium
 ************************************************************
 * Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
 ************************************************************
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[15,7],[9,20],[3]]
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

std::ostream & operator << (std::ostream &out, TreeNode *root);
template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
    {
        std::queue<TreeNode *> q;
        if (!root ) {
            return {};
        }
        q.push(root);
        std::vector<std::vector<int>> result;
        while (!q.empty()) {
            int size = q.size();
            std::vector<int> res;
            for (int i =0; i< size; ++i) {
                auto curr = q.front();
                if(curr->left ) {
                    q.push(curr->left );
                }
                if(curr->right) {
                    q.push(curr->right);
                }
                res.push_back(curr->val);
                q.pop();
            }
            result.insert(result.begin(), res);
        }
        return result;
        return std::vector<std::vector<int>>();
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

    std::cout << "Tree:" << root << std::endl;
    // solution.printtree(root);
const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.levelOrderBottom(root);

        std::cout << "result: " << result << std::endl;
        // solution.printvectorvector(result);
        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            // solution.printvectorvector(expected);
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

    std::vector<std::vector<int>> expected = {{4,5},{2,3},{1}};
    Test("Test0", p_node1, expected );
}

void Test1()
{
    //Input: root = [3,9,20,null,null,15,7]
    //Output: [[15,7],[9,20],[3]]

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

    std::vector<std::vector<int>> expected = {{15,7},{9,20},{3}};
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

    std::vector<std::vector<int>> expected = {{4,5,6,7},{2,3},{1}};
    Test("Test1", p1, expected);
}
void Test5()
{
    std::cout << "      12        " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   7     1      " << std::endl;
    std::cout << "     \\  / \\   " << std::endl;
    std::cout << "      9 10  5   " << std::endl;
    struct TreeNode * p9 = new TreeNode(9 );
    struct TreeNode * p10= new TreeNode(10);
    struct TreeNode * p5 = new TreeNode(5 );
    struct TreeNode * p7 = new TreeNode(7, nullptr, p9);
    struct TreeNode * p1 = new TreeNode(1, p10, p5);
    struct TreeNode * p12= new TreeNode(12,p7 , p1);

    std::vector<std::vector<int>> expected = {{9,10,5},{7,1},{12}};
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
