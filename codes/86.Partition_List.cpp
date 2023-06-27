/*
 * 86. Partition List
 *
 * Given a linked list and a value x,
 * partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * Example:
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
/*
 *        
 *           head
 *           1 -> 4 -> 3 -> 2 -> 5 -> 2
 */
    ListNode* partition(ListNode* head, int x)
    {
        ListNode node1(0);
        ListNode node2(0);
        ListNode * p1 = &node1;
        ListNode * p2 = &node2;
        while (head)
        {
            if (head -> val < x)
            {
                p1 = p1 -> next = head;
            }
            else
            {
                p2 = p2 -> next = head;
            }
            head = head -> next;
        }
        p2 -> next = NULL;
        p1 -> next = node2.next;

        return node1.next;
    }
    ListNode* partition1(ListNode* head, int x)
    {
        ListNode left(0);
        ListNode right(0);
        ListNode *l = &left;
        ListNode *r = &right;

        while (head)
        {
            ListNode * & ref = head -> val < x ? l : r;
            ref -> next = head;
            ref = ref -> next;

            head = head -> next;
        }
        l -> next = right.next;
        r -> next = NULL;

        return left.next;
    }
    ListNode* partition2(ListNode* head, int x)
    {
        if (head == NULL || head -> next == NULL)
        {
            return head;
        }
        ListNode * left  = new ListNode(0);
        ListNode * right = new ListNode(0);

        ListNode * phead = head           ;

        ListNode * pleft = left           ;
        ListNode * pright= right          ;

        while (phead)
        {
            std::cout << "phead: " << phead->val << std::endl;
            ListNode *pnext = phead -> next;
            phead -> next = NULL;
            //printList(left);
            //printList(right);
            if (phead -> val < x)
            {
                pleft -> next = phead;
                pleft = pleft ->next;
            }
            else
            {
                pright -> next = phead;
                pright = pright ->next;
            }
            phead = pnext;
        }
        printList(left);
        printList(right);
        pleft -> next = right->next;
        return left->next;
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
    /*
     *
     *           head
     *           1 -> 4 -> 3 -> 2 -> 5 -> 2
     */
    struct ListNode * p1 = new ListNode(1);
    struct ListNode * p2 = new ListNode(4);
    struct ListNode * p3 = new ListNode(3);
    struct ListNode * p4 = new ListNode(2);
    struct ListNode * p5 = new ListNode(5);
    struct ListNode * p6 = new ListNode(2);
   
    struct ListNode * q1 = new ListNode(1);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;

    Solution a;
    a.printList(a.partition(p1, 3));
    a.printList(a.partition(q1, 3));

    return 0;
}
