#include <iostream>

using namespace std;

template <typename  T, typename K>
class TreeMap {
private:
    class Node {
    public:
        T data;
        K key;
        char color;
        Node* left;
        Node* right;
        Node* parent;

        Node(K key, T data) : key(key), data(data) {
            left = right = parent = nullptr;
            color = 'R';
        }


    };
    Node* root;
    bool RR = false;
    bool lrRotation = false;
    bool rlRotation = false;
    bool lRotation = false;
    bool rRotation = false;

    Node* leftRotation(Node* node) {
        Node* y = node->right;
        Node* betta = y->left;

        y->left = node;
        node->right = betta;

        if (betta)
            betta->parent = node;
        node->parent = y;

        return y;
    }

    Node* rightRotation(Node* node) {
        Node* y = node->left;
        Node* betta = y->right;

        y->right = node;
        node->left = betta;

        if (betta)
            betta->parent = node;
        node->parent = y;
        
        return y;
    }
    
    Node* insert(K key, T data, Node* node) {
        if (node == nullptr)
            return new Node(key, data);


        if (key < node->key) {
            node->left = insert(key, data, node->left);
            node->left->parent = node;
            if (node != root) {
                if (node->left && node->left->color == 'R' && node->color == 'R')
                    RR = true;
            }
        }
        else {
            node->right = insert(key, data, node->right);
            node->right->parent = node;
            if (node != root) {
                if (node->right && node->right->color == 'R' && node->color == 'R')
                    RR = true;
            }
        }

        if (lrRotation) { 

            node->left = leftRotation(node->left);
            node->left->parent = node;

            node = rightRotation(node);

           
            node->color = 'B';
       
            node->parent->color = 'R';
       
            lrRotation = false;
        }

        if (rlRotation) {  
            node->right = rightRotation(node->right);
            node->right->parent = node;
            node = leftRotation(node);

         
            node->color = 'B';
          
            node->parent->color = 'R';
          
            rlRotation = false;
        }

        if (lRotation) { 
            node = leftRotation(node);
            node->color = 'B';
          
            node->parent->color = 'R';
            lRotation = false;
        }

        if (rRotation) {

            node = rightRotation(node);

            node->color = 'B';
          
            node->parent->color = 'R';
            rRotation = false;
        }

        
        if (RR) {
            if (node->parent->right == node) {
                if (node->parent->left == nullptr || node->parent->left->color == 'B') { 
                    if (node->left && node->left->color == 'R' && node->color == 'R') {
                        rlRotation = true;
                    }
                    else if (node->right && node->right->color == 'R' && node->color == 'R') {
                     
                        lRotation = true;
                    }
                }
                else { 
                   
                    node->color = 'B';
                    node->parent->left->color = 'B';
                    if (node->parent != root)
                        node->parent->color = 'R';
                }
            }

            else {
                if (node->parent->right == nullptr || node->parent->right->color == 'B') {

                    if (node->right && node->right->color == 'R' && node->color == 'R' && node) {
                      
                        lrRotation = true;
                    }
                    else if (node->left && node->left->color == 'R' && node->color == 'R' && node) {
                        rRotation = true;
                    }
                }
                else {
                 
                    node->color = 'B';
                    node->parent->right->color = 'B';
                    if (node->parent != root)
                        node->parent->color = 'R';
                }
            }
            RR = false;
        }
        return node;

    }

    static void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->key << " " << node->data << " " << "color:" << node->color << endl;
        inorder(node->right);
    }

    Node* search(const K& key) const {
        auto current = root;
        while (current) {
            if (key == current->key) {
                return current;
            }
            else if (key < current->key) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return nullptr;
    }

public:
    TreeMap() {
        root = nullptr;
    }

    void insert(K key, T data) {
        root = insert(key, data, root);
        root->color = 'B';
    }

    T get(const K& key) const {
        auto node = search(key);
        if (node)
            return node->data;
        else
            return T();  
    }


    friend ostream& operator<<(ostream& os, const TreeMap& map) {
        os << "root: " << map.root->key << " " << map.root->data << endl;
        os << "items:" << endl;
        inorder(map.root);
        return os;
    }

    T& operator[](const K& key) {
        Node* currentNode = root;
        while (currentNode != nullptr) {
           
            if (key < currentNode->key) {
                currentNode = currentNode->left;
            }
            else if (key > currentNode->key) {
                currentNode = currentNode->right;
            }
            else {
                return currentNode->data;
            }
        }
    }
};


template <typename K>
class TreeSet {
private:
    TreeMap<char, K> treeMap;

public:

    void add(const K& key) {
        treeMap.insert(key, ' ');
    }

    bool get(const K& key) const {
        return treeMap.get(key) != ' ';
    }


    bool operator[](const K& key) const {
        return get(key);
    }


    friend ostream& operator<<(ostream& os, const TreeSet& set) {
        os << "items:" << endl;
        os << set.treeMap;
        return os;
    }
};


int main() {
    TreeSet<int> treeSet;
    treeSet.add(5);
    treeSet.add(3);
    treeSet.add(7);
    return 0;
}