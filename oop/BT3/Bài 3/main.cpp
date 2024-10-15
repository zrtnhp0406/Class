#include <iostream>
#include "bai3.cpp"

using namespace std;

int main() {
    ThoiGian tg1(2, 30, 45); // Thời gian 2h 30m 45s
    ThoiGian tg2(1, 15, 30); // Thời gian 1h 15m 30s

    cin>>tg1;
    cin>>tg2;
    // Thực hiện các phép toán
    ThoiGian tong = tg1 + tg2;
    ThoiGian hieu = tg1 - tg2;

    cout << "Tong: " << tong << endl;
    cout << "Hieu: " << hieu << endl;

    // Kiểm tra tăng, giảm
    ++tg1;
    cout << "tg1 sau khi ++: " << tg1 << endl;

    --tg2;
    cout << "tg2 sau khi --: " << tg2 << endl;

    // So sánh
    if (tg1 > tg2) {
        cout << "tg1 lon hon tg2" << endl;
    } else {
        cout << "tg1 khong lon hon tg2" << endl;
    }

    return 0;
}

