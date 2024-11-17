#include <iostream>
#include "QuanLy.h"
#include "KySu.h"

using namespace std;

int main() {
    string ma, ten;
    double luong, tyLe;
    int gioLamThem;

    // Nhập thông tin cho Quản lý
    cout << "Nhap thong tin Quan Ly:" << endl;
    cout << "Ma so: ";
    cin >> ma;
    cout << "Ten: ";
    cin.ignore();
    getline(cin, ten);
    cout << "Luong co ban: ";
    cin >> luong;
    cout << "Ty le thuong: ";
    cin >> tyLe;

    // Tạo đối tượng Quản lý
    QuanLy quanLy(ma, ten, luong, tyLe);

    // Nhập thông tin cho Kỹ sư
    cout << "\nNhap thong tin Ky Su:" << endl;
    cout << "Ma so: ";
    cin >> ma;
    cout << "Ten: ";
    cin.ignore(); // Xóa bộ đệm sau khi nhập
    getline(cin, ten);
    cout << "Luong co ban: ";
    cin >> luong;
    cout << "So gio lam them: ";
    cin >> gioLamThem;

    // Tạo đối tượng Kỹ sư
    KySu kySu(ma, ten, luong, gioLamThem);

    // Hiển thị thông tin của Quản lý và Kỹ sư
    cout << "\nThong tin Quan Ly:" << endl;
    quanLy.Xuat();

    cout << "\nThong tin Ky Su:" << endl;
    kySu.Xuat();

    return 0;
}

