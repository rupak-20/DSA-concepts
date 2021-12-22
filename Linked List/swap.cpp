// swapping two nodes in a linked list without swaping the data

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

// swapping the nodes
void swap(node **head, int x, int y) {
  if (x == y)
    return;

  node **nodex = NULL, **nodey = NULL;

  while (*head != NULL) {
    if ((*head)->val == x && nodex == NULL)
      nodex = head;
    if ((*head)->val == y && nodey == NULL)
      nodey = head;

    head = &((*head)->next);
  }

  if (nodex == NULL || nodey == NULL) {
    cout << "either " << x << " or " << y << " not found\n";
    return;
  }

  node *temp = (*nodex)->next;
  (*nodex)->next = (*nodey)->next;
  (*nodey)->next = temp;

  temp = *nodex;
  *nodex = *nodey;
  *nodey = temp;
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

// print list values
void print(node *node) {
  while (node != NULL) {
    cout << node->val << " --> ";
    node = node->next;
  }
  cout << "NULL\n";
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

  cout << "swapping 1 and 7: ";
  swap(&head, 1, 7);
  print(head);
  cout << "swapping 3 and 5: ";
  swap(&head, 3, 5);
  print(head);
  cout << "swapping 4 and 8 (8 doesn't exist in linked list): ";
  swap(&head, 4, 8);

  return 0;
}