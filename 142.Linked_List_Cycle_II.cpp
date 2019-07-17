/*
 * 142. Linked List Cycle II
 *
 * Given a linked list, return the node where the cycle begins. 
 * If there is no cycle, return null.
 * To represent a cycle in the given linked list, 
 * we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. 
 * If pos is -1, then there is no cycle in the linked list.
 * Note: Do not modify the linked list.
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
 * 
 * Example 2:
 *
 *          1 - > 2   
 *          ↖   ↙  
 *            ←
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the first node.
 * 
 * Example 3:
 *
 *          1
 * 
 * Input: head = [1], pos = -1
 * Output: no cycle
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
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                std::cout << "Exist:" << slow->val << ", " << fast->val << std::endl;
                fast = head;
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                std::cout << "endwhile:" << slow->val << ", " << fast->val << std::endl;
                std::cout << fast << std::endl;
                return slow; 
            }
        }
        return NULL;
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

    std::cout << "before detect:";// << detect->val;
    std::cout << p2 << std::endl;
    ListNode * detect = a.detectCycle(p1);
    std::cout << "detect:" << std::endl;
    if (detect)
    {
        std::cout << detect->val;
    }
    else
    {
        std::cout << "NULL";
    }
    std::cout << "Q1:" << std::endl;
    detect = a.detectCycle(q1);
    if (detect != NULL)
    {
        std::cout << detect->val;
    }
    else
    {
        std::cout << "NULL";
    }
    return 0;
}
