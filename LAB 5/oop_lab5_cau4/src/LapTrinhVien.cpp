#include "LapTrinhVien.h"
#include <sstream>

using namespace std;

/*
INPUT: ban phim
OUTPUT: lap trinh vien hop le
*/
void LapTrinhVien::Nhap() {
    NhanVien::Nhap();

    string line;
    char extra;

    while (true) {
        cout << "Nhap so gio overtime: ";
        getline(cin, line);

        stringstream ss(line);

        if (ss >> soGioOvertime && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }
}

/*
OUTPUT: in thong tin
*/
void LapTrinhVien::Xuat() {
    NhanVien::Xuat();
    cout << "So gio overtime: " << soGioOvertime << endl;
}

/*
OUTPUT: luong lap trinh vien
*/
double LapTrinhVien::TinhLuong() {
    return luongCoBan + soGioOvertime * 200000;
}
