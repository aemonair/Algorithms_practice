/*
 * 92. Reverse Linked List II
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 */
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode * cur = NULL;
        while(head)
        {
            ListNode * next = head -> next;
            head -> next = cur;
            cur = head;
            head = next;
        }
        return cur;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
/*
 *           m = 2, n = 4
 *           head
 *           1 -> 2 -> 3 -> 4 -> 5
 *
 *  prehead  head
 *      0 -> 1 -> 2 -> 3 -> 4 -> 5
 *
 *      pre  head
 *      0 -> 1 -> 2 -> 3 -> 4 -> 5
 *
 *           pre 
 *      0 -> 1 -> 2 -> 3 -> 4 -> 5
 *
 *           pre  pstart
 *      0 -> 1 -> 2 -> 3 -> 4 -> 5
 *  while:
 *
 *           pre start p
 *      0 -> 1 -> 2 -> 3 -> 4 -> 5
 *
 *           pre start p
 *      0 -> 1 -> 2    3 -> 4 -> 5
 *                 ------->
 *
 *           pre start p
 *      0 -> 1    2 <- 3    4 -> 5
 *                 ------->
 *             -------->
 *
 *           pre start      p
 *      0 -> 1    2 <- 3    4 -> 5
 *                 ------->
 *             -------->
 *
 *           pre start      p
 *      0 -> 1    2 <- 3    4 -> 5
 *                 ------------>
 *             -------->
 *
 *           pre start      p
 *      0 -> 1    2 <- 3 <- 4    5
 *                 ------------>
 *             ------------->
 *
 *           pre  p       pstart
 *      0 -> 1 -> 4 -> 3 -> 2 -> 5
 */
        if (m == n)
        {
            return head;
        }
        n = n - m;
        ListNode * prehead = new ListNode(0);
        prehead->next = head;

        ListNode * pre     =  prehead;
        std::cout << "prehead: " << prehead ->val << std::endl;
        std::cout << "pre    : " << pre     ->val << std::endl;
        while (--m > 0)
        {
            pre = pre -> next;
        }
        std::cout << "pre    : " << pre     ->val << std::endl;
        ListNode * pstart = pre -> next;
        std::cout << "pre : " << pre  ->val << std::endl;
        //std::cout << "pstart : " << pstart  ->val << std::endl;
        while (pstart && n-- > 0)
        {
            ListNode * p = pstart -> next;
            pstart -> next = p -> next;
            p -> next = pre -> next;
            pre -> next = p;
            std::cout << "p : " << p  ->val << std::endl;
        }
        return prehead->next;
    }
    ListNode* reverseBetween1(ListNode* head, int m, int n)
    {
/*
 *           m = 2, n = 4
 *           head
 *           1 -> 2 -> 3 -> 4 -> 5
 *
 *     dummy head
 *     -1 -> 1 -> 2 -> 3 -> 4 -> 5
 *
 *     cur   head
 *     -1 -> 1 -> 2 -> 3 -> 4 -> 5
 *
 *           cur 
 *     -1 -> 1 -> 2 -> 3 -> 4 -> 5
 *
 *           pre
 *           cur  last
 *     -1 -> 1 -> 2 -> 3 -> 4 -> 5
 *
 * for( i = 2, 2 <= 4)
 *           pre  cur 
 *     -1 -> 1 -> 2 -> 3 -> 4 -> 5
 *
 *           pre  cur 
 *     -1 -> 1    2 -> 3 -> 4 -> 5
 *            ------->
 *
 *                front
 *           pre  cur 
 *     -1 -> 1    2    3 -> 4 -> 5
 *                ->NULL
 *            ------->
 * for( i = 3, 3 <= 4)
 *                front
 *           pre       cur 
 *     -1 -> 1    2    3 -> 4 -> 5
 *                ->NULL
 *            ------->
 *
 *                front
 *           pre       cur 
 *     -1 -> 1    2    3 -> 4 -> 5
 *                ->NULL
 *            ------------->
 *
 *                front
 *           pre       cur 
 *     -1 -> 1    2 <- 3    4 -> 5
 *                ->NULL
 *            ------------->
 *
 *                     front
 *           pre       cur 
 *     -1 -> 1    2 <- 3    4 -> 5
 *                ->NULL
 *            ------------->
 *
 * for( i = 4, 4 <= 4)
 *                     front
 *           pre            cur 
 *     -1 -> 1    2 <- 3    4 -> 5
 *                ->NULL
 *            ------------->
 *
 *                     front
 *           pre            cur 
 *     -1 -> 1    2 <- 3    4 -> 5
 *                ->NULL
 *            ------------------>
 *
 *                     front
 *           pre            cur 
 *     -1 -> 1    2 <- 3 <- 4    5
 *                ->NULL
 *            ------------------>
 *
 *                          front
 *           pre            cur 
 *     -1 -> 1    2 <- 3 <- 4    5
 *                ->NULL
 *            ------------------>
 *
 * end for
 *                          front
 *           pre                 cur 
 *     -1 -> 1    2 <- 3 <- 4    5
 *                ->NULL
 *            ------------------>
 *
 *                          front
 *           pre                 cur 
 *     -1 -> 1    2 <- 3 <- 4    5
 *                ->NULL
 *            ------------->
 *
 *                          front
 *           pre  last           cur 
 *     -1 -> 1    2 <- 3 <- 4    5
 *                -------------->
 *            ------------->
 *
 *           pre  front     last cur 
 *     -1 -> 1 -> 4 -> 3 -> 2 -> 5
 *
 *     dummy pre  front     last cur 
 *     -1 -> 1 -> 4 -> 3 -> 2 -> 5
 */
        ListNode * dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *cur = dummy;
        ListNode * pre   ;
        ListNode * front ;
        ListNode * last  ;
        for (int i =1 ; i <= m -1 && cur; ++i)
        {
            cur = cur -> next;
        }
        pre = cur;
        if (cur->next == NULL)
        {
            return head;
        }
        last = cur -> next;
        std::cout << "cur    : " << cur     ->val << std::endl;
        std::cout << "pre    : " << pre     ->val << std::endl;
        std::cout << "last   : " << last    ->val << std::endl;
        for (int i = m ; i <= n ; ++i)
        {
            cur  =  pre -> next;
            pre->next = cur -> next;
            cur->next = front;
            front = cur;
            std::cout << "w.pre    : " << pre     ->val << std::endl;
            std::cout << "w.cur    : " << cur     ->val << std::endl;
            std::cout << "w.front  : " << front   ->val << std::endl;
        }
        cur = pre -> next;
        std::cout << "cur    : " << cur     ->val << std::endl;
        std::cout << "pre    : " << pre     ->val << std::endl;
        std::cout << "front  : " << front   ->val << std::endl;
        pre -> next = front;
        std::cout << "pre    : " << pre     ->val << std::endl;
        last -> next = cur;
        return dummy->next;
    }
    ListNode* reverseBetween2(ListNode* head, int m, int n)
    {
/*
 *           m = 2, n = 4
 *           head
 *           1 -> 2 -> 3 -> 4 -> 5
 *           old
 *           1 -> 2 -> 3 -> 4 -> 5
 *           prev head
 *           1 -> 2 -> 3 -> 4 -> 5
 *           while:
 *                     next
 *           1 -> 2 -> 3 -> 4 -> 5
 *                     next
 *           1 -> 2    3 -> 4 -> 5
 *                -> cur(NULL)
 *
 *                cur
 *           1 -> 2    3 -> 4 -> 5
 *                -> NULL
 *
 *                cur  head
 *           1 -> 2    3 -> 4 -> 5
 *                -> NULL
 *
 *                cur  head next
 *           1 -> 2    3 -> 4 -> 5
 *                -> NULL
 *
 *                cur  head next
 *           1 -> 2 <- 3    4 -> 5
 *                -> NULL
 *
 *                     cur  head
 *           1 -> 2 <- 3    4 -> 5
 *                -> NULL
 *
 *                     cur  head next
 *           1 -> 2 <- 3    4 -> 5
 *                -> NULL
 *
 *                     cur  head next
 *           1 -> 2 <- 3 <- 4    5
 *                -> NULL
 *
 *           prev           cur  head
 *           1 -> 2 <- 3 <- 4    5
 *                -> NULL
 *
 *           prev           cur  head
 *           1 -> 2 <- 3 <- 4    5
 *                -------------->
 *
 *           prev           cur  head
 *           1    2 <- 3 <- 4    5
 *                -------------->
 *            -------------->
 *
 *           prev cur            head
 *           1 -> 4 -> 3 -> 2 -> 5
 */
        if (!head || !(head->next))
        {
            return head;
        }
        if (m < 1 )
        {
            m = 1;
        }
        ListNode * oldhead = head;
        ListNode * cur = NULL;
        ListNode * next = NULL; 
        ListNode * prev = NULL; 
        int mm = m;
        while (mm-- > 1)
        {
            prev = head;
            head = head->next;
        }
        printList(oldhead);
        std::cout << "head: " << head ->val << std::endl;
        if (m>1)
        {
            std::cout << "prev: " << prev ->val << std::endl;
        }
        else
        {
            prev = head;
            std::cout << "prev: " << head ->val << std::endl;
        }
        while(head && ((n--)-m+1))
        {
            next = head -> next;
            head -> next = cur;
            cur = head;
            head = next;
        }
        if (head)
        {
            std::cout << "head: " << head ->val << std::endl;
        }
        std::cout << "prev: " << prev ->val << std::endl;
        std::cout << "cur : " << cur  ->val << std::endl;
        if (m >1)
        {
            std::cout << "m>1, prev: " << prev ->val << std::endl;
            std::cout << "prev->next: " << prev ->next->val << std::endl;
            prev->next->next =  head;
            prev -> next = cur ;
            return oldhead;
        }
        else
        {
            prev -> next = head;
            return cur;
        }
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

int main()
{
    struct ListNode * p1 = new ListNode(1);
    struct ListNode * p2 = new ListNode(2);
    struct ListNode * p3 = new ListNode(3);
    struct ListNode * p4 = new ListNode(4);
    struct ListNode * p5 = new ListNode(5);
    
    struct ListNode * q1 = new ListNode(6);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    Solution a;
    a.printList (p1);
    a.printList (q1);

    a.printList(a.reverseBetween(p1, 2, 4));
    a.printList(a.reverseBetween(q1, 2, 4));
    return 0;
}
