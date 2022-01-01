// reversing the linked list

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

// print list values
void print(node *node) {
  while (node != NULL) {
    cout << node->val << " --> ";
    node = node->next;
  }
  cout << "NULL\n";
}

// reversing linked list
void reverse(node **head) {
  if (!head) {
    cout << "list empty\n";
    return;
  }

  node *prev = NULL, *curr = *head, *next = NULL;

  while (curr) {
    next = curr->next; // change next before changing the next of currernt ie.
                       // curr->next
    curr->next = prev; // reverse the next pointer to the previous node
    prev = curr;       // move prev one step ahead
    curr = next;       // move curr one step ahead
  }

  *head = prev; // restore head
}

// driver code
int main() {

  node *head = NULL;

  append(&head, 1);
  append(&head, 2);
  append(&head, 3);
  append(&head, 4);
  append(&head, 5);
  append(&head, 6);
  append(&head, 7);
  cout << "original linked list: ";
  print(head);

  reverse(&head);
  cout << "linked list after reversal: ";
  print(head);

  return 0;
}