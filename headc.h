//Header file round robin system execution
#include <iostream>
using namespace std;

class List{ //Design of the list
private:
    typedef struct node{
        int data;
        node* next;
    }node;
    node* head;

public:
    List(){
        head=NULL;
    }

    void insertprocess(int);
    void executeprocess(int);
    void display();
};

//Function definitions
void List::insertprocess(int value){ //To insert the time of a new process
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    if(head==NULL){
        newnode->next=newnode;// Points to itself if it's the only node
        head=newnode;
    }
    else{
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newnode->next=head;  
        temp->next=newnode; 
    }
    return;
}

void List::executeprocess(int fixedtime){ //To execute a process once
  if(head==NULL){
    cout<<"There are no processes to execute";
    return;
  }
  if(head->data<fixedtime){ //Process gets removed from list after execution whenever the remaining time is lesser than fixed time
    if(head->next==head){
      head=NULL;
      cout<<"Process execution is over";
      return;
    }
    node* temp=head;
    while(temp->next!=head){
      temp=temp->next;
    }
    temp->next=head->next;
    head=head->next;
    cout<<"Process execution is over";
    return;
  }
  head->data-=fixedtime;
  head=head->next;
  cout<<"Execution is not over";
  return;
}

void List::display(){ //To display the list
  if(head==NULL){
    cout<<"No processes pending";
    return;
  }
  node* temp=head->next;
  cout<<head->data<<" ";
  while(temp!=head){
      cout<<temp->data<<" ";
      temp=temp->next;
  }
}