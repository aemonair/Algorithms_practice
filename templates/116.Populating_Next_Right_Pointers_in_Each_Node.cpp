/*
 * 116. Populating Next Right Pointers in Each Node
 * Medium
 ******************************************************************************
 * You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
 * The binary tree has the following definition:
 * 
 * struct Node {
 *   int val;
 *   Node *left;
 *   Node *right;
 *   Node *next;
 * }
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 ****************************************************************************** 
 * Follow up:
 * 
 * You may only use constant extra space.
 * Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 * *****************************************************************************
 * 
 * Example 1:
 * 
 *       1
 *    /     \
 *   2       3
 *  / \     / \
 * 4   5   6   7
 * 
 *       1 -> NULL
 *    /     \
 *   2  ---> 3 -> NULL
 *  / \     / \
 * 4-->5-->6-->7 -> NULL
 *
 * Input: root = [1,2,3,4,5,6,7]
 * Output: [1,#,2,3,#,4,5,6,7,#]
 * Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 * 
 * *****************************************************************************
 * Constraints:
 * 
 * The number of nodes in the given tree is less than 4096.
 * -1000 <= node.val <= 1000
 * 
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
/**
 * Definition for a node.
 */
class Node 
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next ;
    Node() : val(0), left(nullptr), right(nullptr),next(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr),next(nullptr) {}
    Node(int x, Node *_left, Node *_right, Node *_next) 
        : val(x), left(_left), right(_right),next(_next) {}
};
 
class Solution {
public:
    // 
    Node* connect0(Node* root)
    {
        return root;
    }
    Node* connect1(Node* root)
    {
        return root;
    }
    Node* connect(Node* root)
    {
        return root;
    }
    Node* connect(Node* _left, Node *_right)
    {
        return _left;
    }
    int printtree  (const Node * head)
    {
        if (head==nullptr)
        {
            std::cout << "null tree. " << std::endl;
            return 0;
        }
        std::cout << "head->val: " << head->val << std::endl;
        printtreenextnode(head);
        std::cout << std::endl;
        return 0;
    }
    int printtreenextnode (const Node * head)
    {
        if(head==nullptr)
        {
            std::cout << "N" << ",";
        }
        else
        {
            std::cout << head->val << ",";
            std::cout << "(";
            if (head->next)
            {
                std::cout <<head->next->val;
            }
            else
            {
                std::cout <<"N";
            }
            std::cout <<"),";
            printtreenextnode(head->left);
            printtreenextnode(head->right);
        }
        return 0;
    }
    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << "| "<<std::endl;
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
    bool isSame(Node *T1, Node *T2)
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
        if(T1->next == nullptr ^ T2->next == nullptr)
        {
            return false;
        }

        if(T1->val==T2->val )//&& T1->next->val == T2->next->val)
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
void Test(const std::string& testName, Node *root, Node *expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printtree(root);
    std::cout << "expected:" << std::endl;
    solution.printtree(expected);
    // getpermutataion
const static int TEST_TIME = 1;
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.connect0(root);

        std::cout << "connect0  :" << std::endl;
        solution.printtree(result);
        if(solution.isSame(result , expected) == true)
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
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.connect1(root);

        std::cout << "connect1  :" << std::endl;
        solution.printtree(result);
        if(solution.isSame(result , expected) == true)
            std::cout << "Solution1 passed." << std::endl;
        else
            std::cout << "Solution1 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.connect(root);

        std::cout << "connect  :" << std::endl;
        solution.printtree(result);
        if(solution.isSame(result , expected) == true)
            std::cout << "Solution  passed." << std::endl;
        else
            std::cout << "Solution  failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution  costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
}
void Test1()
{
    Node * pnode1 = new Node(1);
    Node * pnode3 = new Node(3);
    Node * pnode6 = new Node(6);
    Node * pnode9 = new Node(9);
    
    Node * pnode2 = new Node(2, pnode1, pnode3,nullptr);
    Node * pnode7 = new Node(7, pnode6, pnode9,nullptr);

    Node * pnode4 = new Node(4, pnode2, pnode7,nullptr);
    std::cout << "      4         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     7      " << std::endl;
    std::cout << "  / \\   / \\   " << std::endl;
    std::cout << " 1   3 6   9    " << std::endl;
    ////////////////////////////////////
    Node * p_node9 = new Node(9);
    Node * p_node6 = new Node(6,nullptr,nullptr,p_node9);
    Node * p_node3 = new Node(3,nullptr,nullptr,p_node6);
    Node * p_node1 = new Node(1,nullptr,nullptr,p_node3);
    
    Node * p_node7 = new Node(7, p_node6, p_node9,nullptr);
    Node * p_node2 = new Node(2, p_node1, p_node3,p_node7);

    Node * p_node4 = new Node(4, p_node2, p_node7,nullptr);
    Test("Test1", pnode4, p_node4);
    std::cout << "      4 -N      " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2 --> 7 -N   " << std::endl;
    std::cout << "  / \\   / \\   " << std::endl;
    std::cout << " 1 - 3-6 --9 -N " << std::endl;
    std::cout << "----------------" << std::endl;
}
void Test2()
{
    Node * pnode3 = new Node(3);
    Node * pnode9 = new Node(9);
    Node * pnode20= new Node(20);
    Node * pnode15= new Node(15);
    Node * pnode7 = new Node(7);
    pnode3 ->left  = pnode9 ;
    pnode3 ->right = pnode20;
    pnode20->left  = pnode15;
    pnode20->right = pnode7 ;
    //    
    //      3
    //    /   \
    //   9     20
    //        / \
    //       15  7
    std::cout << "      3         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   9     20     " << std::endl;
    std::cout << "         / \\   " << std::endl;
    std::cout << "       15  7    " << std::endl;
    Node * p_node7 = new Node(7);
    Node * p_node15= new Node(15,nullptr ,nullptr,p_node7);

    Node * p_node20= new Node(20,p_node15, p_node7,nullptr);
    Node * p_node9 = new Node(9 ,nullptr , nullptr,p_node20);

    Node * p_node3 = new Node( 3,p_node9 , p_node20,nullptr);
    Test("Test2", pnode3, p_node3);
    std::cout << "      3 -N      " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   9 --  20 -N  " << std::endl;
    std::cout << "         / \\   " << std::endl;
    std::cout << "       15- 7 -N " << std::endl;
    std::cout << "----------------" << std::endl;
}

void Test3()
{
    std::cout << "      1         " << std::endl;
    std::cout << "        \\      " << std::endl;
    std::cout << "         2      " << std::endl;
    std::cout << "        / \\    " << std::endl;
    std::cout << "       3    4   " << std::endl;
    std::cout << "          /     " << std::endl;
    std::cout << "         5      " << std::endl;
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


    Node * p_node5 = new Node(5);
    Node * p_node4 = new Node(4, p_node5, nullptr ,nullptr);
    Node * p_node3 = new Node(3, nullptr, nullptr, p_node4);
    Node * p_node2 = new Node(2, p_node3, p_node4, nullptr);
    Node * p_node1 = new Node(1, nullptr, p_node2, nullptr);
    Test("Test3", pnode1, p_node1);
    std::cout << "      1 -N      " << std::endl;
    std::cout << "        \\      " << std::endl;
    std::cout << "         2 -N   " << std::endl;
    std::cout << "        / \\    " << std::endl;
    std::cout << "       3 -- 4 -N" << std::endl;
    std::cout << "          /     " << std::endl;
    std::cout << "         5 -N   " << std::endl;
    std::cout << "----------------" << std::endl;
}

void Test4()
{
    std::cout << "      1         " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2     3      " << std::endl;
    std::cout << "  / \\   / \\   " << std::endl;
    std::cout << " 4   5 6   7    " << std::endl;
    Node * pnode4 = new Node(4);
    Node * pnode5 = new Node(5);
    Node * pnode6 = new Node(6);
    Node * pnode7 = new Node(7);
    
    Node * pnode3 = new Node(3, pnode6, pnode7, nullptr);
    Node * pnode2 = new Node(2, pnode4, pnode5, nullptr);

    Node * pnode1 = new Node(1, pnode2, pnode3, nullptr);
    //
    //
    //

    Node * p_node7 = new Node(7);
    Node * p_node6 = new Node(6,nullptr, nullptr,p_node7);
    Node * p_node5 = new Node(5,nullptr, nullptr,p_node6);
    Node * p_node4 = new Node(4,nullptr, nullptr,p_node5);
    
    Node * p_node3 = new Node(3, p_node6, p_node7, nullptr);
    Node * p_node2 = new Node(2, p_node4, p_node5, p_node3);

    Node * p_node1 = new Node(1, p_node2, p_node3, nullptr);
    Test("Test4", pnode1, p_node1);
    std::cout << "      1 -N      " << std::endl;
    std::cout << "    /   \\      " << std::endl;
    std::cout << "   2 --  3-N    " << std::endl;
    std::cout << "  / \\   / \\   " << std::endl;
    std::cout << " 4 - 5-6 --7 -N " << std::endl;
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
