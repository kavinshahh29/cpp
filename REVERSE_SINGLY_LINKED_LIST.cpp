#include<bits/stdc++.h>
using namespace std;
// REVERSE THE SINGLY LINKED LIST
struct Node* reverseList(struct Node *head)
    {
        // code here
        struct Node*start=head;
        Node*ptr=NULL;
        while(start!=nullptr)
        {
            Node*temp=start->next;
            start->next=ptr;
            ptr=start;
            start=temp;
        }
        return ptr;
        // return head of reversed list
    }
    // IN THIS QUESTION WE ARE JUST TRANSFORM ONE BY ONE POINTER TO PTR POINTER AND UPDATING THE PTR POINTER
     // JUST MOVING THE START POINTER USING TEMP