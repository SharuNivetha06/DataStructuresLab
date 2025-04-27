//Header file containing insert ascending, merge and display functions.
#ifndef LISTADT_H
#define LISTADT_H

#include <cstdio>

class List {
public:
    struct Node {
        int data;
        Node* next;
        
        Node(int val) : data(val), next(nullptr) {} // Constructor inside struct
    };

private:
    Node* head;

public:
    List() : head(nullptr) {}

    Node* getHead() { return head; }

    void insertAscending(int);
    void display();
    void merge(List& l1, List& l2);
};

// Function to insert a value in ascending order
void List::insertAscending(int val) {
    Node* newNode = new Node(val);
    if (!head || head->data >= val) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data < val) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the linked list
void List::display() {
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to merge two sorted lists into the current list
void List::merge(List& l1, List& l2) {
    head = nullptr; // Reset the current list before merging

    Node* a = l1.getHead();
    Node* b = l2.getHead();
    
    while (a || b) {
        if (!b || (a && a->data <= b->data)) {
            insertAscending(a->data);
            a = a->next;
        } else {
            insertAscending(b->data);
            b = b->next;
        }
    }
}

#endif
