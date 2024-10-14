#include <iostream>
#include "bai3.cpp"

using namespace std;

int main() {
    Polygon pg;
    int n;

    pg.Nhap();
    cout << "Da giac ban dau:\n";
    pg.Xuat();

    pg.TinhTien(2, 3);
    cout << "Da giac sau khi tinh tien (2, 3):\n";
    pg.Xuat();

    pg.PhongTo(2);
    cout << "Da giac sau khi phong to: \n";
    pg.Xuat();

    pg.ThuNho(2);
    cout << "Da giac sau khi thu nho: \n";
    pg.Xuat();

    pg.Quay(90);
    cout << "Da giac sau khi quay 90 do: \n";
    pg.Xuat();

    return 0;
}
