//breadth first search in a binary tree

#include <iostream>
#include <queue>
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

node *bfs(node *root, int key)
{
    //if root == null return root
    if (!root)
        return root;

    queue<node *> q;
    q.push(root);
    node *itr;

    //while queue is not empty
    while (!q.empty())
    {
        itr = q.front();
        q.pop();

        if (itr->left)
        {
            q.push(itr->left);
        }

        if (itr->val == key)
            return itr;

        if (itr->right)
        {
            q.push(itr->right);
        }
    }
    return NULL;
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

    cout << "searching for 3\n";
    node *found = bfs(root, 3);
    if (!found)
        cout << "key not found\n";
    else
        cout << found->val << " found at " << found;

    return 0;
}