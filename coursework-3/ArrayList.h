#pragma once
using namespace std;

template <typename T> class ArrayList {

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

    // void add(T &arg, unsigned int index) {
    //     if (index >= 0 && index <= size) {
    //         if (index == size) {
    //             add(arg);
    //         }
    //         else {
    //             array[index] = &arg;
    //         }
    //     }
    //     else {
    //         throw "IndexOutOfBoundException";
    //     }
    // };

    // void remove(unsigned int index) { //remove element from specific position
    //     if (index >= 0 && index < size) {
    //         for (int i = index; i < size - 1; i++) {
    //             array[i] = array[i + 1];
    //         }
    //         size--;
    //     }
    //     else {
    //         throw "IndexOutOfBoundException";
    //     }
    // };

    void clear() {
        for (int i = 0; i < size; i++) {
            array[i] = NULL;
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

    unsigned int getIndex(T arg) { 
        unsigned int index = 0;
        while (arg != array[index] && index < size) {
            index++;
        }
        if (index == size) {
            throw "ArgumentNotFoundException";
        }
        return index;
    };

    unsigned int getSize() { //return size of list
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