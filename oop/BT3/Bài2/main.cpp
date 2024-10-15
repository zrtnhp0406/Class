#include <iostream>
#include "bai2.cpp"

int main() {
    SoPhuc a, b;

    // Nhập hai số phức
    cout << "Nhap so phuc a:\n";
    cin >> a;
    cout << "Nhap so phuc b:\n";
    cin >> b;

    // Thực hiện phép toán
    SoPhuc tong = a + b;
    SoPhuc hieu = a - b;
    SoPhuc tich = a * b;
    SoPhuc thuong = a / b;

    // Xuất kết quả
    cout << "Tong: " << tong << endl;
    cout << "Hieu: " << hieu << endl;
    cout << "Tich: " << tich << endl;
    cout << "Thuong: " << thuong << endl;

    //sosanh
    if(a==b) cout<<"Bang nhau"<<endl;
    else cout<<"Khac nhau"<<endl;
    return 0;
}
