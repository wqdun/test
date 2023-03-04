#include <iostream>
#include <vector>

class Dnode {
public:
    explicit Dnode() {}
    ~Dnode() {}

    explicit Dnode(int i)
        : data(i) {}
    explicit Dnode(int i, Dnode *_prev)
        : data(i)
        , prev(_prev) {}

public:
    int data = 0;
    Dnode *prev = nullptr;
    Dnode *next = nullptr;
};

Dnode *CreateList(const std::vector<int> &arr) {
    if (arr.empty()) {
        return nullptr;
    }

    Dnode *root = new Dnode(arr[0]);
    Dnode *head = root;
    for (size_t i = 1; i < arr.size(); ++i) {
        head->next = new Dnode(arr[i], head);
        head = head->next;
    }

    return root;
}

Dnode *ForwardTraverse(Dnode *front) {
    Dnode *p = front;
    Dnode *back = front;
    while (p) {
        std::cout << p->data << "\t";
        back = p;
        p = p->next;
    }
    std::cout << "\n";

    return back;
}

Dnode *BackwardTraverse(Dnode *back) {
    Dnode *p = back;
    Dnode *front = back;
    while (p) {
        std::cout << p->data << "\t";
        front = p;
        p = p->prev;
    }
    std::cout << "\n";

    return front;
}

Dnode *Reverse(Dnode *root) {
    Dnode *p = root;

    Dnode *prev_ = nullptr;
    Dnode *next_ = nullptr;
    while (p) {
        prev_ = p->prev;
        next_ = p->next;

        p->prev = next_;
        p->next = prev_;

        p = next_;
    }

    return root;
}

Dnode *Reverse_(Dnode *root) {
    Dnode *p = root;

    Dnode *prev_ = nullptr;
    while (p) {
        Dnode *next = p->next;

        p->prev = next;
        p->next = prev_;

        prev_ = p;
        p = next;
    }

    return root;
}


int main(int argc, char const *argv[]) {
    std::vector<int> a {1, 2, 5, 4, 3, 0};
    // a = {3, 2};

    Dnode *root = CreateList(a);
    Dnode *back = ForwardTraverse(root);
    Dnode *front = BackwardTraverse(back);

    (void) ForwardTraverse(root);
    (void) Reverse_(root);
    (void) BackwardTraverse(root);

    return 0;
}
