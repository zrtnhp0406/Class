#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
using namespace std;

class NhanVien {
protected:
    string maSo;      
    string ten;       
    double luongCB;   

public:
    // Hàm dựng mặc định
    NhanVien(string ma, string t, double luong) : maSo(ma), ten(t), luongCB(luong) {}

   virtual double TienThuong() = 0;

    // Hàm Xuat() để xuất thông tin nhân viên
    virtual void Xuat() {
        cout << "Ma so: " << maSo << endl;
        cout << "Ten: " << ten << endl;
        cout << "Luong co ban: " << luongCB << endl;
        cout << "Tien thuong: " << TienThuong() << endl;
    }
};

#endif // NHANVIEN_H
