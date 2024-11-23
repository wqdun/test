#include <iostream>
#include <memory>


int main(int argc, char const *argv[]) {
    std::shared_ptr<int> p = nullptr; // std::shared_ptr<int>();

    std::cout << p << "\n";
    return 0;
}

