#include <iostream>


class DataType {
public:
    int a = 0;
    DataType()
        : a(0) {}
    DataType(int i)
        : a(i) {}

    ~DataType() {
        std::cout << "ByeBye, a: " << a << "\n";
    }
};


std::unique_ptr<DataType> return_ptr() {
    // return std::unique_ptr<DataType>(new DataType());

    std::unique_ptr<DataType> pData(new DataType(3));
    return pData;
}

std::unique_ptr<DataType> ptr_param(std::unique_ptr<DataType> p) {
    return p;
}

std::unique_ptr<DataType> ref_ptr_param(std::unique_ptr<DataType> &p) {
    std::unique_ptr<DataType> pData(new DataType(4));
    return pData;
}

int main(int argc, char const *argv[]) {
    std::unique_ptr<DataType> data1(new DataType(1));
    std::unique_ptr<DataType> data2(new DataType(2));

    // error: object of type 'std::unique_ptr<DataType>' cannot be assigned because its copy assignment operator is implicitly deleted
    // Compile ERROR: copy assignment operator is implicitly deleted because 'unique_ptr<DataType, std::__1::default_delete<DataType> >'
    // has a user-declared move constructor unique_ptr(unique_ptr&& __u) _NOEXCEPT
    // data2 = data1;
    std::cout << __LINE__ << "\n";
    data2 = std::move(data1);
    std::cout << __LINE__ << "\n";

    // error: call to implicitly-deleted copy constructor of 'std::unique_ptr<DataType>'
    // (void) ptr_param(data1);

    std::unique_ptr<DataType> p = return_ptr();
    p = ref_ptr_param(p);

    return 0;
}
