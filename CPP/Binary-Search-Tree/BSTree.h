#pragma once

#include "Node.h"

class BSTree {
  Node* root;

public:
  BSTree() : root(nullptr) {}

  ~BSTree() {
    // Safe to delete nullptr, so no check needed
    // The Node struct recursively deletes its children
    delete root;
  }

  BSTree(const BSTree&) = delete;
  BSTree& operator=(const BSTree&) = delete;
  
  void insert(const string& key);
  bool search(const string& key) const;
  string largest() const;
  string smallest() const;
  int height(const string& key) const;
  void remove(const string& key);

  void preOrder() const;
  void postOrder() const;
  void inOrder() const;
  
  void debug() const {
    debug(root,0);
  }

private:
  void remove(Node* parent, Node* tree, const string& key);
  int height_of(Node* tree) const;
  void preOrder(Node* tree) const;
  void postOrder(Node* tree) const;
  void inOrder(Node* tree) const;

  bool is_empty() const;
  bool is_leaf(Node* node) const;

  Node* searchInTree(const string& key) const;

  void debug(Node* tree, int indent) const;
};
