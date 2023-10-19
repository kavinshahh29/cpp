#include<bits/stdc++.h>
using namespace std;

// I have reverse first and second then add . then add the remaining sum pointer and then reverse the pointer for ans 
 struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node*ptr1=NULL;
        Node*st1=first;
        Node*st2=second;
        while(st1!=nullptr)
        {
            Node*temp=st1->next;
            st1->next=ptr1;
            ptr1=st1;
            st1=temp;
        }
        Node*ptr2=NULL;
        while(st2!=nullptr)
        {
            Node*temp=st2->next;
            st2->next=ptr2;
            ptr2=st2;
            st2=temp;
            
        }
        int sum=0;
        
        Node*ans=nullptr;
        Node*strt=ans;
        while(ptr1!=nullptr and ptr2!=nullptr)
        {
            sum=ptr1->data+ptr2->data+sum;
            // Node*temp=new Node(sum);
            Node*temp=new Node(sum%10);
            sum=sum/10;
            // cout<<"HELLO@";
            if(ans==nullptr){
                // cout<<temp->data;
            ans=new Node(temp->data);
            strt=ans;
            // cout<<"hi";
            // cout<<ans->data;
            }
            else{
                // cout<<"HELLO";
                // cout<<temp->data;
            ans->next=temp;
            ans=ans->next;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        while(ptr1!=nullptr)
        {
            sum+=ptr1->data;
            ptr1=ptr1->next;
            Node*temp=new Node(sum%10);
            sum=sum/10;
            if(ans==nullptr){
                
            // cout<<temp->data;
            ans=temp;
        }
            else
            {
                ans->next=temp;
                ans=ans->next;
            }
            
        }
           while(ptr2!=nullptr)
        {
            sum+=ptr2->data;
            ptr2=ptr2->next;
            Node*temp=new Node(sum%10);
            sum=sum/10;
            if(ans==nullptr)
            ans=temp;
            else
            {
                ans->next=temp;
                ans=ans->next;
            }
        }
        if(sum!=0)
        {
            Node*temp=new Node(sum);
            ans->next=temp;
            ans=ans->next;
            
            
        }
        // Node*ansr=nullptr;
          Node*reans=nullptr;
          while(strt!=nullptr)
          {
              Node*temp=strt->next;
              strt->next=reans;
              reans=strt;
              strt=temp;
          }
          
          return reans;
          
        
    }