#include <iostream>
#include <map>

// str1: 1A2C; str2: A2;
// return: A2


void PrintMap(const std::multimap<size_t, std::string> &inMap) {
    for (const auto &ele: inMap) {
        std::cout << ele.first << ": " << ele.second << "\t";
    }
    std::cout << "\n";
    return;
}

std::string GetLongestIdenticalSubstring(const std::string &str1, const std::string &str2) {
    if (str1.empty()) {
        return "";
    }
    if (str2.empty()) {
        return "";
    }

    size_t num = str1.size();
    std::multimap<size_t, std::string> res;
    for (int left = 0; left < num; ++left) {
        for (int right = num - 1; right >= left; --right) {
            const std::string sub1 = str1.substr(left, right - left + 1);
            // std::cout << left << ": " << right << "\n";
            std::cout << sub1 << "\n";

            if (std::string::npos != str2.find(sub1)) {
                res.insert({sub1.size(), sub1});
                if (right == num - 1) {
                    std::cout << "Find longest when left: " << left << "\n";
                    return res.rbegin()->second;
                }

                break;
            }
            // else continue
        }
    }

    (void) PrintMap(res);
    if (res.empty()) {
        std::cout << "Find none.\n";
        return "";
    }
    else {
        return res.rbegin()->second;
    }
}


int main(int argc, char const *argv[]) {
    const std::string str1("1AB2345CD");
    const std::string str2("1AB345C");

    std::cout << GetLongestIdenticalSubstring(str1, str2);
    std::cout << "\n";
    return 0;
}
