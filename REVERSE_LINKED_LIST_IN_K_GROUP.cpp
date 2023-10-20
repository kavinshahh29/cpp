#include<bits/stdc++.h>
using namespace std;


 struct node*reverse(node*start,node*ptr){
        node*res=nullptr;
        while(start!=ptr)
        {
            struct node*temp=start->next;
            start->next=res;
            res=start;
            start=temp;
            
        }
        return res;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        struct node*ptr=head;
        struct node*res=new struct node(-1);
        struct node*ans=res;
        while(ptr!=nullptr)
        {
            node*start=ptr;
            int t=k;
            while(t>0)
            {
                if(ptr==nullptr)
                break;
                ptr=ptr->next;
                t--;
                
            }
            res->next=reverse(start,ptr);
            while(res->next!=nullptr)
            {
                res=res->next;
            }
            
            
        }
        return ans->next;
        
    }