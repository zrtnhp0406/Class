#ifndef QUANLY_H
#define QUANLY_H

#include "NhanVien.h"

class QuanLy : public NhanVien {
private:
    double tyLeThuong; // Tỷ lệ thưởng

public:
    // Hàm dựng
    QuanLy(string ma, string t, double luong, double tyLe)
        : NhanVien(ma, t, luong), tyLeThuong(tyLe) {}

    // Tính tiền thưởng của quản lý
    double TienThuong() override {
        return luongCB * tyLeThuong / 100;
    }

    // Xử lý việc xuất thông tin cho quản lý
    void Xuat() override {
        NhanVien::Xuat();
        cout << "Ty le thuong: " << tyLeThuong << "%" << endl;
    }
};

#endif // QUANLY_H
