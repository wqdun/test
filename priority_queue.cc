#include <iostream>
#include <queue>
#include <string>

int main() {
    // 对于基础类型 默认是大顶堆
    std::priority_queue<int> a;
    // 等同于 std::priority_queue<int, std::vector<int>, less<int>> a;

    // 这样就是小顶堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> c;
    std::priority_queue<std::string> b;

    for (int i = 0; i < 5; i++) {
        a.push(i);
        c.push(i);
    }

    // 降序输出
    while (!a.empty()) {
        std::cout << a.top() << ' ';
        a.pop();
    }
    std::cout << "\n";

    // 升序输出
    while (!c.empty()) {
        std::cout << c.top() << ' ';
        c.pop();
    }
    std::cout << "\n";

    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty()) {
        std::cout << b.top() << ' ';
        b.pop();
    }
    std::cout << "\n";
    return 0;
}
