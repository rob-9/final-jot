#include <iostream>
using namespace std;


class Foo {
    private:
        int* p;
        int size;
    
    public:
        Foo(int s) {
            size = s;
            p = new int[size];
        }

        ~Foo() { delete[] p; }

        void set(int index, int val) { p[index] = val; }
        int getSize() const { return size; }
        int get(int index) const { return p[index]; }
        
        // bypass the default memberwise assignment
        Foo& operator=(const Foo& rhs) {
            delete[] p;
            p = new int[size];

            for (int i=0; i<size; ++i) {
                p[i] = rhs.p[i];
            }

            return *this;
        }
};

// i++ (return the value and then increment)
// ++i (increment the value and then return)


class Integer {
    private:
        int i;
    
    public:
        Integer(int x = 0): i(x) { }

        // accessor
        int get() const { return i; }

        // postfix
        Integer operator++();    // prefix
        Integer operator++(int); // postfix
        Integer& operator--();    // prefix
        Integer operator--(int); // postfix
};

Integer Integer::operator++() {
    ++i;
    return *this;
}

Integer Integer::operator++(int) {
    Integer tmp = *this;
    ++i;
    return tmp;
}

Integer& Integer::operator--() {
    --i;
    return *this;
}

Integer Integer::operator--(int) {
    Integer tmp = *this;
    --i;
    return tmp;
}

void PrintName(const std::string& name)
{
    std::cout << name << std::endl;
}

void PrintName(std::string&& name)
{
    std::cout << "rvalue: " << name << std::endl;
}


int main() {
    std::string first = "Robert ";
    std::string last = "Ji";

    std::string full = first + last;

    PrintName(full); // full is an lvalue
    PrintName(first + last); // first+last is an rvalue

    // accept both with const lvalue reference

    /*
    also cant have ambiguity in references. for example, for lvalue references,
    if we have void PrintName(std::string name) and voidPrintName(std::string& name)
    then the code will NOT compile.
    */

    Foo f(5), g(6);

    for (int i=0; i<g.getSize(); ++i) {
        g.set(i, i*i);
    }

    f = g; // f.operator = (g);

    for (int i=0; i<f.getSize(); ++i) {
        cout << f.get(i) << ' ';
    }

    cout << endl;

    Foo a(5), b(7), c(8);

    // f = g = h is illegal, since return type of g=h is void -> f.operator=(void)
    // solution: change return type to Foo

    a = b = c;

    Integer i(5);
    i++;
    cout << i.get() << endl;

    return 0;
}