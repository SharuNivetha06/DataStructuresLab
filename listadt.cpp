//menu-driven program to implement list adt using an array of size 5
#include<iostream>
using namespace std;
#define MAX 5

//class definition
class List{
    public:
    int arr[MAX];
    int val,pos,search,k,size;

    List(){
        size=0;
    }


    public:
    int insertb(int val);
    int inserte(int val);
    int insertp(int val,int pos);
    int deleteb();
    int deletee();
    int deletep(int pos);
    int find(int search);
    int display();
    int rotate(int k);

};


//main function
int main(){
    int arr[MAX];
    int size;
    int choice;
    int val;
    int pos;
    int search;
    int k;
    int st;

    //class object declaration
    List s;

    do{
        cout<<"\n\nThe menu is as follows\n1.Insert Beginning\n2.Insert End\n3.Insert Position\n4.Delete Beginning\n5.Delete End\n6.Delete position\n7.Search\n8.Display\n9.Rotate\n10.Exit";
        cout<<"\n\nEnter your choice\n";
        cin>>choice;

        switch(choice){
            case 1:{
                cout<<"\nInsert in the beginning\n";
                cout<<"Enter the value to insert\n";
                cin>>val;
                st=s.insertb(val);
                if(st==1)
                s.display();

                break;
            }
            case 2:{
                cout<<"\nInsert in the end\n";
                cout<<"Enter the value to be entered\n";
                cin>>val;
                st=s.inserte(val);
                if(st==1)
                s.display();

                break;
            }
            case 3:{
                cout<<"\nInsert at a particular position\n";
                cout<<"Enter the value to be inserted and the position to insert it in\n";
                cin>>val;
                cin>>pos;
                st=s.insertp(val,pos);
                if(st==1)
                s.display();
                break;
            }
            case 4:{
                cout<<"\nDelete in the beginning\n";
                st=s.deleteb();
                if(st!=0)
                cout<<"The deleted element is "<<st;
                break;
            }
            case 5:{
                cout<<"\nDelete in the end\n";
                st=s.deletee();
                if(st!=0)
                cout<<"The deleted element is "<<st;
                break;
            }
            case 6:{
                cout<<"\nDelete a particular position\n";
                cout<<"Enter the position\n";
                cin>>pos;
                st=s.deletep(pos);
                if(st!=0)
                cout<<"The deleted element is "<<st;
                break;
            }
            case 7:{
                cout<<"\nSearch\n";
                cout<<"Enter the value to search\n";
                cin>>search;
                st=s.find(search);
                if(st==-1)
                cout<<"Search element not found\n";
                else
                cout<<"Search element found in "<<st<<" position";
            
                break;
            }
            case 8:{
                cout<<"\nDisplay the array\n";
                s.display();
                break;
            }
            case 9:{
                cout<<"\nRotating the array\n";
                cout<<"Enter the number of times the array has to be rotated\n";
                cin>>k;
                st=s.rotate(k);
                if(st==1){
                    s.display();
                }
                break;
            }
            case 10:{
                cout<<"\nProgram terminated\n";
                exit(0);
            }
            default:{
                cout<<"\nInvalid choice entered\n";
            }
        }

    }while(choice!=10);
    if(choice==10){
        cout<<"\nProgram terminated\n";
        exit(0);
    }
}

//function to insert a new element in the beginning 
int List::insertb(int val){
    if(size==MAX){
        cout<<"The array is full already\n";
        return 0;
    }
    else{
        for(int i=size;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=val;
        size++;
        cout<<"Insertion successful\n";
        return 1;
    }

}

//function to insert a element in the end 
int List::inserte(int val){
    if(size==MAX){
        cout<<"The array is full already\n";
        return 0;
    }
    else{
        arr[size++]=val;
        cout<<"Insertion succesful\n";
        return 1;
    }
}

//fuction to insert a element in the position defined by the user
int List::insertp(int val,int pos){
    if(size==MAX){
        cout<<"The array is full already\n";
        return 0;
    }
    else if(pos<0 || pos>MAX){
        cout<<"Invalid position entered\n";

    }
    else{
        for(int i=size;i>=pos;i--){
            arr[i]=arr[i-1];
        }
        arr[pos-1]=val;
        size++;
        cout<<"Insertion succesful\n";
        return 1;
    }
}

//functio to delete the element in the beginning
int List::deleteb(){
    if(size==0){
        cout<<"The array is empty already\n";
        return 0;
    }
    else{
        int a=arr[0];
        for(int i=0;i<size;i++){
            arr[i]=arr[i+1];
        }
        size--;
        cout<<"Deletion succesful\n";
        return a;
    }
}

//function to delete the element in the end
int List::deletee(){
    if(size==0){
        cout<<"The array is empty already\n";
        return 0;
    }
    else{
        int a=arr[size-1];
        for(int i=0;i<size;i++){
            arr[i]=arr[i+1];
        }
        size--;
        cout<<"Deletion succesful\n";
        return a;
    }
}

//function to delete the element in the position defined by the user
int List::deletep(int pos){
    if(size==0){
        cout<<"The array is empty already\n";
        return 0;
    }
    else if(pos<0 || pos>MAX){
        cout<<"Invalid Position entered\n";
        return 0;
    }
    else{
        int a=arr[pos-1];
        for(int i=0;i<pos;i++){
            arr[i]=arr[i+1];
        }
        size--;
        cout<<"Deletion succesful\n";
        return a;
    }
}

//fucntion to search an element in the array
int List::find(int search){
    for(int i=0;i<size;i++){
        if(arr[i]==search)
        return i+1;
     }
     return -1;
     
}

//function to display the array
int List::display(){
    for(int i=0;i<size;i++){
        cout<<"\t"<<arr[i];
    }
    return 0;
}

//function to rotate the array elements
int List::rotate(int k){
    if(size==0){
        cout<<"The array is empty already, so it cannot be rotated\n";
        return 0;
    }
    else{
    for(int i=0;i<k;i++){
        int temp=arr[size-1];
        for(int i=size;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=temp;
    }
    cout<<"The new rotated array is:\n";
    return 1;
}
}
    
