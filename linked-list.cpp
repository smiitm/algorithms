#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor with data and next
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class MethodsLL {
public:

    // Function to insert a new node at the head
    Node* insertAtHead(Node* head, int newData) {
        Node* newNode = new Node(newData, head);
        return newNode;
    }

    // Function to print the linked list
    void printList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to delete the tail node
    Node* deleteTail(Node* head){
        if(head == nullptr) return head;

        if(head->next == nullptr){
            delete head;
            return nullptr;
        }

        Node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return head;
    }

    // Function to search for a value in the linked list
    bool searchLL(Node* head, int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Function to get the length of the linked list
    int getLength(Node* head) {
        int length = 0;
        Node* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    // Fuction to add a new node at the end
    Node* insertAtTail(Node* head, int newData) {
        Node* newNode = new Node(newData);
        if (head == nullptr) {
            return newNode;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }

    // Function to add a new node at Kth position
    Node* insertAtKthPosition(Node* head, int newData, int k){
        Node* newNode = new Node(newData);
        if(k == 0){
            newNode->next = head;
            return newNode;
        }
        Node* temp = head;
        for(int i = 0; i < k - 1 && temp != nullptr; i++){
            temp = temp->next;
        }
        if(temp == nullptr){
            delete newNode;
            return head;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }

    // Function to reverse the linked list
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

};