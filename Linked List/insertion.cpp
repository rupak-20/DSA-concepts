#include<iostream>
using namespace std;

class node {
    
    public:
    int val;
    node *next;

    node(int n = 0, node *nxt = NULL) {
        val = n;
        next = nxt;
    }
};

void insert(node *pre, int n) {
    node *new_node = new node(n);
    if(pre->next == NULL) {
        cout<<"invalid previous node\n"; return;
    }
    new_node->next = pre->next;
    pre->next =  new_node;
}

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

void add(node **head, int n) {
    node *new_node = new node(n);
    new_node->next = (*head);
    (*head) = new_node;
}

void print(node *node) {
    while(node != NULL) {
        cout<<node->val<<" ";
        node = node->next;
    }
    cout<<"\n";
}

int main() {

    node *head = NULL, *tail = NULL;
    int a, b;

    add(&head, 2);
    append(&head, 3);
    insert(head->next, 1);
    add(&head, 0);
    append(&head, 4);
    print(head);

    return 0;
}