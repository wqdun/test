// given {-2, -1, 2, 3, 4, 5, 90, 900}
// return {2, 3, 4, 5} which value equals index

#include <iostream>
#include <vector>


int BinarySearch(const std::vector<int> &arr, int key, size_t left, size_t right) {
    std::cout << key << ", " << left << ", " << right << "\n";

    if (left > right) {
        std::cout << __LINE__ << "\n";
        return -1;
    }
    if (key == arr[left]) {
        return left;
    }
    if (key == arr[right]) {
        return right;
    }

    size_t mid = left + (right - left) / 2;
    if (key == arr[mid]) {
        return mid;
    }

    if (key <= arr[left]) {
        std::cout << __LINE__ << "\n";
        return -1;
    }
    else
    if (key <= arr[mid]) {
        return BinarySearch(arr, key, left, mid - 1);
    }
    else
    if (key <= arr[right]) {
        return BinarySearch(arr, key, mid + 1, right);
    }
    // arr[right] < key
    else {
        std::cout << __LINE__ << "\n";
        return -1;
    }
}

int BinarySearchTheOne(const std::vector<int> &arr, int left, int right) {
    std::cout << left << ", " << right << "\n";

    if (left > right) {
        std::cout << __LINE__ << "\n";
        return -1;
    }

    size_t mid = left + (right - left) / 2;
    if (arr[mid] == mid) {
        return mid;
    }

    if (arr[mid] < mid) {
        return BinarySearchTheOne(arr, mid + 1, right);
    }
    // arr[mid] > mid
    else {
        return BinarySearchTheOne(arr, left, mid - 1);
    }
}

int GetLeftSide(const std::vector<int> &arr, int start) {
    if (start < 0) {
        return -1;
    }
    for (int i = start; i >= 0; --i) {
        if (arr[i] == i) {
            continue;
        }
        else {
            return i + 1;
        }
    }

    return 0;
}

int GetRightSide(const std::vector<int> &arr, int start) {
    if (start < 0) {
        return -1;
    }
    for (int i = start; i < arr.size(); ++i) {
        if (arr[i] == i) {
            continue;
        }
        else {
            return i - 1;
        }
    }

    return arr.size() - 1;
}


int main(int argc, char const *argv[]) {
    const std::vector<int> arr {};

    int start = BinarySearchTheOne(arr, 0, arr.size() - 1);
    std::cout << start << "\n";

    int leftIndex = GetLeftSide(arr, start);
    int rightIndex = GetRightSide(arr, start);
    std::cout << leftIndex << "; " << rightIndex << "\n";
    return 0;
}
