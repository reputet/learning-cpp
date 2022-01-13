#pragma once
#include <iostream>
using namespace std;

template <typename T> struct Node {

    T _data;
    Node<T>* next;
    Node<T>* prev;

    Node(T data, Node<T>* tail) {
        _data = data;
        prev = tail;
    }

    bool hasNext() {
        return next != 0;
    }

    T get() {
        return _data;
    }

};

template <typename T> struct LinkedList {
private:
    unsigned int size;

public:
    Node<T>* head;
    Node<T>* tail;
    LinkedList() {
        size = 0;
        head = 0;
        tail = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    Node<T>* add (T value) {
        Node<T>* newElement = new Node<T>(value, tail);
        if (size == 0) {
            head = newElement;
        } else {
            tail->next = newElement;
        }
        tail = newElement;
        size++;
        return tail;
    }

    T get (int index) {
        if (index > size - 1) throw "Index out of bounds";
        Node<T>* element = head;
        for (int i = 0; i < index; i++) element = element->next;
        return element->_data;
    }

    Node<T>* addBefore (T value, T searchedValue) {
        Node<T>* newElement = new Node<T>(value, 0);
        Node<T>* i = head;
        while (i != 0) {
            if (i->_data == searchedValue) {
                newElement->prev = i->prev;
                newElement->next = i;
                if (i == head) {
                    head = newElement;
                } else {
                i->prev->next=newElement;
                }
                i->prev = newElement;
                size++;
                return newElement;
            }
            i = i->next;
        }
        throw "Searched element not found";        
    }

    Node<T>* addAfter (T value, T searchedValue) {
        Node<T>* newElement = new Node<T>(value, 0);
        Node<T>* i = head;
        while (i != 0) {
            if (i->_data == searchedValue) {
                newElement->prev = i;
                newElement->next = i->next;
                if (i == tail) {
                    tail = newElement;
                } else {
                i->next->prev=newElement;
                }
                i->next = newElement;
                size++;
                return newElement;
            }
            i = i->next;
        }
        throw "Searched element not found";        
    }

    void remove (T value) {
        Node<T>* i = head;
        while (i != 0) {
            cout << i->_data << " data" << endl;
            if (i->_data == value) {
                if (i == head) {
                    head = i->next;
                    head->prev = 0;
                } else if (i == tail) {
                    tail = i->prev;
                    tail->next = 0;
                } else {
                    i->prev->next = i->next;
                    i->next->prev = i->prev;
                }
                delete i;                
                size--;
                return;
            }
            i = i->next;
        }
        throw "No such element";        
    }

    void clear() {
        Node<T>* current = head;
        Node<T>* next = 0;
        while (current != 0) {            
            next = current->next;
            free(current);
            current = next;
        };        
        head = 0;        
        tail = head;
        size = 0;
    }

    unsigned int getSize() {
        return size;
    }
    
    void printAllElements() {
        cout << "[";
        Node<T>* i = head;
        if (size != 0) {
            while (i != 0) {
                cout << i->_data << ", ";
                i = i->next;
            }
            cout << "\b\b";
        }
        cout << "]";
    }
    void swap (Node<T>* first, Node<T>* second) {
        T temp = first->_data;
        first->_data = second->_data;
        second->_data = temp;
    }

    void sort() {
        for (int i = 0; i < size; i++) {
            Node<T>* n = head;
            while (n != tail) {        
                n = n->next;
                if (n->_data < n->prev->_data) {
                    swap(n->prev, n);            
                };
            }
        }
    }
};
