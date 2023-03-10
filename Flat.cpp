#include <iostream>
using namespace std;

class Flat {
    double price_;
    double area_;
public:
    Flat() :price_(0), area_(0) {};
    Flat(const double& prc, const double& area) :price_(prc), area_(area) {};
    Flat(const Flat& other) :price_(other.price_), area_(other.area_) {};
    Flat& operator = (const Flat&);
    bool operator == (const Flat&);
    bool operator != (const Flat&);
    bool operator > (const Flat&);
    bool operator < (const Flat&);
    friend ostream& operator<<(ostream& out, const Flat& other);
};
Flat& Flat::operator = (const Flat& other) {
    if (this == &other)
        return *this;
    price_ = other.price_;
    area_ = other.area_;
    return *this;
}
bool Flat::operator == (const Flat& other) {
    return area_ == other.area_;
}
bool Flat::operator != (const Flat& other) {
    return !(area_ == other.area_);
}
bool Flat::operator > (const Flat& other) {
    return price_ > other.price_;
}
bool Flat::operator < (const Flat& other) {
    return price_ < other.price_;
}
ostream& operator<<(ostream& out, const Flat& other) {
    out << "Площадь: " << other.area_ << ", Цена: " << other.price_;
    return out;
}


int main() {
    
    Flat f01(35000, 60);
    Flat f02(42000, 75);
    Flat f03;
    f03 = f01;

    cout << "f01:\t" << f01 << endl;
    cout << "f02:\t" << f02 << endl;
    cout << "f03:\t" << f03 << endl;
    cout << endl;
    cout << "f01" << " == " << "f02" << ": " << boolalpha << (f01 == f02) << endl;
    cout << "f01" << " == " << "f03" << ": " << boolalpha << (f01 == f03) << endl;
    cout << "f01" << " <  " << "f02" << ": " << boolalpha << (f01 < f02) << endl;
    cout << "f01" << " >  " << "f02" << ": " << boolalpha << (f01 > f02) << endl;
    return 0;
}