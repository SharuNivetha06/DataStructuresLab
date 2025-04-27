//c++ menu-driven program to implement queue ADT using singly linked list.
#include<iostream>
using namespace std;

class Queue{
    public:
    typedef struct node{
        int data;
        node* next;
    }node;

    node* front;
    node* rear;

    Queue(){
        front=NULL;
        rear=NULL;
    }

    int enqueue(int);
    int dequeue();
    int peek();
    void display();
};

//Main function
int main(){
    Queue q;
    int ch,a,check;
    do{
        cout<<"\nMenu :\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:
            cout<<"\nEnqueue\n";
            cout<<"Enter the number to be enqued :  ";
            cin>>a;
            check=q.enqueue(a);
            if(check==1){
            cout<<"\nEnqueued succesfully\n";
            q.display();
            }
            break;

            case 2:
            cout<<"\nDequeue\n";
            check=q.dequeue();
            if(check!=-1)
            cout<<"\nDequeued element is "<<check;
            break;

            case 3:
            cout<<"\nPeek\n";
            check=q.peek();
            if(check!=-1)
            cout<<"Element at front is "<<check;
            break;

            case 4:
            cout<<"\nTerminating the program...\n";
            exit(0);

            default:
            cout<<"\nInvalid choice entered\n";
            break;
        }
}while(ch!=4);

}

//Function to enqueue an element into the queue.
int Queue::enqueue(int a){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=a;
    if(front==NULL){
        newnode->next=NULL;
        front=newnode;
        rear=newnode;
        return 1;
    }
    newnode->next=NULL;
    rear->next=newnode;
    rear=newnode;
    return 1;
}

//Function to dequeue an element from the queue.
int Queue::dequeue(){
    if(front==NULL){
        cout<<"Queue is empty!!\n";
        return -1;
    }
    if(front->data==rear->data){
        int a=front->data;
        front=NULL;
        rear=NULL;
        return a;
    }
    int a=front->data;
    node* temp=front;
    front=front->next;
    free(temp);
    return a;
}

//Function to peek at the front element of the queue.
int Queue::peek(){
    if(front==NULL){
        cout<<"Queue is empty!!\n";
        return -1;
    }
    int a=front->data;
    return a;
}

//Function to display the queue.
void Queue::display(){
    node* temp=front;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
}
