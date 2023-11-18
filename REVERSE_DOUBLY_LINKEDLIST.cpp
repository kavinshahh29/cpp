#include<bits/stdc++.h>
using namespace std;



    Node* reverseDLL(Node * head)
    {
        if(head==nullptr|| head->next==nullptr)
        return head;
        
        Node*ptr=head;
        Node*start=head;
        while(ptr!=nullptr)
        {
            Node*temp=ptr->next;
            ptr->next=ptr->prev;
            ptr->prev=temp;
            start=ptr;
            ptr=temp;
        }
        return start;
        
        
    }