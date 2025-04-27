//C++ program to implement a program that calculates the maximum possible blocks in tower 1 using STL.
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//Function to calculate the maximum possible blocks in tower 1.
int solve(){
    int n; 
    cout<<"Enter the number of towers :  ";
    cin>>n;
    vector<long long> a(n);
    cout<<"Enter the number of blocks per tower in order : \n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long a1=a[0];
    vector<long long> othertowers(a.begin()+1,a.end());
    sort(othertowers.begin(),othertowers.end());

    for(long long blocks:othertowers){
        while(blocks>a1){
            a1++;
            blocks--;
        }
    }

    return a1;
}

//Main function 
int main(){
    int t,t1;
    cout<<"Enter the number of test cases :  ";
    cin>>t;
    while(t>0){
        t1=solve();
        cout<<"Maximum possible blocks in tower 1 is "<<t1<<"\n";
        t--;
    }
}