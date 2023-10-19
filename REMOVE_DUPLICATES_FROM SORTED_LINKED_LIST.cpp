#include<bits/stdc++.h>
using namespace std;
Node *removeDuplicates(Node *head)
{
 // your code goes here
 if(head==nullptr || head->next==nullptr)
 return head;
 Node*start=head;
 Node*ptr=head->next;
 while(ptr!=nullptr)
 {
     if(start->data==ptr->data)
     {
         start->next=ptr->next;
     }
     else
     {
         start=start->next;
         
     }
     ptr=ptr->next;
 }
 return head;
 
 
}