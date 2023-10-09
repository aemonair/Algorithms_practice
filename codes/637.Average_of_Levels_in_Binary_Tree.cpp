/*
 * 637. Average of Levels in Binary Tree
 * Easy
 ************************************************************
 * Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
 *
 ************************************************************
 * Example 1:
 *
 * Input: root = [3,9,20,null,15,7]
 * Output: [3.00000,14.50000,11.00000]
 * Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
 * Hence return [3, 14.5, 11].
 ************************************************************
 * Example 2:
 *
 * Input: root = [3,9,20,15,7]
 * Output: [3.00000,14.50000,11.00000]
 *
 ************************************************************
 * Constraints:
 *
 * The number of nodes in the tree is in the range [1, 104].
 * -2^31 <= Node.val <= 2^31 - 1
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
class Solution {
public:

    std::vector<double> averageOfLevels(TreeNode* root)
    {
        if (!root) {
            return {};
        }
        std::queue<TreeNode *> q;
        q.push(root);
        std::vector<double> result;
        while (!q.empty()) {
            int size = q.size();
            double avg = 0.0;
            for (int i=0; i< size; ++i) {
                auto curr = q.front();
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                avg += curr->val;
                q.pop();
            }
            result.push_back(avg / size);
        }
        return result;
        return std::vector<double>();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        TreeNode * root,
        std::vector<double> expected)
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

        decltype(expected) result = solution.averageOfLevels(root);

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

    std::vector<double> expected = {{1},{2.5},{4.5}};
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

    std::vector<double> expected = {{3},{14.5},{11.0}};
    Test("Test1", p_node3, expected);
}

void Test2()
{
    TreeNode * p_node1 = new TreeNode(1 );

    std::vector<double> expected = {{1}};

    Test("Test2", p_node1, expected);
}

void Test3()
{
    //Input: root = [3,9,20,15,7]
    //Output: [3.00000,14.50000,11.00000]
    std::cout << "      3         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   9     20     " << std::endl;
    std::cout << "  / \\          " << std::endl;
    std::cout << "15  7           " << std::endl;

    TreeNode * p_node15= new TreeNode(15);
    TreeNode * p_node7 = new TreeNode(7 );
    TreeNode * p_node9 = new TreeNode(9 , p_node15, p_node7 );
    TreeNode * p_node20= new TreeNode(20);
    TreeNode * p_node3 = new TreeNode(3 , p_node9 , p_node20);

    std::vector<double> expected = {{3},{14.5},{11.0}};

    Test("Test3", p_node3, expected);
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

    std::vector<double> expected = {{1},{2.5},{5.5}};
    Test("Test1", p1, expected);
}
void Test5()
{
    std::cout << "      12        " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   7     1      " << std::endl;
    std::cout << "  /  \\  / \\   " << std::endl;
    std::cout << " 9    2 10  5   " << std::endl;
    struct TreeNode * p9 = new TreeNode(9 );
    struct TreeNode * p2 = new TreeNode(2 );
    struct TreeNode * p20= new TreeNode(20);
    struct TreeNode * p5 = new TreeNode(5 );
    struct TreeNode * p10= new TreeNode(10);
    struct TreeNode * p7 = new TreeNode(7, p9, p2);
    struct TreeNode * p1 = new TreeNode(1, p10, p5);
    struct TreeNode * p12= new TreeNode(12,p7 , p1);

    std::vector<double> expected = {{12},{4.0},{6.5}};
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
