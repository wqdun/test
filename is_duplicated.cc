#include <iostream>
#include <vector>
#include <unordered_map>

bool IsDuplicated(const std::vector<int> &arr) {
    std::unordered_map<int, size_t> numToCount;
    for (int ele: arr) {
        if (numToCount[ele] > 0) {
            return true;
        }
        ++numToCount[ele];
    }

    return false;
}

bool IsDuplicated_(std::vector<int> &arr) {
    std::sort(arr.begin(), arr.end());

    if (arr.empty()) {
        return false;
    }

    int prev = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] == prev) {
            return true;
        }
    }

    return false;
}

int main(int argc, char const *argv[]) {
    std::vector<int> a {1, 2, 3, 0, 5};

    std::cout << IsDuplicated_(a) << "\n";
    return 0;
}
