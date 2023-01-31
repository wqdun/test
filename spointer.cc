#include <iostream>

class SPointer {
public:
    SPointer() {
        std::cout << __FUNCTION__ << " called.\n";
        data_ = "h";
        pRefCount_ = new int(1);
        return;
    }

    SPointer(const SPointer &pointerB) {
        std::cout << __FUNCTION__ << " called.\n";

        data_ = pointerB.data_;
        pRefCount_ = pointerB.pRefCount_;
        ++(*pRefCount_);
        return;
    }

    ~SPointer() {
        std::cout << __FUNCTION__ << " called.\n";
        --(*pRefCount_);
        std::cout << *this << "\n";
        if (0 == *pRefCount_) {
            std::cout << "Delete data.\n";
            data_ = "DELETED";
            delete pRefCount_;
            pRefCount_ = nullptr;
        }
        return;
    }

    SPointer &operator=(SPointer &pointerB) {
        std::cout << __FUNCTION__ << " called.\n";
        if (&pointerB == this) {
            std::cout << "Same object.\n";
            return *this;
        }

        std::cout << "Diff object.\n";
        data_ = pointerB.data_;
        if (pRefCount_ == pointerB.pRefCount_) {
            std::cout << "Same Pointer.\n";
            return *this;
        }

        std::cout << "Diff Pointer.\n";
        --(*pRefCount_);
        if (0 == *pRefCount_) {
            std::cout << "Delete data.\n";
            delete pRefCount_;
            pRefCount_ = nullptr;
        }

        pRefCount_ = pointerB.pRefCount_;
        ++(*pRefCount_);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const SPointer &sp) {
        os << sp.data_ << ": " << *(sp.pRefCount_);
        return os;
    }

public:
    int *pRefCount_ = nullptr;
    std::string data_ = "";
};


int main(int argc, char const *argv[]) {
    SPointer p1;
    p1 = p1;
    std::cout << p1 << "\n";

    SPointer p2 = p1;
    std::cout << p1 << "; " << p2 << "\n";

    p2 = p2;
    p2 = p1;
    std::cout << p1 << "; " << p2 << "\n";

    SPointer p3;
    p3 = p2;
    std::cout << p1 << "; " << p2 << "; " << p3 << "\n";

    SPointer p4;
    std::cout << p1 << "; " << p2 << "; " << p3 << "; " << p4 << "\n";

    return 0;
}
