//inserting a node in binary tree in level order

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

node *insertion(node *root, int val)
{
    //if root == null return root
    if (!root)
    {
        root = new node(val);
        return root;
    }

    node *newnode = new node(val);
    //if newnode == null return null
    if (!newnode)
    {
        cout << "no space available!\n";
        return nullptr;
    }

    queue<node *> q;
    q.push(root);

    //while queue is not empty
    while (!q.empty())
    {
        node *itr = q.front();
        q.pop();

        if (itr->left)
        {
            q.push(itr->left);
        }
        //if itr->left is null add newnode there
        else
        {
            itr->left = newnode;
            return root;
        }

        if (itr->right)
        {
            q.push(itr->right);
        }
        //if itr->right is null add newnode there
        else
        {
            itr->right = newnode;
            return root;
        }
    }
}

// binary tree inorder traversal
void inOrderTraversal(node *root)
{
    if (!root)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

//driver code
int main()
{
    node *root = new node(1);
    cout << "binary tree before insertion: ";
    inOrderTraversal(root);
    cout << "\n";

    root = insertion(root, 2);
    root = insertion(root, 3);
    root = insertion(root, 4);
    root = insertion(root, 5);
    root = insertion(root, 6);
    root = insertion(root, 7);

    /*

               1
           /      \
        2           3
      /   \       /   \
    4      5    6      7

    */

    cout << "binary tree after insertion: ";
    inOrderTraversal(root);

    return 0;
}