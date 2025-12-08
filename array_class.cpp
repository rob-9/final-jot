#include <iostream>

const int CAP = 100;
class array {
    public:
        array() : arr(new int[CAP]), cap(CAP), size(0) {} // default constructor with no params
        void addElement(int i) {
            if (size < cap) {
                arr[size++] = i;
            }
        }
        // array(int* a, int c, int s)
        //     : arr(a), cap(c), size(s) {} // constructor with params

        // ^^ shallow copy. when dealing with pointers, 
        // the newly constructed object points to the same memory.

        array(const array& otherArray); // copy constructor
        array& operator=(const array& otherArray); // overloaded copy assignment operator

        array(array&& otherArray) noexcept; // move constructor
        array& operator=(array&& otherArray) noexcept; // overloaded move assignment operator

        ~array() { delete[] arr; } // destructor

        int getSize() { return size; }
        void print() {
            for (int i=0; i<size; ++i) {
                std::cout << arr[i] << std::endl;
            }
        }

    private:
        int *arr; // points to array of integers on heap
        int cap; // capacity
        int size; // current size
};

array::array(const array& otherArray) {
    cap = otherArray.cap;
    size = otherArray.size;
    arr = new int[cap];
    for (int i=0; i<size; ++i) {
        arr[i] = otherArray.arr[i];
    }
};

array& array::operator=(const array& otherArray) {
    if (&otherArray != this) {
        if (cap != otherArray.cap) {
            delete[] arr; // deallocate a;
            arr = new int[otherArray.cap];
            cap = otherArray.cap;
        }
        for (int i=0; i<otherArray.size; ++i) {
            arr[i] = otherArray.arr[i];
        }
        size = otherArray.size;
    } else {
        std::cerr << "can't assign to self.";
    }
    return *this;
    // overloaded copy assignment operator: returns pointer to itself (*this), (&type)
}

array::array(array&& otherArray) noexcept
    : arr(otherArray.arr), cap(otherArray.cap), size(otherArray.size) {
    // steal the resources from otherArray
    otherArray.arr = nullptr;
    otherArray.cap = 0;
    otherArray.size = 0;
}

array& array::operator=(array&& otherArray) noexcept {
    if (this != &otherArray) {
        delete[] arr;  // free existing resources

        // steal resources from otherArray
        arr = otherArray.arr;
        cap = otherArray.cap;
        size = otherArray.size;

        // leave otherArray in valid but empty state
        otherArray.arr = nullptr;
        otherArray.cap = 0;
        otherArray.size = 0;
    }
    return *this;
}


int main() {
    // test copy constructor
    array arr1;
    for (int i = 0; i < 5; ++i)
        arr1.addElement(i);

    array arr2(arr1);  // calls copy constructor
    std::cout << "Copy constructor test:\n";
    arr2.print();

    // test copy assignment operator
    array arr3;
    arr3 = arr1;  // calls copy assignment operator
    std::cout << "\nCopy assignment test:\n";
    arr3.print();

    // test move constructor
    array arr4(std::move(arr1));  // calls move constructor
    std::cout << "\nMove constructor test:\n";
    arr4.print();
    std::cout << "arr1 size after move: " << arr1.getSize() << "\n";  // should be 0

    // test move assignment operator
    array arr5;
    arr5 = std::move(arr2);  // calls move assignment operator
    std::cout << "\nMove assignment test:\n";
    arr5.print();
    std::cout << "arr2 size after move: " << arr2.getSize() << "\n";  // should be 0

    return 0;
}




// prototypes
// destructor - class::~class() {}
// copy constructor - class:class(const class& other)
// overloaded copy assignment operator - class& class::operator=(const class& other)
// move constructor - 
// overloaded move assignment operator - 