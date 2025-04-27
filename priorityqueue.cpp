//C++ menu-driven program to implement priority queue ADT using a max heap
#include<iostream>

using namespace std;

class Priority{
    public:
    int* arr;
    int current;
    int capacity;

    Priority(int capacity){
        this->capacity=capacity;
        current = 0;
        arr=new int[capacity];
    }

    //Helper functions
    void swap(int &a,int &b);
    void heapifyup(int);
    void heapifydown(int);

    int insertvalue(int);
    int deletevalue();
    void display();
    int search(int);
    void heapsort();
};

//Main function
int main(){
    int ch,a,capacity,check;
    cout<<"Enter the capacity of the priority queue : ";
    cin>>capacity;
    Priority p(capacity);
    do{
        cout<<"\nMenu :\n1. Insert\n2.Delete\n3.Display\n4.Search\n5.Heap sort\n6.Exit\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:
            cout<<"1.Insert\n";
            cout<<"Enter the value to be inserted : ";
            cin>>a;
            check=p.insertvalue(a);
            if(check!=0)
            cout<<a<<" inserted succesfully !!\n";
            break;

            case 2:
            cout<<"2.Delete\n";
            check=p.deletevalue();
            if(check!=-1)
            cout<<"Deleted element is "<<check<<"\n";
            break;

            case 3:
            cout<<"3.Display\n";
            p.display();
            break;

            case 4:
            cout<<"4.Search\n";
            cout<<"Enter the value to be searched : ";
            cin>>a;
            check=p.search(a);
            if(check!=-1){
                cout<<"Target element found!!\n";
            }
            else{
                cout<<"Target element not found...\n";
            }
            break;

            case 5:
            cout<<"5.Heap Sort\n";
            p.heapsort();
            break;

            case 6:
            cout<<"\nTerminating the program...\n";
            exit(0);

            default:
            cout<<"\nInvalid case entered!!";
            break;
        }
    }while(ch!=6);
}

//Helper function to swap two values.
void Priority::swap(int &a,int &b){
    int temp=b;
    b=a;
    a=temp;
}

//Helper function to maintain heap property during insertion.
void Priority::heapifyup(int idx){
    int parent=(idx-1)/2;
    while(idx>0 && arr[idx]>arr[parent]){
        swap(arr[idx],arr[parent]);
        idx=parent;
        parent=(idx-1)/2;
    }
}

//Helper function to maintain heap property during deletion.
void Priority::heapifydown(int idx) {
    int left, right, largest;
    while (true) {
        left = 2 * idx + 1;
        right = 2 * idx + 2;
        largest = idx;

        if (left < current && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < current && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest == idx) {
            break;
        }

        swap(arr[idx], arr[largest]);
        idx = largest;
    }
}


//Function to insert an element into a priority queue.
int Priority::insertvalue(int a){
    if(current==capacity){
        cout<<"Queue is full already!!\n";
        return 0;
    }
    arr[current]=a;
    heapifyup(current);
    current++;
    return 1;

}

//Function to delete an element from the priority queue.
int Priority::deletevalue(){
    if(current==0){
        cout<<"Queue is empty!!\n";
        return -1;
    }
    int a=arr[0];
    arr[0]=arr[current-1];
    heapifydown(0);
    current--;
    return a;

}

//Function to display the priority queue.
void Priority::display(){
    if (current== 0) {
        cout << "Queue is empty!!\n";
        return;
    }

    for (int i = 0; i < current; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

//Function to search an element in the priority queue.
int Priority::search(int a){
    for(int i=0;i<current;i++){
        if(arr[i]==a)
        return 1;
    }
    return -1;

}

//Function to heap sort the queue.
void Priority::heapsort(){
    if(current==0){
        cout<<"The queue is empty!!";
        return;
    }
    Priority temp(capacity);
    for (int i = 0; i < current; i++) {
        temp.insertvalue(arr[i]);
    }

    cout << "Sorted elements in descending order: ";
    while (temp.current > 0) {
        cout << temp.deletevalue() << " ";
    }
    cout << endl;
}
