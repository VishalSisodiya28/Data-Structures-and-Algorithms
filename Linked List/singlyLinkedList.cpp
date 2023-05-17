#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{

    Node *temp = new Node(data); // creating a new node
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data); // new node

    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtPosition(Node *&head, int data, int pos)
{

    Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(data);

    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    Node *node1 = new Node(50);

    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 10);
    insertAtTail(tail, 20);
    insertAtHead(head, 40);
    insertAtTail(tail, 30);

    insertAtPosition(head, 60, 3);
    print(head);

    return 0;
}