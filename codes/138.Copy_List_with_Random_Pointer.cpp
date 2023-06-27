/*
 * 138. Copy List with Random Pointer
 *
 * A linked list is given such that each node contains an additional random pointer
 * which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 * Example 1:
 *
 *     ---------              ---------
 *    | val: 1  |            | val: 2  |
 *    |  next---|----------> |  next---|
 *    |random---|----------> |random---|----
 *     ---------              ---------      |
 *                                ↖        ↙ 
 *                                  ← ← ← ←
 *                               
 * Input:
 * {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 *
 * {
    $id: "1",
    next:
    {
        $id: "2",
        next: null,
        random:
        {
            $ref: "2"
        },
        val: 2
    },
    random: {
        $ref: "2"
    },
    val: 1
}
 *
 * Explanation:
 * Node 1's value is 1, both of its next and random pointer points to Node 2.
 * Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
 */
#include <unordered_map>
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
/*
 *        
 */
    std::unordered_map<Node *, Node *> hmap;
    Node* copyRandomList(Node* head)
    {
        if (!head)
        {
            return NULL;
        }
        if (hmap.find(head)!= hmap.end())
        {
            return hmap.find(head)->second;
        }
        Node * node = new Node(head->val, NULL, NULL);
        hmap[head] = node;
        node -> next = copyRandomList(head->next);
        node -> random = copyRandomList(head->random);
        return node;
    }
    Node* copyRandomList0(Node* head)
    {
        if (!head)
        {
            return NULL;
        }
        std::unordered_map<Node *, Node *> m;
        Node *p = head;
        while(p)
        {
            Node * newhead = new Node(p->val, NULL, NULL);
            m[p] = newhead;
            p    = p -> next;
        }
        p = head;
        Node *q = m[head];
        while (q)
        {
            if (p->random)
            {
                q->random = m [p->random];
            }
            else
            {
                q->random = NULL         ;
            }
            p = p->next;
            if (p)
            {
                q->next = m[p];
            }
            else
            {
                q -> next = NULL;
            }
            q = q->next;
        }
        return m[head];
    }

    Node* copyRandomList1(Node* head)
    {
        Node *iter = head;
        Node *next = NULL;

        //1. copy node
        //   and linked
        while (iter != NULL)
        {
            next = iter->next;

            Node * copy = new Node(iter->val, NULL, NULL);
            iter->next  = copy;
            copy->next  = next;

            iter        = next;
        }

        //2. assign random pointers
        iter = head;
        while (iter != NULL)
        {
            if (iter->random != NULL)
            {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        //3. restore list
        iter = head;
        Node *psHead   = new Node(0, NULL, NULL);
        Node *copy     = NULL;
        Node *copyIter = psHead;

        while (iter != NULL)
        {
            next = iter->next->next;

            copy           = iter->next;
            copyIter->next = copy;
            copyIter       = copy;

            //
            iter->next = next;

            iter = next;
        }
        return psHead->next;

    }
    Node* copyRandomList2(Node* head)
    {
        if (!head)
        {
            return head;
        }
        // Add new Node to List
        // 1 -> 2
        // 1 -> 1' -> 2 -> 2'
        Node *phead = head;
        while (phead)
        {
            Node *head2 = new Node(phead->val, NULL, NULL);
            head2 -> next = phead->next;
            phead -> next = head2;
            phead =  phead -> next -> next;
        }
        std::cout << "Add New node:" << std::endl;
        printList(head);

        phead = head;
        while (phead && phead->next)
        {
            if (phead -> random)
            {
                phead -> next -> random = phead -> random -> next;
            }
            phead =  phead -> next -> next;
        }
        std::cout << "Add Random pointer:" << std::endl;
        printList(head);

        phead = head;
        Node * p2head = head->next;
        Node * newhead = p2head;
        while (phead && p2head->next)
        {
            phead -> next = p2head -> next;
            p2head-> next = p2head -> next -> next;
            phead = phead -> next;
            p2head = p2head -> next;
            printList(head);
            printList(newhead);
        }
        phead->next = NULL;
        p2head->next = NULL;
        return newhead;
    }
    std::vector<int> printList(Node* head)
    {
        std::vector<int> ret ; // = new ArrayList<>();
        Node *node = head;
        if (head)
        {
            std::cout << "head" << node->val << std::endl;
        }
        else
        {
            std::cout << "null" << std::endl;
        }
        while (node != nullptr) // && listNode->next != nullptr)
        {
            std::cout << node << ":"<< node->val << " " ; // << std::endl;
            if (node->random)
            {
                std::cout << ",(" << node->random <<":" << node->random->val << ") " ; // << std::endl;
            }
            else
            {
                std::cout << ",() " ; // << std::endl;
            }
            ret.push_back(node->val);
            node = node->next;
        }
        std::cout << std::endl;
        return ret;
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
     */
    struct Node * p1 = new Node(1, NULL, NULL);
    struct Node * p2 = new Node(2, NULL, NULL);
   
    struct Node * q1 = new Node(1, NULL, NULL);

    p1->next = p2;
    p2->next = NULL;

    p1->random = p1;
    p2->random = NULL;

    Solution a;
    a.printList(p1);
    a.printList(q1);

    a.printList(a.copyRandomList1(p1));
    std::cout << "old:" << std::endl;
    a.printList((p1));
    a.printList(a.copyRandomList(q1));
    std::cout << "old:" << std::endl;
    a.printList((q1));

    return 0;
}
