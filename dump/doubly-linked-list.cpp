#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor with data and next
    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

class MethodsLL {
    public:
    
    // Function to reverse the doubly linked list
    Node* reverseDLL(Node* head) {
        if(head == nullptr) return head;

        Node* current = head;
        Node* temp = nullptr;

        // Swap next and prev for each node
        while(current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        // Adjust head to the new first node
        if(temp != nullptr) {
            head = temp->prev;
        }

        return head;
    }
};