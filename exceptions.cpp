// string exceptions
#include <iostream>
#include <vector>


// custom exception
class divByZero{
	public:
		divByZero() : message("Division by zero") {}
		divByZero(std::string str) : message(str) {}
		std::string what() { return message; }
	
	private:
		std::string message;
};

int main() {
	std::string sentence, str1;
	try {
		sentence = "Testing string exceptions.";
		str1 = sentence.substr(28, 10); // out of range
		std::cout << "this will not print";
	}
	catch (std::out_of_range re) {
		std::cout << "in the out of range: " << re.what() << std::endl;
	}
    int *list[100];
	try {
		list[0] = new int[1000000000000000]; // too much
		std::cout << "this wont print";
	}
	catch (std::bad_alloc be) {
		std::cout << "in the bad alloc: " << be.what() << std::endl;	
	}
	

    int num, den, quo;
	try {
        std::cin >> num >> den;
		if (den == 0) throw divByZero();
	}
	catch(divByZero dbz) {
		std::cout << "in err: " << dbz.what() << std::endl;
	}
	return 0;
}




// composition
class X
{
    public:
        void start() { std::cout << "starting"; }
};

class Y
{
    X x;
};

// aggregation
class Student 
{
    std::string name;
    public:
        Student(std::string n) : name(n) {}
        std::string getName() const { return name; }
};

class Classroom 
{
    std::vector<Student*> students; // reference / pointer to external
    Student& studentRef;

    public:
        Classroom(Student& s) : studentRef(s) {}

        void addStudent(Student* s)
        {
            students.push_back(s);
        }
        void listStudents()
        {
            for (auto* s : students) {
                std::cout << s->getName() << "\n";
            }
        }

        ~Classroom() {}
};