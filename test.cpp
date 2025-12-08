class DArray {
private:
    int* data;
    int size;
public:
    DArray(int s) : size(s) {
        data = new int[size];
    }

    DArray(const DArray& other) : size(other.size) {
        data = new int[size];
        for (int i=0; i<size; ++i)
            data[i] = other.data[i];
    }
    
    ~DArray() {
        delete[] data;
    }
};

int main() {
    DArray arr1(10);
    DArray arr2 = arr1;  // What happens here?
    // When main ends, what happens?
}