#include <iostream>
#include <vector>

class ListNode {
public:
    explicit ListNode() {};
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
        // std::cout << "push: " << arr[i] << "\n";
        p->next = new ListNode(arr[i]);
        p = p->next;
    }

    return root;
}

void PrintList(ListNode *list) {
    ListNode *p = list;
    while (p) {
        std::cout << p->data << "\t";
        p = p->next;
    }
    std::cout << "\n";
    return;
}

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }

        ListNode *p1 = head;
        ListNode *p2 = head;
        for (size_t i = 0; i < k; ++i) {
            p2 = p2->next;
        }

        PrintList(p2);

        if (!p2) {
            return head->next;
        }

        while (p2) {
            p2 = p2->next;
            if (!p2) {
                // remove p1
                ListNode *toRemove = p1->next;
                p1->next = toRemove->next;
                delete toRemove;
                toRemove = NULL;
                return head;
            }
            p1 = p1->next;
        }

        std::cerr << "Failed.\n";
        exit(1);
    }
};

int main(int argc, char const *argv[]) {
    const std::vector<int> a {1, 2, 3, 3, 2};

    ListNode *list = CreateList(a);
    PrintList(list);
    Solution s;
    ListNode *res = s.getKthFromEnd(list, 5);

    PrintList(res);
    return 0;
}
