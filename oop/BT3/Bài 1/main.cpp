#include <iostream>
#include "bai1.cpp"

int main() {
    PhanSo a, b;

    // Nhập hai số phức
    cout << "Nhap phan so a:\n";
    cin >> a;
    cout << "Nhap phan so b:\n";
    cin >> b;

    // Thực hiện phép toán
    PhanSo tong = a + b;
    PhanSo hieu = a - b;
    PhanSo tich = a * b;
    PhanSo thuong = a / b;

    // Xuất kết quả
    cout << "Tong: " << tong << endl;
    cout << "Hieu: " << hieu << endl;
    cout << "Tich: " << tich << endl;
    cout << "Thuong: " << thuong << endl;

    //sosanh
    if(a==b) cout<<"Bang nhau"<<endl;
    if(a!=b) cout<<"Khac nhau"<<endl;
    if(a<b) cout<<"Be hon"<<endl;
    if(a>b) cout<<"Lon hon"<<endl;

    return 0;
}

