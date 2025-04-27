//C++ menu-diven program to implement Stack ADT using a character singly linked list.
#include<iostream>
using namespace std;

class Stack{
    public:
    typedef struct node{
        char data;
        node* next;
    }node;

    node* top;

    Stack(){
        top=NULL;
    }
    
    int push(char);
    char pop();
    char peek();
    void display();
};


//Main function
int main(){
    Stack s;
    int choice;
    char c;
    int check;
    do{
        cout<<"\n\nMenu :\n1.Push\n2.Pop\n3.Peek\n4.Exit\n\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Pushing a character into the linked list :\n";
                cout<<"Enter the character to be pushed : ";
                cin>>c;
                check=s.push(c);
                if(check==1)
                s.display();
                break;
            }
            case 2:{
                cout<<"Popping a character from the linked list :\n";
                c=s.pop();
                if(c!=0)
                cout<<"The popped character is "<<c;
                break;
            }
            case 3:{
                cout<<"Peeking at the last entered character :\n";
                c=s.peek();
                if(c!=0)
                cout<<"The last entered character is "<<c;
                break;
            }
            case 4:{
                cout<<"\nProgram has been terminated....\n";
                exit(0);
            }
            default:{
                cout<<"\nInvalid choice has been entered \n";
                break;
            }
        }
    }while(choice!=4);
}

//Function to push a character into the linked list
int Stack::push(char c){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=c;
    if(top==NULL){
        newnode->next=NULL;
        top=newnode;
        return 1;
    }
    newnode->next=top;
    top=newnode;
    return 1;
}

//Function to pop the last entered character
char Stack::pop(){
    if(top==NULL){
        cout<<"Stack underflow!!\n";
        return 0;
    }
    node* temp=top;
    char a=temp->data;
    top=temp->next;
    free(temp);
    return a;
}

//Function to peek at the last entered character
char Stack::peek(){
    if(top==NULL){
        cout<<"Stack underflow!!\n";
        return 0;
    }
    char a=top->data;
    return a;
}

//Function to display the linked list
void Stack::display(){
    node* temp=top;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
}