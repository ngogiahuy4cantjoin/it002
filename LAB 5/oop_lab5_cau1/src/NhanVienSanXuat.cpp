#include "NhanVienSanXuat.h"
#include <sstream>

/*
INPUT: ban phim
OUTPUT: nhan vien san xuat hop le
*/
void NhanVienSanXuat::Nhap() {
    NhanVien::Nhap();

    string line;
    int sp;
    double lcb;

    while (true) {
        cout << "Nhap luong can ban: ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> lcb && !(ss >> extra)) break;
        cout << "Nhap sai. Nhap lai.\n";
    }

    while (true) {
        cout << "Nhap so san pham: ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> sp && !(ss >> extra)) break;
        cout << "Nhap sai. Nhap lai.\n";
    }

    luongCanBan = lcb;
    soSanPham = sp;
}

/*
INPUT: thong tin nhan vien
OUTPUT: in ra man hinh
*/
void NhanVienSanXuat::Xuat() {
    NhanVien::Xuat();
    cout << "Luong can ban: " << luongCanBan << endl;
    cout << "So san pham: " << soSanPham << endl;
    cout << "Luong: " << TinhLuong() << endl;
}

/*
INPUT: luong can ban, so san pham
OUTPUT: luong
ALGORITHM:
luong = luongCanBan + soSanPham * 5000
*/
double NhanVienSanXuat::TinhLuong() {
    return luongCanBan + soSanPham * 5000;
}
