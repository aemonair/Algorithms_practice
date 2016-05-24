/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void *Malloc(size_t size);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int flag =0;
    struct ListNode* list = NULL;
    struct ListNode *l = NULL;
    
    if(l1!= NULL || l2!= NULL)
    {
        list = (struct ListNode*)(Malloc(sizeof(struct ListNode)));
        list->val =0;
        l = list;
    }
    while(l1!= NULL || l2!=NULL || flag ==1)
    {
        if(l1!=NULL)
        {
            list->val += l1->val ;
        }
        if(l2!= NULL)
        {
            list->val += l2->val;
        }
        list->val += flag;
        
        flag = 0;
        
        if(list->val >= 10)
        {
            list->val %= 10;
            flag = 1;
        }
        //l1 == NULL l2 == NULL
        if(l1 == NULL && l2 == NULL)
        {
            list->next = NULL;
            if(flag == 1)
            {
                list->next= (struct ListNode*)(Malloc(sizeof(struct ListNode)));
                list = list->next;
            }
        }
        else//( l1 == NULL ,l2 != NULL )  ||( l1 != NULL ,l2 != NULL )||( l1 != NULL ,l2 ==NULL)
        {
            if(l1 != NULL)
            {
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                l2 = l2->next;
            }
            
            if(l1 != NULL || l2!=NULL || flag == 1)
            {
                list->next= (struct ListNode*)(Malloc(sizeof(struct ListNode)));
                list = list->next;
                list->val =0;
            }
            else
            {
                list->next =NULL;
                list = list->next;
            }
        }
    }
    return l;
}
void *Malloc(size_t size)
{
    void *p;
    if((p = malloc(size)) == NULL)
    {
        return;
    }
    return p;
}

void Free(struct ListNode *l)
{
    struct ListNode *p =NULL;
    p = l;
    while(p!= NULL)
    {
        p = l->next;
        free(l);
    }
}
