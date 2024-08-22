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
// 45 yy
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <climits>
#include <chrono>
#include <vector>
#include <string>
#include <thread>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define     RESET   "\033[0m"
#define     RED     "\033[31m"             /*      Red     */
#define     CYAN    "\033[36m"             /*      Cyan    */
#define     BLUE    "\033[34m"             /*      Blue    */
#define     GREEN   "\033[32m"             /*      Green   */
#define     WHITE   "\033[37m"             /*      White   */
#define     BLACK   "\033[30m"             /*      Black   */
#define     YELLOW  "\033[33m"             /*      Yellow  */
#define     MAGENTA "\033[35m"             /*      Magenta */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow  */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black   */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White   */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green   */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue    */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan    */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red     */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

    friend bool isSame(const ListNode * head1, const ListNode * head2);
    bool operator == (ListNode & hhead2)
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
        if(head1 == nullptr && head2==nullptr) {
            return true;
        } else {
            return false;
        }
    }
};

bool isSame (const ListNode * head1, const ListNode * head2)
{
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
    if(head1 == nullptr && head2==nullptr) {
        return true;
    } else {
        return false;
    }
}
template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

std::ostream & operator << (std::ostream &out, ListNode *_node);


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

};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        ListNode * head,
        int m, int n,
        ListNode * expected)
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << head << std::endl;
    std::cout << "m:" << m << ",n: " << n<< std::endl;

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
const static int TEST_2    = 0;
    if(TEST_0)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.reverseBetween(head, m, n);
        std::cout << "solution result:" << result << std::endl;

        if(*result == *expected)
        //if(result == expected)
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
        head = solution.reverseBetween(result, m, n);
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if (TEST_1)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.reverseBetween1(head, m, n);
        std::cout << "solution result:" << result << std::endl;

        //if(result == expected)
        //if(*result == *expected)
        if (isSame(result, expected))
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
        head = solution.reverseBetween1(result, m, n);
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if (TEST_2)
    {
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.reverseBetween2(head, m, n);
        std::cout << "solution2 result:" << result << std::endl;

        //if(result == expected)
        if(*result == *expected)
        {
            std::cout << GREEN << "Solution2 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution2 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        if (TEST_TIME)
        {
           end = std::chrono::system_clock::now();
           elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
           std::cout << "Solution2 costs " << elapsed.count() <<"micros" << std::endl;
        }
        head = solution.reverseBetween2(result, m, n);
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
}
// 76 yy
//template<typename T>
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
template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec)
{
    out << "[  ";
    for(auto v: _vec)
    {
        out << v << ", ";
    }
    out << "\b\b ]" ;
    return out;
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

    struct ListNode * q5 = new ListNode(5);
    struct ListNode * q4 = new ListNode(4, q5);
    struct ListNode * q2 = new ListNode(2, q4);
    struct ListNode * q3 = new ListNode(3, q2);
    struct ListNode * q1 = new ListNode(1, q3);

    Test("Test2", p1, 2, 3, q1);
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

    struct ListNode * q5 = new ListNode(5);
    struct ListNode * q4 = new ListNode(4, q5);
    struct ListNode * q1 = new ListNode(1, q4);
    struct ListNode * q2 = new ListNode(2, q1);
    struct ListNode * q3 = new ListNode(3, q2);
    Test("Test3", p1, 1, 3, q3);
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
