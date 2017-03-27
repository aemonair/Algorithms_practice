//234. Palindrome Linked List 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (NULL == head)
    {
        return true;
    }
    struct ListNode * p = head;
    struct ListNode * q = head;
    struct ListNode * r = head;
    int count = 0; //节点个数数量
    
    while(q != NULL)
    {
        if(q->next)
        {
            q = q->next->next; //tail
            p = p->next;      //mid
            count+=2;
        }
        else
        {
            q = q->next;
            ++ count;
        }
    }
    printf("count:%d\n",count);
    
    int n = count/2;
    int _n = count/2;
    printf("n:%d\n",n);
    if(count %2 != 0)
    {
        p = p->next;   
    }
    
    while(_n)
    {
        r = head;
        
        n = _n;
        _n --;
        while((--n)  > 0)
        {
            r = r->next;
            // printf("1.p:%d r:%d n:%d\n", p->val,r->val,n);
        }
        // assert (p !=NULL || r != NULL);
        if(r && p)
        {
            if (r->val == p->val)
            {
                // printf("2.p:%d r:%d\n", p->val,r->val);
                p = p->next;
                continue;
            }
            else
            {
                return false;
            } 
        }
    }
    return true;
}
