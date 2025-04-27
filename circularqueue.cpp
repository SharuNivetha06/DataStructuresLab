//c++ menu-friven program to implement circular queue ADT using an array of size 5
#include<iostream>
#define MAX_SIZE 5
using namespace std;

class Queue{
    public:
    int arr[MAX_SIZE]={};
    int front,rear;

    Queue(){
        front=-1;
        rear=-1;
    }

    bool isFull();
    bool isEmpty();
    int enqueue(int);
    int dequeue();
    int peek();
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

//Function to check if a queue is Full.
bool Queue::isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1));
}

// Function to check if the queue is empty
bool Queue::isEmpty() {
    return front == -1;
}

// Function to add an element to the queue
int Queue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue \n";
        return 0;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    arr[rear] = value;
    return 1;
}

// Function to remove an element from the queue
int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return 0;
    }
    int value = arr[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
    return value;
}

// Function to get the front element of the queue 
int Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty. No element to peek.\n";
        return 0;
    }
    int value=arr[front];
    return value;
}

