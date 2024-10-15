#include<bits/stdc++.h>
using namespace std;
#ifndef BAI4_H
#define BAI4_H


class NgayThangNam{
  private:
      int iNgay, iThang, iNam;
  public:
      NgayThangNam();
      NgayThangNam(int Nam, int Thang, int Ngay);
      int tinhngay() const;

      NgayThangNam operator+(int ngay);
      NgayThangNam operator-(int ngay);
      int operator-(const NgayThangNam& a);

     NgayThangNam& operator++();
    NgayThangNam& operator--();

    bool operator==(const NgayThangNam& a) ;
    bool operator!=(const NgayThangNam& a) ;
    bool operator>=(const NgayThangNam& a) ;
    bool operator<=(const NgayThangNam& a) ;
    bool operator>(const NgayThangNam& a) ;
    bool operator<(const NgayThangNam& a) ;

    friend istream& operator>>(istream& in, NgayThangNam& nt);
    friend ostream& operator<<(ostream& os, const NgayThangNam& nt);

};

#endif
