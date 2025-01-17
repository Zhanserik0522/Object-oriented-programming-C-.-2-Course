﻿#include <iostream>
#include <string>
#include <utility> // for std::pair

using namespace std;

template<typename T>
class RBT {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node* parent;
        char color;

        Node(const T& data) : data(data), parent(nullptr), left(nullptr), right(nullptr), color('R') {}
    };

    Node* root;
    bool RR;
    bool rRotation;
    bool lRotation;
    bool rlRotation;
    bool lrRotation;

    Node* rightRotation(Node* node) {
        Node* x = node->left;
        Node* beta = x->right;

        x->right = node;
        node->left = beta;

        node->parent = x;
        if (beta != nullptr)
            beta->parent = node;

        return x;
    }

    Node* leftRotation(Node* node) {
        Node* x = node->right;
        Node* beta = x->left;

        x->left = node;
        node->right = beta;

        node->parent = x;
        if (beta != nullptr)
            beta->parent = node;

        return x;
    }

    Node* insert(const T& data, Node* node) {
        if (node == nullptr) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insert(data, node->left);
            node->left->parent = node;
            if (node != root) {
                if (node->color == 'R' && node->left->color == 'R')
                    RR = true;
            }
        }
        else if (data > node->data) {
            node->right = insert(data, node->right);
            node->right->parent = node;
            if (node != root) {
                if (node->color == 'R' && node->right->color == 'R')
                    RR = true;
            }
        }

        if (rRotation) {
            node = rightRotation(node);
            node->color = 'B';
            node->left->color = 'R';
            rRotation = false;
        }
        else if (lRotation) {
            node = leftRotation(node);
            node->color = 'B';
            node->right->color = 'R';
            lRotation = false;
        }
        else if (lrRotation) {
            node = leftRotation(node);
            node->left->parent = node;
            node = rightRotation(node);
            node->color = 'B';
            node->left->color = 'R';
            lrRotation = false;
        }
        else if (rlRotation) {
            node = rightRotation(node);
            node->right->parent = node;
            node = leftRotation(node);
            node->color = 'B';
            node->left->color = 'R';
            rlRotation = false;
        }

        if (RR) {
            if (node->parent->right == node) {
                if (node->parent->left == nullptr || node->parent->left->color == 'B') {
                    if (node->left != nullptr && node->left->color == 'R')
                        this->rlRotation = true;
                    else if (node->right != nullptr && node->right->color == 'R')
                        this->lRotation = true;
                }
                else {
                    node->parent->left->color = 'B';
                    node->color = 'B';
                    if (node->parent != this->root)
                        node->parent->color = 'R';
                }
            }
            else {
                if (node->parent->right == nullptr || node->parent->right->color == 'B') {
                    if (node->left != nullptr && node->left->color == 'R')
                        this->rRotation = true;
                    else if (node->right != nullptr && node->right->color == 'R')
                        this->lrRotation = true;
                }
                else {
                    node->parent->right->color = 'B';
                    node->color = 'B';
                    if (node->parent != this->root)
                        node->parent->color = 'R';
                }
            }
        }
        return node;
    }

public:
    RBT() : root(nullptr), RR(false), rRotation(false), lRotation(false), rlRotation(false), lrRotation(false) {}

    void insert(const T& data) {
        if (root == nullptr) {
            root = new Node(data);
            root->color = 'B';
            return;
        }
        root = insert(data, root);
    }
};


template<typename T>
class TreeSet {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(const T& data, Node* node) {
        if (node == nullptr) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insert(data, node->left);
        }
        else if (data > node->data) {
            node->right = insert(data, node->right);
        }

        return node;
    }

    bool contains(const T& data, Node* node) {
        if (node == nullptr) {
            return false;
        }

        if (data == node->data) {
            return true;
        }
        else if (data < node->data) {
            return contains(data, node->left);
        }
        else {
            return contains(data, node->right);
        }
    }

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    TreeSet() : root(nullptr) {}

    void add(const T& element) {
        root = insert(element, root);
    }

    bool contains(const T& element) {
        return contains(element, root);
    }

    void clear() {
        clear(root);
        root = nullptr;
    }
};

template<typename K, typename V>
class TreeMap {
private:
    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;

        Node(const K& key, const V& value) : key(key), value(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(const K& key, const V& value, Node* node) {
        if (node == nullptr) {
            return new Node(key, value);
        }

        if (key < node->key) {
            node->left = insert(key, value, node->left);
        }
        else if (key > node->key) {
            node->right = insert(key, value, node->right);
        }
        else {
            node->value = value; // Update value if key already exists
        }

        return node;
    }

    V* get(const K& key, Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key == node->key) {
            return &node->value;
        }
        else if (key < node->key) {
            return get(key, node->left);
        }
        else {
            return get(key, node->right);
        }
    }

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    TreeMap() : root(nullptr) {}

    void add(const K& key, const V& value) {
        root = insert(key, value, root);
    }

    V* get(const K& key) {
        return get(key, root);
    }

    void clear() {
        clear(root);
        root = nullptr;
    }
};

int main() {
    TreeSet<int> treeSet;
    treeSet.add(5);
    treeSet.add(3);
    treeSet.add(7);
    cout << "Contains";
    return 0;
}