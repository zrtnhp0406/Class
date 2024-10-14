#include<bits/stdc++.h>
#include "bai5.cpp"
int main() {
    Diem p;

    // Nhập tọa độ điểm
    p.Nhap();
    cout << "Toa do diem ban dau: ";
    p.Xuat();

    int n;
    cout << "Nhap so chi thi: ";
    cin>>n;
    int x;
    while(n--){
        cin>>x;
        if(x==1) p.SetToaDo(p.gethoanh()*2,p.gettung()*2);
        if(x==2) p.SetToaDo(0,0);
        if(x==3){
            int t,k;
            cin>>k>>t;
            p.TinhTien(k,t);
        }

    }
    return 0;
}

