#include <bits/stdc++.h>
using namespace std;

// Struct de tinh gia tri sin(x)
struct SinCalculator {
    double x;      // Gia tri dau vao
    double sinx;  // Ket qua tinh toan
    double threshold; // Nguong dung tinh toan

    // Ham khoi tao
    SinCalculator(double value) : x(value), sinx(0), threshold(0.00001) {}

    // Ham tinh sin(x) bang chuoi Taylor
    void calculate() {
        int n = 0;            // Bien dem so hang
        int sign = 1.0;      // Bien de theo doi dau
        double tmp = x;         // Gia tri hien tai

        while (abs(tmp) >= threshold) { // Neu gia tri hien tai lon hon nguong
            sinx += tmp * sign; // Cong vao ket qua
            n++;                 // Tang bien dem
            // Tinh toan hang tiep theo
            tmp = tmp * x * x / ((2 * n) * (2 * n + 1));
            sign *= -1;       // Dao dau
        }
    }

    // Ham xuat ket qua
    void display() {
        cout << fixed << setprecision(5) << sinx << endl;
    }
};

int main() {
    double x;
    cout << "Nhap gia tri x: ";
    cin >> x;

    SinCalculator calculator(x); // Tao doi tuong tinh toan sin
    calculator.calculate();       // Tinh sin(x)
    calculator.display();         // Xuat ket qua

    return 0;
}
