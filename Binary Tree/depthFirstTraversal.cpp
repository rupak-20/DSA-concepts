//depth first search in preorder, inorder and postorder traversal

//preorder: root-left-right
//inorder: left-root-right
//postorder: left-right-root

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//binary tree node
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

//preorder traversal
void preorder(node *root)
{
    //if root == null return
    if (!root)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

//inorder traversal
void inorder(node *root)
{
    //if root is null return
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

//postorder traversal
void dfs_postorder(node *root)
{
    //if root is null return
    if (!root)
        return;

    dfs_postorder(root->left);
    dfs_postorder(root->right);

    cout << root->val << " ";
}

//driver code
int main()
{
    node *root = new node(1);
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

    cout << "preorder traversal: ";
    preorder(root);

    cout << "\ninorder traversal: ";
    inorder(root);

    cout << "\npostorder traversal: ";
    dfs_postorder(root);

    return 0;
}