#include <iostream>
#include <vector>
#include <stack>


class StacksToQueue {
public:
    void ReverseStack(std::stack<int> &stack1, std::stack<int> &stack2);
    void Add(int i);
    int Pop();
    bool Empty();
    int Peek();


public:
    std::stack<int> pushStack_;
    std::stack<int> popStack_;
};


void StacksToQueue::Add(int i) {
    if (pushStack_.empty()) {
        ReverseStack(popStack_, pushStack_);
    } // else: ReverseStack already

    pushStack_.push(i);
    return;
}

bool StacksToQueue::Empty() {
    if (!pushStack_.empty()) {
        return false;
    }
    if (!popStack_.empty()) {
        return false;
    }
    return true;
}

int StacksToQueue::Pop() {
    if (popStack_.empty()) {
        ReverseStack(pushStack_, popStack_);
    } // else: ReverseStack already

    if (popStack_.empty()) {
        std::cerr << __LINE__ << ": Failed.\n";
        return -1;
    }
    int i = popStack_.top();
    popStack_.pop();
    return i;
}

void StacksToQueue::ReverseStack(std::stack<int> &stack1, std::stack<int> &stack2) {
    while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
    }
    return;
}

int StacksToQueue::Peek() {
    if (popStack_.empty()) {
        ReverseStack(pushStack_, popStack_);
    } // else: ReverseStack already

    if (popStack_.empty()) {
        std::cerr << __LINE__ << ": Failed.\n";
        return -1;
    }
    int i = popStack_.top();
    return i;
}


int main(int argc, char const *argv[]) {
    StacksToQueue q;
    std::cout << q.Peek() << "\n";
    q.Add(1);
    q.Add(2);
    std::cout << q.Peek() << "\n";
    std::cout << q.Pop() << "\n";
    std::cout << q.Pop() << "\n";
    q.Add(3);
    q.Add(4);

    while (!q.Empty()) {
        std::cout << q.Pop() << "\t";
    }
    std::cout << "\n";
    return 0;
}
