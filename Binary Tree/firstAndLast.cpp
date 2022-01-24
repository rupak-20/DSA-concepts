//returning the node in the subtree that comes first and last in that subtree's traversal order

#include <iostream>
using namespace std;

class node
{
public:
    int val;
    node *right, *left;

    node()
    {
        val = 0;
        right = nullptr;
        left = nullptr;
    }

    node(int v)
    {
        val = v;
        right = nullptr;
        left = nullptr;
    }

    node(int v, node *l, node *r)
    {
        val = v;
        left = l;
        right = r;
    }
};

node *subtree_first(node *root)
{
    node *itr = root;
    while (itr != NULL && itr->left != NULL)
    {
        itr = itr->left;
    }

    return itr;
}

node *subtree_last(node *root)
{
    node *itr = root;
    while (itr != NULL && itr->right != NULL)
    {
        itr = itr->right;
    }

    return itr;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    (root->left)->left = new node(3);
    (root->left)->right = new node(4);
    root->right = new node(5);
    (root->right)->left = new node(6);
    (root->right)->right = new node(7);

    /*

               1
           /      \
        2           5
      /   \       /   \
    3      4    6      7

    */

    node *first = subtree_first(root);
    node *last = subtree_last(root);

    cout << "first value = " << first->val << "\n";
    cout << "last value = " << last->val;

    return 0;
}