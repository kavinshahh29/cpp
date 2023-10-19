#include<bits/stdc++.h>
using namespace std;


Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node*ans=nullptr;
    Node*res;
    while(head1!=nullptr and head2!=nullptr)
    {
        if(head1->data<=head2->data)
        {
            Node*temp=new Node(head1->data);
            if(ans==nullptr){
                ans=new Node(head1->data);
                res=ans;
            }
            else
            {
                ans->next=temp;
                ans=ans->next;
                
            }
            head1=head1->next;
        }
        else
        {
            Node*temp=new Node(head2->data);
            if(ans==nullptr)
            {
                ans=new Node(head2->data);
                res=ans;
            }
            else
            {
                ans->next=temp;
                ans=ans->next;
            }
            head2=head2->next;
            
        }
        
    }
    while(head1!=nullptr)
    {
        Node*temp=new Node(head1->data);
            if(ans==nullptr){
                ans=new Node(head1->data);
                res=ans;
            }
            else
            {
                ans->next=temp;
                ans=ans->next;
                
            }
            head1=head1->next;
        
    }
    while(head2!=nullptr)
    {
        Node*temp=new Node(head2->data);
            if(ans==nullptr)
            {
                ans=new Node(head2->data);
                res=ans;
            }
            else
            {
                ans->next=temp;
                ans=ans->next;
            }
            head2=head2->next;
    }
    return res;
    // code here
} 