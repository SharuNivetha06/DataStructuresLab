//C++ menu-driven program to implement List ADT using doubly linked list.
#include<iostream>
using namespace std;

//Declaration of class
class List{
    public: 
    typedef struct node{
        node* prev;
        int data;
        node* next;
    }node;

    node* head;
    node* tail;

    public:
    List(){
        head=NULL;
        tail=NULL;
    }
     
    int insertbeginning(int);
    int insertend(int);
    int insertposition(int,int);
    int deletebeginning();
    int deleteend();
    int deleteposition(int);
    int search(int);
    void display(); 
};

// Main function 
int main(){
    int choice;
    int val;
    int check;
    int pos;
    int target;
    List l1;
    do{
        cout<<"\n\nMenu : \n1.Insert in the beginning\n2.Insert in the end\n3.Insert in a particular position\n4.Deletion in the beginning\n5.Deletion in the end\n6.Deletion in a particular position\n7.Search an element\n8.Display\n9.Exit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"\n\nInsertion in the beginning :";
                cout<<"\nEnter the value to be inserted : ";
                cin>>val;
                check=l1.insertbeginning(val);
                if(check==1)
                l1.display();
                break;
            }
            case 2:{
                cout<<"\n\nInsertion in the end :";
                cout<<"\nEnter the value to be inserted : ";
                cin>>val;
                check=l1.insertend(val);
                if(check==1)
                l1.display();
                break;
            }
            case 3:{
                cout<<"\n\nInsertion in a particular position : ";
                cout<<"\nEnter the value and the position to insert : ";
                cin>>val;
                cin>>pos;
                check=l1.insertposition(val,pos);
                if(check==1)
                l1.display();
                break;
            }
            case 4:{
                cout<<"\n\nDeletion in the beginning : ";
                check=l1.deletebeginning();
                if(check!=0)
                cout<<"The deleted element is "<<check;
                break;
            }
            case 5:{
                cout<<"\n\nDeletion in the end : ";
                check=l1.deleteend();
                if(check!=0)
                cout<<"The deleted element is "<<check;
                break;
            }
            case 6:{
                cout<<"\n\nDeletion in a particular position : ";
                cout<<"\nEnter the position that has to be deleted : ";
                cin>>pos;
                check=l1.deleteposition(pos);
                if(check!=0)
                cout<<"The deleted element is "<<check;
                break;
            }
            case 7:{
                cout<<"\n\nSearching an element in the list : ";
                cout<<"\nEnter the search element : ";
                cin>>target;
                check=l1.search(target);
                if(check==-1)
                cout<<"\nElement not found!!";
                else if(check!=-1)
                cout<<"\nElement found in "<<check<<" position ";
                break;
            }
            case 8:{
                cout<<"\n\nDisplaying the doubly linked list : \n";
                l1.display();
                break;
            }
            case 9:{
                cout<<"\n\nProgram terminated !!";
                exit(0);
            }
            default:{
                cout<<"\n\nInvalid choice entered!!";
                break;
            }

        }
    }while(choice!=9);
}

//Function for inserting an element in the start of the doubly linked list.
int List::insertbeginning(int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=head;
    if(head==NULL){
        head=tail=newnode;
        return 1;
    }
    head->prev=newnode;
    head=newnode;
    return 1;
}

//Function for inserting an element in the end of the doubly linked list.
int List::insertend(int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
        insertbeginning(val);
        return 1;
    }
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    return 1;
}

//Function for inserting an element in a particular position.
int List::insertposition(int val,int pos){
    if(head==NULL || pos==1){
        insertbeginning(val);
        return 1;
    }
    if(pos<0){
        cout<<"Invalid position entered!!\n";
    }
    node* temp=head;
    int count=1;
    while(count<pos-1 && temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertend(val);
        return 1;
    }
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=temp->next;
    temp->next->prev=newnode;
    newnode->prev=temp;
    temp->next=newnode;

     return 1;
}

//Function to delete the first element of the doubly linked list.
int List::deletebeginning(){
    if(head==NULL){
        cout<<"The list is empty already!!";
        return 0;
    }
    node* del=head;
    int a = del->data;
    del->next->prev=NULL;
    head=del->next;
    free(del);
    return a;
}

//Function to delete the last element of the doubly linked list.
int List::deleteend(){
    if(head==NULL){
        cout<<"The list is empty already!!";
        return 0;
    }
    node* del=tail;
    int a =del->data;
    del->prev->next=NULL;
    tail=del->prev;
    free(del);
    return a;
}

//Function to delete an element in a particular position.
int List::deleteposition(int pos){
    if(head==NULL){
        cout<<"The list is empty already!!";
        return 0;
    }
    if(pos<0){
        cout<<"Invalid position entered!!";
        return 0;
    }
    if(pos==1){
        int a=deletebeginning();
        return a;
        
    }
    int count=1;
    node* temp=head;
    while(count<pos-1 && temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        int a=deleteend();
        return a;
    }
    else{
    node* del=temp->next;
    int a=del->data;
    temp->next = del->next;
    if (del->next != NULL) {
        del->next->prev = temp;
    }
    free(del);
    return a;
    }
}

//Function to search an element in the doubly linked list
int List::search(int target) {
    if (head == NULL) {
        cout << "The list is empty!" << endl;
        return -1;
    }

    node* temp = head;
    int position = 1;  // Start counting from position 1

    while (temp != NULL) {
        if (temp->data == target) {
            return position;  // Return position if element is found
        }
        temp = temp->next;
        position++;
    }

    return -1;  // Return -1 if element is not found
}

//Function to display the doubly linked list
void List::display(){
    if(head==NULL){
        cout<<"The list is empyt!!";
    }
    node* temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" , ";
        temp=temp->next;
    }
    cout<<temp->data;
    
    cout<<"\n\nDisplaying the reverse of the doubly linked list :\n";
    temp=tail;
    while(temp->prev!=NULL){
        cout<<temp->data<<" , ";
        temp=temp->prev;
    }
    cout<<temp->data;
}
