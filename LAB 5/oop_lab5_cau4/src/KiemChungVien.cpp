#include "KiemChungVien.h"
#include <sstream>

using namespace std;

/*
INPUT: ban phim
OUTPUT: kiem chung vien hop le
*/
void KiemChungVien::Nhap() {
    NhanVien::Nhap();

    string line;
    char extra;

    while (true) {
        cout << "Nhap so loi phat hien: ";
        getline(cin, line);

        stringstream ss(line);

        if (ss >> soLoiPhatHien && !(ss >> extra))
            break;

        cout << "Nhap sai. Nhap lai.\n";
    }
}

/*
OUTPUT: in thong tin
*/
void KiemChungVien::Xuat() {
    NhanVien::Xuat();
    cout << "So loi phat hien: " << soLoiPhatHien << endl;
}

/*
OUTPUT: luong kiem chung vien
*/
double KiemChungVien::TinhLuong() {
    return luongCoBan + soLoiPhatHien * 50000;
}
