/*
 ******************************************************************************************
 * 23. Merge k Sorted Lists
 * Hard
 ******************************************************************************************
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 *
 * >> Merge k sorted linked lists and return it as one sorted list.
 * >> Analyze and describe its complexity. (@20200504)
 ******************************************************************************************
 * Example 1:
 *
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 * Explanation: The linked-lists are:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * merging them into one sorted list:
 * 1->1->2->3->4->4->5->6
 ******************************************************************************************
 * Example 2:
 *
 * Input: lists = []
 * Output: []
 ******************************************************************************************
 * Example 3:
 *
 * Input: lists = [[]]
 * Output: []
 ******************************************************************************************
 * Constraints:
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] is sorted in ascending order.
 * The sum of lists[i].length won't exceed 10^4.
 ******************************************************************************************
 * @20200504
 * 23. Merge k Sorted Lists
 * Example:
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 ******************************************************************************************
 */
#include <iostream>
#include <chrono>
#include <vector>
#include <queue>


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    bool operator == (ListNode const &A, ListNode const &B)
    {
        auto a = &A;
        auto b = &B;
        if(a == nullptr && b == nullptr)
        {
            return true;
        }
        if(a == nullptr || b == nullptr)
        {
            return false;
        }
        if(a->val == b ->val )
        {
            return *a->next == *b->next;
        }
        else
        {
            return false;
        }
    }

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

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
    }

    ListNode* partion(std::vector<ListNode*>& lists, int s , int e)
    {
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        return nullptr;
    }
   
    ListNode* mergeKLists0(std::vector<ListNode*>& lists)
    {
    }
    ListNode* mergeKLists1(std::vector<ListNode*>& lists)
    {
    }
    ListNode* mergeKLists2(std::vector<ListNode*>& lists)
    {
    }

    int printList(std::vector<ListNode*>& head)
    {
        for(auto h : head)
        {
            printList(h);
        }
        return 0;
    }
    std::vector<int> printList(ListNode* head)
    {
        std::vector<int> ret ;
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
        std::vector<ListNode *>& head,
        ListNode * expected)
{
    if(testName.length() > 0)
        std::cout << BOLDMAGENTA << testName << " begins: "<< RESET << std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

const static int TEST_TIME = 1;
    {
        solution.printList(head);
        if (TEST_TIME)
        {
            start = std::chrono::system_clock::now();
        }

        decltype(expected) result = solution.mergeKLists(head);

        std::cout << "result: ";
        solution.printList(result);
        //if(result == expected)
        if(*result == *expected)
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

}

int Test1()
{
    ListNode * p5 = new ListNode(5);
    ListNode * p4 = new ListNode(4, p5);
    ListNode * p1 = new ListNode(1, p4);

    ListNode * q4 = new ListNode(4);
    ListNode * q3 = new ListNode(3, q4);
    ListNode * q1 = new ListNode(1, q3);
   
    ListNode * r6 = new ListNode(6);
    ListNode * r2 = new ListNode(2, r6);

    std::vector<ListNode*> lists{p1, q1, r2};
    //std::vector<ListNode*> lists; // {p1, q1, r2};
    //lists.push_back(p1);
    //lists.push_back(q1);
    //lists.push_back(r2);

    //* Input: lists = [[1,4,5],[1,3,4],[2,6]]
    //* Output: [1,1,2,3,4,4,5,6]
    ListNode * result8 = new ListNode(6);
    ListNode * result7 = new ListNode(5, result8);
    ListNode * result6 = new ListNode(4, result7);
    ListNode * result5 = new ListNode(4, result6);
    ListNode * result4 = new ListNode(3, result5);
    ListNode * result3 = new ListNode(2, result4);
    ListNode * result2 = new ListNode(1, result3);
    ListNode * result1 = new ListNode(1, result2);
    Test("Test0", lists, result1);
    std::cout << "result:" << std::boolalpha << (result1 == result1) << std::endl;
    std::cout << "result:" << std::boolalpha << (p1      == result1) << std::endl;
    return 0;
}
int Test2()
{
    std::vector<ListNode*> v{nullptr};
    Test("Test2", v ,nullptr);
    return 0;
}
int Test3()
{
    std::vector<ListNode*> v{};
    Test("Test3", v, nullptr);
    return 0;
}
int Test4()
{
    ListNode * l1_9 = new ListNode(9);
    ListNode * l1_8 = new ListNode(8, l1_9);
    ListNode * l1_5 = new ListNode(5, l1_8);

    ListNode * l2_7 = new ListNode(7);
    ListNode * l2_1 = new ListNode(1, l2_7);

    std::vector<ListNode*> v{l2_1, l1_5};

    ListNode * r_5  = new ListNode(9);
    ListNode * r_4  = new ListNode(8, r_5);
    ListNode * r_3  = new ListNode(7, r_4);
    ListNode * r_2  = new ListNode(5, r_3);
    ListNode * r_1  = new ListNode(1, r_2);
    Test("Test4", v, r_1);
    return 0;
}
int Test5()
{
    ListNode * l1_8 = new ListNode(8);
    ListNode * l1_6 = new ListNode(6, l1_8);
    ListNode * l1_2 = new ListNode(2, l1_6);

    ListNode * l2_7 = new ListNode(7);
    ListNode * l2_6 = new ListNode(6, l2_7);
    ListNode * l2_3 = new ListNode(3, l2_6);

    ListNode * l3_4 = new ListNode(4);
    ListNode * l3_3 = new ListNode(3, l3_4);
    ListNode * l3_1 = new ListNode(1, l3_3);
    std::vector<ListNode*> v{l3_1, l2_3, l1_2};

    ListNode * r_9  = new ListNode(8);
    ListNode * r_8  = new ListNode(7, r_9);
    ListNode * r_7  = new ListNode(6, r_8);
    ListNode * r_6  = new ListNode(6, r_7);
    ListNode * r_5  = new ListNode(4, r_6);
    ListNode * r_4  = new ListNode(3, r_5);
    ListNode * r_3  = new ListNode(3, r_4);
    ListNode * r_2  = new ListNode(2, r_3);
    ListNode * r_1  = new ListNode(1, r_2);
    Test("Test5", v, r_1);
    return 0;
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
