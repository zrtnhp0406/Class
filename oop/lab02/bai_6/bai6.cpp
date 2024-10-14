#include "bai6.h"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y) : x(x), y(y) {}

#include <iostream>
#include <cmath>
#include "bai6.h"

using namespace std;

void TamGiac::Nhap() {
    cout << "Nhap toa do dinh A (x, y): ";
    cin >> A.x >> A.y;
    cout << "Nhap toa do dinh B (x, y): ";
    cin >> B.x >> B.y;
    cout << "Nhap toa do dinh C (x, y): ";
    cin >> C.x >> C.y;
}

void TamGiac::Xuat() {
    cout << "Dinh A: (" << A.x << ", " << A.y << ")\n";
    cout << "Dinh B: (" << B.x << ", " << B.y << ")\n";
    cout << "Dinh C: (" << C.x << ", " << C.y << ")\n";
}

void TamGiac::TinhTien(float huong, float do_dai) {
        // Chuyển hướng từ độ sang radian
    float huong_rad = huong * 3.14 / 180.0;

    // Tính toán sự thay đổi theo x và y
    float dx = do_dai * cos(huong_rad);
    float dy = do_dai * sin(huong_rad);

    A.x += dx; A.y += dy;
    B.x += dx; B.y += dy;
    C.x += dx; C.y += dy;
}
