//Impleenting round-robin system using circular linked list
#include <iostream>
using namespace std;
#include "headc.h"

#define fixedtime 5 //fixed time of each exectution of a process

int main(){
  List list;
  int choice,value;
  cout<<"Menu:\n\t";
  cout<<"1.Insert Process\n\t2.Execute\n\t3.Display\n\t4.Exit\n";
  cout<<"Enter choice: ";
  cin>>choice;
  while(choice!=4){
      if(choice>4 ||choice<1){
          cout<<"Enter a valid choice\n\n";
      }
      switch(choice){
      case 1:
          cout<<"Enter value: ";
          cin>>value;
          list.insertprocess(value); //Declared in header
          break;
      case 2:
          list.executeprocess(fixedtime); 
          break;
      case 3:
          list.display();
          break;
      }
      cout<<"\n\nEnter choice: ";
      cin>>choice;
  }
  cout<<"\nExiting program...\n";
  cout<<"Program terminated\n\n";
}