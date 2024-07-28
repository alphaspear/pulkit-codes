#include <iostream>
#include <string>

template <typename T>
class finite_queue {
public:
    // Constructor to create queue object of a given capacity
    queue(int queue_size) {
        this->queue_size = queue_size;
        queue_array = new T[queue_size];
        front = -1;
        rear = -1;
    }

    // Destructor to free memory when exit
    ~queue() {
        delete[] queue_array;
    }

    // Function to get queue size
    int get_size() {
        return queue_size;
    }

    // Function to print queue content
    void print_queue() {
        if (is_empty()) {
            std::cout << "QUEUE IS EMPTY" << std::endl;
            return;
        }

        std::cout << "QUEUE CONTENT: ";
        for (int i = front; i != rear; i = (i + 1) % queue_size) {
            std::cout << queue_array[i] << " ";
        }
        std::cout << queue_array[rear] << std::endl;
    }

    // Function to remove the first value from queue
    void dequeue() {
        if (is_empty()) {
            std::cout << "QUEUE UNDERFLOW" << std::endl;
            return;
        }
        if (front == rear) {
            front = rear = -1; // Reset queue when it becomes empty
        } else {
            front = (front + 1) % queue_size;
        }
    }

    // Function to add value to queue
    void enqueue(const T& data) {
        if (is_full()) {
            std::cout << "QUEUE OVERFLOW" << std::endl;
            return;
        }
        if (is_empty()) {
            front = 0;
        }
        rear = (rear + 1) % queue_size;
        queue_array[rear] = data;
    }

    // Function to print front data in queue
    void peek() {
        if (is_empty()) {
            std::cout << "QUEUE IS EMPTY" << std::endl;
            return;
        }
        std::cout << "FRONT ELEMENT: " << queue_array[front] << std::endl;
    }

private:
    int queue_size;
    T* queue_array;
    int front, rear;

    bool is_empty() const {
        return front == -1;
    }

    bool is_full() const {
        return (rear + 1) % queue_size == front;
    }
};

// Driver Code
int main() {
    queue<int> int_queue(3);
    int_queue.print_queue();
    int_queue.dequeue();
    int_queue.enqueue(1);
    int_queue.enqueue(2);
    int_queue.enqueue(3);
    int_queue.enqueue(4); // This should indicate overflow
    int_queue.print_queue();
    int_queue.peek();
    int_queue.dequeue();
    int_queue.print_queue();
    int_queue.peek();

    queue<std::string> string_queue(3);
    string_queue.print_queue();
    string_queue.dequeue();
    string_queue.enqueue("abhi");
    string_queue.enqueue("lash");
    string_queue.enqueue("jo");
    string_queue.enqueue("shi"); // This should indicate overflow
    string_queue.print_queue();
    string_queue.peek();
    string_queue.dequeue();
    string_queue.print_queue();
    string_queue.peek();

    return 0;
}
