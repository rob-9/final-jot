#include <iostream>

// //template
// template <typename T> T maximum(T x, T y)
// {
//     if (x>=y) return x;
//     return y;
// };

template<typename T1, typename T2> auto maximum(T1 a, T2 b) {
    return b < a ? a : b;
};

int main() 
{
    std::cout << maximum(5, 6) << std::endl;
    std::cout << maximum(5.5, 6.5) << std::endl;
    std::cout << maximum('A', 'B') << std::endl;

    std::cout << maximum("aa", "a") << std::endl;
}