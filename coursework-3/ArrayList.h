#pragma once
using namespace std;

template <typename T> struct ArrayList {

public:
    ArrayList() {
        array = new T[16];
        arraySize = 16;
        size = 0;
    };

    int add(T arg) {
        if (size == arraySize) {
            increase();
        }
        array[size] = arg;
        size++;
        return size - 1;
    };

    void replace(T arg, unsigned int index) {
        if (index >= 0 && index < size) {            
            array[index] = arg;                
        }
        else {
            throw "IndexOutOfBoundException";
        }
    };

    void insert(T arg, unsigned int index) {
        if (index >= 0 && index <= size) {
            if (index == size) {
                add(arg);
            }
            else { 
                if (size == arraySize) {
                    increase();            
                }
                for (int i = size; i > index; i--) {
                    array[i] = array[i - 1];
                }
                array[index] = arg;
            }
            size++;
        } else {
            throw "IndexOutOfBoundException";
        }
    };

    void remove(unsigned int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                array[i] = array[i + 1];
            }
            delete &array[size - 1];
            size--;
        } 
        else {
            throw "IndexOutOfBoundException";
        }
    };

    void clear() { // why not delete all empty elements?
        delete[] array;
        size = 0;
        arraySize = 0;
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

    T *getPointer(unsigned int index) {
        if (index >= 0 && index < size) {
            return &array[index];
        } else {
            throw "IndexOutOfBoundException";
        }
    }

    void sort() {
        for (int i = 1; i < size; i++) {
            for (int n = 1; n <= size - i; n++) {                
                if (array[n] < array[n - 1]) {                
                    T temp = array[n];
                    array[n] = array[n - 1];
                    array[n - 1] = temp;
                }             
            }        
        }
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