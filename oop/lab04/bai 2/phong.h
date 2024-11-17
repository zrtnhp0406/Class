#ifndef PHONG_H
#define PHONG_H

#include <string>
using namespace std;

class Phong {
protected:
    int soDem;         // Số đêm
    double phiDichVu;  // Phí dịch vụ
    double phiPhucVu;  // Phí phục vụ

public:
    // Hàm dựng cho tất cả các phòng
    Phong(int dem, double dichVu, double phucVu = 0)
        : soDem(dem), phiDichVu(dichVu), phiPhucVu(phucVu) {}

    // Phương thức tính doanh thu cho phòng
    virtual double TinhDoanhThu() const = 0;

    // Getter để lấy thông tin về số đêm và phí dịch vụ
    int GetSoDem() const { return soDem; }
    double GetPhiDichVu() const { return phiDichVu; }
    double GetPhiPhucVu() const { return phiPhucVu; }
};

#endif // PHONG_H
