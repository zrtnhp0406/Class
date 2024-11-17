#ifndef KYSU_H
#define KYSU_H

#include "NhanVien.h"

class KySu : public NhanVien {
private:
    int soGioLamThem; // Số giờ làm thêm

public:
    // Hàm dựng
    KySu(string ma, string t, double luong, int gioLamThem)
        : NhanVien(ma, t, luong), soGioLamThem(gioLamThem) {}

    // Tính tiền thưởng của kỹ sư
    double TienThuong() override {
        return soGioLamThem * 100000; // Mỗi giờ làm thêm được trả 100,000
    }

    // Xử lý việc xuất thông tin cho kỹ sư
    void Xuat() override {
        NhanVien::Xuat();
        cout << "So gio lam them: " << soGioLamThem << endl;
    }
};

#endif // KYSU_H
