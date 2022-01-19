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
        next = 0;
    }

    bool hasNext() {
        return next != 0;
    }

/*
    bool hasPrev() {
        return prev != 0;
    }

    Node<T>* getNext()
    {
        return next;
    }

    Node<T>* getPrev()
    {
        return prev;
    }

    void setNext(Node<T>* _next)
    {
        next = _next;
    }

    void setPrev(Node<T>* _prev)
    {
        prev = _prev;
    }

    void setData(T data)
    {
        _data = data;
    }
*/

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
        return head == 0; 
    }

    Node<T>* add (T value) {
        Node<T>* newElement = new Node<T>(value, tail);
        if (size == 0) {
            head = newElement;
        } else {
            tail->next = newElement;
        }
        newElement->next = 0; // --
        tail = newElement;
        size++;
        return tail; // ?
    }

    Node<T>* addBefore (T value, int index) { 
        if (index < 0 || index > size - 1) throw "Index out of bounds"; 
        Node<T>* newElement = new Node<T>(value, 0);
        Node<T>* i = head;
        for (int n = 0; n < index; n++) i = i->next;
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

    Node<T>* addAfter (T value, int index) { 
        if (index < 0 || index > size - 1) throw "Index out of bounds"; 
        Node<T>* newElement = new Node<T>(value, 0);
        Node<T>* i = head;
        for (int n = 0; n < index; n++) i = i->next;
        newElement->prev = i;
        newElement->next = i->next;
        if (i == tail) {
            tail = newElement;
        } else {
            newElement->next->prev=newElement;
        }
        i->next = newElement;
        size++;
        return newElement;
    }

    T get (int index) { // index begins with 0 (but user sees in as 1)
        if (index < 0 || index > size - 1) throw "Index out of bounds"; 
        Node<T>* element = head;
        for (int i = 0; i < index; i++) element = element->next;
        return element->_data;
    }

    T edit (int index, T value) {
        if (index < 0 || index > size - 1) throw "Index out of bounds"; 
        Node<T>* element = head;
        for (int i = 0; i < index; i++) element = element->next;
        element->_data = value;
    }

    int getIndex (T value) {   
        Node<T>* element = head;
        int i = 0;
        while (element != 0) {
            if (element->_data == value) {
                return i;
            }
            element = element->next;
            i++;
        }
        return -1;
    }

    void remove (int index) { // search by index
        if (index < 0 || index > size - 1) {
            cout << "Out of index\n";
            return;
        }
        if (size == 1) {
            clear();
            return;
        }
        Node<T>* element = head;
        for (int i = 0; i < index; i++) element = element->next;        
        if (index == 0) {
            head = element->next;
            head->prev = 0;
        } else if (index == size - 1) {
            tail = element->prev;
            tail->next = 0;
        } else {
            element->prev->next = element->next;
            element->next->prev = element->prev;
        }
        delete element; // what if data is a pointer?
        size--;
        return;    
    }

    void clear() {
        Node<T>* current = head;
        Node<T>* next = 0;
        while (current != 0) {            
            next = current->next;
            // free(current);
            delete current;
            current = next;
        };        
        head = 0;        
        tail = head;
        size = 0;
    }

    unsigned int getSize() {
        return size;
    }
    
    void printAllElements() { // index begins from 1
        int k = 1;
        Node<T>* i = head;
        if (size != 0) {
            while (i != 0) {
                cout << k << ". " << i->_data << endl;
                i = i->next;
                k++;
            }
            cout << "\b\b";
        }
        else{
            cout << "Empty list" << endl;
        }
        cout << endl;
    }

// find by value (if operator == is in T)


    void swap (Node<T>* first, Node<T>* second) {
        T temp = first->_data;
        first->_data = second->_data;
        second->_data = temp;
    }

    void sort() {
        for (int i = 0; i < size; i++) {
            Node<T>* n = head->next;
            while (n != 0) {        
                if (n->_data < n->prev->_data) { // if operator < is in T
                    swap(n->prev, n);            
                    
                };
                n = n->next;
            }
        }
    }
};
