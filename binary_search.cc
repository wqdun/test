#include <iostream>
#include <vector>

int BinarySearch(const std::vector<int> &arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (target < arr[mid]) {
            right = mid - 1;
        }
        else
        if (target == arr[mid]) {
            std::cout << "Find: " << mid << "\n";
            return mid;
        }
        else {
            left = mid + 1;
        }
    }

    std::cout << "not find.\n";
    std::cout << "Min index: " << right << "\n";
    return right;
}

bool FindDataIn2DArray(const std::vector<std::vector<int>> &_2dArr, int target) {
    if (_2dArr.empty()) {
        std::cout << "Empty.\n";
        return false;
    }

    int minRow = BinarySearch(_2dArr[0], target);

    std::vector<int> row0Array(0);
    for (const auto &arr: _2dArr) {
        row0Array.emplace_back(arr[0]);
    }

    int minCol = BinarySearch(row0Array, target);

    for (size_t i = 0; i <= minRow; ++i) {
        for (size_t j = 0; j <= minCol; ++j) {
            std::cout << _2dArr[j][i] << "\n";
            if (_2dArr[j][i] == target) {
                return true;
            }
        }

    }

    return false;
}

int main(int argc, char const *argv[]) {
    const std::vector<int> a {1, 2, 3, 5, 6};
    // std::cout << BinarySearch(a, 4) << "\n";

    const std::vector<std::vector<int>> _2d {
        {1, 2, 8, 9, 10},
        {2, 4, 9, 12, 14},
        {10, 11, 12, 13, 15}
    };
    std::cout << FindDataIn2DArray(_2d, 9) << "\n";

    return 0;
}
