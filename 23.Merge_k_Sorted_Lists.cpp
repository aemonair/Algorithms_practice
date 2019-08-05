/*
 * 23. Merge k Sorted Lists
 * Merge k sorted linked lists and return it as one sorted list. 
 * Analyze and describe its complexity.
 * 
 * Example:
 * 
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 */
#include <queue>
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

class Solution {
public:
/*
 *         
 *           head
 *           1 -> 4 -> 3 -> 2 -> 5 -> 2
 */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (NULL == l1)
        {
            return l2;
        }
        else if (NULL == l2)
        {
            return l1;
        }
        if (l1 -> val < l2 -> val)
        {
            l1 -> next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2 -> next = mergeTwoLists(l1 , l2->next);
            return l2;
        }
    }

    ListNode* partion(vector<ListNode*>& lists, int s , int e)
    {
        if (s == e)
        {
            return lists[s];
        }
        if (s < e)
        {
            int q = (s + e) / 2;
            std::cout << "start: " << s << ", mid:" << q << ",end:" << e << std::endl;
            ListNode * l1 = partion(lists, s  , q);
            ListNode * l2 = partion(lists, q+1, e);
            return mergeTwoLists(l1, l2);
        }
        else
        {
            return nullptr;
        }
    }

    struct compare 
    {
        bool operator()(const ListNode* l, const ListNode* r) 
        {
            return l->val > r->val;
        }
    }; 

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode *, vector<ListNode *> , compare> q;
        for (auto l : lists)
        {
            if (l)
            {
                q.push(l);
            }
        }
        if (q.empty())
        {
            return nullptr;
        }

        ListNode * result = q.top();
        q.pop();
        if (result->next)
        {
            q.push(result->next);
        }
        ListNode * tail = result;
        while (!q.empty())
        {
            tail -> next = q.top();
            q.pop();
            tail = tail -> next;
            if (tail -> next)
            {
                q.push(tail->next);
            }
        }
        return result;
    }
    ListNode* mergeKLists0(vector<ListNode*>& lists)
    {
        return partion(lists, 0, lists.size() - 1);
    }
    ListNode* mergeKLists1(vector<ListNode*>& lists)
    {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        int count = lists.size();
        int interval = 1;
        while (interval < count)
        {
            for (int i = 0; i < count - interval ; i += interval * 2)
            {
                std::cout << "i: " << i << ", i + interval" << i + interval << std::endl;
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval = interval * 2;
        }
        return lists[0];
    }
    ListNode* mergeKLists2(vector<ListNode*>& lists)
    {
        if (lists.empty())
        {
            return NULL;
        }
        int len = lists.size();
        while (len > 1)
        {
            for (int i = 0 ; i < len / 2; ++i)
            {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }

        return lists.front();
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
    struct ListNode * p1 = new ListNode(1);
    struct ListNode * p4 = new ListNode(4);
    struct ListNode * p5 = new ListNode(5);

    struct ListNode * q1 = new ListNode(1);
    struct ListNode * q3 = new ListNode(3);
    struct ListNode * q4 = new ListNode(4);
    
    struct ListNode * r2 = new ListNode(2);
    struct ListNode * r6 = new ListNode(6);

    p1->next = p4;
    p4->next = p5;

    q1->next = q3;
    q3->next = q4;

    r2->next = r6;

    std::vector<ListNode*> lists;
    lists.push_back(p1);
    lists.push_back(q1);
    lists.push_back(r2);

    Solution a;
    a.printList(a.mergeKLists(lists));

    return 0;
}
