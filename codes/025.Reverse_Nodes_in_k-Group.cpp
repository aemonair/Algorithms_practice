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
    ListNode *reverseList(ListNode *head)
    {
        return nullptr;
    }
    ListNode *reverseList(ListNode *head, ListNode *tail)
    {
        return nullptr;
    }
    ListNode* reverse(ListNode* head, int k)
    {
        ListNode * phead = head;
        for (int i = 1; i < k && phead; ++i) {
            phead = phead->next;
        }
        if (phead == nullptr || k == 1) {
            return head;
        }
        phead = head;
        auto prev = new ListNode(-1, phead);
        int i = 1;
        while (i<k) {
            auto next = phead->next;
            phead->next = phead->next->next;
            next->next = prev->next;
            prev->next = next;
            ++i;
        }
        // 反转后 phead 身为最后一个,可用通过phead->next = reverse(phead->next)进行连接;
        //head->next = reverse(phead->next, k);
        phead->next = reverse(phead->next, k);
        return prev->next;
    }
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        auto newhead = reverse(head, k);
        return newhead;
    }
    ListNode* reverseKGroup1(ListNode* head, int k)
    {
        ListNode *curr = head;
        //std::unique_ptr<ListNode> prev = new ListNode(-1, curr);
        ListNode * dummy = new ListNode(-1, curr);
        ListNode * prev = dummy;
        while (curr) {
            ListNode *phead = curr;
            int i = 1;
            for (i=1; i< k; i++) {
                phead = phead->next;
            }
            if (phead==nullptr) {
                break;
            }
            phead = curr;
            i=1;
            while (i< k) {
                i++;
                auto next = curr->next;
                curr->next = curr->next->next;
                next -> next = prev->next;
                prev -> next = next;
            }
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
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
        std::cout << "k:" << k << " ";
        solution.printList(head);
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.reverseKGroup(head, k);
        std::cout << "solution result:" << result << std::endl;

        // std::cout << "result: ";
        // solution.printList(result);
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
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if(TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        std::cout << "k:" << k << " " << head << std::endl;
        //solution.printList(head);
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.reverseKGroup1(head, k);
        std::cout << "solution result:" << result << std::endl;

        // std::cout << "result: ";
        // solution.printList(result);
        if(result == expected)
        {
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
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
