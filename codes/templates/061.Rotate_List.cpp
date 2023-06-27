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
class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
        return nullptr;
    }
    ListNode *reverseList(ListNode *head, ListNode *tail)
    {
        return nullptr;
    }
    ListNode* rotateRight (ListNode* head, int k)
    {
        return head;
    }

    std::vector<int> printList(ListNode* head)
    {
        std::vector<int> ret ; // = new ArrayList<>();
        ListNode *listNode = head;
        if (head)
        {
            std::cout << "head" << listNode->val << std::endl;
        }
        else
        {
            std::cout << "null" << std::endl;
        }
        while (listNode != nullptr) // && listNode->next != nullptr)
        {
            std::cout << listNode->val << " " ; // << std::endl;
            ret.push_back(listNode->val);
            listNode = listNode->next;
        }
        std::cout << std::endl;
        return ret;
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
    {
        std::cout << "k:" << k << " ";
        solution.printList(head);
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.rotateRight(head, k);

        std::cout << "result: ";
        solution.printList(result);
        if(result == expected)
        {
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << std::endl;
            solution.printList(expected);
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    {
    }
    {
    }
    std::cout << "-----------------------------" << std::endl;
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

    Test("Test0", p1, 5, p4);
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
