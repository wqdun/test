#include <iostream>
#include <stack>


class StackGetMin {
public:
    std::stack<int> stackData_;
    std::stack<int> stackMin_;
    
    int GetMin() {
        if (stackMin_.empty()) {
            std::cerr << __LINE__ << ": Failed.\n";
            exit(-1);
        }
        
        return stackMin_.top();
    }
    
    void Push(int i) {
        if (stackData_.empty()) {
            stackData_.push(i);
            stackMin_.push(i);
            return;
        }

        if (i <= GetMin()) {
            stackData_.push(i);
            stackMin_.push(i);
            return; 
        }

        stackData_.push(i);
        return;
    }

    int Pop() {
        if (stackData_.empty()) {
            std::cerr << __LINE__ << ": Failed.\n";
            exit(-1);
        }
        int i = stackData_.top();
        if (i == GetMin()) {
            stackData_.pop();
            stackMin_.pop();
            return i;
        }

        stackData_.pop();
        return i;
    }
};


int main() {
    // your code goes here
    StackGetMin s;
    s.Push(6);
    s.Push(5);
    s.Push(3);
    s.Push(9);
    
    std::cout << s.Pop() << "\n";
    std::cout << s.Pop() << "\n";
    
    std::cout << s.GetMin() << "\n";

    return 0;
}
