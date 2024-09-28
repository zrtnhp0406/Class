#include <bits/stdc++.h>

using namespace std;

struct Ngay {
    int d, m, y;

    Ngay(int day = 1, int month = 1, int year = 1) : d(day), m(month), y(year) {
        if (!hopLe()) {
            throw invalid_argument("Ngay khong hop le");
        }
    }

    bool namNhuan() const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    bool hopLe() const {
        if (m < 1 || m > 12 || d < 1 || y < 1) return false;
        if (m == 2) return (namNhuan() ? d <= 29 : d <= 28);
        if (m == 4 || m == 6 || m == 9 || m == 11) return d <= 30;
        return d <= 31;
    }

    bool operator<(const Ngay& other) const {
        return (y < other.y) || (y == other.y && (m < other.m || (m == other.m && d < other.d)));
    }

    bool operator==(const Ngay& other) const {
        return d == other.d && m == other.m && y == other.y;
    }
};

struct Gio {
    int h, m;

    Gio(int hour = 0, int minute = 0) : h(hour), m(minute) {
        if (!hopLe()) {
            throw invalid_argument("Gio khong hop le");
        }
    }

    bool hopLe() const {
        return (h >= 0 && h < 24) && (m >= 0 && m < 60);
    }

    bool operator<(const Gio& other) const {
        return (h < other.h) || (h == other.h && m < other.m);
    }
};

struct CB {
    string ma;
    Ngay ng;
    Gio gt;
    string noiDi;
    string noiDen;

    CB(const string& c, const Ngay& d, const Gio& t, const string& dep, const string& arr)
        : ma(c), ng(d), gt(t), noiDi(dep), noiDen(arr) {}
};

void hienThi(const vector<CB>& chuyenBay) {
    for (const auto& cb : chuyenBay) {
             cout << "Ma: " << cb.ma;
             cout<< ", Ngay: " << cb.ng.d << "/" << cb.ng.m << "/" << cb.ng.y;
             cout<< ", Gio: " << cb.gt.h << "h " << cb.gt.m << "m";
             cout<< ", Tu: " << cb.noiDi;
             cout<< ", Den: " << cb.noiDen << '\n';
    }
}
int demCB(const vector<CB>& chuyenBay, const string& di, const string& den) {
    int cnt=0;
    for(auto v: chuyenBay){
        cnt+=v.noiDi==di && v.noiDen==den;
    }
    return cnt;
}

vector<CB> timCB(const vector<CB>& chuyenBay, const string& place) {
    vector<CB> ds;
    for (const auto& cb : chuyenBay) {
        if (cb.noiDi == place)  ds.push_back(cb);
    }
    return ds;
}



int main() {
    vector<CB> chuyenBay;
    int n;

    cout << "Nhap so luong chuyen bay: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string ma, dep, arr;
        int day, month, year, hour, minute;

        cout << "Nhap ma chuyen bay: ";
        getline(cin, ma);

        cout << "Nhap ngay khoi hanh (ngay thang nam): ";
        cin >> day >> month >> year;

        cout << "Nhap gio khoi hanh (gio phut): ";
        cin >> hour >> minute;
        cin.ignore(); // Xoa ky tu newline

        cout << "Nhap noi khoi hanh: ";
        getline(cin, dep);

        cout << "Nhap noi den: ";
        getline(cin, arr);

        try {
            CB cb(ma, Ngay(day, month, year), Gio(hour, minute), dep, arr);
            chuyenBay.push_back(cb);
        } catch (const invalid_argument& e) {
            cout << e.what() << '\n';
            --i; // Giam i de nhap lai chuyen bay
        }
    }

    cout << "Danh sach chuyen bay:\n";
    hienThi(chuyenBay);

    string noiDi;

    cout << "Nhap noi khoi hanh de tim: ";
    getline(cin, noiDi);
    vector<CB> foundCB = timCB(chuyenBay, noiDi);

    hienThi(foundCB);

    string from, to;
    cout << "Nhap noi khoi hanh: ";
    getline(cin, from);
    cout << "Nhap noi den: ";
    getline(cin, to);
    int count = demCB(chuyenBay, from, to);
    cout << "So luong chuyen bay tu " << from << " den " << to << ": " << count << '\n';

    return 0;
}
