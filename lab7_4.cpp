//C++ program to process a string and give the desired output.
#include<iostream>
#include"stackADT.h"
using namespace std;

//Function that processes the string using stack ADT
string processing(string input){
    Stack s;
    for(char ch:input){
        if(ch=='+'){
            if(!s.empty()){
                s.pop();
            }
        }
        else{
            s.push(ch);
        }
    }

    string result=" ";
    while(!s.empty()){
        result=s.peek()+result;
        s.pop();
    }

    return result;
}

//Main function
int main(){
    string s;
    cout<<"Enter a string : ";
    cin>>s;

    cout<<processing(s);
}