#include<bits/stdc++.h>
using namespace std;
Node* findIntersection(Node* head1, Node* head2)
    {
        map<int,bool>mp;
        while(head2!=nullptr)
        {
            mp[head2->data]=true;
            head2=head2->next;
        }
        Node*ans=new Node(-1);
        Node*start=ans;
        while(head1!=nullptr)
        {
            Node*temp=new Node(head1->data);
            if(mp[head1->data]==true)
            {
                ans->next=temp;
                ans=temp;
                
            }
            else
            mp[head1->data]=true;
        
            head1=head1->next;
            
        }
        return start->next;
      
    }