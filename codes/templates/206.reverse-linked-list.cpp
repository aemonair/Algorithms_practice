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

template<typename T>
std::ostream & operator << (std::ostream &out, std::vector<T> &_vec);

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
        if(head1 == nullptr && head2==nullptr) {
            return true;
        } else {
            return false;
        }
    }
};
//template<typename T>
std::ostream & operator << (std::ostream &out, ListNode *_node);

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        return nullptr;
    }
    ListNode* reverseList1(ListNode* head)
    {
        return nullptr;
    }
    ListNode * reverseList2(ListNode *head)
    {
        return nullptr;
    }
    ListNode* reverseList3(ListNode* head)
    {
        return nullptr;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        ListNode * phead ,
        ListNode * expected
        )
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << phead << std::endl;

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 1;
const static int TEST_2    = 1;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected)  result = solution.reverseList(phead);
        std::cout << "solution result:" << result << std::endl;

        if(*result == *expected)
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
        phead = solution.reverseList(result);
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if (TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected)  result = solution.reverseList1(phead);
        std::cout << "solution result:" << result << std::endl;

        if(*result == *expected)
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
        std::cout << "- - - - - - - - - - - - - - - - - - -" << std::endl;
    }
    if (TEST_2)
    {
        std::cout << "Solution2 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected)  result = solution.reverseList2(phead);
        std::cout << "solution result:" << result << std::endl;

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
