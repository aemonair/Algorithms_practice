/*
 * 25. Reverse Nodes in k-Group
 * Hard
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 *
 ************************************************************
 * Follow up:
 *
 * Could you solve the problem in O(1) extra memory space?
 * You may not alter the values in the list's nodes, only nodes itself may be changed.
 *
 ************************************************************
 * Example 1:
 *   1 -> 2 -> 3 -> 4 -> 5
 *            |
 *   2 -> 1 -> 4 -> 3 -> 5
 *
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 ************************************************************
 * Example 2:
 *   1 -> 2 -> 3 -> 4 -> 5
 *            |
 *   3 -> 2 -> 1 -> 4 -> 5
 *
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 ************************************************************
 * Example 3:
 *
 * Input: head = [1,2,3,4,5], k = 1
 * Output: [1,2,3,4,5]
 ************************************************************
 * Example 4:
 *
 * Input: head = [1], k = 1
 * Output: [1]
 ************************************************************
 * Constraints:
 *
 * The number of nodes in the list is in the range sz.
 * 1 <= sz <= 5000
 * 0 <= Node.val <= 1000
 * 1 <= k <= sz
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
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
std::ostream & operator << (std::ostream &out, ListNode *_node);

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        return nullptr;
    }
    ListNode* reverseKGroup1(ListNode* head, int k)
    {
        return nullptr;
    }
};

std::ostream & operator << (std::ostream &out, ListNode *_node)
{
    ListNode *listNode = _node;
    out << "[  ";
    if (!_node) {
        out << "null ]" << std::endl;
        return out;
    }
    while (listNode != nullptr) { // && listNode->next != nullptr)
        out << listNode->val << " -> " ; // << std::endl;
        listNode = listNode->next;
    }
    out << "\b\b\b ]" ;
    out << std::endl;
    return out;
}
bool isSame( const ListNode *head1, const ListNode * head2)
{
    while (head1 && head2)
    {
        std::cout << head1->val << "," << head2->val << " -> " ; //<< std::endl;
        if(head1->val != head2->val)
        {
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    if(head1 == nullptr && head2==nullptr) {
        return true;
    } else {
        return false;
    }
}
// ==================== TEST Codes====================
void Test(const std::string& testName,
        ListNode * head,
        int k,
        ListNode * expected)
{
    if(testName.length() > 0)
    {
        std::cout << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST_0    = 0;
const static int TEST_1    = 1;
    if(TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        std::cout << "k:" << k << " " << head << " ";
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.reverseKGroup(head, k);
        std::cout << "solution result:" << result << std::endl;

        // std::cout << "result: ";
        if(isSame(result ,expected))
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
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if(TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        std::cout << "k:" << k << " " << head << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.reverseKGroup1(head, k);
        std::cout << "solution result:" << result << std::endl;

        if(isSame(result ,expected))
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    {
    }
}
void Test0()
{
    struct ListNode * p1 = new ListNode(1);
    struct ListNode * p2 = new ListNode(2);
    struct ListNode * p3 = new ListNode(3);
    struct ListNode * p4 = new ListNode(4);
    struct ListNode * p5 = new ListNode(5);

    struct ListNode * q5 = new ListNode(5);
    struct ListNode * q3 = new ListNode(3, q5);
    struct ListNode * q4 = new ListNode(4, q3);
    struct ListNode * q1 = new ListNode(1, q4);
    struct ListNode * q2 = new ListNode(2, q1);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    Test("Test0", p1, 2, q2);
    // 1 -> 2 -> 3 -> 4 -> 5
}

void Test1()
{
    struct ListNode * p1 = new ListNode(1);
    struct ListNode * p2 = new ListNode(2);
    struct ListNode * p3 = new ListNode(3);
    struct ListNode * p4 = new ListNode(4);
    struct ListNode * p5 = new ListNode(5);


    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    Test("Test1", p1, 2, p2);
}

void Test2()
{
    struct ListNode * p1 = new ListNode(1);
    struct ListNode * p2 = new ListNode(2);
    struct ListNode * p3 = new ListNode(3);
    struct ListNode * p4 = new ListNode(4);
    struct ListNode * p5 = new ListNode(5);

    // 1 2 3 4 5
    // 3 2 1 4 5
    ListNode * q5 = new ListNode(5);
    ListNode * q4 = new ListNode(4, q5);
    ListNode * q1 = new ListNode(1, q4);
    ListNode * q2 = new ListNode(2, q1);
    ListNode * q3 = new ListNode(3, q2);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    Test("Test2", p1, 3, q3);
}

void Test3()
{
    struct ListNode * p1 = new ListNode(1);
    struct ListNode * p2 = new ListNode(2);
    struct ListNode * p3 = new ListNode(3);
    struct ListNode * p4 = new ListNode(4);
    struct ListNode * p5 = new ListNode(5);

    // 1 2 3 4 5
    // 3 2 1 4 5
    ListNode * q5 = new ListNode(5);
    ListNode * q4 = new ListNode(4, q5);
    ListNode * q3 = new ListNode(3, q4);
    ListNode * q2 = new ListNode(2, q3);
    ListNode * q1 = new ListNode(1, q2);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    Test("Test3", p1, 1, q1);
}

void Test4()
{
    struct ListNode * q1 = new ListNode(6);

    Test("Test4", q1, 1, q1);
}
void Test5()
{
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
