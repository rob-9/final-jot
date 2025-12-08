#include <iostream>
#include "string.h"



namespace A
{
    std::string func() { return "A"; }
}
namespace B
{
    using A::func;
    std::string func(int x) { return "B"; }
}

using namespace B;
int main() 
{
    std::cout << func(5) << std::endl;
    return 0;
}

