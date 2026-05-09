#include "NhanVienVanPhong.h"
#include <sstream>

/*
INPUT: ban phim
OUTPUT: nhan vien van phong hop le
*/
void NhanVienVanPhong::Nhap() {
    NhanVien::Nhap();

    string line;
    int temp;

    while (true) {
        cout << "Nhap so ngay lam: ";
        getline(cin, line);

        stringstream ss(line);
        char extra;

        if (ss >> temp && !(ss >> extra)) {
            soNgayLam = temp;
            break;
        }

        cout << "Nhap sai. Nhap lai.\n";
    }
}

/*
INPUT: thong tin nhan vien
OUTPUT: in ra man hinh
*/
void NhanVienVanPhong::Xuat() {
    NhanVien::Xuat();
    cout << "So ngay lam: " << soNgayLam << endl;
    cout << "Luong: " << TinhLuong() << endl;
}

/*
INPUT: so ngay lam
OUTPUT: luong
ALGORITHM:
luong = soNgayLam * 100000
*/
double NhanVienVanPhong::TinhLuong() {
    return soNgayLam * 100000;
}
