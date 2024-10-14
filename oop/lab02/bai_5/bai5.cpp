#include<bits/stdc++.h>
#include "bai5.h"
using namespace std;

void Diem::Nhap(){
    cout << "Nhap toa do (Tung, Hoanh): ";
    cin >> Tung >> Hoanh;
}

void Diem::Xuat() const {
    cout << "Toa do: (" << Tung << ", " << Hoanh << ")" << endl;
}

void Diem::SetToaDo(int t, int h) {
    Tung = t;
    Hoanh = h;
}

void Diem::TinhTien(int k, int d) {
    if(k==0)
        Hoanh += d;
    else
        Tung += d;
}

int Diem::gethoanh(){
        return Hoanh;
}

int Diem::gettung(){
    return Tung;
}
