 Node* segregate(Node *head) {
        
        Node*ans0=new Node(-1);
        Node*temp=head;
        Node*res0=ans0;
        Node*ans1=new Node(-1);
        Node*res1=ans1;
        Node*ans2=new Node(-1);
        Node*res2=ans2;
        while(temp!=nullptr)
        {
            if(temp->data==0)
            {
                Node*temp=new Node(0);
                ans0->next=temp;
                ans0=ans0->next;
            }else if(temp->data==1)
            {
                Node*temp=new Node(1);
                ans1->next=temp;
                ans1=ans1->next;
            }
            else
            {
                Node*temp=new Node(2);
                ans2->next=temp;
                ans2=ans2->next;
            }
            temp=temp->next;
        }
        
        if(res0->next==nullptr and res1->next==nullptr)
        return res2->next;
        else if(res0->next==nullptr and res2->next==nullptr)
        return res1->next;
        else if(res1->next==nullptr and res2->next==nullptr)
        return res0->next;
        else if(res0->next==nullptr)
        {
            ans1->next=res2->next;
            return res1->next;
        }
        else if(res1->next==nullptr)
        {
            ans0->next=res2->next;
            return res0->next;
        }
        else if(res2->next==nullptr)
        {
            ans0->next=res1->next;
            return res0->next;
            
        }
        ans0->next=res1->next;
        ans1->next=res2->next;
        return res0->next;
       
        
    }