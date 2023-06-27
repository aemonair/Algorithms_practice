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
    ListNode* reversealternateK(ListNode* head, int k)
    {
        if(head == nullptr || head->next == nullptr || k <= 1)
        {
            return head;
        }
        ListNode * curr = head;
        ListNode * prev = nullptr;
        ListNode * next = nullptr;
        ListNode * prevpart = nullptr;
        while(true)
        {
            ListNode * lastnode = curr;
            for(int i = 0;curr != nullptr && i< k; i++)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            if(prevpart != nullptr)
            {
                prevpart->next = prev;
            }
            else
            {
                head = prev;
            }
            lastnode->next = curr;
            if(curr == nullptr)
            {
                break;
            }
            ListNode * firstnode = prev;
            // lastnode <- ... <- prev
            for(int i = 0;curr != nullptr && i< k; i++)
            {
                prev = curr;
                curr = curr->next;
            }
            if(curr == nullptr )
            {
                break;
            }
            prevpart = prev;
        }

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

        decltype(expected) result = solution.reversealternateK(head, k);

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

    Test("Test0", p1, 2, p2);
#if 0
    Solution solution;
    ListNode *head = p1;
    ListNode * rev = solution.reverseList(head);
    std::cout << "reverseList List:" << std::endl;
    solution.printList(rev);

    std::cout << "List:" << std::endl;
    solution.reverseList(rev);
    solution.printList(head);

    std::cout << "reverseList List, p2 & p4:" << std::endl;
    ListNode *new_head = solution.reverseList(p2, p4);
    solution.printList(new_head);
    // 3 -> 2

    p1 -> next = new_head;
    // 1 -> 3

    p2 -> next = p4;
    // 2 -> 4

    solution.printList(head);
    // 1 -> 3 -> 2 -> 4 -> 5

    //std::cout << "reverseListre List, p3 & p1:" << std::endl;
    //solution.reverseList(p3  , p1);
    //std::cout << "List:" << std::endl;
    //solution.printList(head);
    std::cout << "" << std::endl;
#endif
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

    Test("Test1", p1, 2, p2);
}

void Test2()
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

    Test("Test2", p1, 3, p3);
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

    Test("Test3", p1, 1, p1);
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

    Test("Test1", p1, 3, p3);
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
