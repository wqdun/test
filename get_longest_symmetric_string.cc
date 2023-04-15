#include <iostream>
#include <map>


bool IsSymmtricString(const std::string &str) {
    size_t num = str.size();

    for (size_t i = 0; i < num / 2; ++i) {
        if (str[i] != str[num - 1 - i]) {
            return false;
        }
    }

    return true;
}

void TEST_IsSymmtricString() {
    std::cout << IsSymmtricString("") << "\n";
    std::cout << IsSymmtricString("1") << "\n";
    std::cout << IsSymmtricString("12") << "\n";
    std::cout << IsSymmtricString("121") << "\n";
    std::cout << IsSymmtricString("2332") << "\n";
    return;
}

class BigFirst {
public:
    bool operator()(size_t a, size_t b) {
        return a > b;
    }
};
std::string GetLongestSymmtricString(const std::string &str) {
    std::map<size_t, std::string, BigFirst> sizeToSymmtricString;

    size_t num = str.size();
    for (size_t i = 0; i < num; ++i) {
        for (size_t j = 2; j < num - i + 1; ++j) {
            const std::string sub(str.substr(i, j));
            std::cout << "sub: " << sub << "\n";
            if (IsSymmtricString(sub)) {
                sizeToSymmtricString.insert({ sub.size(), sub });
                std::cout << "get one sub: " << sub << "\n";
            }
            // else nothing
        }
    }

    if (sizeToSymmtricString.empty()) {
        return "";
    }
    else {
        // return (--sizeToSymmtricString.end())->second;
        return (sizeToSymmtricString.begin())->second;
    }
}


int main(int argc, char const *argv[]) {
    (void) TEST_IsSymmtricString();
    std::cout << "GetLongestSymmtricString: "
        << GetLongestSymmtricString("Hellooo") << "\n";
    std::cout << "GetLongestSymmtricString: "
        << GetLongestSymmtricString("") << "\n";

    return 0;
}
