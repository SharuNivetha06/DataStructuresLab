//C++ menu-driven program to implement Stack ADT using a character array of size 5.
#include<iostream>
using namespace std;
#define SIZE 5

class Stack{
    public:
    char arr[SIZE]={};
    int top;

    Stack(){
        top=-1;
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
                cout<<"Pushing a character into the array :\n";
                cout<<"Enter the character to be pushed : ";
                cin>>c;
                check=s.push(c);
                if(check==1)
                s.display();
                break;
            }
            case 2:{
                cout<<"Popping a character from an array :\n";
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
                cout<<"\nProgram has been terminated....";
                exit(0);
            }
            default:{
                cout<<"\nInvalid choice has been entered ";
                break;
            }
        }
    }while(choice!=4);
}

//Function to push a character into the array.
int Stack::push(char c){
    if(top>=SIZE-1){
        cout<<"Stack overflow!!";
        return 0;
    }
    ++top;
    arr[top]=c;
    return 1;
}

//Function to pop the character in the array.
char Stack::pop(){
    if(top<0){
        cout<<"Stack underflow!!";
        return 0;
    }
    char a=arr[top];
    --top;
    return a;
}

//Function to peek the last entered charcter of the array.
char Stack::peek(){
    if(top<0){
        cout<<"Stack underflow!!";
        return 0;
    }
    char a=arr[top];
    return a;
}

//Function to display the array.
void Stack::display(){
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
}