/*
 * 25. Reverse alternate K nodes in a Singly Linked List
 * medium
 *
 * Given a linked list, write a function to reverse every alternate k nodes (where k is an input to the function) in an efficient way. Give the complexity of your algorithm.
 ************************************************************
 * Example :
 *   1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL and k = 3
 *   3 -> 2 -> 1 -> 4 -> 5 -> 6 -> 9 -> 8 -> 7 -> NULL.
 *
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

class Solution {
public:
    ListNode* reversealternateK(ListNode* head, int k)
    {
        ListNode * dummy = new ListNode(-1, head);
        ListNode * prev = dummy;
        ListNode * curr = head;
        while(prev) {
            ListNode * p_prev = prev;
            for (int i =0; i< k && p_prev; ++i) {
                p_prev = p_prev->next;
            }
            if (!p_prev) {
                break;
            }
            curr = prev->next;
            std::cout << "p:" << prev << std::endl;
            for (int i=1; i< k && curr; ++i) {
                auto next = curr->next->next;
                curr->next->next = prev->next;
                prev->next = curr->next;
                curr->next = next;
            }
            std::cout << " p:" << prev << std::endl;
            prev = curr;
            for (int i =0; i< k && prev; ++i) {
                prev = prev->next;
            }
            if (!prev) {
                break;
            }
        }
        return dummy->next;
        return nullptr;
    }
    ListNode* reversealternateK1(ListNode* head, int k)
    {
        return nullptr;
    }
};

bool is_same( const ListNode *head1, const ListNode * head2)
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
    if(testName.length() > 0) {
        std::cout <<testName << " begins: "<< std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if(TEST_0)
    {
        std::cout << "k:" << k << " " << head << " ";
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.reversealternateK(head, k);

        std::cout << "result: " << result << " ";
        if(is_same(result , expected))
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
    if(TEST_1)
    {
        std::cout << "k:" << k << " " << head << " ";
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.reversealternateK1(head, k);

        std::cout << "result: " << result << " ";
        if(result == expected)
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
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
}
void Test0()
{
    struct ListNode * p1 = new ListNode(1);
    struct ListNode * p2 = new ListNode(2);
    struct ListNode * p3 = new ListNode(3);
    struct ListNode * p4 = new ListNode(4);
    struct ListNode * p5 = new ListNode(5);

    ListNode * q5 = new ListNode(5);
    ListNode * q4 = new ListNode(4, q5);
    ListNode * q3 = new ListNode(3, q4);
    ListNode * q1 = new ListNode(1, q3);
    ListNode * q2 = new ListNode(2, q1);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    Test("Test0", p1, 2, q2);
}

void Test1()
{
    struct ListNode * p9 = new ListNode(9 );
    struct ListNode * p8 = new ListNode(8, p9);
    struct ListNode * p7 = new ListNode(7, p8);
    struct ListNode * p6 = new ListNode(6, p7);
    struct ListNode * p5 = new ListNode(5, p6);
    struct ListNode * p4 = new ListNode(4, p5);
    struct ListNode * p3 = new ListNode(3, p4);
    struct ListNode * p2 = new ListNode(2, p3);
    struct ListNode * p1 = new ListNode(1, p2);

    ListNode * q9 = new ListNode(9 );
    ListNode * q8 = new ListNode(8, q9);
    ListNode * q7 = new ListNode(7, q8);
    ListNode * q5 = new ListNode(5, q7);
    ListNode * q6 = new ListNode(6, q5);
    ListNode * q4 = new ListNode(4, q6);
    ListNode * q3 = new ListNode(3, q4);
    ListNode * q1 = new ListNode(1, q3);
    ListNode * q2 = new ListNode(2, q1);
    // 2 1 3 4 6 5 7 8 9

    Test("Test1", p1, 2, q2);
}

void Test2()
{
    struct ListNode * p1 = new ListNode(1);
    struct ListNode * p2 = new ListNode(2);
    struct ListNode * p3 = new ListNode(3);
    struct ListNode * p4 = new ListNode(4);
    struct ListNode * p5 = new ListNode(5);

    ListNode * q5 = new ListNode(5    );
    ListNode * q4 = new ListNode(4, q5);
    ListNode * q1 = new ListNode(1, q4);
    ListNode * q2 = new ListNode(2, q1);
    ListNode * q3 = new ListNode(3, q2);

    // 3 2 1 4 5

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    Test("Test2", p1, 3, q3);
}

void Test3()
{
    ListNode * p1 = new ListNode(1);
    ListNode * p2 = new ListNode(2);
    ListNode * p3 = new ListNode(3);
    ListNode * p4 = new ListNode(4);
    ListNode * p5 = new ListNode(5);

    ListNode * q5 = new ListNode(5    );
    ListNode * q4 = new ListNode(4, q5);
    ListNode * q3 = new ListNode(3, q4);
    ListNode * q2 = new ListNode(2, q3);
    ListNode * q1 = new ListNode(1, q2);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    Test("Test3", p1, 1, p1);
}

void Test4()
{
    struct ListNode * q1 = new ListNode(6);

    Test("Test4", q1, 1, q1);
}
void Test5()
{
    ListNode * p9 = new ListNode(9 );
    ListNode * p8 = new ListNode(8, p9);
    ListNode * p7 = new ListNode(7, p8);
    ListNode * p6 = new ListNode(6, p7);
    ListNode * p5 = new ListNode(5, p6);
    ListNode * p4 = new ListNode(4, p5);
    ListNode * p3 = new ListNode(3, p4);
    ListNode * p2 = new ListNode(2, p3);
    ListNode * p1 = new ListNode(1, p2);

    ListNode * q7 = new ListNode(7    );
    ListNode * q8 = new ListNode(8, q7);
    ListNode * q9 = new ListNode(9, q8);
    ListNode * q6 = new ListNode(6, q9);
    ListNode * q5 = new ListNode(5, q6);
    ListNode * q4 = new ListNode(4, q5);
    ListNode * q1 = new ListNode(1, q4);
    ListNode * q2 = new ListNode(2, q1);
    ListNode * q3 = new ListNode(3, q2);
    // 3 2 1 4 5 6 9 8 7

    Test("Test1", p1, 3, q3);
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
