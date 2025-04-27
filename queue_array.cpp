//C++ menu-driven program to implement queue ADT using an integer array of size 5.
#include<iostream>
#define SIZE 5
using namespace std;

class Queue{
    public:
    int arr[SIZE]={};
    int front,rear;

    Queue(){
        front=-1;
        rear=-1;
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

//Function to enqueue an element into a queue.
int Queue::enqueue(int a){
    if(rear==SIZE-1){
        cout<<"Queue is full already!!\n";
        return 0;
    }
    if(front==-1)
    front=0;
    rear++;
    arr[rear]=a;
    return 1;
}

//Function to dequeue an element from the queue.
int Queue::dequeue(){
    if(front==-1){
        cout<<"Queue is empty!!\n";
        return -1;
    }
    int a=arr[front];
    front++;
    if(front>rear){
        front=-1;
        rear=-1;
    }
    return a;
}

//Function to peek at the front element in the queue.
int Queue::peek(){
    if(front==-1){
        cout<<"Queue is empty!!\n";
        return -1;
    }
    int a=arr[front];
    return a;
}

//Function to display the queue.
void Queue::display(){
    for(int i=front;i<=rear;i++)
    cout<<arr[i]<<" ";
}