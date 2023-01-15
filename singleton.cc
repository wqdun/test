#include <iostream>

class Singleton {
private:
    Singleton() = default;
    ~Singleton() = default;

public:
    static Singleton &GetInstance() {
        static Singleton s;
        return s;
    }

    Singleton(const Singleton &s) = delete;
    Singleton(Singleton &&s) = delete;
    Singleton &operator=(const Singleton &s) = delete;
    Singleton &operator=(Singleton &&s) = delete;

public:
    int data = 0;
};

int main(int argc, char const *argv[]) {
    // Singleton s; supposed to fail
    Singleton &s = Singleton::GetInstance();
    std::cout << s.data << "\n";

    return 0;
}
