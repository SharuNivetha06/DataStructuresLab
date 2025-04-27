//C++ menu-driven program to implement Tree ADT using a character binary tree.
#include<iostream>
using namespace std;

class Tree{
    public:

    typedef struct node{
        char data;
        node* left;
        node* right;
    }node;

    node* root;

    Tree(){
        root=NULL;
    }

    int insert(char);
    void preorder(node*);
    void displaypreorder();
    void inorder(node*);
    void displayinorder();
    void postorder(node*);
    void displaypostorder();
    bool search(node*,char);
    void displaysearch(char);

};

//Main function 
int main(){
    Tree t;
    int ch,check;
    char a;
    do{
        cout<<"\nMenu:\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:
            cout<<"\nInserting into the binary tree :\n";
            cout<<"Enter the character to be inserted : ";
            cin>>a;
            check=t.insert(a);
            if(check==1)
            cout<<a<<" has been inserted succesfully!! \n";
            break;

            case 2:
            cout<<"\nPreorder traversal :\n";
            t.displaypreorder();
            break;

            case 3:
            cout<<"\nInorder traversal :\n";
            t.displayinorder();
            break;

            case 4:
            cout<<"\nPostorder traversal :\n";
            t.displaypostorder();
            break;

            case 5:
            cout<<"\nSearching an element :\n";
            cout<<"Enter the character to be searched : ";
            cin>>a;
            t.displaysearch(a);
            break;
                                         
            case 6:
            cout<<"\nTerminating program....\n";
            exit(0);

            deafult:
            cout<<"\nInvalid choice entered\n";
            break;
        }
    }while(ch!=6);
}

//Function to insert a character into a binary tree
int Tree::insert(char a){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=a;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL){
        root=newnode;
        return 1;
    }
    while(true){
    char ch;
    cout<<"Enter 'L' for left and 'R' for right : ";
    cin>>ch;
    node* temp=root;
    if(ch=='L'){
        if(temp->left==NULL){
            temp->left=newnode;
            return 1;
        }
        else{
            temp=temp->left;
        }
    }
    else if(ch=='R'){
        if(temp->right==NULL){
            temp->right=newnode;
            return 1;
        }
        else{
            temp=temp->right;
        }
    }
    else{
        cout<<"Invalid choice!!\n";
    }
}
}

//Function for preorder traversal.
void Tree::preorder(node* root){
    node* temp=root;
    if(temp==NULL){
        return;
    }
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
}

//Function to display the preorder traversal.
void Tree::displaypreorder(){
    if(root==NULL){
        cout<<"The tree is empty!!\n";
        return;
    }
    preorder(root);
    return;
}

//Function for inorder traversal.
void Tree::inorder(node* root){
    node* temp=root;
    if(temp==NULL){
        return;
    }
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}

//Function to display the inorder traversal.
void Tree::displayinorder(){
    if(root==NULL){
        cout<<"The tree is empty!!\n";
        return;
    }
    inorder(root);
    return;
}

//Function for postorder traversal.
void Tree::postorder(node* root){
    node* temp=root;
    if(temp==NULL){
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data<<" ";
}

//Function to display the postorder traversal.
void Tree::displaypostorder(){
    if(root==NULL){
        cout<<"The tree is empty!!\n";
        return;
    }
    postorder(root);
    return;
}

//Function to search the target character
bool Tree::search(node* root,char key)
{
    if (!root) return false;
    if (root->data == key)return true;
    return search(root->left, key) || search(root->right, key);
}

//Functio to display of the search character was found or not 
void Tree::displaysearch(char key){
    if(search(root,key))
    cout<<"Character found!!\n";
    else
    cout<<"Character not found\n";
}