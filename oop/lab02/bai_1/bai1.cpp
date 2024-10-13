#include "bai1.h"
// Constructors
Diem::Diem() : iHoanh(0), iTung(0) {}

Diem::Diem(int Hoanh, int Tung) : iHoanh(Hoanh), iTung(Tung) {}

Diem::Diem(const Diem &x) : iHoanh(x.iHoanh), iTung(x.iTung) {}

void Diem::Xuat() const {
    std::cout << "Diem(" << iHoanh << ", " << iTung << ")\n";
}

int Diem::GetTungDo() const {
    return iTung;
}

int Diem::GetHoanhDo() const {
    return iHoanh;
}

void Diem::SetTungDo(int Tung) {
    iTung = Tung;
}

void Diem::SetHoanhDo(int Hoanh) {
    iHoanh = Hoanh;
}

void Diem::TinhTien(int dx, int dy) {
    iHoanh += dx;
    iTung += dy;
}
