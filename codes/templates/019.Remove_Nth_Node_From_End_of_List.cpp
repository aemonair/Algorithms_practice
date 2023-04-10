/*
 * 19. Remove Nth Node From End of List
 * Medium
 ***********************************************************************************************
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * 
 * Follow up: Could you do this in one pass?
 ***********************************************************************************************
 * Example 1:
 * 
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 ***********************************************************************************************
 * Example 2:
 * 
 * Input: head = [1], n = 1
 * Output: []
 ***********************************************************************************************
 * Example 3:
 * 
 * Input: head = [1,2], n = 1
 * Output: [1]
 ***********************************************************************************************
 * Constraints:
 * 
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 ***********************************************************************************************
 * 
 */
#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
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
    bool isSame(ListNode * head1, ListNode * head2)
    {
        if(head1==nullptr && head2== nullptr)
        {
            return true;
        }
        if(head1==nullptr || head2== nullptr)
        {
            return false;
        }
        if (head1->val == head2->val)
        {
            return isSame(head1->next , head2->next);
        }
        else
        {
            return false;
        }
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        ListNode * head, int n,
        ListNode * expected )
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "head:" << std::boolalpha << std::endl; 
    solution.printList(head);
    // getpermutataion
    {
        //start = std::chrono::system_clock::now();

        decltype(expected) result = solution.removeNthFromEnd(head, n);
        std::cout << "result:" << std::boolalpha << std::endl;
        solution.printList(result);

        if(solution.isSame(result, expected))
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
        //end = std::chrono::system_clock::now();
        //elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        //std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
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

    struct ListNode * q5 = new ListNode(5);
    struct ListNode * q3 = new ListNode(3, q5);
    struct ListNode * q2 = new ListNode(2, q3);
    struct ListNode * q1 = new ListNode(1, q2);

    Test("Test1", p1, 2, q1);
}

void Test2()
{
    struct ListNode * p1 = new ListNode(1);

    Test("Test2", p1, 1, nullptr);
}

void Test3()
{
    struct ListNode * p2 = new ListNode(2);
    struct ListNode * p1 = new ListNode(1, p2);

    struct ListNode * q1 = new ListNode(1);
    Test("Test2", p1, 1, q1);
}

void Test4()
{
}

void Test5()
{
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
