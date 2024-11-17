#ifndef DELUXE_H
#define DELUXE_H

#include "Phong.h"

class Deluxe : public Phong {
public:
    // Hàm dựng
    Deluxe(int dem, double dichVu, double phucVu)
        : Phong(dem, dichVu, phucVu) {}

    // Tính doanh thu cho phòng Deluxe
    double TinhDoanhThu() const override {
        return GetSoDem() * 750000 + GetPhiDichVu() + GetPhiPhucVu();
    }
};

#endif // DELUXE_H
