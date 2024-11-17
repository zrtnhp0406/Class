#ifndef BUSINESS_H
#define BUSINESS_H

#include "Phong.h"

class Business : public Phong {
public:
    // Hàm dựng
    Business(int dem)
        : Phong(dem, 0) {}  // Phí dịch vụ và phí phục vụ là 0 cho phòng Business

    // Tính doanh thu cho phòng Business
    double TinhDoanhThu() const override {
        return GetSoDem() * 300000;
    }
};

#endif // BUSINESS_H
