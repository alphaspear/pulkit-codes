#include<iostream>
#include <string>
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
            for(int i=pointer_index; i >= 0; i--){
                std::cout<<stack_array[i]<<" ";
            }
        }

        //function to remove the first value from stack array
        void pop(){
            if(pointer_index == -1){
                std::cout<<"STACK UNDERFLOW"<<std::endl;
                return;
            }
            --pointer_index;
        }

        //function to push value to stack
        void push(const T& data){
            if(pointer_index == get_size() - 1){
                std::cout<<"STACK OVERFLOW"<<std::endl;
                return;
            }
        stack_array[++pointer_index] = data;
        }

        //function to print first data in stack 
        void peak(){
            if(pointer_index == -1){
                std::cout<<"STACK IS EMPTY"<<std::endl;
                return;
            }
            std::cout<<std::endl<<stack_array[pointer_index]<<std::endl;
        }
        void get_pointer(){
            std::cout<<std::endl<<"pointer "<<pointer_index<<std::endl;
        }

    private:
        int stack_size;
        T* stack_array;
        int pointer_index;
};

// Driver Code
int main(){
    stack <int> int_stack(3);
    int_stack.print_stack();
    int_stack.pop();
    int_stack.push(1);
    int_stack.push(2);
    int_stack.push(3);
    int_stack.push(4);
    int_stack.print_stack();
    int_stack.get_pointer();
    int_stack.peak();

    stack <std::string> string_stack(3);
    string_stack.print_stack();
    string_stack.pop();
    string_stack.push("abhi");
    string_stack.push("lash");
    string_stack.push("jo");
    string_stack.push("shi");
    string_stack.print_stack();
    string_stack.get_pointer();
    string_stack.peak();
    
}
    