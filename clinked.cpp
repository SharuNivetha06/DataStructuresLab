//C++ menu_driven program to implment list ADT using circular linked list.
#include <iostream>
using namespace std;

class List {
public:
 struct Node {
      int data;
      Node* next;
};
    Node* head; 
public:
    List() : head(nullptr){}

    int insertBeginning(int);
    int insertEnd(int); 
    int insertPosition(int, int);
    int deleteBeginning(); 
    int deleteEnd(); 
    int deletePosition(int); 
    int search(int); 
    void display();
};

int main() {
    List list;
    int choice, value, pos,check;
    do {
        cout << "\nMENU:\n";
        cout << "1. Insert Beginning\n2. Insert End\n3. Insert Position\n";
        cout << "4. Delete Beginning\n5. Delete End\n6. Delete Position\n";
        cout << "7. Search\n8. Display\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertBeginning(value);
                list.display();
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertEnd(value);
                list.display();
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                list.insertPosition(value, pos);
                list.display();
                break;
            case 4:
                check=list.deleteBeginning();
                if(check!=0)
                cout<<"The deleted element is "<<check;
                break;
            case 5:
                check=list.deleteEnd();
                if(check!=0)
                cout<<"The deleted element is "<<check;
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                check=list.deletePosition(pos);
                if(check!=0)
                cout<<"The deleted element is "<<check;
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                check=list.search(value);
                if (check==1)
                    cout << "Value found!\n";
                else
                    cout << "Value not found!\n";
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);
    return 0;
}

//Insertion in the beginning
int List::insertBeginning(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        head->next = head;
        return 1;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        return 1;
    }
}

 // Insert at the end
int List:: insertEnd(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        insertBeginning(value);
        return 1;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
    temp->next = newNode;
    newNode->next = head;
    return 1;
    }
}

// Insert at a specific position
int List:: insertPosition(int value, int pos) {
        if (pos < 1) {
            cout << "Invalid position!\n";
            return 0;
        }
        Node* newNode = new Node{value, nullptr};
        if (pos==1) {
            insertBeginning(value);
            return 1;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return 1;
    }

    // Delete from the beginning
int List:: deleteBeginning() {
        if (!head) {
            cout << "List is empty!\n";
            return 0;
        }
        Node* temp = head;
        int a;
        if (head->next == head) {
            a=temp->data;
            return a;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            a=temp->data;
            head = head->next;
            temp->next = head;
        }
        return a;
        delete temp;
    }

    // Delete from the end
int List::deleteEnd() {
        if (!head) {
            cout << "List is empty!\n";
            return 0;
        }
        Node* temp = head;
        if (head->next == head) {
            int a=temp->data;
            delete head;
            head = nullptr;
            return a;
        }
        while (temp->next->next != head) {
            temp = temp->next;
        }
        int a= temp->next->data;
        delete temp->next;
        temp->next = head;
        return a;
    }

    // Delete from a specific position
int List:: deletePosition(int pos) {
        if (!head || pos < 1) {
            cout << "Invalid position or empty list!\n";
            return 0;
        }
        Node* temp = head;
        Node* prev = nullptr;
        for (int i = 1; i < pos && temp->next != head; ++i) {
            prev = temp;
            temp = temp->next;
        }
        if (!prev) {
            int a=deleteBeginning();
            return a ;
        }
        prev->next = temp->next;
        return temp->data;
        delete temp;
    }

    // Search for an element
    int List:: search(int value) {
        if (head==NULL) 
        return 0;
        Node* temp = head;
        do {
            if (temp->data == value)
                return 1;
            temp = temp->next;
        } while (temp != head);
        return 0;
    }

    // Display the list
    void List:: display() {
        if (head==NULL) {
            cout << "List is empty!\n";
        }
        Node* temp = head;
        do {
            cout << temp->data << " , ";
            temp = temp->next;
        } while (temp != head);
        cout << "(Back to Head)\n";
    }