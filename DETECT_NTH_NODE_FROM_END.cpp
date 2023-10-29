#include<bits/stdc++.h>
using namespace std;
  int getNthFromLast(Node *head, int n)
    {
           
           Node*ptr=head;
            Node*start=head;
        
           while(n>0)
           {
               if(start==nullptr)
               return -1;
               start=start->next;
               n--;
           }
           while(start!=nullptr)
           {
               start=start->next;
               ptr=ptr->next;
           }
           if(ptr==nullptr)
           return -1;
           return ptr->data;
           
    }