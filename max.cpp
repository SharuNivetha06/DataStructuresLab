//C++ program to display the max difference.
#include<iostream>
using namespace std;

void solve(){
    int n;
    cout<<"Enter the number of inputs : ";
    cin>>n;
    int strength[n];
    int max1,max2;
    max1=-1;
    max2=-1;
    cout<<"Enter each input : ";
    for(int i=0;i<n;i++){
        cin>>strength[i];
        if(strength[i]>max1){
            max2=max1;
            max1=strength[i];
        }
        else if(strength[i]>max2){
            max2=strength[i];
        }
    }
    for(int i=0;i<n;i++){
        int sub=(strength[i]==max1)?max2:max1;
        cout<<strength[i]-sub<<" ";
    }
}

//Main function
int main(){
    int t;
    cout<<"Enter the number of test cases : ";
    cin>>t;
    while(t--){
        solve();
    }
}