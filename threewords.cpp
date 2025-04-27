//C++ program to allot points to three players in a game
#include<iostream>
#include<vector>
#include<unordered_map>

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

//Function that allots points to the three players
void solve(){
    int n;
    cout<<"Enter the number of words per player : ";
    cin>>n;

    vector< vector< string > > words(3 , vector<string>(n));
    unordered_map<string , int> freq;

    for(int i=0;i<3;i++){
        cout<<"Enter the words of player "<<i+1<<endl;
        for(int j=0;j<n;j++){
            cin>>words[i][j];
            freq[words[i][j]]++;//Keeping track of frequency of occurence of each word.

        }
    }

    vector<int> points(3,0);
    for(int i=0;i<3;i++){
        for(const string& word : words[i]){
            if(freq[word]==1){
                points[i]+=3;
            }
            else if(freq[word]==2){
                points[i]+=1;
            }
        }
    }

    cout<<"Points scored by player 1, 2 and 3 respectively : \n";

    for(int i=0;i<3;i++){
        cout<<points[i]<<" ";
    }

    cout<<endl;
}