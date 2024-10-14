 #include <iostream>
#include <cmath>
#include "bai4.cpp"
int main() {
    int n;
    cout << "Nhap so thi sinh: ";
    cin >> n;

    ThiSinh* ds = new ThiSinh[n]; // Tạo mảng động

    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin thi sinh " << i + 1 << ":\n";
        ds[i].Nhap();
    }

    cout << "\nThi sinh co tong diem lon hon 15:\n";
    for (int i = 0; i < n; ++i) {
        if (ds[i].Tong() > 15) {
            ds[i].Xuat();
            cout << endl;
        }
    }

    cout << "\nThi sinh co tong diem lon hon 15:\n";
    float ma=0;
    for(int i = 0; i < n; ++i){
        ma=max(ma,ds[i].Tong());
    }
    for(int i = 0; i < n; ++i){
            if(ds[i].Tong()==ma){
                ds[i].Xuat();
                cout<<endl;
            }
    }
    delete[] ds; // Giải phóng bộ nhớ
    return 0;
}

