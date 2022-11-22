#include <iostream>
#include <queue>
#include <string>

void TestBasic() {
    // 对于基础类型 默认是大顶堆
    std::priority_queue<int> a;
    // 等同于 std::priority_queue<int, std::vector<int>, less<int>> a;

    // 这样就是小顶堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> c;
    std::priority_queue<std::string> b;

    for (int i = 0; i < 5; i++) {
        a.emplace(i);
        c.emplace(i);
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

    b.emplace("abc");
    b.emplace("abcd");
    b.emplace("cbd");
    while (!b.empty()) {
        std::cout << b.top() << ' ';
        b.pop();
    }
    std::cout << "\n";
}

class MyData {
public:
    MyData(int x):
        x_(x) {}

    bool operator<(const MyData &b) const {
        return (x_ < b.x_);
    }

    friend std::ostream & operator<<(std::ostream& os, const MyData &a) {
        os << a.x_;
        return os;
    }

private:
    int x_;
};

class MyLess {
public:
    bool operator()(const MyData &a, const MyData &b) {
        return a < b;
    }
};

void TestMyData() {
    MyData a1(1);
    MyData a2(2);
    std::cout << (a1 < a2) << "\n";

    std::priority_queue<MyData, std::vector<MyData>, MyLess> q;

    q.emplace(1);
    q.emplace(2);
    while (!q.empty()) {
        std::cout << q.top() << "\t";
        q.pop();
    }
    std::cout << "\n";

    return;
}

int main() {
    TestBasic();
    TestMyData();

    return 0;
}
