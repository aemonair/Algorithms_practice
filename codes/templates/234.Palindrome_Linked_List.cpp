/*
 * 234. Palindrome Linked List
 * Easy
 * 
 ****************************************************************
 * Given a singly linked list, determine if it is a palindrome.
 * 
 **************************************************************** 
 * Example 1:
 * 
 * Input: 1->2
 * Output: false
 ****************************************************************
 * Example 2:
 * 
 * Input: 1->2->2->1
 * Output: true
 **************************************************************** 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 **************************************************************** 
 * 
 */

// 44 yy
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <climits>
#include <chrono>
#include <vector>
#include <string>
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

// Definition for singly-linked list.
typedef struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}ListNode;

class Solution {
public:
    /////////////////////////////////////////////////////////////////
    bool isPalindrome3(struct ListNode* head) 
    {
        return true;
    }
    /////////////////////////////////////////////////////////////////
    bool isPalindrome2(struct ListNode* head) 
    {
        return true;
    }
    /////////////////////////////////////////////////////////////////
    bool isPalindrome1(struct ListNode* head) 
    {
        return true;
    }
    /////////////////////////////////////////////////////////////////
    bool isPalindrome0(struct ListNode* head) 
    {
        return false;
    }
    /////////////////////////////////////////////////////////////////
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
        struct ListNode * head,
        bool expected)
{
    if(testName.length() > 0)
    {
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;        
    }

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
const static int TEST_2    = 0;
const static int TEST_3    = 0;
    solution.printList(head);
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        start = std::chrono::system_clock::now();

        decltype(expected) result = solution.isPalindrome0(head);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
    }
    if (TEST_1)
    {
        std::cout << "Solution1 start.........." << std::endl;
        start = std::chrono::system_clock::now();

        decltype(expected) result = solution.isPalindrome1(head);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution1 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution1 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
    }
    if (TEST_2)
    {
        std::cout << "Solution2 start.........." << std::endl;
        start = std::chrono::system_clock::now();

        decltype(expected) result = solution.isPalindrome2(head);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution2 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution2 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Solution2 costs " << elapsed.count() <<"micros" << std::endl;
    }
    if (TEST_3)
    {
        std::cout << "Solution3 start.........." << std::endl;
        start = std::chrono::system_clock::now();

        decltype(expected) result = solution.isPalindrome3(head);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
        {
            //10yy
            std::cout << GREEN << "Solution3 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution3 failed." <<  RESET << std::endl;
            std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RESET << std::endl;
        }
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Solution3 costs " << elapsed.count() <<"micros" << std::endl;
    }
}
void Test1()
{
    ListNode * p2 = new ListNode(2);
    ListNode * p1 = new ListNode(1, p2);
    Test("Test1", p1, false );
}

void Test2()
{
    ListNode * p4 = new ListNode(1);
    ListNode * p3 = new ListNode(2, p4);
    ListNode * p2 = new ListNode(2, p3);
    ListNode * p1 = new ListNode(1, p2);
    Test("Test2", p1, true  );
}

void Test3()
{
    ListNode * p5 = new ListNode(2);
    ListNode * p4 = new ListNode(3, p5);
    ListNode * p3 = new ListNode(4, p4);
    ListNode * p2 = new ListNode(3, p3);
    ListNode * p1 = new ListNode(2, p2);
    Test("Test3", p1, true  );
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
