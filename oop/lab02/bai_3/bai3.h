#ifndef POINT_H
#define POINT_H

class Point {
public:
    float x, y;

    Point();
    Point(float x, float y);
};

#endif // POINT_H


#ifndef POLYGON_H
#define POLYGON_H

#include <vector>

class Polygon {
private:
    int n;
    std::vector<Point> vertices;

public:
    void Nhap();
    void Xuat();
    void TinhTien(float dx, float dy);
    void PhongTo(float scale);
    void ThuNho(float scale);
    void Quay(float angle);
};

#endif // POLYGON_H
