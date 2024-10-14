#ifndef POINT_H
#define POINT_H

class Point {
public:
    float x, y;

    Point();
    Point(float x, float y);
};

#endif // POINT_H

#ifndef TAMGIAC_H
#define TAMGIAC_H

class TamGiac {
private:
    Point A, B, C;

public:
    void Nhap();
    void Xuat();
    void TinhTien(float dx, float dy);
    void PhongTo(float scale);
    void ThuNho(float scale);
    void Quay(float angle);
};

#endif // TAMGIAC_H
