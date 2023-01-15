#include <iostream>
#include <string.h>
#include <string>

class TestAssignOperator {
public:
    TestAssignOperator(char *s = nullptr) {
        pData_ = s;
    }
    TestAssignOperator(const TestAssignOperator &t) {
        pData_ = t.pData_;
    }
    ~TestAssignOperator() {}

    TestAssignOperator &operator=(char *s) {
        delete[] pData_;
        pData_ = nullptr;
        try {
            pData_ = new char[strlen(s) + 1];
            strncpy(pData_, s, strlen(s));
        }
        catch (...) {
            std::cerr << "Failed to new.\n";
        }

        // pData_ = t.pData_;
        return *this;
    }

    TestAssignOperator &operator=(const TestAssignOperator &t) {
        if (&t == this) {
            std::cout << "Same object.\n";
            return *this;
        }

        delete[] pData_;
        pData_ = nullptr;
        try {
            pData_ = new char[strlen(t.pData_) + 1];
            strncpy(pData_, t.pData_, strlen(t.pData_));
        }
        catch (...) {
            std::cerr << "Failed to new.\n";
        }
        // pData_ = t.pData_;
        return *this;
    }

    TestAssignOperator &operator=(const TestAssignOperator &&t) {
        if (&t == this) {
            std::cout << "Same object.\n";
            return *this;
        }
        delete[] pData_;
        pData_ = nullptr;
        try {
            pData_ = new char[strlen(t.pData_) + 1];
            strncpy(pData_, t.pData_, strlen(t.pData_));
        }
        catch (...) {
            std::cerr << "Failed to new.\n";
        }
        // pData_ = t.pData_;
        return *this;
    }


public:
    char *pData_ = nullptr;
};

int main(int argc, char const *argv[]) {
    TestAssignOperator assigner;
{
    char s[] = "Hello";
    std::cout << std::string(s) << "\n";

    char s2[] = "hello";
    assigner = s2;
    std::cout << assigner.pData_ << "\n";
}
    char s3[] = "World";
    TestAssignOperator assigner2(s3);
    assigner = assigner2;
    std::cout << assigner.pData_ << "\n";

    assigner2 = assigner2 = assigner2;
    return 0;
}
