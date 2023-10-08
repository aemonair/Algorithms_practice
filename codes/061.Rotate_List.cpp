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
    ListNode* rotateRight (ListNode* head, int k)
    {
        int i = 0;
        int size = 0;
        ListNode * phead = head;
        while (phead) {
            phead = phead->next;
            size++;
        }
        // 可用在这里直接变成环,phead->next = head,然后就可用只处理对应k处;
        k %= size;
        if (k ==0) {
            return head;
        }
        std::cout << k << " " << size << std::endl;
        phead = head;
        for (i = 1; i<(size-k) && phead; ++i) {
            phead = phead->next;
        }
        if (phead == nullptr) {
            return head;
        }
        ListNode * newnode = phead->next;
        std::cout << newnode << std::endl;
        phead->next = nullptr;
        phead = newnode;
        while (phead && phead ->next != nullptr) {
            phead = phead->next;
        }
        std::cout << "last:" << phead << std::endl;
        phead ->next = head;
        return newnode; //head;
    }
    ListNode* rotateRight1(ListNode* head, int k)
    {
        ListNode *phead = head;
        int size = 1;
        while (phead && phead->next) {
            phead = phead->next;
            size++;
        }
        phead->next = head;
        k %= size ;
        int i =0;
        for (i=0; i< size-k; ++i) {
            phead = phead->next;
        }
        ListNode *newnode = phead->next;
        phead->next = nullptr;
        return newnode;
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

const static int TEST_TIME = 1;
const static int TEST_0    = 0;
const static int TEST_1    = 1;
const static int TEST_2    = 0;
const static int TEST_3    = 0;
    if(TEST_0)
    {
        std::cout << "k:" << k << " " << head << " ";
        // solution.printList(head);
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.rotateRight(head, k);

        std::cout << "result: " << result << " ";
        // solution.printList(result);
        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            // solution.printList(expected);
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
        std::cout << "k:" << k << " " << head << " ";
        // solution.printList(head);
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.rotateRight1(head, k);

        std::cout << "result: " << result << " ";
        // solution.printList(result);
        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            // solution.printList(expected);
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
void Test0()
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

    Test("Test0", p1, 5, p1);
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

    Test("Test1", p1, 2, p8);
}

void Test2()
{
    struct ListNode * p1 = new ListNode(1);
    struct ListNode * p2 = new ListNode(2);
    struct ListNode * p3 = new ListNode(3);
    struct ListNode * p4 = new ListNode(4);
    struct ListNode * p5 = new ListNode(5);
    struct ListNode * p6 = new ListNode(6);


    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;

    Test("Test2", p1, 3, p4);
}

void Test3()
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

    Test("Test3", p1, 8, p3);
}

void Test4()
{
    struct ListNode * q1 = new ListNode(6);

    Test("Test4", q1, 1, q1);
}
void Test5()
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

    Test("Test1", p1, 3, p7);
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
