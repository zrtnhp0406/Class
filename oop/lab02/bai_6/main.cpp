#include <iostream>
#include "bai6.cpp"

using namespace std;

int main() {
    TamGiac tg;
    tg.Nhap();
    cout << "Tam giac ban dau:\n";
    tg.Xuat();

    float a,b;

    cout<<"Nhap he so tinh tien: ";
    cin>>a>>b;

    tg.TinhTien(a, b);
    cout << "Tam giac sau khi tinh tien (2, 3):\n";
    tg.Xuat();

    return 0;
}

