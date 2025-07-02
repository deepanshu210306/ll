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
    //destructor
    ~Node(){
        int value=this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for "<<value<<endl;
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
    //insertion in middle
    void insertAtPosition(Node*&tail,Node*&head,int position,int d){
        if(position==1){
            insertHead(head,d);
            return;
        }
        Node*temp=head;
        int cnt=1;
        while(cnt<position-1){
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL){
            insertTail(tail,d);
            return;
        }
        Node*nodetoinsert=new Node(d);
        nodetoinsert->next=temp->next;
        temp->next=nodetoinsert;
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
    // deletion
    void deletion(int position, Node*& head, Node*& tail) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;

        // If list becomes empty, tail must be NULL too
        if (head == NULL) {
            tail = NULL;
        }

        delete temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;

        // Fix tail if deleting last node
        if (curr == tail) {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
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
    helper.insertAtPosition(tail,head,3,22);
    helper.print(head);
    helper.deletion(3, head, tail);
    helper.print(head);
    return 0;
}
