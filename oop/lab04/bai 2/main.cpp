#include <iostream>
#include <vector>
#include "Deluxe.h"
#include "Premium.h"
#include "Business.h"

using namespace std;

int main() {
    // Khởi tạo các phòng trong khách sạn
    vector<Phong*> danhSachPhong;
    danhSachPhong.push_back(new Deluxe(3, 213215, 5512));
    danhSachPhong.push_back(new Deluxe(4, 102010, 412341));
    danhSachPhong.push_back(new Premium(2, 21512));
    danhSachPhong.push_back(new Premium(11, 421049));
    danhSachPhong.push_back(new Business(15));

    // Biến để theo dõi doanh thu của từng loại phòng
    long long doanhThuDeluxe = 0, doanhThuPremium = 0, doanhThuBusiness = 0;

    // Duyệt qua các phòng và tính doanh thu
    for (Phong* phong : danhSachPhong) {
        double doanhThu = phong->TinhDoanhThu();

        // phan loai
        if (dynamic_cast<Deluxe*>(phong)) {
            doanhThuDeluxe += doanhThu;
        } else if (dynamic_cast<Premium*>(phong)) {
            doanhThuPremium += doanhThu;
        } else if (dynamic_cast<Business*>(phong)) {
            doanhThuBusiness += doanhThu;
        }
    }

    // Hiển thị doanh thu của từng loại phòng
    cout << "Doanh thu cua phong Deluxe: " << doanhThuDeluxe << endl;
    cout << "Doanh thu cua phong Premium: " << doanhThuPremium << endl;
    cout << "Doanh thu cua phong Business: " << doanhThuBusiness << endl;

    // Tìm loại phòng có doanh thu cao nhất
    if (doanhThuDeluxe > doanhThuPremium && doanhThuDeluxe > doanhThuBusiness) {
        cout << "Loai phong co doanh thu cao nhat: Deluxe" << endl;
    } else if (doanhThuPremium > doanhThuDeluxe && doanhThuPremium > doanhThuBusiness) {
        cout << "Loai phong co doanh thu cao nhat: Premium" << endl;
    } else {
        cout << "Loai phong co doanh thu cao nhat: Business" << endl;
    }

    // Giải phóng bộ nhớ đã cấp phát
    for (Phong* phong : danhSachPhong) {
        delete phong;
    }

    return 0;
}

