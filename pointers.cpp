#include <iostream>

int sum(int *A[], int r) {
    int sum = 0;
    for (int j = 0; j < r; ++j) {
        for (int k=0; k < 8; ++k) {
            std::cout << A[j][k];
            sum += A[j][k];
                // or *(d[k] + k)
        }
        std::cout << std::endl;
    }
    return sum;
}
int main() {
    int *d[5], s;
    for (int i=0; i<5; ++i)
        d[i] = new int[8];
    for (int j=0; j<5; ++j)
        for (int k=0; k<8; ++k)
            *(d[j] + k) = j + k;
    s = sum(d, 5);
    
    for (int i=0; i<5; ++i)
        delete d[i];
    
    std::cout << s << std::endl;
    return 0;
}