#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;
public:
    PhanSo(); // Khởi tạo mặc định
    PhanSo(int x, int y); // Khởi tạo với tham số

    // Toán tử
    PhanSo operator + (const PhanSo& b);
    PhanSo operator - (const PhanSo& b);
    PhanSo operator * (const PhanSo& b);
    PhanSo operator / (const PhanSo& b);

    bool operator == (const PhanSo& b);
    bool operator != (const PhanSo& b);
    bool operator >= (const PhanSo& b);
    bool operator <= (const PhanSo& b);
    bool operator < (const PhanSo& b);
    bool operator > (const PhanSo& b);

    // Hàm bạn bè
    friend istream& operator>>(istream &in, PhanSo &b);
    friend ostream& operator<<(ostream& os, const PhanSo& b);
};

#endif // SOPHUC_H

