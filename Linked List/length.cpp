// finding length of the linked list using iterative and recursive approach

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

// finding length using iterative approach
int lengthiterative(node **head) {
  node *itr = *head;
  int len = 0;
  while (itr != NULL) {
    itr = itr->next;
    len++;
  }

  return len;
}

// finding length using recursive approach
int lengthrecursive(node **head) {

  if ((*head) == NULL)
    return 0;

  else
    return 1 + lengthrecursive(&(*head)->next);
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
  print(head);

  cout << "length of linked list using iterative approach = "
       << lengthiterative(&head) << "\n";
  cout << "length of linked list using recursive approach = "
       << lengthrecursive(&head) << "\n";

  return 0;
}