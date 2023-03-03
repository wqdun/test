#include <iostream>
#include <array>


class Ring {
public:
    Ring() {
        assert(max_size >= 1);
    }
    ~Ring() = default;

    bool IsFull() {
        return (front == ((rear + 1) % max_size));
    }

    bool IsEmpty() {
        return (rear == front);
    }

    size_t GetSize() {
        return (rear + max_size - front) % max_size;
    }

    int Pop() {
        if (IsEmpty()) {
            std::cerr << "Empty.\n";
            return -1;
        }
        int res = buffer[front];
        front = ((front + 1) % max_size);
        return res;
    }

    void Push(int i) {
        if (IsFull()) {
            std::cout << "Full, pop: " << Pop() << "\n";
        } // else no pop
        buffer[rear] = i;
        rear = ((rear + 1) % max_size);

        return;
    }

    void PrintBuffer() {
        std::cout << "Size: " << GetSize() << "\n";

        if (IsEmpty()) {
            std::cout << "No element.\n";
            return;
        }

        for (size_t i = front; i != rear; i = (i + 1) % max_size) {
            std::cout << "buffer[" << i << "]: " << buffer[i] << "\n";
        }
        return;
    }


public:
    static const size_t max_size = 10;
    std::array<int, max_size> buffer;
    int front = 0;
    int rear = 0;
};


int main(int argc, char const *argv[]) {
    Ring r;
    r.PrintBuffer();

    r.Push(7);
    r.Push(8);
    for (size_t i = 0; i < 8; ++i) {
        r.Push(i);
    }

    std::cout << "Pop: " << r.Pop() << "\n";
    std::cout << "Pop: " << r.Pop() << "\n";
    std::cout << "Pop: " << r.Pop() << "\n";

    r.PrintBuffer();
    return 0;
}
