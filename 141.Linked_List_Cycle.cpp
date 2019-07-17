/*
 * 141. Linked List Cycle
 * Given a linked list, determine if it has a cycle in it.
 *
 * To represent a cycle in the given linked list, 
 * we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to.
 * If pos is -1, then there is no cycle in the linked list.
 *
 * Example 1:
 * 
 *     3 -> 2 -> 0 -> -4  
 *          ↖        ↙  
 *            ← ← ← ←
 *
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the second node.
 * 
 * Example 2:
 *
 *          1 - > 2   
 *          ↖   ↙  
 *            ←
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the first node.
 * 
 * Example 3:
 *
 *          1
 * 
 * Input: head = [1], pos = -1
 * Output: false
 * Explanation: There is no cycle in the linked list.
 * 
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
    bool hasCycle1(ListNode *head)
    {
        ListNode * slow = head;
        ListNode * fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
    bool hasCycle2(ListNode *head)
    {
        if (!head || !(head->next))
        {
            return false;
        }
        ListNode * f = head->next->next;
        ListNode * l = head;

        while (l != f && f && l)
        {
            l = l->next;
            if (f->next)
            {
                f = f->next->next;
            }
            else
            {
                return false;
            }
        }
        if (l == f)
        {
            return true;
        }
        else
        {
            return false;
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
    
    struct ListNode * q1 = new ListNode(6);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    p5->next = p2;

    Solution a;

    std::cout << a.hasCycle(p1);
    std::cout << a.hasCycle(q1);

    return 0;
}
