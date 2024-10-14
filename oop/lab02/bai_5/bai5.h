#ifndef BAI5_H
#define BAI5_H

#include<bits/stdc++.h>
using namespace std;

class Diem {
private:
    int Hoanh; // Tọa độ hoành
    int Tung;  // Tọa độ tung

public:


    // cac ham
    void Nhap();
    void Xuat() const;
    void SetToaDo(int Tung,int Hoanh);
    void TinhTien(int k, int d);
    int gethoanh();
    int gettung();
};


#endif // BAI5_H_INCLUDED
