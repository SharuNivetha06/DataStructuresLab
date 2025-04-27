//Menu-Driven C++ program to get inputs for two lists and then merge them.5

#include <iostream>
#include "headnew.h" // Include header file

using namespace std;

int main() {
    List list1, list2, list3;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert into List1\n";
        cout << "2. Insert into List2\n";
        cout << "3. Merge List1 and List2 into List3\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert into List1: ";
                cin >> value;
                list1.insertAscending(value);
                list1.display();
                break;
            case 2:
                cout << "Enter value to insert into List2: ";
                cin >> value;
                list2.insertAscending(value);
                list2.display();
                break;
            case 3:
                list3.merge(list1, list2);
                cout << "Merged successfully into List3.\n";
                list3.display();
                break;
            case 4:
                cout << "Select list to display (1, 2, or 3): ";
                int listChoice;
                cin >> listChoice;
                if (listChoice == 1) 
                list1.display();
                else if (listChoice == 2) 
                list2.display();
                else if (listChoice == 3) 
                list3.display();
                else 
                cout << "Invalid list selection.\n";
                break;
            case 5:
                cout << "Exiting program.\n";
                exit(0);
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
