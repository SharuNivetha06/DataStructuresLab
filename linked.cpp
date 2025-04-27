//menu-driven program to implement list adt using a singly linked list
#include<iostream>
using namespace std;

//class declaration
class List{
    public:
    typedef struct node{
        int data;
        node* next;
    }node;
    node* head;
    
    List(){
        head=NULL;
    }

    public:
    int insertb(int);
    int inserte(int);
    int insertp(int,int);
    int deleteb();
    int deletee();
    int deletep(int);
    int search(int);
    void display();
    void displayr();
    int reverselink();
    
};

//main function
int main(){
    int val;
    int pos;
    int choice;
    int target;
    int check;
    List l1;
    do{
        cout<<"\n\nThe menu is as follows\n1.Insert Beginning\n2.Insert End\n3.Insert Position\n4.Delete Beginning\n5.Delete End\n6.Delete Position\n7.Search\n8.Display\n9.Display Reverse\n10.Reverse Link\n11.exit\n";
        cout<<"Enter your choice : \n";
        cin>>choice;

        switch(choice){
            case 1:
            {
                cout<<"\nInsertion in the beginning\n";
                cout<<"Enter the value to be inserted :\n";
                cin>>val;
                check=l1.insertb(val);
                if(check==1)
                l1.display();
                break;

            }
            case 2:
            {
                cout<<"\nInsertion in the End\n";
                cout<<"Enter the value to be inserted :\n";
                cin>>val;
                check=l1.inserte(val);
                if(check==1)
                l1.display();
                break;
            }
            case 3:
            {
                cout<<"\nInsertion in a particular position\n";
                cout<<"Enter the value to be inserted and the position to be inserted in :\n";
                cin>>val;
                cin>>pos;
                check=l1.insertp(val,pos);
                if(check==1)
                l1.display();
                break;
            }
            case 4:
            {
                cout<<"\nDeletion in the beginning\n";
                check=l1.deleteb();
                if(check!=0)
                cout<<"The deleted element is "<<check;
                break;
            }
            case 5:
            {
                cout<<"\nDeletion in the end\n";
                check=l1.deletee();
                if(check!=0)
                cout<<"The deleted element is "<<check;
                break;
            }
            case 6:
            {
                cout<<"\nDeletion in a particular position\n";
                cout<<"Enter the position to be deleted\n";
                cin>>pos;
                check=l1.deletep(pos);
                if(check!=0)
                cout<<"The deleted element is "<<check;
                break;
            }
            case 7:
            {
                cout<<"\nSearching the linked list\n";
                cout<<"Enter the element to be searched\n";
                cin>>target;
                check=l1.search(target);
                if(check==-1)
                cout<<"Search element not found\n";
                else if(check!=0 && check!=0)
                cout<<"Search element found in position "<<check;
                break;
            }
            case 8:
            {
                cout<<"\nDisplaying the linked list\n";
                l1.display();
                break;
            }
            case 9:
            {
                cout<<"\nDisplaying the reverse of the linked list\n";
                l1.displayr();
                break;
            }
            case 10:
            {
                cout<<"\nReversing the linked list\n";
                check=l1.reverselink();
                if(check==1)
                l1.display();
                break;
            }
            case 11:
            {
                cout<<"\nProgram has been terminated\n";
                exit(0);
                break;
            }
            default:
            {
                cout<<"\nInvalid choice has been entered\n";
                break;
            }
        }
    }while(choice!=11);
}

//function to insert in the beginning of the list
int List::insertb(int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;
    return 1;
}

//function to insert in the end of the list
int List::inserte(int val){
    if(head==NULL){
        insertb(val);
        return 1;
    }
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return 1;
}

//function to insert in a particular position in the list
int List::insertp(int val,int pos){
    if(pos==1){
        insertb(val);
        return 1;
    }
    else if(pos<0){
        cout<<"Invalid position entered\n";
        return 0;
    }
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=val;
        newnode->next=NULL;
        int count=1;
        node* temp=head;
        while(count<pos-1){
            temp=temp->next;
            count++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        return 1;
    
}

//function to delete the first element of the list
int List::deleteb(){
    if(head==NULL){
        cout<<"The list is empyt\n";
        return 0;
    }
    node* del=(node*)malloc(sizeof(node));
    del=head;
    int a=del->data;
    head=del->next;
    free(del);
    return a;
}

//function to delete the last item of the list
int List::deletee(){
    if(head==NULL){
        cout<<"The list is empty\n";
        return 0;
    }
    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    int a=temp->next->data;
    temp->next=NULL;
    return a;
}

//function to delete the element in a particular position of the list
int List::deletep(int pos){
    if(head==NULL){
        cout<<"The list is empty\n";
        return 0;
    }
    if(pos<0){
        cout<<"Invalid position entered\n";
        return 0;
    }
    int count=1;
    node* temp=head;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    int a=temp->next->data;
    temp->next=temp->next->next;
    return a;
}

//function to search a element in the list
int List::search(int target){
    if(head==NULL){
        cout<<"The list is empty already\n";
        return 0;
    }
    node* temp=head;
    int count=1;
    while(temp->data!=target){
        temp=temp->next;
        count++;
    }
    if(temp->data==target){
        return count;
    }
    else
    return -1;
}

//function to display the reverse of the linked list 
void List::displayr(){
    node* temp=head;
    int arr[100];
    int count=0;
    while(temp->next!=NULL){
        arr[count]=temp->data;
        temp=temp->next;
        count++;
    }
    arr[count]=temp->data;
    for(int i=count;i>=0;i--){
        cout<<" "<<arr[i];
    }


}

//function to reverse the link of the singly linked list
int List::reverselink(){
    if(head==NULL){
        cout<<"The list is empty already ";
        return 0;
    }
    node* prev=NULL;
    node* current=head;
    node* next=NULL;
    while(current->next!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
    head=prev;
    return 1;

}


//function to display the linked list 
void List::display(){
    node* temp=head;
    while(temp->next!=NULL){
        cout<<" "<<temp->data;
        temp=temp->next;
    }
    cout<<" "<<temp->data;
}