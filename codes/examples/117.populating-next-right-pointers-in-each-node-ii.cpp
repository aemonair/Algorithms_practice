/*
 * 117. Populating Next Right Pointers in Each Node II
 * Medium
 ************************************************************
 * Given a binary tree
 *
 * struct Node {
 *  int val;
 *  Node *left;
 *  Node *right;
 *  Node *next;
 * }
 * Populate each next pointer to point to its next right node.
 * If there is no next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 ************************************************************
 *
 *
 * Follow up:
*
 * You may only use constant extra space.
 * Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem`
 *
 ************************************************************
 *
 *     1                 1 -->N
 *    / \               / \
 *   2   3             2-->3 -->N
 *  / \   \           / \   \
 * 4   5   7         4-->5-->7 -->N
 *
 * Input: root = [1,2,3,4,5,null,7]
 * Output: [1,#,2,3,#,4,5,7,#]
 * Explanation:
 * Given the above binary tree (Figure A),
 * your function should populate each next pointer to point to its next right node, just like in Figure B.
 * The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 ************************************************************
 * Constraints:
 *
 * The number of nodes in the given tree is less than 6000.
 * -100 <= node.val <= 100
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

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);
std::ostream & operator << (std::ostream &out, Node *root);

class Solution {
public:
    Node* connect(Node* root)
    {
        std::queue<Node *> queue;
        if (!root) {
            return {};
        }
        queue.push(root);
        // std::vector<std::vector<int>> result;
        while (!queue.empty()) {
            int size = queue.size();
            while(size > 0) {
                Node * top = queue.front();
                if (top->left) {
                    queue.push(top->left);
                }
                if (top->right) {
                    queue.push(top->right);
                }
                --size;
                queue.pop();
                if (size > 0) {
                    top->next = queue.front();
                }
            }
        }
        return root  ;
        return nullptr;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        Node * root,
        Node * expected)
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

        decltype(expected) result = solution.connect(root);
        std::cout << "result:" << result << std::endl;// << result->val << std::endl;

        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected <<  std::endl;
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
std::ostream & operator << (std::ostream &out, Node *root)
{
    if (root == nullptr) {
        // out << "N" << ",";
        return out;
    }
    out << root->val << " " ;
    if (root->next) {
        out << "->" << root->next->val << ");";
    } else {
        out << "->N);" ;
    }
    out << (root->left) ;
    out << (root->right);
    return out;
}
int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}
int printTreeGrid(Node* root, bool printline=false)
{
    int depth = maxDepth(root);
    int last_layer_offset = 1 ; //(1 << (depth - 1)) - 1; // 最后一层的offset
    int max_width = (last_layer_offset * 2 + 1) * (1 << (depth - 1)); // 确保最后一层有足够的空间
    //std::cout << "last_layer_offset:" << last_layer_offset << ",max_width:" << max_width << std::endl;

    std::vector<std::vector<char>> grid(depth * 2 - 1, std::vector<char>(max_width, ' '));

    std::queue<std::tuple<Node*, int, int>> q; // (node, row, col)
    q.push({root, 0, (max_width - 1) / 2}); // 根节点在第一行中间

    std::vector<int> offsets(depth, 0); // 存储每一层的offset
    offsets[depth - 1] = last_layer_offset;

    // 计算每一层的offset
    for (int i = depth - 2; i >= 0; --i) {
        offsets[i] = offsets[i + 1] * 2;
        //std::cout << "offset:" << i << " :" << offsets[i] << std::endl;
    }
    for (auto i=0; i< offsets.size(); ++i) {
        //std::cout << "offset:" << i << " :" << offsets[i] << std::endl;
    }

    while (!q.empty()) {
        auto [node, row, col] = q.front();
        //std::cout << "row:" << row << ",col:" << col << ",value:" << node->val << std::endl;
        q.pop();
        grid[row][col] = node->val + '0'; // 将数值转换为字符

        int next_row = row + 2; // 下一层的行索引，考虑到行间距
        int current_offset = offsets[row/2];
        //std::cout << "row:" << row << ";current_offset:" << current_offset << std::endl;

        if (node->left) {
            int left_col = col - current_offset/2;
            //std::cout << "left_col:" << col-current_offset/2 << std::endl;
            q.push({node->left, next_row, left_col});
            if (printline) {
                grid[row + 1][col - (current_offset / 4)] = '/'; // 斜杠位置
            }
        }
        if (node->right) {
            int right_col = col + current_offset/2;
            //std::cout << "right_col:" << col+current_offset/2 << std::endl;
            q.push({node->right, next_row, right_col});
            if (printline) {
                grid[row + 1][col + (current_offset / 4)] = '\\'; // 斜杠位置
            }
        }
    }

    for (const auto& row : grid) {
        for (char c : row) {
            if (c == ' ' ||( c > '0' && c < '9') || (c=='\\' || c == '/')) {
                std::cout << c << " ";
            } else {
                std::cout << static_cast<int>(c-'0') << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
void Test0()
{
    Test("Test0", nullptr, 0);
}
void Test1()
{
    std::cout << "      3         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   9     20     " << std::endl;
    std::cout << "         / \\   " << std::endl;
    std::cout << "       15   7   " << std::endl;
    Node * pnode3 = new Node(3);
    Node * pnode9 = new Node(9);
    Node * pnode20= new Node(20);
    Node * pnode15= new Node(15);
    Node * pnode7 = new Node(7);
    pnode3 ->left  = pnode9 ;
    pnode3 ->right = pnode20;
    pnode20->left  = pnode15;
    pnode20->right = pnode7 ;
    printTreeGrid(pnode3, true);
    Test("Test1", pnode3, pnode3);
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
    Node * pnode6 = new Node(6);
    Node * pnode5 = new Node(5, nullptr, pnode6, nullptr);
    Node * pnode4 = new Node(4, nullptr, pnode5, nullptr);
    Node * pnode3 = new Node(3, nullptr, pnode4, nullptr);
    Node * pnode2 = new Node(2, nullptr, pnode3, nullptr);
    Test("Test2", pnode2, pnode2);
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
    Node * pnode1 = new Node(1);
    Node * pnode2 = new Node(2);
    Node * pnode3 = new Node(3);
    Node * pnode4 = new Node(4);
    Node * pnode5 = new Node(5);

    //    1
    //     2
    //    3  4
    //      5
    //
    pnode1->right  = pnode2;
    pnode2->left   = pnode3;
    pnode2->right  = pnode4;
    pnode4->left   = pnode5;
    Test("Test3", pnode1, pnode1);
}

void Test4()
{
    //Test("Test4", 6, 6, 3);
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    std::cout << " /   \\  / \\   " << std::endl;
    std::cout << "4     5 6   7   " << std::endl;

    Node * p7 = new Node(7);
    Node * p6 = new Node(6);
    Node * p5 = new Node(5);
    Node * p4 = new Node(4);
    Node * p3 = new Node(3, p6, p7, nullptr);
    Node * p2 = new Node(2, p4, p5, nullptr);
    Node * p1 = new Node(1, p2, p3, nullptr);

    Test("Test1", p1, p1);
}
void Test5()
{
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    std::cout << " /      / \\   " << std::endl;
    std::cout << "4      6   7   " << std::endl;

    Node * p7 = new Node(7);
    Node * p6 = new Node(6);
    Node * p4 = new Node(4);
    Node * p3 = new Node(3, p6, p7, nullptr);
    Node * p2 = new Node(2, p4, nullptr, nullptr);
    Node * p1 = new Node(1, p2, p3, nullptr);

    Test("Test5", p1, p1);
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
