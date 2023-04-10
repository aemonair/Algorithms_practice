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
 
class Solution {
public:
    // 
    bool isValidSequence(TreeNode* root, std::vector<int> &arr)
    {
        if(root==nullptr)
        {
            return false;
        }
        if(arr.size() == 0)
        {
            return false;
        }
        if(arr[0] == root->val)
        {
            if( arr.size() == 1 && root->left == nullptr && root->right == nullptr )
            {
                return true;
            }
            else
            {
                std::vector<int> temp(arr.begin()+1,arr.end());
                    return isValidSequence(root->left , temp)
                    ||     isValidSequence(root->right, temp);
            }
        }
        else
        {
            return false;
        }
    }
    bool isValidSequence1(TreeNode* root, std::vector<int> &arr)
    {
        if(root==nullptr)
        {
            return false;
        }
        std::stack<std::pair<TreeNode *, int>> stack;
        int index = 0;
        stack.push(std::make_pair(root, index));
        while(!stack.empty())
        {
            //printstack(stack);
            TreeNode * curr = stack.top().first;
            int index = stack.top().second;
            stack.pop();
            if(index > arr.size())
            {
                continue;
            }
            if(arr[index] == curr->val)
            {

                if(arr.size() == index+1 && curr->left == nullptr && curr->right == nullptr)
                {
                    return true;
                }
                if(curr->right)
                {
                    stack.push(std::make_pair(curr->right, index+1));
                }
                if(curr->left )
                {
                    stack.push(std::make_pair(curr->left, index+1 ));
                }
            }
        }
        return false;
    }
    template <typename T>
    int printstack(std::stack<T> s)
    {
        if (s.empty())
        {
            std::cout << "The stack is empty." << std::endl;
            return 0;
        }
        std::cout <<  "The stack size is: " << s.size() << std::endl;
        std::stack<T> tmp(s);
        while (!tmp.empty())
        {
            std::cout << tmp.top() << ", ";
            tmp.pop();
        }
        std::cout <<  std::endl;
        return tmp.size();
    }
    int printstack(std::stack<std::pair <TreeNode *, int>> s)
    {
        if (s.empty())
        {
            std::cout << "The TreeNode pair stack is empty." << std::endl;
            return 0;
        }
        std::cout <<  "The TreeNode stack size is: " << s.size() << std::endl;
        std::stack<std::pair<TreeNode *, int>> tmp(s);
        while (!tmp.empty())
        {
            std::cout << "(" << (tmp.top()).first->val << ", " << tmp.top().second << ");";
            tmp.pop();
        }
        std::cout << "\b]" << std::endl;
        return tmp.size();
    }

    template <typename T>
    int printdeque(const std::deque<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  " ;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", "; //<<std::endl;
        }
        std::cout << "\b\b]" << std::endl;
        return v.size();
    }
    int printdeque(const std::deque<TreeNode *> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  " ;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << (*iter) ->val << ", "; //<<std::endl;
        }
        std::cout << "\b\b]" << std::endl;
        return v.size();
    }
    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        std::cout << "[  " ;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << ", "; //<<std::endl;
        }
        std::cout << "\b\b]" << std::endl;
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

    std::cout << "find arr:" << " ";
    solution.printvector(arr);
    solution.printtree(root);
const static int TEST_TIME = 1;
const static int TEST_0    = 0;
const static int TEST_1    = 1;

    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.isValidSequence(root, arr);
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
    }
    std::cout << "-----------------------------" << std::endl;
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
        Test("Test6", p5, arr,  expected );
    }
    {
        std::vector<int> arr= {5,8,4,5};
        bool expected = true ;
        Test("Test6", p5, arr,  expected );
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
