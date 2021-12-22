// merging two sorted linked list

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

// merging two sorted linked list
node *merge(node **head1, node **head2) {
  node *l1 = *head1, *l2 = *head2, *head = NULL, *itr = head;

  // assign head to the smaller number among l1->val and l2->val
  if (l1->val < l2->val) {
    head = l1;
    itr = l1;
    l1 = l1->next;
  } else {
    head = l2;
    itr = l2;
    l2 = l2->next;
  }

  // link to subsequent node to the node with smaller number until l1 and l2 not
  // equal to NULL
  while (l1 && l2) {
    if (l1->val < l2->val) {
      itr->next = l1;
      l1 = l1->next;
    } else {
      itr->next = l2;
      l2 = l2->next;
    }

    itr = itr->next;
  }

  // remaining nodes are already sorted
  if (l1)
    itr->next = l1;
  if (l2)
    itr->next = l2;

  return head;
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

  node *head1 = NULL, *head2 = NULL, *head = NULL;

  append(&head1, 1);
  append(&head1, 5);
  append(&head1, 5);
  append(&head1, 7);
  append(&head1, 10);
  cout << "linked list 1: ";
  print(head1);

  append(&head2, 2);
  append(&head2, 4);
  append(&head2, 6);
  append(&head2, 6);
  append(&head2, 10);
  cout << "linked list 2: ";
  print(head2);

  cout << "merged linked list: ";
  head = merge(&head1, &head2);
  print(head);

  return 0;
}