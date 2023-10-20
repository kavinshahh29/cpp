#include<bits/stdc++.h>
using namespace std;
struct node *reverse (struct node *head, int k)
    { 
        if(head==nullptr)
        return NULL;
        
        int count=0;
        struct node*ptr=head;
        struct node*ans=nullptr;
        while(ptr!=nullptr and count<k)
        {
            struct node*temp=ptr->next;
            ptr->next=ans;
            ans=ptr;
            ptr=temp;
            count++;
        }
        if(ptr!=nullptr)
        {
            head->next=reverse(ptr,k);
        }
        return ans;
        // Complete this method
    }