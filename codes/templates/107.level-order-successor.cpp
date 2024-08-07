/*
 * Level Order Successor
 * easy
 ************************************************************
 * Given a binary tree and a node, find the level order successor of the given node in the tree. The level order successor is the node that appears right after the given node in the level order traversal.
 ************************************************************
 * Example 1:
 *
 *      1
 *     / \
 *    2   3
 *  /  \
 * 4    5
 *
 * Given Node: 3
 * Level Order Successor: 4
 ************************************************************
 * Example 2:
 *
 *      12
 *     /  \
 *    7    1
 *  /     / \
 * 9    10   5
 * Given Node: 9
 * Level Order Successor: 10
 ************************************************************
 * Example 3:
 *
 *      12
 *     /  \
 *    7    1
 *  /     / \
 * 9    10   5
 * Given Node: 12
 * Level Order Successor: 7
 ************************************************************
 * Constraints:
 *
 * The number of nodes in the tree is in the range [0, 105].
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
int getheight(TreeNode *root)
{
    if (root == nullptr) {
        return 0;
    }
    return 1+std::max(getheight(root->left), getheight(root->right));
}
std::ostream & operator << (std::ostream &out, TreeNode *root)
{
    int height = getheight(root);
    // out << "height:" << height << std::endl;
        if(root==nullptr)
        {
            out << "[ null ]"<< std::endl;
            return out;
        }
        out << std::endl;
        std::vector<std::vector<int>> result;
        std::queue<TreeNode *> queue;
        queue.push(root);
        int level = 0;
        while(queue.empty() == false)
        {
            int levelsize = queue.size();
            for (int j = 0; j < height - level ; j++) {
                out << " " ;
            }
            for(int i =0; i < levelsize; i++)
            {
                TreeNode * curr = queue.front();
                if (curr) {
                    out << (curr->val) << " ";
                    queue.push(curr->left);
                    queue.push(curr->right);
                } else {
                    // out << "N ";
                    out << "  ";
                }
                for (int j = 1; j < height - level ; j++) {
                    out << " ";
                }
                queue.pop();
            }
            out << std::endl;
            ++ level;
            // result.push_back(vec);
        }
        return out;
}
// std::ostream & operator << (std::ostream &out, TreeNode *root)
// {
//     if (root == nullptr) {
//         out << "N" << ",";
//         return out;
//     }
//     out << root->val << ",";
//     out << (root->left) ;
//     out << (root->right);
//     return out;
// }
class Solution {
public:
    //
    TreeNode * findSuccessor(TreeNode* root, int key)
    {
        return nullptr;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        TreeNode *root,
        int key,
        TreeNode *expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "find " << key << " successor of Tree:" << root << std::endl;
const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.findSuccessor(root, key);
        std::cout << "result:";// << result->val << std::endl;
        if (result)
        {
            std::cout << result->val << std::endl;
        }
        else
        {
            std::cout << "null" << std::endl;
        }

        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:";// << expected->val << std::endl;
            if (expected)
            {
                std::cout << expected->val << std::endl;
            }
            else
            {
                std::cout << "null" << std::endl;
            }
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
    Test("Test0", nullptr, 2, nullptr);
}
void Test1()
{
    std::cout << "      3         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   9     20     " << std::endl;
    std::cout << "         / \\   " << std::endl;
    std::cout << "       15   7   " << std::endl;
    TreeNode * pnode3 = new TreeNode(3);
    TreeNode * pnode9 = new TreeNode(9);
    TreeNode * pnode20= new TreeNode(20);
    TreeNode * pnode15= new TreeNode(15);
    TreeNode * pnode7 = new TreeNode(7);
    pnode3 ->left  = pnode9 ;
    pnode3 ->right = pnode20;
    pnode20->left  = pnode15;
    pnode20->right = pnode7 ;
    Test("Test1", pnode3, 20, pnode15);
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
    std::cout << "        \\        " << std::endl;
    std::cout << "         3        " << std::endl;
    std::cout << "           \\     " << std::endl;
    std::cout << "            4     " << std::endl;
    std::cout << "             \\   " << std::endl;
    std::cout << "              5   " << std::endl;
    std::cout << "               \\ " << std::endl;
    std::cout << "                6 " << std::endl;
    TreeNode * pnode6 = new TreeNode(6);
    TreeNode * pnode5 = new TreeNode(5, nullptr, pnode6);
    TreeNode * pnode4 = new TreeNode(4, nullptr, pnode5);
    TreeNode * pnode3 = new TreeNode(3, nullptr, pnode4);
    TreeNode * pnode2 = new TreeNode(2, nullptr, pnode3);
    Test("Test2", pnode2, 5, pnode6);
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
    Test("Test3", pnode1,3, pnode4);
}

void Test4()
{
    //Test("Test4", 6, 6, 3);
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

    int expected = 3;
    Test("Test1", p1, 3, p4);
}
void Test5()
{
    //Test("Test4", 6, 6, 3);
    std::cout << "      12        " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   7     1      " << std::endl;
    std::cout << " /       / \\   " << std::endl;
    std::cout << "9       10  5   " << std::endl;

    struct TreeNode * p9 = new TreeNode(9 );
    struct TreeNode * p5 = new TreeNode(5 );
    struct TreeNode * p10= new TreeNode(10);
    struct TreeNode * p7 = new TreeNode(7, p9, nullptr);
    struct TreeNode * p1 = new TreeNode(1, p10, p5);
    struct TreeNode * p12= new TreeNode(12,p7 , p1);
    Test("Test2", p12, 9, p10);
    Test("Test3", p12, 12, p7);
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
