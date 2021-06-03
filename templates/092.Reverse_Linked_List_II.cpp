/*
 * 92. Reverse Linked List II
 * Medium 
 ***********************************************************
 * Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
 ***********************************************************
 * Example 1:
 *
 * 1->2->3->4->5->NULL, m = 2, n = 4
 * 1->4->3->2->5->NULL
 * 
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 ***********************************************************
 * Example 2:
 * 
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
 ***********************************************************
 * Constraints:
 * 
 * The number of nodes in the list is n.
 * 1 <= n <= 500
 * -500 <= Node.val <= 500
 * 1 <= left <= right <= n
 ***********************************************************
 * Follow up: Could you do it in one pass?
 ***********************************************************
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        return nullptr;
    }
    ListNode* reverseListre(ListNode* head) 
    {
        return nullptr;
    }
    ListNode *reverseListN(ListNode *head, int n)
    {
        return nullptr;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        return nullptr;
    }
    ListNode* reverseBetween1(ListNode* head, int m, int n)
    {
        return nullptr;
    }
    ListNode* reverseBetween2(ListNode* head, int m, int n)
    {
        return nullptr;
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
        int m, int n,
        ListNode * expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printList(head);

    // getpermutataion
const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
const static int TEST_2    = 0;
const static int TEST_3    = 0;
    if(TEST_0)
    {
        solution.printList(head);
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        std::cout << "m:" << m << ",n: " << n<< std::endl;
        decltype(expected) result = solution.reverseBetween(head, m, n);

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
    if (TEST_1)
    {
        solution.printList(head);
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.reverseBetween1(head, m, n);

        if(result == expected)
            std::cout << "Solution1 passed." << std::endl;
        else
            std::cout << "Solution1 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
        solution.printList(result);
    }
    if (TEST_2)
    {
        solution.printList(head);
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.reverseBetween2(head, m, n);

        if(result == expected)
            std::cout << "Solution2 passed." << std::endl;
        else
            std::cout << "Solution2 failed." << std::endl;
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution2 costs " << elapsed.count() <<"micros" << std::endl;
        }
        solution.printList(result);
    }
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

#if 0
    Solution solution;
    ListNode *head = p1;
    ListNode * rev = solution.reverseList(head);
    std::cout << "reverseList List:" << std::endl;
    solution.printList(rev);
    std::cout << "List:" << std::endl;
    solution.reverseList(rev);
    solution.printList(head);
    std::cout << "reverseListre List:" << std::endl;
    ListNode *new_head = solution.reverseListre(head);
    solution.printList(new_head);
    solution.reverseListre(new_head);
    std::cout << "List:" << std::endl;
    solution.printList(head);
    std::cout << "reverseListre List:" << std::endl;
    ListNode * newlist= solution.reverseListre(head);
    solution.reverseListre(newlist);
    std::cout << "List:" << std::endl;
    solution.printList(head);
    ListNode *re1 = solution.reverseListN(head, 1);
    std::cout << "List 1:" << std::endl;
    solution.printList(re1);
    ListNode *re3 = solution.reverseListN(head, 3);
    std::cout << "List 3:" << std::endl;
    solution.printList(re3);
#endif
    Test("Test1", p1, 2, 4, p1);
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

    Test("Test2", p1, 2, 3, p1);
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

    Test("Test3", p1, 1, 3, p1);
}

void Test4()
{
    struct ListNode * q1 = new ListNode(6);

    Test("Test4", q1, 2, 4, q1);
}

void Test5()
{
}

int main()
{
    Solution solution;

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;

}
