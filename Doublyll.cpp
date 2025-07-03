// 4:52pm
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for " << value << endl;
    }

    // Insertion at head
    void insertHead(int d, Node *&head)
    {
        Node *temp = new Node(d);
        temp->next = head;
        if (head != NULL)
        {
            head->prev = temp;
        }
        head = temp; // FIXED
    }

    // Insertion at tail
    void insertTail(int d, Node *&tail)
    {
        Node *temp = new Node(d);
        temp->prev = tail;
        if (tail != NULL)
        {
            tail->next = temp;
        }
        tail = temp; // FIXED
    }

    // Insertion in middle
    void inserPos(int d, Node *&head, int position)
    {
        Node *node1 = new Node(d);
        Node *temp = head;
        int cnt = 1;

        while (cnt < position - 1)
        {
            temp = temp->next;
            cnt++;
        }

        Node *forward = temp->next; //  store the next node

        temp->next = node1; // temp's next is the new node
        node1->prev = temp; // new node's prev is temp

        node1->next = forward; // new node's next is forward
        if (forward != NULL)
        { // if forward is not null, fix its prev
            forward->prev = node1;
        }
    }
    void deleteNode(int position, Node *&head, Node *&tail)
    {
        if (position == 1)
        {
            Node *temp = head;
            if (temp->next != NULL)
            {
                temp->next->prev = NULL;
            }
            else
            {
                // If deleting the only node, update tail too!
                tail = NULL;
            }
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            Node *curr = head;
            Node *prev = NULL;
            int cnt = 1;
            while (cnt < position)
            {
                prev = curr;
                curr = curr->next;
                cnt++;
            }

            prev->next = curr->next;

            if (curr->next != NULL)
            {
                curr->next->prev = prev;
            }
            else
            {
                //  If deleting the last node, update tail!
                tail = prev;
            }

            curr->next = NULL;
            curr->prev = NULL;

            delete curr;
        }
    }

    void print(Node *&head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    Node *helper = new Node(0); // dummy node

    helper->insertHead(11, head);
    helper->insertTail(12, tail);
    helper->inserPos(15, head, 2);
    helper->print(head);
    helper->deleteNode(2, head, tail);

    helper->print(head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    helper->deleteNode(3, head, tail);
cout<<head->data<<endl;
    cout<<tail->data<<endl;

    return 0;
}
