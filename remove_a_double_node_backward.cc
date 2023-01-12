#include <iostream>
#include <vector>


class DoubleNode {
public:
    explicit DoubleNode() {}
    explicit DoubleNode(int a)
        : data(a) {}
    explicit DoubleNode(int a, DoubleNode *_prev)
        : data(a)
        , prev(_prev) {}

public:
    int data = 0;
    DoubleNode *prev = nullptr;
    DoubleNode *next = nullptr;
};

DoubleNode *GetBackNode(DoubleNode *list) {
    while (list) {
        if (!(list->next)) {
            return list;
        }
        list = list->next;
    }

    return nullptr;
}

DoubleNode *CreateDoubleList(const std::vector<int> &arr) {
    if (arr.empty()) {
        return nullptr;
    }

    DoubleNode *root = new DoubleNode(arr[0]);
    DoubleNode *p = root;
    for (size_t i = 1; i < arr.size(); ++i) {
        p = p->next = new DoubleNode(arr[i], p);
    }

    return root;
}

DoubleNode *RemoveDoubleNodeBackward(DoubleNode *list, int n) {
    DoubleNode *backNode = GetBackNode(list);

    DoubleNode *p = backNode;
    int backwardIndex = 1;
    while (p) {
        if (n == backwardIndex) {
            if (p->prev) {
                p->prev->next = p->next;
                if (p->next) {
                    p->next->prev = p->prev;
                } // else nothing

                p->next = p->prev = nullptr;
                delete p;
                p = nullptr;
                return list;
            }
            else {
                if (p->next) {
                    p->next->prev = nullptr;

                    DoubleNode *ret = p->next;
                    p->next = p->prev = nullptr;
                    delete p;
                    p = nullptr;
                    return ret;
                }
                else {
                    delete p;
                    p = nullptr;
                    return nullptr;
                }
            }
        }

        ++backwardIndex;
        p = p->prev;
    }

    return list;
}

void PrintList(DoubleNode *list) {
    while (list) {
        std::cout << list->data << "\t";
        list = list->next;
    }
    std::cout << "\n";
    return;
}


int main(int argc, char const *argv[]) {
    const std::vector<int> a {1, 2, 3, 2, 0, 0, 0, 9};

    DoubleNode *list = CreateDoubleList(a);
    DoubleNode *newList = RemoveDoubleNodeBackward(list, 6);

    (void) PrintList(newList);

    return 0;
}
