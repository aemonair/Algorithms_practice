/*
 ***********************************************************************
 * 142. Linked List Cycle II
 * Medium
 ***********************************************************************
 * Given a linked list, return the node where the cycle begins.
 * If there is no cycle, return null.
 * To represent a cycle in the given linked list,
 * we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to.
 * If pos is -1, then there is no cycle in the linked list.
 * Note: Do not modify the linked list.
 ***********************************************************************
 *
 * Example 1:
 *
 *     3 -> 2 -> 0 -> -4
 *          ↖        ↙
 *            ← ← ← ←
 *
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the second node.
 ***********************************************************************
 *
 * Example 2:
 *
 *          1 - > 2
 *          ↖   ↙
 *            ←
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the first node.
 ***********************************************************************
 *
 * Example 3:
 *
 *          1
 *
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 ***********************************************************************
 * Constraints:
 *
 * The number of the nodes in the list is in the range [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * pos is -1 or a valid index in the linked-list.
 ***********************************************************************
 * Follow up: Can you solve it using O(1) (i.e. constant) memory?
 ***********************************************************************
 */
#include <unordered_map>
#include <unordered_set>
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, struct ListNode * next) : val(x), next(next) {}
};

std::ostream & operator << (std::ostream &out, ListNode * head);

class Solution {
public:
/*
 * 17 找到带环链表的环入口节点
 *
 *    - - - 、
 *           \    - - - - 、
 *            \ /          |
 *             \          /
 *         入口点 ` - -*- -
 *                    \
 *                      相遇点
 *             |<-x->|
 *   |<---a--->|<-----r---->|
 *   |<----------L--------->|
 *  我们设整个链表长L，入口点与相遇点长x，起点到入口点长度为a;
 *  快指针走的长度是慢指针的2倍，由于快指针可能不止走了一圈;
 *  慢指针走了s步，即快指针走了2s步。
 *
 *  ∵ 2s = s + nr ;
 *  ∴ s = nr;
 *
 *    a + x = nr
 *    a + x = nr = (n-1)r + r =  (n-1)r + L -a
 *    a = (n-1)r + (L -a -x)
 *    链表从头到环入口点长度 = (n -1)环长 + 相遇点到环入口长度
 *    所以， 从链表头和相遇点各设一个一步长的指针，必定会在相遇点回合。
 *
 *              l    f
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖       ↙
 *                     ← 6 ←
 *
 *                   l         f
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖       ↙
 *                     ← 6 ←
 *
 *                   f    l
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖       ↙
 *                     ← 6 ←
 *
 *                             lf         Found
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖       ↙
 *                     ← 6 ←
 *
 *         |     a   |    b    |
 *         l                   f
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖       ↙
 *                     ← 6 ←
 *                    |  c  |
 *
 *
 *         |     a   |    b    |
 *              l
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖       ↙
 *                     ← 6 ←
 *                       f
 *                    |  c  |
 *
 *         |     a   |    b    |
 *                  lf
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖       ↙
 *                     ← 6 ←
 *                    |  c  |
 *
 * * * * * * * * * * * * *
 *              l    f
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖        ↙
 *                     ← ← ← ←
 *
 *                   l         f
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖        ↙
 *                     ← ← ← ←
 *
 *                        lf
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖        ↙
 *                     ← ← ← ←
 *
 *                        lf             Found
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖        ↙
 *                     ← ← ← ←
 *
 *         a             b
 *                        lf             Found
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖        ↙     c
 *                     ← ← ← ←
 *
 *         | a       |    b    |
 *         l              f
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖        ↙
 *                     ← ← ← ←
 *                   |   c     |
 *
 *              l              f
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖        ↙     c
 *                     ← ← ← ←
 *
 *                   lf
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖        ↙     c
 *                     ← ← ← ←
 *
 *         |    a    |    b     |
 *         1 -> 2 -> 3 -> 4 -> 5
 *                   ↖        ↙     c
 *                     ← ← ← ←
 *
 * * * * * * * * * * * * *
 *      2 * sum = a + m*(b+c) + b
 *      1 * sum = a + n*(b+c) + b
 *
 *      2a +     2n(b+c) + 2b = a + m*(b+c) +b
 *       a + (2n-m)(b+c) +  b = 0
 *           (m-2n)(b+c)      = a + b
 *           (m-2n)(b+c)      = a + b -c + c
 *         (1+m-2n)(b+c)      = a + b -c + c
 *
 *           x     (b+c)      = a + b
 *           a                = x * (b+c) - b
 *           a                = (x-1) * (b+c) + b + c - b
 *           a                = (x-1) * (b+c) + c
 *           a                = c
 *
 *
 */
    ListNode *detectCycle(ListNode *head)
    {
        return nullptr;
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName,
        ListNode * head,
        ListNode * target
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

    std::cout << head << std::endl;

const static int TEST_TIME = 1;
const static int TEST_0    = 1;
const static int TEST_1    = 0;
    if (TEST_0)
    {
        std::cout << "Solution0 start.........." << std::endl;
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(target) solution_result = solution.detectCycle(head);
        std::cout << "target:"; // << std::endl;
        if (solution_result)
        {
            std::cout << solution_result->val << std::endl;
        }
        else
        {
            std::cout << "nullptr" << std::endl;
        }

        if(solution_result == target)
        {
            //10yy
            std::cout << GREEN << "Solution0 passed." << RESET <<  std::endl;
        }
        else
        {
            std::cout << RED << "Solution0 failed." <<  RESET << std::endl;
            //std::cout << RED << "expected:" << expected << std::endl;
            std::cout << RED << "expected:";  // << std::endl;
            if (target)
            {
                std::cout << target->val<< RESET << std::endl;
            }
            else
            {
                std::cout << "nullptr"<< RESET << std::endl;
            }
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
    }
}
std::ostream & operator << (std::ostream &out, ListNode * head)
{
        ListNode *listNode = head;
        std::unordered_set<ListNode *> uset;
        if (head)
        {
            out << "head" << listNode->val << std::endl;
        }
        else
        {
            out << "null" << std::endl;
        }
        while (listNode != nullptr) // && listNode->next != nullptr)
        {
            std::cout << listNode->val << " " ; // << std::endl;
            listNode = listNode->next;
            if (uset.count(listNode) > 0) {
                out << " ∞ ";
                break;
            }
            uset.insert(listNode);
        }
        out << std::endl;
        return out;
}
void Test1()
{
    /*
     *
     *         1 -> 2 -> 3 -> 4 -> 5
     *              ↖            ↙
     *                ← ← ← ← ← ←
     *
     *
     */
    struct ListNode * p1 = new ListNode(1);
    struct ListNode * p2 = new ListNode(2);
    struct ListNode * p3 = new ListNode(3);
    struct ListNode * p4 = new ListNode(4);
    struct ListNode * p5 = new ListNode(5);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    p5->next = p2;

    Test("Test1", p1, p2);
}
void Test2()
{
    struct ListNode * r1 = new ListNode(1);
    struct ListNode * r2 = new ListNode(2, r1);
    Test("Test2", r1, nullptr);
}
void Test3()
{
    struct ListNode * q1 = new ListNode(6);
    Test("Test3", q1, nullptr);
}
int main()
{
    Test1();
    Test2();
    Test3();

    return 0;
}
