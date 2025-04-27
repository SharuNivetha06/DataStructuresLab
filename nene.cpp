//Program to implement a game 
#include <iostream>
using namespace std;

void solve(){ //Code of the game
    int k,q,min;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"Enter the value of q: ";
    cin>>q;
    cout<<"Enter the k sequence:\n";
    int ks[k],qs[q];
    cout<<"\tEnter the value of k sequence: ";
    cin>>ks[0];
    min=ks[0];
    for(int i=1;i<k;i++){
        cout<<"\tEnter the value of k sequence: ";
        cin>>ks[i];
        if(min>ks[i]){
            min=ks[i];
        }
    }
    cout<<"Enter the q sequence:\n";
    for(int i=0;i<q;i++){
        cout<<"\tEnter the value of q sequence: ";
        cin>>qs[i];
    }
    
    cout<<"Winners: ";
    for(int i=0;i<q;i++){
        if(qs[i]<min){
            cout<<qs[i]<<" ";
        }
        else{
            cout<<min-1<<" ";
        }
    }
}


int main(){
     int cases;
     cout<<"Enter the number of test cases: ";
     cin>>cases;
     for(int i=1;i<=cases;i++){
        cout<<"Enter the details of testcase "<<i<<": \n";
        solve(); //Function call to the game
        cout<<"\n\n";
     }
     return 0;
}


