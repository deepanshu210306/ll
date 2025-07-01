#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Insertion at head
    void insertHead(Node*& head, int d) {
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
    }

    // Insertion at tail
    void insertTail(Node*& tail, int d) {
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }

    // Print the list
    void print(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    // Make an object to call member functions
    Node helper(0);  // dummy node just to use its functions

    helper.print(head);

    helper.insertHead(head, 12);
    helper.print(head);

    helper.insertTail(tail, 15);
    helper.print(head);

    return 0;
}
