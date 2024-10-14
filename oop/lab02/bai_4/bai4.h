#ifndef thisinh_H
#define thisinh_H
#include<bits/stdc++.h>
using namespace std;

class ThiSinh {
private:
    string Ten;
    string MSSV;
    int iNgay, iThang, iNam;
    float fToan, fVan, fAnh;

public:
    void Nhap();
    void Xuat();
    float Tong();
};


#endif
