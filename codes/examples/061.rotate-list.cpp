/*
 * 61. Rotate List
 * Medium
 ************************************************************
 * Given the head of a linked list, rotate the list to the right by k places.
 ************************************************************
 * Example 1:
 *          1 -> 2 -> 3 -> 4 -> 5
 *
 * rotate1  5 -> 1 -> 2 -> 3 -> 4
 * rotate2  4 -> 5 -> 1 -> 2 -> 3
 *
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 ************************************************************
 * Example 2:
 *
 *          0 -> 1 -> 2
 *
 * rotate1  2 -> 0 -> 1
 * rotate2  1 -> 2 -> 0
 * rotate3  0 -> 1 -> 2
 * rotate4  2 -> 0 -> 1
 *
 * Input: head = [0,1,2], k = 4
 * Output: [2,0,1]
 ************************************************************
 * Constraints:
 *
 * The number of nodes in the list is in the range [0, 500].
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 10^9
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
bool is_same( const ListNode *head1, const ListNode * head2);
std::ostream & operator << (std::ostream &out, ListNode *_node);

class Solution {
public:
    ListNode* rotateRight (ListNode* head, int k)
    {
        ListNode * curr =head;
        int len =1;
        while (curr && curr->next) {
            curr = curr->next;
            ++len;
        }
        ListNode * tail = curr;
        ListNode * ptail = curr;
        tail->next = head;
        std::cout << "len:" << len << ",tail:" << tail->val << std::endl;
        for (int i= 0; i< len - k%len ; ++i) {
            ptail = ptail->next;
        }
        auto temp = ptail->next;
        ptail->next = nullptr;

        return temp;
        return nullptr;
    }
    ListNode* rotateRight1(ListNode* head, int k)
    {
        return nullptr;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        ListNode * head,
        int k,
        ListNode * expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "k:" << k << " " << head << " ";

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.rotateRight(head, k);

        std::cout << "result: " << result << " ";
        if(is_same(result ,expected))
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
        std::cout << "-----------------------------" << std::endl;
    }
    if(TEST_1)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.rotateRight1(head, k);

        std::cout << "result: " << result << " ";
        if(is_same(result ,expected))
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
        std::cout << "-----------------------------" << std::endl;
    }
}
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
void Test0()
{
    struct ListNode * p1 = new ListNode(1);
    struct ListNode * p2 = new ListNode(2);
    struct ListNode * p3 = new ListNode(3);
    struct ListNode * p4 = new ListNode(4);
    struct ListNode * p5 = new ListNode(5);

    struct ListNode * q5 = new ListNode(5    );
    struct ListNode * q4 = new ListNode(4, q5);
    struct ListNode * q3 = new ListNode(3, q4);
    struct ListNode * q2 = new ListNode(2, q3);
    struct ListNode * q1 = new ListNode(1, q2);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    Test("Test0", p1, 5, q1);
}

void Test1()
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
    ListNode * q6 = new ListNode(6, q7);
    ListNode * q5 = new ListNode(5, q6);
    ListNode * q4 = new ListNode(4, q5);
    ListNode * q3 = new ListNode(3, q4);
    ListNode * q2 = new ListNode(2, q3);
    ListNode * q1 = new ListNode(1, q2);
    ListNode * q9 = new ListNode(9, q1);
    ListNode * q8 = new ListNode(8, q9);
    // 8 9 1 2 3 4 5 6 7
    Test("Test1", p1, 2, q8);
}

void Test2()
{
    ListNode * p1 = new ListNode(1);
    ListNode * p2 = new ListNode(2);
    ListNode * p3 = new ListNode(3);
    ListNode * p4 = new ListNode(4);
    ListNode * p5 = new ListNode(5);
    ListNode * p6 = new ListNode(6);

    ListNode * q3 = new ListNode(3    );
    ListNode * q2 = new ListNode(2, q3);
    ListNode * q1 = new ListNode(1, q2);
    ListNode * q6 = new ListNode(6, q1);
    ListNode * q5 = new ListNode(5, q6);
    ListNode * q4 = new ListNode(4, q5);
    // 4 5 6 1 2 3

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;

    Test("Test2", p1, 3, q4);
}

void Test3()
{
    ListNode * p1 = new ListNode(1);
    ListNode * p2 = new ListNode(2);
    ListNode * p3 = new ListNode(3);
    ListNode * p4 = new ListNode(4);
    ListNode * p5 = new ListNode(5);

    ListNode * q1 = new ListNode(1);
    ListNode * q2 = new ListNode(2);
    ListNode * q3 = new ListNode(3);
    ListNode * q4 = new ListNode(4);
    ListNode * q5 = new ListNode(5);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    Test("Test3", p1, 8, p3);
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

    ListNode * q6 = new ListNode(6    );
    ListNode * q5 = new ListNode(5, q6);
    ListNode * q4 = new ListNode(4, q5);
    ListNode * q3 = new ListNode(3, q4);
    ListNode * q2 = new ListNode(2, q3);
    ListNode * q1 = new ListNode(1, q2);
    ListNode * q9 = new ListNode(9, q1);
    ListNode * q8 = new ListNode(8, q9);
    ListNode * q7 = new ListNode(7, q8);
    // 7 8 9 1 2 3 4 5 6

    Test("Test1", p1, 3, q7);
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
