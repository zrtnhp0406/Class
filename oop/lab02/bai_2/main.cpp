#include <iostream>
#include "bai2.cpp"

using namespace std;

int main() {
    TamGiac tg;
    tg.Nhap();
    cout << "Tam giac ban dau:\n";
    tg.Xuat();

    tg.TinhTien(2, 3);
    cout << "Tam giac sau khi tinh tien (2, 3):\n";
    tg.Xuat();

    tg.PhongTo(2);
    cout << "Tam giac sau khi phong to: \n";
    tg.Xuat();

    tg.ThuNho(2);
    cout << "Tam giac sau khi thu nho: \n";
    tg.Xuat();

    tg.Quay(90);
    cout << "Tam giac sau khi quay 90 do: \n";
    tg.Xuat();

    return 0;
}
