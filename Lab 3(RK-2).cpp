#include<iostream>
using namespace std;
template<typename T> class DoubleLinkedList {
    class Node {
    public:
        T value;
        Node* next;
        Node* prev;
        Node(T value, Node* next, Node* prev) : value(value), next(next), prev(prev) {}
    };
    int size;
    Node* head;
    Node* tail;
public:
    DoubleLinkedList() {
        size = 0;
        head = tail = nullptr;
    }
    void push_back(T data) {
        if (head == nullptr) {
            head = new Node(data, nullptr, nullptr);
            tail = head;
        }
        else {
            Node* temp = new Node(data, nullptr, tail);
            tail->next = temp;
            tail = tail->next;
        }
        size++;
    }
    void push_front(T data) {
        if (head == nullptr) {
            head = new Node(data, nullptr, nullptr);
            tail = head;
        }
        else {
            Node* temp = new Node(data, head, nullptr);
            head->prev = temp;
            head = head->prev;
        }
        size++;
    }
    void pop_back() {
        if (size == 1) {
            delete head;
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        size--;
    }
    void pop_front() {
        if (size == 1) {
            delete head;
            head = tail = nullptr;
        }
        else {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        size--;
    }
    int length() {
        return size;
    }
    T operator [] (int index) {
        if (size / 2 >= index) {
            Node* cur = head;
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
            return cur->value;
        }
        else {
            Node* cur = tail;
            for (int i = size - 1; i > index; i--) {
                cur = cur->prev;
            }
            return cur->value;
        }
    }

    void remove(int index) {
        if (index == 0) {
           pop_front();
           size--;
           return;
        }

        if (index == size - 1) {
            pop_back();
             size--;
             return;
        }

        if (size / 2 >= index) {
            int counter = 0;
            Node* current = head;
            Node* previous = nullptr;

            while (counter < index) {
                previous = current;
                current = current->next;
                counter++;
            }
            previous->next = current->next;
            delete current;
            current = nullptr;
            size--;
        }
        else {
            int counter = size - 1;
            Node* current = tail;
            Node* previous = nullptr;

            while (counter > index) {
                previous = current;
                current = current->prev;
                counter--;
            }
            previous->prev = current->prev;
            delete current;
            current = nullptr;

            size--;
        }
        // delete element on index position
    }
    void add(T data, int index) {
        Node* newNode = new Node(data, nullptr, nullptr);
       

        if (index == 0) {
            push_front(data);
            return;

        }

        if ( index == size - 1) {
            push_back(data);
            return;
        }

        if(size / 2  >= index) {
            int counter = 0;
            Node* current = head;
            Node* previous = nullptr;

            while (counter < index) {
                previous = current;
                current = current->next;
                counter++;
            }
            newNode->next = current;
            previous->next = newNode;

            size++;
        }
        else {

            int counter = size - 1;
            Node* current = tail;
            Node* nextNode = nullptr;


            while (counter > index) {
                nextNode = current;
                current = current->prev;
                counter--;
            }
            newNode->next = nextNode;
            newNode->prev = current;
            current->next = newNode;
            nextNode->prev = newNode;

            
        }
        size++;
    }

    void set(T data, int index) {
        if (size / 2 > index) {
            int counter = 0;
            Node* current = head;
            Node* previous = nullptr;
            while (counter < index) {
                previous = current;
                current = current->next;
                counter++;
            }

            current->value = data;
        }
        else {
            int counter = size - 1;
            Node* current = tail;
            Node* nextNode = nullptr;
            while (counter > index) {
                nextNode = current;
                current = current->prev;
                counter--;
            }

            current->value = data;

        }
    }

    bool operator == (DoubleLinkedList<T>& another) {
        if (size != another.size) {
            return false;
        }
        Node* cur = head;
        Node* cur1 = another.head;
        while (cur->next != nullptr) {
            if (cur->value != cur1->value) {
                return false;
            }
            cur = cur->next;
            cur1 = cur1->next;
        }
        return true;
        
    }
    bool operator != (DoubleLinkedList<T>& another) {
        return !(another == *this);
    }
    ~DoubleLinkedList() {
        while (size != 0)
            pop_back();
    }
};


int main() {
    DoubleLinkedList<int> list;
    DoubleLinkedList<int> list1;
    for (int i = 0; i < 100; i++) {
        list.push_back(i);
        list1.push_back(i);
    }
    if (list == list1) {
        cout << " They are equal" << endl;
    }
    else {
        cout << " They are not equal" << endl;
    }
    return 0;
}
// DLL:
// front, back: O(1);
// remove, add, get, []: O(n)
