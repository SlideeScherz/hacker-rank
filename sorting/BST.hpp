#ifndef BST_HPP_INCLUDED
#define BST_HPP_INCLUDED

#include <stdexcept>
#include <iostream>

#include "Stack.hpp"

/**
 * Generic implementation of a BST backed by linked objects.
 */
template <typename K> /*, typename T> */
class BinarySearchTree
{
    struct Node {
        Node(K k, Node* p = nullptr, Node* l = nullptr, Node* r = nullptr)
            : key(k), parent(p), left(l), right(r) {}

        Node* left;
        Node* right;
        Node* parent;
        K key;
        /*
        T data; // imagine that we might want to store more complex data indexed by key
        */
    };
public:

    Node* root() {
        return this->rootNode;
    }

    bool empty() const {
        return empty(this->rootNode);
    }

    void printKeysInorder() const {
        printKeysInorder(this->rootNode);
    }

    void inOrderTree() const {
        inOrderTree(this->rootNode);
    }

    void preOrderWalk() const {
        perOrderWalk(this->rootNode);
    }

    void postOrderWalk() const {
        postOrderWalk(this->rootNode);
    }

    Node* search(K k) {
        return search(this->rootNode, k);
    }

    Node* iterativeSearch(K k) {
        return iterativeSearch(this->rootNode, k);
    }

    Node* minimum() {
        return minimum(this->rootNode);
    }

    Node* maximum() {
        return maximum(this->rootNode);
    }

    Node* successor()
    {
        return successor(this->rootNode);
    }

    void insert(K k)
    {
        insert(*this, k);
    }

    void transplant(Node* u, Node* v)
    {
        transplant(*this, u, v);
    }

    void deleteNode(Node* z)
    {
        deleteNode(*this, z);
    }

    BinarySearchTree() : rootNode(nullptr) {}

    ~BinarySearchTree() { /* TODO */ }
  ~BinarySearchTree() {
    while (this->rootNode) {
      auto oldRoot = this->rootNode;
      deleteNode(this->rootNode);
      delete oldRoot;
    }
  }

private:
    Node* rootNode;

    static bool empty(Node* n) {
        return n == nullptr;
    }

    static void printKeysInorder(Node* n) {
        if (n) {
            printKeysInorder(n->left);
            std::cerr << n->key << std::endl;
            printKeysInorder(n->right);
        }
    }

    static Node* search(Node* n, K k) {
        if (n == nullptr || n->key == k)
            return n;
        if (k < n->key)
            return search(n->left, k);
        else
            return search(n->right, k);
    }

    static Node* iterativeSearch(Node* n, K k) {
        while (n && k != n->key)
            if (k < n->key)
                n = n->left;
            else
                n = n->right;
        return n;
    }

    static Node* minimum(Node* n) {
        while (n->left)
            n = n->left;
        return n;
    }

    static Node* maximum(Node* n) {
        while (n->right)
            n = n->right;
        return n;
    }

    static Node* successor(Node* n)
    {
        if (n->right)
            return minimum(n->right);
        auto p = n->parent;
        while (p && n == p->right) {
            n = p;
            p = p->parent;
        }
        return p;
    }

    static void insert(BinarySearchTree& T, K k)
    {
        Node* p = nullptr;
        auto q = new Node(k);
        auto n = T.rootNode;

        while (n) {
            p = n;
            if (k < n->key)
                n = n->left;
            else
                n = n->right;
        }

        q->parent = p;

        if (p == nullptr)
            T.rootNode = q;
        else if (q->key < p->key)
            p->left = q;
        else
            p->right = q;
    }

    static void transplant(BinarySearchTree& T, Node* u, Node* v)
    {
        if (u->parent == nullptr)
            T.rootNode = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        if (v)
            v->parent = u->parent;
    }

    static void deleteNode(BinarySearchTree& T, Node* z)
    {
        if (z->left == nullptr)
            transplant(T, z, z->right);
        else if (z->right == nullptr)
            transplant(T, z, z->left);
        else {
            auto y = minimum(z->right);
            if (y->parent != z) {
                transplant(T, y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(T, z, y);
            y->left = z->left;
            y->left->parent = y;
        }
    }

    static void preOrderWalk(Node* z) {
        if (z) {
            std::cout << z->key << " ";
            preOrderWalk(z->left);
            preOrderWalk(z->right);
        }
    }

    static void postOrderWalk(Node* z) {
        if (z) {
            postOrderWalk(z->left);
            postOrderWalk(z->right);
            std::cout << z->key << " ";
        }
    }

  static void inOrderTree(Node* z) {
      ArrayStack<Node*> stack;
      Node* temp = root;
      while (temp != nullptr || !stack.empty()) {
          if (temp != nullptr) {
              stack.push(temp);
              temp = temp->left;
          }
          else {
               temp = stack.pop();
               stack.pop();
               std::cout << temp->data << " ";
               temp = temp->right;
              }
          return temp;
      }
  }
};

#endif // BST_HPP_INCLUDED