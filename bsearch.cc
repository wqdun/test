#include <iostream>
#include <vector>


int _bsearch(const std::vector<int> &arr, int key, int little, int big) {
    std::cout << __LINE__ << ": " << little << " --> " << big << "\n";

    if (little > big) {
        std::cerr << __LINE__ << ": No found.\n";
        return -1;
    }
    if (key < arr[little]) {
        std::cerr << __LINE__ << ": No found.\n";
        return -1;
    }
    if (key > arr[big]) {
        std::cerr << __LINE__ << ": No found.\n";
        return -1;
    }

    int mid = (little + big) / 2;
    if ((key < arr[mid])) {
        return _bsearch(arr, key, little, mid - 1);
    }
    else
    if (key == arr[mid]) {
        return mid;
    }
    else {
        return _bsearch(arr, key, mid + 1, big);
    }
}

int bsearch(const std::vector<int> &arr, int key) {
    if (arr.empty()) {
        std::cerr << __LINE__ << ": No found.\n";
        return -1;
    }

    return _bsearch(arr, key, 0, arr.size() - 1);
}


int main(int argc, char const *argv[]) {
    std::cout << bsearch(std::vector<int>{1}, 1) << "\n";
    return 0;
}
