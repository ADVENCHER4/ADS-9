// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
#include <string>
template<typename T>
struct Node {
    T key;
    int count;
    Node* left, * right;
    explicit Node(T k): key(k), count(1), left(nullptr), right(nullptr) {}
};
template<typename T>
class BST {
 private:
     Node<T>* root;
     int getHeight(Node<T>* p) {
         if (p == nullptr)
             return 0;
         int hr = getHeight(p->right);
         int hl = getHeight(p->left);
         return std::max(hr, hl) + 1;
     }
     Node<T>* insert(Node<T>* p, T k) {
         if (p == nullptr) {
             p = new Node<T>(k);
         } else if (p->key > k) {
             p->left = insert(p->left, k);
         } else if (p->key < k) {
             p->right = insert(p->right, k);
         } else {
             p->count++;
         }
         return p;
     }
     int findVal(Node<T>* p, T k) {
         if (p->key == k)
             return p->count;
         else if (p->key > k)
             return findVal(p->left, k);
         else if (p->key < k)
             return findVal(p->right, k);
         else
             return 0;
     }
     void deleteTree(Node<T>* p) {
         if (p == nullptr)
             return;
         deleteTree(p->right);
         deleteTree(p->left);
         delete p;
         p = nullptr;
     }

 public:
     BST() : root(nullptr) {}
     void insert(T k) {
         root = insert(root, k);
     }
     int depth() {
         return getHeight(root) - 1;
     }
     int search(T k) {
         return findVal(root, k);
     }
     ~BST() {
         deleteTree(root);
     }
};
#endif  // INCLUDE_BST_H_
