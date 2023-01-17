#include <iostream>
#include <queue>


std::priority_queue<double> ArrayToPriorityQueue(const std::vector<double> &arr) {
    std::priority_queue<double> prioQ;
    for (double ele: arr) {
        prioQ.push(ele);
    }

    return prioQ;
}

std::priority_queue<double> MergeQueue(
        std::priority_queue<double> &q1
        , std::priority_queue<double> &q2) {
    while (!q2.empty()) {
        q1.push(q2.top());
        q2.pop();
    }

    return q1;
}

void PrintQueue(std::priority_queue<double> &q) {
    while (!q.empty()) {
        std::cout << q.top() << "\t";
        q.pop();
    }
    std::cout << "\n";

}

int main(int argc, char const *argv[]) {
    const std::vector<double> d1 {1, 2, 4, 1, -1};
    const std::vector<double> d2 {-9, 6, 2, 1, -1};

    std::priority_queue<double> q1 = ArrayToPriorityQueue(d1);
    std::priority_queue<double> q2 = ArrayToPriorityQueue(d2);

    std::priority_queue<double> q3 = MergeQueue(q1, q2);

    PrintQueue(q3);
    return 0;
}

