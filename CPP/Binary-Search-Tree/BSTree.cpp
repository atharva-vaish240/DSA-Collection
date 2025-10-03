#include "BSTree.h"

#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * Inserts a new node with the given key into the binary search tree.
 * If the tree is empty, creates a new node as the root with the given key.
 * If the key already exists in the tree, increments the count of the existing node.
 * If the key does not exist, inserts a new node in the appropriate position based on the key's value.
 * 
 * @param key The key of the node to be inserted.
 */
void BSTree::insert(const string& key) {
  if(is_empty()) { // Edge case:  The tree is empty
    root = new Node(key);
    return;
  }

  if(search(key)) { // Edge case: If we find the key in the tree, just increment its count
    searchInTree(key)->count++;
    return;
  }

  for(Node* iter = root; iter != nullptr; ) { // Manual iteation to find the left/right node's pointer where the new node can be added
    if(key < iter->key) { // iterate left
      if(iter->left == nullptr) {
        iter->left = new Node(key);
        return;
      }
      iter = iter->left;
    } else { // iterate right
      if(iter->right == nullptr) {
        iter->right = new Node(key);
        return;
      }
      iter = iter->right;
    }
  }
}

/**
 * Searches for a node with the given key in the binary search tree.
 * Returns true if the key is found in the tree, false otherwise.
 *
 * @param key The key to search for in the tree.
 * @return True if the key is found, false otherwise.
 */
bool BSTree::search(const string& key) const {
  if(is_empty()) {
    return false;
  }

  for(Node* iter = root; iter != nullptr; )  {  //manual iteration
    if(iter->key == key) { // key found
      return true;
    } else if(key < iter->key) { // search left, otherwise search right
      iter = iter->left;
    } else {
      iter = iter->right; 
    }
  }
  return false;
}

/**
 * Searches for a node with the given key in the binary search tree.
 * Returns the pointer to the node if the key is found in the tree
 *
 * @param key The key to search for in the tree.
 * @return Pointer to the node if the key is found, nullptr otherwise.
 */
Node* BSTree::searchInTree(const string& key) const {
  if(is_empty()) {
    return nullptr;
  }

  for(Node* iter = root; iter != nullptr; )  {  //manual iteration
    if(iter->key == key) { // return ptr
      return iter;
    } else if(key < iter->key) { // search left, otherwise right
      iter = iter->left;
    } else {
      iter = iter->right;
    }
  }
  return nullptr;
}

/**
 * Searches for the largest value in the binary search tree
 * 
 * @return the key value of the node
 */
string BSTree::largest() const {
  if(is_empty()) {  // Edge case: Tree is empty
    return "";
  }

  Node* iter = nullptr;
  // iterate through the tree, going as far right as possible
  for(iter = root; iter != nullptr && iter->right != nullptr; iter = iter->right) {}

  return iter->key;
}

/**
 * Searches for the smallest value in the binary search tree
 * 
 * @return the key value of the node
 */
string BSTree::smallest() const {
  if(is_empty()) {  // Edge case: Tree is empty
    return "";
  }

  Node* iter = nullptr;
  // iterate through the tree, going as far left as possible
  for(iter = root; iter != nullptr && iter->left != nullptr; iter = iter->left) {}

  return iter->key;
}

/**
 * Calculates the height of the subtree rooted at the node with the given key in the binary search tree.
 * The height of an empty tree is defined as -1.
 *
 * @param key The key of the node whose subtree height is to be calculated.
 * @return The height of the subtree rooted at the node with the given key
 */
int BSTree::height(const string& key) const {
  if(is_empty()) {
    return -1;
  }
  // First find the node with this key, then run "height_of" to get the height
  Node* searchedNode = searchInTree(key);
  if(searchedNode == nullptr) {
    return -1;
  }
  return height_of(searchedNode);
}

/**
 * Remove a node with the specified key from the binary search tree.
 * 
 * @param key The key of the node to be removed.
 */
void BSTree::remove(const string& key) {
  if(is_empty() || !search(key)) { // Edge case: Tree is empty or key is not found
    return;
  }
  
  Node* searched = searchInTree(key);
  if(searched->count > 1) { // if node's count is > 1, decrement and return
    searched->count--;
    return;
  }

  remove(nullptr, root, key);
}

/**
 * Remove a node with the specified key from the binary search tree, starting from the specified node.
 * Recursively finds the node to be removed, and recursively removes and rebuilds the tree.
 * 
 * @param parent The parent node of the current node being checked.
 * @param tree The current node being checked for removal.
 * @param key The key of the node to be removed.
 */
void BSTree::remove(Node* parent, Node* tree, const string& key) {
  if(tree == nullptr) { // node can not be found
    return;
  }
  if(key < tree->key) { // find the node
    remove(tree, tree->left, key);
  } else if(key > tree->key){
    remove(tree, tree->right, key);
  } else {
    if(is_leaf(tree)) { // if node is leaf, 
      if(parent == nullptr) { // delete (if it is root)
        delete tree;
        root = nullptr;
      } else {
        if(tree == parent->left) { // check if ndoe is on left or right
          parent->left = nullptr;
        } else {
          parent->right = nullptr;
        }
        delete tree;
      }
    } else if(tree->left != nullptr) { // find predecessor (largest in left sub-tree)
      Node* largest = tree->left;
      while(largest->right != nullptr) {
        largest = largest->right;
      }

      tree->key = largest->key;
      tree->count = largest->count;
      largest->count = 1;
      remove(tree, tree->left, tree->key); // recursively call
    } else { // find successor (largest in right sub-tree)
      Node* smallest = tree->right;
      while(smallest->left != nullptr) {
        smallest = smallest->left;
      }

      tree->key = smallest->key;
      tree->count = smallest->count;
      smallest->count = 1;
      remove(tree, tree->right, tree->key); // recursively call
    }
  }
}

/**
 * prints out the tree recursively in pre-order
 */
void BSTree::preOrder() const {
  preOrder(root);
  cout << endl;
}

/**
 * prints out the tree recursively in post-order
 */
void BSTree::postOrder() const {
  postOrder(root);
  cout << endl;
}

/**
 * prints out the tree recursively in in-order
 */
void BSTree::inOrder() const {
  inOrder(root);
  cout << endl;
}

/** 
 * The height (length of longest path to the bottom) of an empty tree is -1
 * Otherwise, you pick the larger of the left height and the right height
 * and add one to that
 * 
 * @param tree the node pointer
 * @return the height of the tree
*/
int BSTree::height_of(Node* tree) const {
  if(tree == nullptr) {
    return -1;
  }
  return max(height_of(tree->left), height_of(tree->right)) + 1;
}

void BSTree::preOrder(Node* tree) const {
  if(tree == nullptr) {
    return;
  }

  cout << tree->key << "(" << tree->count << ")" << ", ";
  preOrder(tree->left);
  preOrder(tree->right);
}

void BSTree::postOrder(Node* tree) const {
  if(tree == nullptr) {
    return;
  }
        
  postOrder(tree->left);
  postOrder(tree->right);
  cout << tree->key << "(" << tree->count << ")" << ", ";
}

void BSTree::inOrder(Node* tree) const {
  if(tree == nullptr) {
    return;
  }

  inOrder(tree->left);
  cout << tree->key << "(" << tree->count << ")" << ", ";
  inOrder(tree->right);
}

/**
 * @return true if the tree is empty, false otherwise
 */
bool BSTree::is_empty() const {
  return (root == nullptr);
}

/**
 * @return true if the node is a leaf (left and right children do not exist)
 */
bool BSTree::is_leaf(Node* node) const {
  return (node != nullptr && node->left == nullptr && node->right == nullptr);
}

// This is a pre-order traversal that shows the full state of the tree
// (but it is a code turd)
void BSTree::debug(Node* tree, int indent) const {
  if (tree == nullptr) return;
  for(int i=0;i<4*indent;++i) cout << ' ';
  cout << tree << ' ' << *tree << endl;
  debug(tree->left,indent+1);
  for(int i=0;i<4*indent;++i) cout << ' ';
  cout << "-" << endl;
  debug(tree->right,indent+1);
}
