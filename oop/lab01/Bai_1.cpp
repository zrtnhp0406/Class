#include <bits/stdc++.h>
using namespace std;

struct phan_so {
    int tu, mau;

    // Ham khoi tao nhap tu va mau
    void init() {
        cout << "Nhap tu: " << '\n';
        cin >> this->tu;

        cout << "Nhap mau: " << '\n';
        cin >> this->mau;

        // Kiem tra mau co bang 0 khong
        if (this->mau == 0) {
            cout << "Loi: Mau so khong the bang 0.\n";
            exit(0);
        }
    }

    // Ham rut gon phan so
    void rut_gon() {
        int g = __gcd(this->tu, this->mau);
        this->tu /= g;
        this->mau /= g;
    }

    // Ham xuat phan so
    void xuat() {
        cout << "Phan so: " << this->tu << '/' << this->mau << '\n';
    }
};

int main() {
    phan_so a;  // Tao doi tuong phan so
    a.init();   // Nhap gia tri cho tu va mau
    a.rut_gon(); // Rut gon phan so
    a.xuat();   // Xuat phan so
}
