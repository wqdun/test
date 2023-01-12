#include <iostream>
#include <vector>

class ListNode {
public:
    explicit ListNode() {}
    explicit ListNode(int a)
        : data(a) {}

public:
    int data = 0;
    ListNode *next = nullptr;
};

ListNode *CreateList(const std::vector<int> &arr) {
    if (arr.empty()) {
        return nullptr;
    }

    ListNode *root = new ListNode(arr[0]);
    ListNode *p = root;
    for (size_t i = 1; i < arr.size(); ++i) {
        p = p->next = new ListNode(arr[i]);
        // p = p->next;
    }

    return root;
}

void PrintList(ListNode *list) {
    while (list) {
        std::cout << list->data << "\t";
        list = list->next;
    }
    std::cout << "\n";
    return;
}

ListNode *RemoveNodeBackward(ListNode *list, int index) {
    if (index <= 0) {
        return list;
    }

    ListNode *p = list;

    int num = 0;
    std::vector<ListNode *> pointers(0);
    while (p) {
        ++num;
        pointers.emplace_back(p);
        p = p->next;
    }
    std::cout << "num: " << num << "\n";

    int index2remove = num - index;
    if (index2remove == 0) {
        delete list;
        list = nullptr;
        return list->next;
    }
    pointers[index2remove -1]->next = pointers[index2remove]->next;
    delete pointers[index2remove];
    pointers[index2remove] = nullptr;

    return list;
}

int main(int argc, char const *argv[]) {
    const std::vector<int> a {1, 2, 3, 2, 1, 1, 1, 1, 0};

    ListNode *list = CreateList(a);
    (void) PrintList(list);

    ListNode *newList = RemoveNodeBackward(list, 7);
    (void) PrintList(newList);
    return 0;
}
