#include "bai3.h"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y) : x(x), y(y) {}


#include <iostream>
#include <cmath>
#include "bai3.h"

using namespace std;

void Polygon::Nhap() {
    cin>>n;
    vertices.resize(n);
    for (int i = 0; i < n; ++i) {
        cout << "Nhap toa do dinh " << i + 1 << " (x, y): ";
        cin >> vertices[i].x >> vertices[i].y;
    }
}

void Polygon::Xuat() {
    for (size_t i = 0; i < vertices.size(); ++i) {
        cout << "Dinh " << i + 1 << ": (" << vertices[i].x << ", " << vertices[i].y << ")\n";
    }
}

void Polygon::TinhTien(float dx, float dy) {
    for (auto& vertex : vertices) {
        vertex.x += dx;
        vertex.y += dy;
    }
}

void Polygon::PhongTo(float scale) {
    for (auto& vertex : vertices) {
        vertex.x *= scale;
        vertex.y *= scale;
    }
}

void Polygon::ThuNho(float scale) {
    for (auto& vertex : vertices) {
        vertex.x /= scale;
        vertex.y /= scale;
    }
}

void Polygon::Quay(float angle) {
    float rad = angle * M_PI / 180; // Chuyển đổi độ sang radian
    float cosA = cos(rad);
    float sinA = sin(rad);

    for (auto& vertex : vertices) {
        float tempX = vertex.x;
        vertex.x = tempX * cosA - vertex.y * sinA;
        vertex.y = tempX * sinA + vertex.y * cosA;
    }
}
