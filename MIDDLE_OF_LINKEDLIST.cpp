#include<bits/stdc++.h>
using namespace std;

int getMiddle(Node *head)
    {
        // Your code here
        Node*fastptr=head;
        Node*slowptr=head;
        while(fastptr!=nullptr and fastptr->next!=nullptr)
        {
            fastptr=fastptr->next->next;
            slowptr=slowptr->next;
        }
        return slowptr->data;
    }

    // fast pointer reaches end of list then at that time slow pointer will be at the middle of the linked list.