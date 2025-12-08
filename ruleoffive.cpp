#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
	private:
		std::vector<T> stack;
		int size = 0;
		
	public:
		// Stack(T[] st, int s) : stack{st}, size(s) {};
        Stack() : size(0) {};
        Stack(const std::vector<T>& vec) : stack(vec), size(vec.size()) {};
		
		void push(T item) { 
			stack.push_back(item); 
			++size;
		}
		void pop() { 
            if (size == 0) {
               std::cout << "stack is empty!" << std::endl; 
               return;
            }
			stack.pop_back(); 
			--size;
		}
		
		T peek() const { return stack.back(); }
		bool isEmpty() const { return size == 0; }
		int getSize() const { return size; }
		
		void print() const {
			for (auto item : stack)
				std::cout << item << ' ';
			
			std::cout << std::endl;
		}
};


int main() {
	// Test with integers
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    
    cout << "Int Stack:" << endl;
    intStack.print();
    cout << "Top: " << intStack.peek() << endl;
    intStack.pop();
    cout << "Popped" << endl;
    cout << "Size: " << intStack.getSize() << endl;
    intStack.print();
    
    cout << "\n";
    
    // Test with strings
    Stack<string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("!");
    
    cout << "String Stack:" << endl;
    stringStack.print();
    stringStack.pop();
    cout << "Popped" << endl;
    stringStack.print();
    
    // Test empty check
    cout << "\nIs int stack empty? " << (intStack.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}