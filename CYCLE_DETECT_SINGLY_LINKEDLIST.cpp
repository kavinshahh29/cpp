#include<bits/stdc++.h>
using namespace std;



/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
   // Your code here
   Node*fastptr=head;
   Node*slowptr=head;
   while(fastptr!=nullptr and fastptr->next!=nullptr){
       fastptr=fastptr->next->next;
       slowptr=slowptr->next;
       if(fastptr==slowptr)
       return 1;
   }
   return 0;
   
   
}
