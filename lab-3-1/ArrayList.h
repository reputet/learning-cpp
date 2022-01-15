#pragma once
#include <iostream>
using namespace std;

template <typename T> struct ArrayList {

public:
    ArrayList() {
        array = new T[16];
        arraySize = 16;
        size = 0;
    };

    void add(T arg) {
        if (size == arraySize) {
            increase();
        }
        array[size] = arg;
        size++;
    };

    void add(T arg, unsigned int index) {
        if (index >= 0 && index <= size) {
            if (index == size) {
                add(arg);
            }
            else {
                array[index] = arg;
            }
        }
        else {
            throw "IndexOutOfBoundException";
        }
    };

    void remove(unsigned int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                array[i] = array[i + 1];
            }
            size--;
        }
        else {
            throw "IndexOutOfBoundException";
        }
    };

    void clear() {
        for (int i = 0; i < size; i++) {
            array[i] = 0;
        }
        size = 0;
    };

    T get(unsigned int index) { 
        if (index >= 0 && index < size) {
            return array[index];
        }
        else {
            throw "IndexOutOfBoundException";
        }
    };

    int getIndex(T arg) { 
        unsigned int index = 0;
        while (index < size && arg != array[index]) {
            index++;
        }
        if (index == size) {        
            return -1;
        }
        return index;
    };

    unsigned int getSize() { 
        return size;
    };

    bool isEmpty() {
        return size == 0;
    };

    T *begin() {
        return &array[0];
    }
    T  *end() {
        return &array[size];
    }

private:
    unsigned int arraySize;
    unsigned int size;
    T* array;

    void increase() { 
        if (arraySize + 16 <= LONG_MAX) {
            T* newArray = new T[arraySize + 16];
            for (unsigned int i = 0; i < arraySize; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
            arraySize += 16;
        }
        else {
            throw "ArraySizeOutOfBoundException";
        }
    };
};