#include <iostream> 

class Time {
    private:
        int hrs;
        int min;
        int sec;    
    public:
        Time() : hrs(0), min(0), sec(0) {}; // default constructor
        Time(int h, int m, int s) : hrs(h), min(m), sec(s) {} // params

        void print() const {
            std::cout << hrs << ':' << min << ':' << sec << std::endl;
        }

        static const int test = 5;
};

bool streq(const char* lhs, const char* rhs) {
    while (*lhs && *rhs) 
    {
        if (lhs == nullptr && rhs == nullptr) return true;
        if (lhs == nullptr || rhs == nullptr) return false;
        if (*lhs != *rhs) return false;
        lhs++;
        rhs++;
    }
    return true;
}

int main() {
    // Time time;
    // Time time2(5, 5, 5);

    // time.print();
    // time2.print();

    // Time timeArray[5] = {};
    // for (int i=0; i<5; ++i) 
    //     timeArray[i].print();

    char name[] = "robert";
    char last[] = "robert";

    char* nameptr = name;
    char* lastptr = last;

    std::cout << streq(nameptr, lastptr);
}