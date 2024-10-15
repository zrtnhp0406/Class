#include "bai4.cpp"

int main() {
    NgayThangNam ngay1, ngay2;

    cout << "Nhap ngay1:" << endl;
    cin >> ngay1;

    cout << "Nhap ngay2:" << endl;
    cin >> ngay2;

    cout << "Ngay1: " << ngay1 << endl;
    cout << "Ngay2: " << ngay2 << endl;
      if (ngay1 < ngay2) {
        cout << "Ngay 1 be hon ngay 2" << endl;
    } else if(ngay1> ngay2){
        cout << "Ngay 1 lon hon ngay 2" << endl;
    }
    else if(ngay1==ngay2){
        cout<< "Ngay 1 bang ngay 2" <<endl;
    }
    ngay1 = ngay1 + 34;
    cout << "Ngay 1 sau khi cong 34 ngay: " << ngay1 << endl;

    ngay2 = ngay2 - 16;
    cout << "Ngay 2 sau khi tru 16 ngay: " << ngay2 << endl;

    ++ngay1;
    cout << "Ngay 1 sau khi cong +1 ngay: " << ngay1 << endl;

    --ngay2;
    cout << "Ngay 2 sau khi tru -1 ngay: " << ngay2 << endl;


    return 0;
}
