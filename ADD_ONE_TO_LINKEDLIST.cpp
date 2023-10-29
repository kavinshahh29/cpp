#include<bits/stdc++.h>
using namespace std;
    Node*reverse(Node*head)
    {
        Node*ptr=nullptr;
        while(head!=nullptr)
        {
            Node*temp=head->next;
            head->next=ptr;
            ptr=head;
            head=temp;
        }
        return ptr;
    }
    Node* addOne(Node *head) 
    {
      
        Node*ptr=nullptr;
        ptr=reverse(head);
        Node*ans=ptr;
        int sum=1;
        while(ptr!=nullptr)
        {
            sum=sum+ptr->data;
            int a=sum;
            sum=sum%10;
            ptr->data=sum;
            
            sum=a/10;
            if(ptr->next==nullptr and sum!=0)
            {
                Node*temp=new Node(sum);
                ptr->next=temp;
                return reverse(ans);
            }
            
            ptr=ptr->next;
        }
        
        return reverse(ans);
        
       
    }