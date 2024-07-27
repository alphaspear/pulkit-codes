#include<iostream>
#include <stdexcept>
template <typename T>
class stack{
    public:
        // Constructor to create stack object of a given capacity
        stack(int stack_size){
            this->stack_size = stack_size;
            stack_array = new T[stack_size];
            pointer_index = -1;

        }
        // Distructor to free memory when exit
        ~stack(){
            delete [] stack_array;
        }

        // function to get stack size
        int get_size(){
            return stack_size;
        }

        //function to return stack_array
        void print_stack(){
            if(pointer_index == -1){
                std::cout<<"STACK IS EMPTY"<<std::endl;
                return;
            }

            std::cout<<std::endl<<"STACK CONTENT"<<std::endl;
            for(int i=pointer_index; i <= 0; i--){
                std::cout<<stack_array[i]<<" ";
            }
        }

        //function to remove the first value from stack array
        void pop(){
            if(pointer_index == -1){
                throw std::underflow_error("STACK UNDERFLOW");
                return;
            }
            pointer_index = pointer_index - 1;
        }
        //function to push value to stack
        void push(){
            
        }


    private:
        int stack_size;
        T* stack_array;
        int pointer_index;
};

int main(){
    stack<int> s1(5);
    std::cout<<s1.get_size()<<std::endl;
    s1.print_stack();
    s1.pop();
}
    