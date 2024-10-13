#include "bai1.cpp"

int main() {
    Diem d1; // Sử dụng constructor mặc định
    d1.Xuat(); // Xuất điểm (0, 0)

    Diem d2(3, 4); // Sử dụng constructor với tham số
    d2.Xuat(); // Xuất điểm (3, 4)

    cout<<"Diem sau khi tinh tien: ";
    d2.TinhTien(2, 3); // Dịch điểm d2
    d2.Xuat(); // Xuất điểm (5, 7)

    d1.SetTungDo(5);
    d1.SetHoanhDo(3);
    cout<<"Diem sau khi set la: ";
    cout<< d1.GetTungDo() <<" "<< d1.GetHoanhDo();

    return 0;
}

