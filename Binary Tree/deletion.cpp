//deleting a node in a binary tree

#include <iostream>
#include <queue>
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

void deleteDeepest(node *root, node *dnode)
{
    queue<node *> q;
    q.push(root);
    node *itr;

    while (!q.empty())
    {
        itr = q.front();
        q.pop();

        if (itr == dnode)
        {
            itr = NULL;
            delete (dnode);
            return;
        }

        if (itr->left)
            if (itr->left == dnode)
            {
                itr->left = NULL;
                delete (dnode);
                return;
            }
            else
                q.push(itr->left);

        if (itr->right)
            if (itr->right == dnode)
            {
                itr->right = NULL;
                delete (dnode);
                return;
            }
            else
                q.push(itr->right);
    }
}

node *deletion(node *root, int key)
{
    if (!root)
        return root;

    if (!root->left && !root->right)
        if (root->val == key)
            return NULL;
        else
            return root;

    queue<node *> q;
    q.push(root);
    node *temp, *dnode = NULL;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->val == key)
            dnode = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    if (dnode)
    {
        cout << "\nkey deleted\n";
        int x = temp->val;
        deleteDeepest(root, temp);
        dnode->val = x;
    }

    else
        cout << "\nkey not found\n";

    return root;
}

// binary tree inorder traversal
void inOrderTraversal(node *root)
{
    if (!root)
        return;

    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
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

    cout << "tree before deleting a node\n";
    inOrderTraversal(root);
    deletion(root, 2);
    cout << "tree after deleting a node\n";
    inOrderTraversal(root);

    return 0;
}