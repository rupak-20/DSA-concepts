//given an array where array indexes represent the values in a node of the binary tree
//and array values represent the parent node of that particular node. The value of root node index is -1
//construct the binary tree and return its root node

//expected time complexity : O(n)

#include <iostream>
#include <vector>
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

//fucntion declarations
node *arrayToBinaryTree(vector<int>);
void createNode(vector<int>, int, vector<node *> &, node **);
void inOrderTraversal(node *);

//driver code
int main()
{
    vector<int> arr = {-1, 0, 0, 1, 1, 3, 5};
    node *root = arrayToBinaryTree(arr);
    cout << "inorder traversal of the constructed binary tree is: ";
    inOrderTraversal(root);
    /*
    constructed binary tree

             0
           /   \
          1     2
         / \
        3   4
       /
      5 
     /
    6

*/
    return 0;
}

node *arrayToBinaryTree(vector<int> arr)
{
    vector<node *> p(arr.size(), NULL);
    node *root;

    for (int i = 0; i < arr.size(); i++)
        createNode(arr, i, p, &root);

    return root;
}

void createNode(vector<int> arr, int i, vector<node *> &p, node **root)
{
    //if the node has already been created then return
    if (p[i])
        return;

    //else create a new node and assign to p[i]
    p[i] = new node(i);

    //if i is the root node then assign the root and return
    if (arr[i] == -1)
    {
        *root = p[i];
        return;
    }

    //if the parent node has not been created then create the parent node first
    if (!p[arr[i]])
        createNode(arr, arr[i], p, root);

    //locate the parent pointer
    node *parent = p[arr[i]];

    //if this is the first child of the parent
    if (!parent->left)
        parent->left = p[i];
    else
        parent->right = p[i];
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