#include <iostream>
using namespace std;
#include <stack>
// Definition for a binary tree node.
struct Node
{
 int data;
 Node *left;
 Node *right;
 Node(int val)
 {
  data = val;
  left = NULL;
  right = NULL;
 }
};

Node *flatten(Node *root)  // flatten the binary tree to a linked list in-place time: O(n) space: O(1)
{
 if (!root)
  return NULL;
 Node *curr = root;

 while (curr != NULL)
 {
  if (curr->left != NULL)
  {
   Node *prev = curr->left;
   while (prev->right)
   {
    prev = prev->right;
   }
   prev->right = curr->right;
   curr->right = curr->left;
   curr->left = NULL;
  }
  curr = curr->right;
 }
 return root;
}

void inorder(Node *root)  // inorder traversal to display the tree
{
 if (!root)
  return;
 inorder(root->left);
 cout << root->data << " ";
 inorder(root->right);
}

int main()
{
 cout << "Build the binary tree (use -1 for NULL nodes): ";
 Node *root = new Node(1);
 root->left = new Node(2);
 root->right = new Node(5);
 root->left->left = new Node(3);
 root->left->right = new Node(4);
 root->right->right = new Node(6);

 cout << "Inorder Traversal of original tree: ";
 inorder(root);
 cout << endl;

 root = flatten(root);

 cout << "Inorder Traversal of flattened tree: ";
 inorder(root);
 cout << endl;

 return 0;
}
