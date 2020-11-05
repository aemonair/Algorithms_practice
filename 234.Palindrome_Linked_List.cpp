/*
 * 234. Palindrome Linked List
 * Easy
 * 
 ****************************************************************
 * Given a singly linked list, determine if it is a palindrome.
 * 
 **************************************************************** 
 * Example 1:
 * 
 * Input: 1->2
 * Output: false
 ****************************************************************
 * Example 2:
 * 
 * Input: 1->2->2->1
 * Output: true
 **************************************************************** 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 **************************************************************** 
 * 
 */

#include <algorithm>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
 

// Definition for singly-linked list.
typedef struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}ListNode;

class Solution {
public:
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
    /////////////////////////////////////////////////////////////////

    ListNode * reverse3(ListNode * head)
    {
        ListNode * pre = nullptr;
        ListNode * nxt = nullptr;

        while (head != nullptr)
        {
            nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        return pre;
    }
    ListNode * find_mid(ListNode *head)
    {
        ListNode * fast = head;
        ListNode * slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast != nullptr)
        {
            slow = slow ->next;
        }
        return slow;
    }
    bool isPalindrome3(struct ListNode* head) 
    {
        //printList(reverse3(head));
        ListNode * left= head;
        ListNode * mid = find_mid(head);
        ListNode * right = reverse3(mid);
        while (right != nullptr)
        {
            if (left ->val != right->val )
            {
                return false;
            }
            left = left->next;
            right = right -> next;
        }
        return true;
    }
    /////////////////////////////////////////////////////////////////
    ListNode * left = nullptr;
    bool isPalindrome2(struct ListNode* head) 
    {
        left = head;
        return reverse2(head->next);
    }
    bool reverse2(ListNode *right)
    {
        if (right == nullptr){return true;}
        bool result = reverse2(right->next);
        result = result && (left->val == right->val);
        left = left->next;
        return result;
    }
    /////////////////////////////////////////////////////////////////
    ListNode * new_head = nullptr;
    ListNode * new_reverse(ListNode *head)
    {
        ListNode * n_head = new ListNode(head->val);
        if (head->next == nullptr)
        {
            new_head = n_head;
            return n_head;
        }
        ListNode * newnext = new_reverse(head->next);
        n_head->next = nullptr;
        newnext-> next = n_head;
        return n_head;
    }
    ListNode * reverse(ListNode *head)
    {
        if (head->next == nullptr)
        {
            new_head = head;
            return head;
        }
        ListNode * newnext = reverse(head->next);
        head->next = nullptr;
        newnext-> next = head;
        return head;
    }
    bool isPalindrome1(struct ListNode* head) 
    {
        //printList(head);
        //reverse(head);
        new_reverse(head);
        ListNode *newhead = new_head;
        //printList(new_head);
        for (;
                head != nullptr && new_head != nullptr;
                head = head->next , new_head = new_head->next
            )
        {
            if (head->val != new_head->val )
            {
                return false;
            }
        }
        return true;
    }
    /////////////////////////////////////////////////////////////////
    bool isPalindrome0(struct ListNode* head) 
    {
        if (NULL == head)
        {
            return true;
        }
        struct ListNode * p = head;
        struct ListNode * q = head;
        struct ListNode * r = head;
        int count = 0; //
        
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

    template <typename T>
    int printvector(const std::vector<T> &v)
    {
        std::cout << "vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            std::cout << *iter << "| ";//<<std::endl;
        }
        std::cout << std::endl;
        return v.size();
    }

    template <typename T>
    int printvectorvector(const std::vector<T> &v)
    {
        std::cout << "this vector size: " << v.size() << std::endl;
        for (auto iter = v.begin(); iter != v.end(); iter++ )
        {
            printvector( *iter );
        }
        std::cout << std::endl;
        return v.size();
    }
};

// ==================== TEST Codes====================
void Test(const std::string& testName, 
        struct ListNode * head,
        bool expected)
{
    if(testName.length() > 0)
        std::cout <<testName << " begins: "<< std::endl;

    Solution solution;

    auto start = std::chrono::system_clock::now();
    decltype(start) end ;
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    solution.printList(head);
    // getpermutataion
    {
        std::cout << "Solution0 start.........." << std::endl;
        start = std::chrono::system_clock::now();

        decltype(expected) result = solution.isPalindrome0(head);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
            std::cout << "Solution0 passed." << std::endl;
        else
            std::cout << "Solution0 failed." << std::endl;
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Solution0 costs " << elapsed.count() <<"micros" << std::endl;
    }
    {
        std::cout << "Solution1 start.........." << std::endl;
        start = std::chrono::system_clock::now();

        decltype(expected) result = solution.isPalindrome1(head);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
            std::cout << "Solution1 passed." << std::endl;
        else
            std::cout << "Solution1 failed." << std::endl;
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Solution1 costs " << elapsed.count() <<"micros" << std::endl;
    }
    {
        std::cout << "Solution2 start.........." << std::endl;
        start = std::chrono::system_clock::now();

        decltype(expected) result = solution.isPalindrome2(head);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
            std::cout << "Solution2 passed." << std::endl;
        else
            std::cout << "Solution2 failed." << std::endl;
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Solution2 costs " << elapsed.count() <<"micros" << std::endl;
    }
    {
        std::cout << "Solution3 start.........." << std::endl;
        start = std::chrono::system_clock::now();

        decltype(expected) result = solution.isPalindrome3(head);
        std::cout << "result:" << std::boolalpha << result << std::endl;

        if(result == expected)
            std::cout << "Solution3 passed." << std::endl;
        else
            std::cout << "Solution3 failed." << std::endl;
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Solution3 costs " << elapsed.count() <<"micros" << std::endl;
    }
}
void Test1()
{
    ListNode * p2 = new ListNode(2);
    ListNode * p1 = new ListNode(1, p2);
    Test("Test1", p1, false );
}

void Test2()
{
    ListNode * p4 = new ListNode(1);
    ListNode * p3 = new ListNode(2, p4);
    ListNode * p2 = new ListNode(2, p3);
    ListNode * p1 = new ListNode(1, p2);
    Test("Test2", p1, true  );
}

void Test3()
{
    ListNode * p5 = new ListNode(2);
    ListNode * p4 = new ListNode(3, p5);
    ListNode * p3 = new ListNode(4, p4);
    ListNode * p2 = new ListNode(3, p3);
    ListNode * p1 = new ListNode(2, p2);
    Test("Test3", p1, true  );
}

void Test4()
{
}

void Test5()
{
}

int main()
{
    Solution solution;

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;

}
