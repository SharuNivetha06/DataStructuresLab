//C++ program to determine the least number of moves from left side to make a sequence a happy sequence.
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

void solve();

//Main function
int main(){
    int t;
    cout<<"Enter the number of test cases : ";
    cin>>t;
    while(t--){
        solve();

    }
}

//Function that determines the least number of moves to make a sequence a happy sequence.
void solve(){
    int n;
    cout<<"Enter the number of elements in the sequence : ";
    cin>>n;

    vector<int> a(n);
    cout<<"Enter the "<<n<<" elements of the sequence : \n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    unordered_set<int> seen;
    int left_moves=0;
    //Traversing the sequence in reverse to find the duplicate element.
    for(int i=n-1;i>=0;--i){
        if(seen.find(a[i]) != seen.end()){
            left_moves=i+1;
            break;
        }
        seen.insert(a[i]);
    }

    cout<<"Minimum number of moves required : "<<left_moves<<endl;

}
