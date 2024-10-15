#include<bits/stdc++.h>
#include "bai1.h"

// Hàm khởi tạo mặc định
PhanSo::PhanSo() : tu(0), mau(0) {}

// Hàm khởi tạo với tham số
PhanSo::PhanSo(int x, int y) : tu(x), mau(y) {}

// Định nghĩa các toán tử
PhanSo PhanSo::operator + (const PhanSo& b) {
    PhanSo c;
    c.tu= tu * b.mau + mau * b.tu;
    c.mau=mau*b.mau;
    int gcd=__gcd(c.tu,c.mau);
    c.tu/=gcd;
    c.mau/=gcd;
    return PhanSo(c.tu, c.mau);
}
PhanSo PhanSo::operator - (const PhanSo& b) {
    PhanSo c;
    c.tu= tu * b.mau - mau * b.tu;
    c.mau=mau*b.mau;
    int gcd=__gcd(c.tu,c.mau);
    c.tu/=gcd;
    c.mau/=gcd;
    return PhanSo(c.tu, c.mau);
}
PhanSo PhanSo::operator * (const PhanSo& b) {
    PhanSo c;
    c.tu= tu * b.tu;
    c.mau=mau*b.mau;
    int gcd=__gcd(c.tu,c.mau);
    c.tu/=gcd;
    c.mau/=gcd;
    return PhanSo(c.tu, c.mau);
}
PhanSo PhanSo::operator / (const PhanSo& b) {
    PhanSo c;
    c.tu= tu * b.mau;
    c.mau=mau*b.tu;
    int gcd=__gcd(c.tu,c.mau);
    c.tu/=gcd;
    c.mau/=gcd;
    return PhanSo(c.tu, c.mau);
}

bool PhanSo::operator == (const PhanSo& b) {
    return (tu*b.mau)==(mau*b.tu);
}
bool PhanSo::operator != (const PhanSo& b) {
    return !(*this == b);
}

bool PhanSo::operator > (const PhanSo& b){
     return (tu*b.mau)>(mau*b.tu);
}


bool PhanSo::operator < (const PhanSo& b){
     return (tu*b.mau)<(mau*b.tu);
}


bool PhanSo::operator >= (const PhanSo& b){
     return (tu*b.mau)>=(mau*b.tu);
}



bool PhanSo::operator <= (const PhanSo& b){
     return (tu*b.mau)<=(mau*b.tu);
}


// Định nghĩa hàm bạn bè
istream& operator>>(istream &in, PhanSo &b) {
    cout << "Nhap tu: ";
    in >> b.tu;
    cout << "Nhap mau: ";
    in >> b.mau;
    return in;
}

ostream& operator<<(ostream& os, const PhanSo& b) {
    os << b.tu << "/" << b.mau;
    return os;
}

