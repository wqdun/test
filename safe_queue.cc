#include <iostream>
#include <memory>
#include <mutex>
#include <deque>

class SQueue {
public:
    SQueue()
        : data_(0) {}
    ~SQueue() {}

    void PushFront(std::string i) {
        std::lock_guard<std::recursive_mutex> lockGuard(mutex_);
        data_.push_front(i);
        return;
    }

    void PushBack(std::string i) {
        std::lock_guard<std::recursive_mutex> lockGuard(mutex_);
        data_.push_back(i);
        return;
    }

    std::string PopFront() {
        std::lock_guard<std::recursive_mutex> lockGuard(mutex_);
        if (data_.empty()) {
            std::cerr << "Empty queue.\n";
            return "";
        }

        std::string &&t = std::move(data_.front());
        // std::shared_ptr<std::string> p = std::make_shared<std::string>(data_.front());
        std::shared_ptr<std::string> p = std::make_shared<std::string>(std::move(data_.front()));

        std::cout << "data_.front(): " << data_.front() << "\n";
        std::cout << "t: " << t << "\n";
        data_.pop_front();
        return *p;

        // std::string res = data_.front();
        // data_.pop_front();
        // return res;
    }

    std::string PopBack() {
        std::lock_guard<std::recursive_mutex> lockGuard(mutex_);
        if (data_.empty()) {
            std::cerr << "Empty queue.\n";
            return "";
        }

        std::string res = data_.back();
        data_.pop_back();
        return res;
    }

    size_t Size_s() const {
        std::lock_guard<std::recursive_mutex> lockGuard(mutex_);
        return data_.size();
    }

    size_t Empty() const {
        std::lock_guard<std::recursive_mutex> lockGuard(mutex_);
        return (0 == data_.size());
    }

    void PrintQ() const {
        std::lock_guard<std::recursive_mutex> lockGuard(mutex_);
        for (auto it = data_.begin(); it != data_.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";
        return;
    }

private:
    std::deque<std::string> data_;
    mutable std::recursive_mutex mutex_;
};


int main(int argc, char const *argv[]) {
    SQueue q;
    std::cout << q.Size_s() << "\n";
    std::cout << q.PopFront() << "\n";
    std::cout << q.PopBack() << "\n";

    q.PushBack("4");
    q.PushBack("8");
    q.PushFront("10");
    q.PrintQ();

    std::cout << q.PopFront() << "\n";
    std::cout << q.PopBack() << "\n";
    q.PrintQ();
    return 0;
}
