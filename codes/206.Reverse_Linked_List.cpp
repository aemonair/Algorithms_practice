/*
 * 206. Reverse Linked List
 *
 * Reverse a singly linked list.
 * Example:
 *
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * Follow up:
 *
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
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
        if (!head || !(head->next))
        {
            return head;
        }

/*
 *                
 *   null <- 1 -> 2 -> 3 -> 4
 *                2 <- 3 <- 4
 *
 *                head node
 *                2 -> 3 <- 4
 *        null <- 2 <- 3 <- 4
 *                      
 *                     head
 *                     3 -> 4
 *              null <-3 <- 4
 *                         
 *                          node
 *                          4
 *      head -> next  ==  List tail
 */
        ListNode * node = reverseList(head->next);
        head -> next -> next = head;
        head -> next = NULL;
        return node;
    }
    ListNode* reverseList1(ListNode* head)
    {
        ListNode * cur = NULL;
        while(head)
        {
            ListNode * next = head -> next;
            head -> next = cur;
            cur = head;
            head = next;
        }
/*
 *     cur  head next
 *     NULL  1 -> 2 -> 3 -> 4
 *
 *     NULL<-1 -> 2 -> 3 -> 4
 *          cur   head
 *     NULL<-1 -> 2 -> 3 -> 4
 *          cur   head next
 *     NULL<-1 -> 2 -> 3 -> 4
 *          cur   head next
 *     NULL<-1 <- 2 -> 3 -> 4
 *                cur  next
 *     NULL<-1 <- 2 -> 3 -> 4
 *                cur  head
 *     NULL<-1 <- 2 -> 3 -> 4
 *                cur  head next
 *     NULL<-1 <- 2 -> 3 -> 4
 *                cur  head next
 *     NULL<-1 <- 2 <- 3 -> 4
 *                     cur  next
 *     NULL<-1 <- 2 <- 3 -> 4
 *                     cur  head next
 *     NULL<-1 <- 2 <- 3 -> 4
 *                     cur  head next
 *     NULL<-1 <- 2 <- 3 <- 4
 *                          cur  head
 *     NULL<-1 <- 2 <- 3 <- 4
 *              
 *           */
        return cur;
    }
    ListNode* reverseList2(ListNode* head)
    {
        ListNode *pre = new ListNode(0);
        ListNode *cur = head;
        pre ->next = head;
        // Add a new node 0 -> 1 -> 2 -...
        /*
 *          head
 *           1 -> 2 -> 3 -> 4
 *           ^
 *          pre
 *          0
 *           cur
 *           1 -> 2 -> 3 -> 4
 *
 *          cur  temp
 *           1 -> 2 -> 3 -> 4
 *
 *           1    2 -> 3 -> 4
 *           -------->
 *
 *          cur  temp
 *           1 <- 2    3 -> 4
 *           -------->
 *           ^
 *           pre
 *
 *          cur  temp
 *           1 <- 2    3 -> 4
 *           -------->
 *                ^
 *               pre
 *
 *          cur      temp
 *           1 <- 2    3 -> 4
 *           ------------->
 *                ^
 *               pre
 *
 *          cur      temp
 *           1 <- 2 <- 3 -> 4
 *           ------------->
 *                ^
 *               pre
 *
 *          cur      temp
 *           1 <- 2 <- 3 -> 4
 *           ------------->
 *                     ^
 *                    pre
 *
 *          cur           temp
 *           1 <- 2 <- 3 -> 4
 *           ------------->
 *                     ^
 *                    pre
 *
 *          cur           temp
 *     NULL<-1 <- 2 <- 3 -> 4
 *                     ^
 *                    pre
 *
 *          cur           temp
 *     NULL<-1 <- 2 <- 3 <- 4
 *                          ^
 *                         pre
 *
 *      */
        while (cur && cur->next)
        {
            ListNode *temp = cur->next;
            cur -> next = temp->next;
            temp-> next = pre->next;
            pre -> next = temp;
        }
        return pre->next;
    }
    ListNode* reverseList3(ListNode* head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode * prev = NULL;
        ListNode * next = head->next;

        while(next != NULL)
        {
            head ->next = prev;
            prev = head;
            std::cout << "head:" << head->val << " , next:" << next->val << "prev:" << prev->val << std::endl;
            head = next;
            next = head ->next;
            std::cout << "head: " << head->val <<  "p:" << prev->val<< std::endl;
        }

/*
 *     prev    head next
 *     NULL    1 -> 2 -> 3 -> 4
 *
 *     prev    head next
 *     NULL <- 1 -> 2 -> 3 -> 4
 *             prev head next
 *     NULL <- 1 -> 2 -> 3 -> 4
 *             prev head next
 *     NULL <- 1 <- 2 -> 3 -> 4
 *                  prev head next
 *     NULL <- 1 <- 2 -> 3 -> 4
 *                  prev head next
 *     NULL <- 1 <- 2 <- 3 -> 4
 *                       prev head next
 *     NULL <- 1 <- 2 <- 3 -> 4
 *                       prev head next
 *     NULL <- 1 <- 2 <- 3 <- 4
 */
        head ->next = prev;
        return head;
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

    a.printList(a.reverseList(p1));
    a.printList(a.reverseList(q1));
    return 0;
}
