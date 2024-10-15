#include "bai3.h"

// Constructor mặc định
ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

// Constructor với tham số
ThoiGian::ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {
    // Chỉnh sửa thời gian nếu cần
    if (iGiay >= 60) {
        iPhut += iGiay / 60;
        iGiay %= 60;
    }
    if (iPhut >= 60) {
        iGio += iPhut / 60;
        iPhut %= 60;
    }
}

// Tính tổng số giây
int ThoiGian::TinhGiay() const {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

// Tính lại giờ từ giây
void ThoiGian::TinhLaiGio(int Giay) {
    iGio = Giay / 3600;
    iPhut = (Giay % 3600) / 60;
    iGiay = Giay % 60;
}

// Toán tử +
ThoiGian ThoiGian::operator+(int Giay) {
    ThoiGian result = *this;
    result.TinhLaiGio(result.TinhGiay() + Giay);
    return result;
}

// Toán tử -
ThoiGian ThoiGian::operator-(int Giay) {
    ThoiGian result = *this;
    result.TinhLaiGio(result.TinhGiay() - Giay);
    return result;
}

// Toán tử +
ThoiGian ThoiGian::operator+(const ThoiGian& a) {
    ThoiGian result = *this;
    result.TinhLaiGio(result.TinhGiay() + a.TinhGiay());
    return result;
}

// Toán tử -
ThoiGian ThoiGian::operator-(const ThoiGian& a) {
    ThoiGian result = *this;
    result.TinhLaiGio(result.TinhGiay() - a.TinhGiay());
    return result;
}

// Toán tử tăng (tiền tố)
ThoiGian& ThoiGian::operator++() {
    iGiay++;
    if (iGiay >= 60) {
        iPhut++;
        iGiay %= 60;
    }
    if (iPhut >= 60) {
        iGio++;
        iPhut %= 60;
    }
    return *this;
}

// Toán tử tăng (hậu tố)
ThoiGian ThoiGian::operator++(int) {
    ThoiGian temp = *this;
    ++(*this);
    return temp;
}

// Toán tử giảm (tiền tố)
ThoiGian& ThoiGian::operator--() {
    iGiay--;
    if (iGiay < 0) {
        iPhut--;
        iGiay = 59;
    }
    if (iPhut < 0) {
        iGio--;
        iPhut = 59;
    }
    return *this;
}

// Toán tử giảm (hậu tố)
ThoiGian ThoiGian::operator--(int) {
    ThoiGian temp = *this;
    --(*this);
    return temp;
}

// Toán tử so sánh
bool ThoiGian::operator==(const ThoiGian& a) {
    return TinhGiay() == a.TinhGiay();
}

bool ThoiGian::operator!=(const ThoiGian& a) {
    return !(*this == a);
}

bool ThoiGian::operator>=(const ThoiGian& a) {
    return TinhGiay() >= a.TinhGiay();
}

bool ThoiGian::operator<=(const ThoiGian& a) {
    return TinhGiay() <= a.TinhGiay();
}

bool ThoiGian::operator>(const ThoiGian& a) {
    return TinhGiay() > a.TinhGiay();
}

bool ThoiGian::operator<(const ThoiGian& a) {
    return TinhGiay() < a.TinhGiay();
}

// Toán tử xuất
ostream& operator<<(ostream& os, const ThoiGian& tg) {
    os << tg.iGio << "h " << tg.iPhut << "m " << tg.iGiay << "s";
    return os;
}

// Toán tử nhập
istream& operator>>(istream& is, ThoiGian& tg) {
    cout<<"Nhap gio: ";
    is >> tg.iGio;
    cout<<"Nhap phut: ";
    is >> tg.iPhut;
    cout<<"Nhap giay: ";
    is>> tg.iGiay;
    return is;
}

