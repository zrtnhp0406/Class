#include <iostream>
#include <cmath>
#include "bai4.h"
using namespace std;
void ThiSinh::Nhap() {
    cout << "Nhap ten thi sinh: ";
    cin.ignore();
    getline(cin, Ten);
    cout << "Nhap MSSV: ";
    getline(cin, MSSV);
    cout << "Nhap ngay sinh (ngay thang nam): ";
    cin >> iNgay >> iThang >> iNam;
    cout << "Nhap diem Toan: ";
    cin >> fToan;
    cout << "Nhap diem Van: ";
    cin >> fVan;
    cout << "Nhap diem Anh: ";
    cin >> fAnh;
}

void ThiSinh::Xuat() {
    cout << "Ten: " << Ten << endl;
    cout << "MSSV: " << MSSV << endl;
    cout << "Ngay sinh: " << iNgay << "/" << iThang << "/" << iNam << endl;
    cout << "Diem Toan: " << fToan << endl;
    cout << "Diem Van: " << fVan << endl;
    cout << "Diem Anh: " << fAnh << endl;
    cout << "Tong diem: " << Tong() << endl;
}

float ThiSinh::Tong() {
    return fToan + fVan + fAnh;
}
