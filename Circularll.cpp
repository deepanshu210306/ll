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

    // Destructor
    ~Node() {
        int value = this->data;

        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }

        cout << "Memory is free for " << value << endl;
    }

    // Insert node in circular linked list
    void insertnode(Node*& tail, int element, int d) {
        // Empty list
        if (tail == NULL) {
            Node* node1 = new Node(d);
            tail = node1;
            node1->next = node1;
        } else {
            // Non-empty list: find element
            Node* curr = tail;
            while (curr->data != element) {
                curr = curr->next;
            }

            // Insert after element
            Node* temp = new Node(d);
            temp->next = curr->next;
            curr->next = temp;

            // ✅ If inserting after tail, update tail
            if (curr == tail) {
                tail = temp;
            }
        }
    }

    // Print circular linked list
    void print(Node* tail) {
        if (tail == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* curr = tail;
        cout << curr->data << " ";
        curr = curr->next;

        while (curr != tail) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    // deletion
    void deletion(Node*&tail,int value){
        if(tail==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        else {
            Node*prev=tail;
            Node*curr=prev->next;
            while(curr->data!=value){
                prev=curr;
                curr=curr->next;
            }
            prev->next=curr->next;
            if(tail==curr){
                tail=prev;
            }
            else if(curr==prev)tail=NULL;
            curr->next=NULL;
            delete curr;
        }
    }
};

int main() {
    Node* tail = NULL;

    // Helper object to call member functions
    Node* helper = new Node(0); // dummy node

    helper->insertnode(tail, 5, 3);   // First node
    helper->insertnode(tail, 3, 10);  // Insert after 3
    helper->insertnode(tail, 3, 31);  // Insert after 3
    helper->insertnode(tail, 31, 69); // Insert after 31

    helper->print(tail);

    // Free the whole list
    delete tail;

    return 0;
}
