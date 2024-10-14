#include "bai2.h"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y) : x(x), y(y) {}

#include <iostream>
#include <cmath>
#include "bai2.h"

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

void TamGiac::TinhTien(float dx, float dy) {
    A.x += dx; A.y += dy;
    B.x += dx; B.y += dy;
    C.x += dx; C.y += dy;
}

void TamGiac::PhongTo(float scale) {
    A.x *= scale; A.y *= scale;
    B.x *= scale; B.y *= scale;
    C.x *= scale; C.y *= scale;
}

void TamGiac::ThuNho(float scale) {
    A.x /= scale; A.y /= scale;
    B.x /= scale; B.y /= scale;
    C.x /= scale; C.y /= scale;
}

void TamGiac::Quay(float angle) {
    float rad = angle * M_PI / 180; // Chuyển đổi độ sang radian
    float cosA = cos(rad);
    float sinA = sin(rad);

    Point tempA = A;
    Point tempB = B;
    Point tempC = C;

    A.x = tempA.x * cosA - tempA.y * sinA;
    A.y = tempA.x * sinA + tempA.y * cosA;

    B.x = tempB.x * cosA - tempB.y * sinA;
    B.y = tempB.x * sinA + tempB.y * cosA;

    C.x = tempC.x * cosA - tempC.y * sinA;
    C.y = tempC.x * sinA + tempC.y * cosA;
}
