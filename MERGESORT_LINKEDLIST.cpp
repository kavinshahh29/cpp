#include<bits/stdc++.h>
using namespace std;

 Node* mergeSort(Node* head) {
     
        if(head==nullptr || head->next==nullptr)
        return head;
        
        Node*mid=findmid(head);
        Node*left=head;
        Node*right=mid->next;
        mid->next=nullptr; 
        left=mergeSort(left);
        right=mergeSort(right);
       
        
        return merge(left,right);
    }

    Node*merge(Node*left,Node*right)
    {
        if(left==nullptr)
        return right;
        if(right==nullptr)
        return left;
        Node*res=nullptr;
        if(left->data<=right->data)
        {
            res=left;
            res->next=merge(left->next,right);
            
        }
        else
        {
            res=right;
            res->next=merge(left,right->next);
        }
        return res;
    }

    Node*findmid(Node*head){
        if(head==nullptr || head->next==nullptr)
        return head;
        Node*fastptr=head->next;
        Node*slowptr=head;
        while(fastptr!=nullptr and fastptr->next!=nullptr)
        {
            fastptr=fastptr->next->next;
            slowptr=slowptr->next;
        }
        return slowptr;
    }