/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*ptr1=headA;
        ListNode*ptr2=headB;
        int l1=0;
        while(ptr1!=nullptr)
        {
            ptr1=ptr1->next;
            l1++;

        }
        int l2=0;
        while(ptr2!=nullptr)
        {
            ptr2=ptr2->next;
            l2++;
        }
        if(l1>l2)
        {
            while(l1!=l2)
            {
                headA=headA->next;
                l1--;
            }
            


        }
        else
        {
            while(l2!=l1)
            {
                headB=headB->next;
                l2--;
            }

        }
        while(headA!=nullptr and headB!=nullptr)
        {
            if(headA==headB)
            return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;

    }

};