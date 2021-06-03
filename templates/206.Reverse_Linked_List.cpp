/*
 ************************************************************************************************* 
 * 206. Reverse Linked List
 * Easy
 ************************************************************************************************* 
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 ************************************************************************************************* 
 * Example1:
 *   1->2->3->4->5->NULL
 *      |
 *   5->4->3->2->1->NULL
 * Input: head = [1,2,3,4,5] 
 * Output: [5,4,3,2,1]
 ************************************************************************************************* 
 *  Example 2:
 * 
 * Input: head = [1,2]
 * Output: [2,1]
 ************************************************************************************************* 
 * Example 3:
 * 
 * Input: head = []
 * Output: []
 ************************************************************************************************* 
 * Constraints:
 * 
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 ************************************************************************************************* 
 * Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
 ************************************************************************************************* 
 *
 *
 *               1 -> 2 -> 3 -> 4
 *
 *               head
 *               1    2 -> 3 -> 4
 *            p<-h    n   
 *               1    2 ->3 -> 4
 *               p    h
 *               1    2 ->3 -> 4
 *                        n
 *               1 <- 2   3 -> 4
 *               p    h   n
 ************************************************************************************************* 
 */
#include <iostream>
#include <chrono>
#include <vector>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    bool operator == (//const ListNode *head1, 
            ListNode & hhead2)
    {
        ListNode *head1= this;
        ListNode *head2= &hhead2;
        while (head1 && head2)
        {
            std::cout << head1->val << "," << head2->val << std::endl;
            if(head1->val != head2->val)
            {
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        if(head1 == nullptr && head2==nullptr)
            return true;
        else
            return false;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode * prev = nullptr;
        ListNode * next = nullptr;
     
        while(head)
        {   
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* reverseList1(ListNode* head) 
    {
        if(head == nullptr || head ->next == nullptr)
        {
            return head;
        }
        ListNode * next = reverseList1(head->next);
        head->next->next= head;
        head->next = nullptr;
        return next;
    }
    ListNode* reverseList2(ListNode* head) 
    {
    }
    ListNode* reverseList3(ListNode* head) 
    {
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
        ListNode * phead ,
        ListNode * expected
        )
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printList(phead);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
const static int TEST_2    = 1;
const static int TEST_3    = 1;
    // getpermutataion
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected)  solution_result = solution.reverseList(phead);
        std::cout << "solution result:" << std::endl;
        solution.printList(solution_result);

        if(*solution_result == *expected)
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
        phead = solution.reverseList(solution_result);
    }
    if (TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected)  solution_result = solution.reverseList1(phead);
        std::cout << "solution result:" << std::endl;
        solution.printList(solution_result);

        if(*solution_result == *expected)
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
           std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
        }
    }
    if (TEST_2)
    {
    }
    if (TEST_3)
    {
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

    ListNode *q1 = new ListNode (1);
    ListNode *q2 = new ListNode (2, q1);
    ListNode *q3 = new ListNode (3, q2);
    ListNode *q4 = new ListNode (4, q3);
    ListNode *q5 = new ListNode (5, q4);
    ListNode * expect = q5;
    Test("Test1", p1, expect);
}
void Test2()
{
    struct ListNode * p1 = new ListNode(1);
    struct ListNode * p2 = new ListNode(2);
    
    p1->next = p2;

    ListNode *q1 = new ListNode (1);
    ListNode *q2 = new ListNode (2, q1);
    ListNode * expect = q2;
    Test("Test2", p1, expect);
}

void Test3()
{
    struct ListNode * p1 = nullptr ;
    
    ListNode * expect = nullptr;
    Test("Test3", p1, expect);
}

void Test4()
{
}

void Test5()
{
}

void Test6()
{
}
int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;

}
