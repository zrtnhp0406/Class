#ifndef BAI1_H
#define BAI1_H

#include<bits/stdc++.h>
using namespace std;

class Diem {
private:
    int iHoanh; // Tọa độ hoành
    int iTung;  // Tọa độ tung

public:
    // Constructors
    Diem();
    Diem(int Hoanh, int Tung);
    Diem(const Diem &x);

    // cac ham
    void Xuat() const;
    int GetTungDo() const;
    int GetHoanhDo() const;
    void SetTungDo(int Tung);
    void SetHoanhDo(int Hoanh);
    void TinhTien(int dx, int dy);
};


#endif // BAI1_H_INCLUDED
