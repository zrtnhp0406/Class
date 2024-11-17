#ifndef PREMIUM_H
#define PREMIUM_H

#include "Phong.h"

class Premium : public Phong {
public:
    // Hàm dựng
    Premium(int dem, double dichVu)
        : Phong(dem, dichVu) {}

    // Tính doanh thu cho phòng Premium
    double TinhDoanhThu() const override {
        return GetSoDem() * 500000 + GetPhiDichVu();
    }
};

#endif // PREMIUM_H
