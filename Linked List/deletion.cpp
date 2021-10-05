#include<iostream>
using namespace std;

//linked list structure
class node {
    
    public:
    int val;
    node *next;

    node(int n = 0, node *nxt = NULL) {
        val = n;
        next = nxt;
    }
};

//deleting first occurance of a given key from the linked list
void deletekey(node **head, int key) {
    if(*head == NULL) {
        cout<<"list empty\n";
        return;
    }
    
    node *temp = *head;
    node *pre = NULL;

    if (temp != NULL && temp->val == key) {
        *head = temp->next;
        delete temp;    //free old head
        return;
    }

    else {
        while (temp!=NULL && temp->val!=key) {
            pre = temp;
            temp = temp->next;
        }
        if(temp == NULL) {
            cout<<"key not found\n";
            return;
        }

        pre->next = temp->next;
        cout<<"key deleted\n";
        delete temp;
    }
}

//appending node at the end of the list
void append(node **head, int n) {
    node *new_node = new node(n);
    node *last = *head;
    if(*head == NULL) {
        (*head) = new_node; return;
    }
    while(last->next != NULL)
        last = last->next;

    last->next = new_node;
}

//print list values
void print(node *node) {
    while(node != NULL) {
        cout<<node->val<<" ";
        node = node->next;
    }
    cout<<"\n";
}

//driver code
int main() {

    node *head = NULL, *tail = NULL;
    int a, b;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    cout<<"linked list now: ";
    print(head);

    deletekey(&head, 3);
    cout<<"linked list after deleting node with key '3': ";
    print(head);

    return 0;
}