#include<bits/stdc++.h>
using namespace std;
 
class Queue {
    int arr[1000000];
    int rear;
    int qfront;
public:
    Queue() {
        // Implement the Constructor
        qfront=-1;
        rear=-1;
    }
    bool isEmpty() {
        if(rear<qfront || qfront==-1) 
        return true;
        return false;
        
        // Implement the isEmpty() function
    }

    void enqueue(int data) {
        if(rear>1000000)
        return;
        rear=rear+1;
        arr[rear]=data;
        if(qfront==-1)
        qfront=qfront+1;
        // Implement the enqueue() function
    }

    int dequeue() {
        if(qfront==-1 || qfront>rear)
        return -1;
        int x=arr[qfront];
        // if(qfront<=rear)
       
        qfront+=1;
      
        return x;
        // Implement the dequeue() function
    }

    int front() {
        if(qfront>rear || qfront==-1)
        return -1;
        return arr[qfront];
        // Implement the front() function
    }
};




// APPROACH -2 





class Queue{
    int size;
    int *arr;
    int qfront;
    int rear;
    

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear) {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data) {
        if(rear == size)
            cout << "Queue is Full" << endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear) {
            return -1;
        }
        else
        {	int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront==rear){
                qfront = 0;
                rear = 0;
            }
         return ans;
        }
    }

    int front() {
        if(qfront == rear) {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};