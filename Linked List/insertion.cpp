// inserting node at the beginning, after a certain node and at the end of a
// linked list

#include <iostream>
using namespace std;

// linked list structure
class node {

public:
  int val;
  node *next;

  node(int n = 0, node *nxt = NULL) {
    val = n;
    next = nxt;
  }
};

// inserting node after a certian node
void insert(node *pre, int n) {
  node *new_node = new node(n);
  if (pre->next == NULL) {
    cout << "invalid previous node\n";
    return;
  }
  new_node->next = pre->next;
  pre->next = new_node;
}

// appending node at the end of the list
void append(node **head, int n) {
  node *new_node = new node(n);
  node *last = *head;
  if (*head == NULL) {
    (*head) = new_node;
    return;
  }
  while (last->next != NULL)
    last = last->next;

  last->next = new_node;
}

// adding the node at the starting of the list
void add(node **head, int n) {
  node *new_node = new node(n);
  new_node->next = (*head);
  (*head) = new_node;
}

// print list values
void print(node *node) {
  while (node != NULL) {
    cout << node->val << " ";
    node = node->next;
  }
  cout << "\n";
}

// driver code
int main() {

  node *head = NULL;

  add(&head, 2);
  append(&head, 3);
  insert(head->next, 1);
  add(&head, 0);
  append(&head, 4);
  print(head);

  return 0;
}