/*
 ************************************************************
 * 1430. Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree
 * Medium
 ************************************************************
 * Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a given string is a valid sequence in such binary tree.
 *
 * We get the given string from the concatenation of an array of integers arr and the concatenation of all values of the nodes along a path results in a sequence in the given binary tree.
 ************************************************************
 * Example 1:
 *
 *            0
 *          /   \
 *         1     0
 *       /   \   /
 *      0     1 0
 *       \   / \
 *        1 0   0
 * Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
 * Output: true
 *
 * Explanation:
 * The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure).
 * Other valid sequences are:
 * 0 -> 1 -> 1 -> 0
 * 0 -> 0 -> 0
 ************************************************************
 * Example 2:
 *
 *            0
 *          /   \
 *         1     0
 *       /   \   /
 *      0     1 0
 *       \   / \
 *        1 0   0
 * Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
 * Output: false
 * Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not even a sequence.
 ************************************************************
 * Example 3:
 *
 *            0
 *          /   \
 *         1     0
 *       /   \   /
 *      0     1 0
 *       \   / \
 *        1 0   0
 * Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
 * Output: false
 * Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a valid sequence.
 ************************************************************
 * Constraints:
 * 1 <= arr.length <= 5000
 * 0 <= arr[i] <= 9
 * Each node's value is between [0 - 9].
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
    bool isValidSequence(TreeNode* root, std::vector<int> &arr)
    {
        return true;
    }
    bool isValidSequence1(TreeNode* root, std::vector<int> &arr)
    {
        return true;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        TreeNode *root,
        std::vector<int> &arr,
        bool expected)
{
    if(testName.length() > 0)
    {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "find arr:" << " " << arr << " " << root << std::endl;
const static int TEST_TIME = 1;
const static int TEST__    = 1;
const static int TEST_1    = 0;

    if(TEST__)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.isValidSequence(root, arr);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::boolalpha << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    }
    if(TEST_1)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.isValidSequence1(root, arr);
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
        std::cout << "-----------------------------" << std::endl;
    }
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
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}
std::ostream & operator << (std::ostream &out, TreeNode *root)
{
    bool printline=false;
    if (root == nullptr) {
        out << "N" << ",";
        return out;
    }
    out << std::endl;
    //out << root->val << ",";
    //out << (root->left) ;
    //out << (root->right);

    int depth = maxDepth(root);
    int last_layer_offset = 1 ; //(1 << (depth - 1)) - 1; // 最后一层的offset
    int max_width = (last_layer_offset * 2 + 1) * (1 << (depth - 1)); // 确保最后一层有足够的空间

    std::vector<std::vector<char>> grid(depth * 2 - 1, std::vector<char>(max_width, ' '));

    std::queue<std::tuple<TreeNode*, int, int>> q; // (node, row, col)
    q.push({root, 0, (max_width - 1) / 2}); // 根节点在第一行中间

    std::vector<int> offsets(depth, 0); // 存储每一层的offset
    offsets[depth - 1] = last_layer_offset;

    // 计算每一层的offset
    for (int i = depth - 2; i >= 0; --i) {
        offsets[i] = offsets[i + 1] * 2;
    }
    for (auto i=0; i< offsets.size(); ++i) {
    }

    while (!q.empty()) {
        auto [node, row, col] = q.front();
        q.pop();
        grid[row][col] = node->val + '0'; // 将数值转换为字符

        int next_row = row + 2; // 下一层的行索引，考虑到行间距
        int current_offset = offsets[row/2];

        if (node->left) {
            int left_col = col - current_offset/2;
            q.push({node->left, next_row, left_col});
            if (printline) {
                grid[row + 1][col - (current_offset / 4)] = '/'; // 斜杠位置
            }
        }
        if (node->right) {
            int right_col = col + current_offset/2;
            q.push({node->right, next_row, right_col});
            if (printline) {
                grid[row + 1][col + (current_offset / 4)] = '\\'; // 斜杠位置
            }
        }
    }

    for (const auto& row : grid) {
        for (char c : row) {
            if ((c>'0' && c<'9') || (c=='\\') ||c=='/' || c == ' ') {
                out << c << " ";
            } else {
                out << static_cast<int>(c-'0') <<  " ";// << std::endl;
            }
        }
        out << std::endl;
    }
    return out;
}

void Test0()
{
    std::vector<int> arr = {};
    bool expected = false;
    Test("Test0", nullptr, arr, expected);
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

    std::vector<int> arr= {3, 9};
    bool expected = true;

    Test("Test1", pnode3, arr,expected);
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
    std::vector<int> arr= {2,3,4,5};
    bool expected = false;
    Test("Test2", pnode2, arr, expected);
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
    std::vector<int> arr= {1,2,3};
    bool expected = true;
    Test("Test3", pnode1, arr, expected);
}

void Test4()
{
    //Test("Test4", 6, 6, 3);
     std::cout << "      0        " << std::endl;
     std::cout << "    /   \\     " << std::endl;
     std::cout << "   1     0     " << std::endl;
     std::cout << " /   \\  /     " << std::endl;
     std::cout << "0     1 0      " << std::endl;
     std::cout << " \\  / \\      " << std::endl;
     std::cout << "  1 0   0      " << std::endl;

    TreeNode * p9 = new TreeNode(0);
    TreeNode * p8 = new TreeNode(0);
    TreeNode * p7 = new TreeNode(1);
    TreeNode * p6 = new TreeNode(0);
    TreeNode * p5 = new TreeNode(0, p8, p9);
    TreeNode * p4 = new TreeNode(0, nullptr, p7);
    TreeNode * p3 = new TreeNode(0, p6, nullptr);
    TreeNode * p2 = new TreeNode(1, p4, p5);
    TreeNode * p1 = new TreeNode(0, p2, p3);
    {
        std::vector<int> arr= {0,1,0,1};
        bool expected = true;
        Test("Test1", p1, arr, expected);
    }
    {
        std::vector<int> arr= {0,0,1};
        bool expected = false;
        Test("Test1", p1, arr, expected);
    }
    {
        std::vector<int> arr= {0,1,1};
        bool expected = false;
        Test("Test1", p1, arr, expected);
    }
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
    std::vector<int> arr= {12,1,7};
    bool expected = false;
    Test("Test5", p12, arr,  expected );
}
void Test6()
{
    std::cout << "      5         " << std::endl;
    std::cout << "     / \\       " << std::endl;
    std::cout << "    4   8       " << std::endl;
    std::cout << "   /   / \\     " << std::endl;
    std::cout << "  11  13  4     " << std::endl;
    std::cout << " / \\    / \\   " << std::endl;
    std::cout << "7   2   5   1   " << std::endl;

    struct TreeNode * p7 = new TreeNode(7 );
    struct TreeNode * p2 = new TreeNode(2 );
    struct TreeNode * p_5= new TreeNode(5 );
    struct TreeNode * p1 = new TreeNode(1 );
    struct TreeNode * p13= new TreeNode(13);
    struct TreeNode * p11= new TreeNode(11, p7, p2);
    struct TreeNode * p4 = new TreeNode(4 , p_5, p1);
    struct TreeNode * p_4= new TreeNode(4 , p11, nullptr);
    struct TreeNode * p8 = new TreeNode(8, p13, p4 );
    struct TreeNode * p5 = new TreeNode(5 ,p_4, p8);
    {
        std::vector<int> arr= {5,4,11};
        bool expected = false;
        Test("Test6.1", p5, arr,  expected );
    }
    {
        std::vector<int> arr= {5,8,4,5,1};
        bool expected = false;
        Test("Test6.2", p5, arr,  expected );
    }
    {
        std::vector<int> arr= {5,8,4,5};
        bool expected = true ;
        Test("Test6.3", p5, arr,  expected );
    }
    {
        std::vector<int> arr= {5,8,4,5,1};
        bool expected = false;
        Test("Test6.4", p5, arr,  expected );
    }
}
int main()
{
    Solution solution;

    Test0();
    Test4();
    Test1();
    Test2();
    Test3();
    Test5();
    Test6();

    return 0;

}
