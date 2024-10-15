#include<bits/stdc++.h>
#include "bai4.h"

NgayThangNam:: NgayThangNam() : iNgay(4), iThang(6), iNam(2005) {}
NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay) : iNam(Nam), iThang(Thang), iNgay(Ngay) {}

int NgayThangNam::tinhngay() const{
    int D[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    D[2]+=(iNam % 4 == 0 && iNam % 100 != 0) || (iNam % 400 == 0);

    int dem=0;
    for(int i=1; i<=iNam; i++){
           if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) dem+=366;
            else dem+=365;
    }
    for(int i=1; i<iThang; i++) dem+=D[i];
    dem+=iNgay;
    return dem;
}



NgayThangNam NgayThangNam::operator+(int Ngay){
    int D[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    NgayThangNam cur = *this;
    int c=D[iThang] +  (cur.iThang==2 && ((cur.iNam % 4 == 0 && cur.iNam % 100 != 0) || (cur.iNam % 400 == 0))) - cur.iNgay+1;
    while(Ngay>0){
          if(c<=Ngay){
                Ngay-=c;
                cur.iThang++;
                cur.iNgay=1;
                if(cur.iThang==13) {cur.iThang=1; cur.iNam++;}
                c=D[cur.iThang] + (cur.iThang==2 && ((cur.iNam % 4 == 0 && cur.iNam % 100 != 0) || (cur.iNam % 400 == 0)));
          }
          else{
                cur.iNgay+=Ngay;
                Ngay=0;
          }
    }
    return cur;
}

NgayThangNam NgayThangNam::operator-(int Ngay){
    int D[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    NgayThangNam cur = *this;
    int c=cur.iNgay;
    while(Ngay>0){
          if(c<=Ngay){
                Ngay-=c;
                cur.iThang--;
                cur.iNgay=D[cur.iThang] + (cur.iThang==2 && ((cur.iNam % 4 == 0 && cur.iNam % 100 != 0) || (cur.iNam % 400 == 0)));
                if(cur.iThang==0) {cur.iThang=12; cur.iNam--;}
                c=D[cur.iThang] + (cur.iThang==2 && ((cur.iNam % 4 == 0 && cur.iNam % 100 != 0) || (cur.iNam % 400 == 0)));
          }
          else{
                cur.iNgay-=Ngay;
                Ngay=0;
          }
    }
    return cur;
}

NgayThangNam& NgayThangNam::operator++() {
    iNgay= iNgay + 1;
    return *this;
}

NgayThangNam& NgayThangNam::operator--() {
    iNgay = iNgay -1;
    return *this;
}


int NgayThangNam::operator-(const NgayThangNam& a) {
    return this->tinhngay() - a.tinhngay();
}



bool NgayThangNam::operator==(const NgayThangNam& a) {
    return iNgay == a.iNgay && iThang == a.iThang && iNam == a.iNam;
}

bool NgayThangNam::operator!=(const NgayThangNam& a) {
    return !(*this == a);
}

bool NgayThangNam::operator>=(const NgayThangNam& a)  {
    return tinhngay() >= a.tinhngay();
}

bool NgayThangNam::operator<=(const NgayThangNam& a)  {
    return tinhngay() <= a.tinhngay();
}

bool NgayThangNam::operator>(const NgayThangNam& a)  {
    return tinhngay() > a.tinhngay();
}

bool NgayThangNam::operator<(const NgayThangNam& a)  {
    return tinhngay() < a.tinhngay();
}

istream& operator>>(istream& in, NgayThangNam& nt) {
    cout << "Nhap ngay: ";
    in >> nt.iNgay;
    cout << "Nhap thang: ";
    in >> nt.iThang;
    cout << "Nhap nam: ";
    in >> nt.iNam;
    return in;
}

ostream& operator<<(ostream& out, const NgayThangNam& nt) {
    out << nt.iNgay << "/" << nt.iThang << "/" << nt.iNam;
    return out;
}
