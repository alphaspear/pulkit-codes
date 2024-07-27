#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    int size;
    int top;
    T* arr;

public:
    // Constructor
    Stack(int size) {
        this->size = size;
        arr = new T[size]; // Dynamically allocate memory for the array
        top = -1; // Initialize top to -1 to indicate the stack is empty
    }

    // Destructor
    ~Stack() {
        delete[] arr; // Deallocate memory to prevent memory leak
    }

    int get_size() const {
        return size;
    }

    bool is_empty() const {
        return top == -1;
    }

    bool is_full() const {
        return top == size - 1;
    }

    void push(const T& item) {
        if (is_full()) {
            throw std::overflow_error("Stack overflow");
        }
        arr[++top] = item;
    }

    T pop() {
        if (is_empty()) {
            throw std::underflow_error("Stack underflow");
        }
        return arr[top--];
    }

    T peek() const {
        if (is_empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[top];
    }
};

int main() {
    try {
        Stack<int> intStack(5);
        intStack.push(1);
        intStack.push(2);
        intStack.push(3);

        std::cout << "Top element: " << intStack.peek() << std::endl;
        std::cout << "Stack size: " << intStack.get_size() << std::endl;
        std::cout << "Is stack empty? " << (intStack.is_empty() ? "Yes" : "No") << std::endl;
        std::cout << "Is stack full? " << (intStack.is_full() ? "Yes" : "No") << std::endl;

        std::cout << "Popping elements: ";
        while (!intStack.is_empty()) {
            std::cout << intStack.pop() << " ";
        }
        std::cout << std::endl;

        // Example with a different type
        Stack<std::string> stringStack(3);
        stringStack.push("Hello");
        stringStack.push("World");
        stringStack.push("World");
        stringStack.push("World");
        stringStack.push("World");
        stringStack.push("World");
        stringStack.push("World");
        stringStack.push("World");
        stringStack.push("World");
        

        std::cout << "Top element: " << stringStack.peek() << std::endl;

        std::cout << "Popping elements: ";
        while (!stringStack.is_empty()) {
            std::cout << stringStack.pop() << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
